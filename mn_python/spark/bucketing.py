from pyspark.sql import SparkSession
from pyspark.ml.feature import Bucketizer
import pyspark.sql.functions as F
from pyspark.sql.types import IntegerType

def main():
    spark = SparkSession.builder.getOrCreate()

    # Sample data: numeric values in a column 'value'
    data = [
        (5.0,),
        (12.3,),
        (19.8,),
        (25.0,),
        (30.5,),
        (45.7,)
    ]
    columns = ["value"]

    df = spark.createDataFrame(data, columns)
    print("Original DataFrame:")
    df.show()

    col_to_bin = "value"

    # Define bucket splits (bins): [0,10), [10,20), [20,Inf)
    splits = [0, 10, 20, float("Inf")]

    bucketizer = Bucketizer(
        splits=splits,
        inputCol=col_to_bin,
        outputCol=f"{col_to_bin}_bins"
    )

    # Apply Bucketizer to bin values
    bin_df = bucketizer.transform(df)

    # Cast bin output from double to int for convenience
    bin_df = bin_df.withColumn(
        f"{col_to_bin}_bins",
        F.col(f"{col_to_bin}_bins").cast(IntegerType())
    )

    print("DataFrame after Bucketizer and casting bins to int:")
    bin_df.show()

if __name__ == "__main__":
    main()

