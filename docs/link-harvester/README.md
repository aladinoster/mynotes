# Link Harvester

A CLI tool to crawl websites and extract links, with filtering and ranking capabilities.

## Setup

Initialize the project environment:
```bash
uv sync
```

## Usage

Run the tool using `uv run`:

```bash
uv run python main.py [OPTIONS] URL
```

### Examples

**1. Harvest all links from a documentation site:**
```bash
uv run python main.py https://spark.apache.org/docs
```

**2. Get the top 15 most referenced internal links:**
```bash
uv run python main.py https://spark.apache.org/docs --top 15
```

**3. Filter for specific content (e.g., only API references):**
```bash
uv run python main.py https://spark.apache.org/docs --filter "api"
```

**4. Capture output to a file:**
```bash
uv run python main.py https://spark.apache.org/docs > links.txt
```
or use the `-o` flag:
```bash
uv run python main.py https://spark.apache.org/docs -o links.txt
```

## Options

*   `URL`: The target URL to crawl (Required).
*   `--top, -n INTEGER`: Return the top N most referenced links.
*   `--filter, -f TEXT`: Filter links containing this text string.
*   `--output, -o TEXT`: Save output to this file instead of stdout.
*   `--cleanup / --no-cleanup`: Remove temporary crawl data (Default: True).
