import os

import polars as pl
from pyiceberg.catalog import load_catalog

# Define where you want the data to live on your WSL disk
warehouse_path = "./my_iceberg_warehouse"
os.makedirs(warehouse_path, exist_ok=True)

# 1. Use a 'sql' catalog with SQLite to persist metadata to a file
# This creates 'pyiceberg_catalog.db' in your folder to track the table
catalog = load_catalog("local", **{
    "type": "sql",
    "uri": f"sqlite:///{warehouse_path}/pyiceberg_catalog.db",
    "warehouse": f"file://{os.path.abspath(warehouse_path)}"
})

# 2. Setup Namespace and Table as before
namespace = "default"
try:
    catalog.create_namespace(namespace)
except:
    pass # Already exists

df = pl.read_csv("https://raw.githubusercontent.com/datasets/oil-prices/refs/heads/main/data/brent-daily.csv")

# Create the table (if it doesn't exist)
table_id = f"{namespace}.brent_prices"
try:
    table = catalog.create_table(table_id, schema=df.to_arrow().schema)
except:
    table = catalog.load_table(table_id)

# 3. Write data to disk
table.append(df.to_arrow())

print(f"Table persisted to {warehouse_path}")

