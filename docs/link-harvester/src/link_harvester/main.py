#!/usr/bin/env python3
import warnings
warnings.filterwarnings("ignore")

import typer
import advertools as adv
import pandas as pd
import os
from typing import Optional
from rich.console import Console
from rich.progress import Progress, SpinnerColumn, TextColumn
import shutil
import tempfile
import logging

# Suppress Scrapy logs to keep stderr clean
logging.getLogger('scrapy').setLevel(logging.WARNING)
logging.getLogger('twisted').setLevel(logging.WARNING)
logging.getLogger('peewee').setLevel(logging.WARNING)
logging.getLogger('advertools').setLevel(logging.WARNING)

app = typer.Typer(help="Harvest and rank links from a website.")
console = Console(stderr=True)  # Print status to stderr so stdout is pipe-friendly

@app.command()
def harvest(
    url: str = typer.Argument(..., help="The URL to start crawling (e.g., https://spark.apache.org/docs)."),
    top: Optional[int] = typer.Option(None, "--top", "-n", help="Return the top N most referenced links."),
    filter_text: Optional[str] = typer.Option(None, "--filter", "-f", help="Filter links containing this text string."),
    output_file: Optional[str] = typer.Option(None, "--output", "-o", help="Save output to this file instead of printing to stdout."),
    cleanup: bool = typer.Option(True, help="Remove temporary crawl data after processing.")
):
    """
    Crawls a website and extracts links. Can filter by content and rank by internal connectivity.
    """
    
    # Create a temporary file for the crawl output (JSON Lines)
    temp_dir = tempfile.mkdtemp()
    crawl_output_file = os.path.join(temp_dir, "crawl_data.jl")

    try:
        with Progress(
            SpinnerColumn(),
            TextColumn("[progress.description]{task.description}"),
            console=console,
            transient=True,
        ) as progress:
            progress.add_task(description=f"Crawling {url}...", total=None)
            
            # Run the crawler
            # follow_links=True is default, but explicit is good.
            # We restrict the crawl to the domain of the input URL implicitly by advertools/scrapy default behavior
            adv.crawl(
                url, 
                crawl_output_file, 
                follow_links=True,
                custom_settings={
                    'LOG_ENABLED': False, # vital to keep stdout/stderr clean
                    'DEPTH_LIMIT': 3,     # Reasonable default to prevent infinite crawls
                    'CLOSESPIDER_PAGECOUNT': 500 # Safety limit, can be increased if needed
                }
            )

        if not os.path.exists(crawl_output_file) or os.path.getsize(crawl_output_file) == 0:
            console.print("[bold red]Error:[/bold red] No data found or crawl failed.", style="red")
            raise typer.Exit(code=1)

        # Process the data
        with console.status("[bold green]Processing links...[/bold green]", spinner="dots"):
            # Read the crawl output
            df = pd.read_json(crawl_output_file, lines=True)
            
            # Check if 'links_url' column exists (it contains the outlinks from each page)
            if 'links_url' not in df.columns:
                 console.print("[bold red]Error:[/bold red] No links found in the crawled pages.", style="red")
                 raise typer.Exit(code=1)

            # explode the list of links into individual rows
            # This creates a Series of all *destination* URLs found in the crawl
            all_links = df['links_url'].explode().dropna()
            
            # Normalize: strip whitespace
            all_links = all_links.str.strip()

            # Filter logic
            if filter_text:
                all_links = all_links[all_links.str.contains(filter_text, case=False, na=False)]

            # Ranking logic
            if top:
                # Count occurrences of each URL (how many pages link TO it)
                link_counts = all_links.value_counts()
                # Get the top N
                result_links = link_counts.head(top).index.tolist()
            else:
                # Just return unique links if no ranking requested? 
                # Or just all of them? The user prompt implies "create files like @databricks.txt", which is a list.
                # Usually we want unique links.
                result_links = all_links.drop_duplicates().tolist()
                # Sort alphabetically for consistency
                result_links.sort()

        # Output logic
        output_content = "\n".join(result_links)
        
        if output_file:
            with open(output_file, 'w') as f:
                f.write(output_content)
            console.print(f"[bold green]Success![/bold green] Links saved to {output_file}")
        else:
            # Print plain text to stdout
            print(output_content)

    except Exception as e:
        console.print(f"[bold red]An unexpected error occurred:[/bold red] {e}")
        raise typer.Exit(code=1)
    finally:
        if cleanup and os.path.exists(temp_dir):
            shutil.rmtree(temp_dir)

if __name__ == "__main__":
    app()
