from pyspark.sql import SparkSession
from pyspark.ml.feature import StringIndexer, OneHotEncoder, VectorAssembler

def main():
    spark = SparkSession.builder.getOrCreate()

    # Each item must be a tuple, so add commas!
    data = [
        ("A",),
        ("B",),
        ("C",),
    ]

    columns = ["category"]
    idx_columns = ["index_" + c for c in columns]
    ohe_columns = ["ohe_" + c for c in columns]
    vas_column = "features"

    df = spark.createDataFrame(data, columns)
    df.show()

    stridx = StringIndexer(
        inputCols=columns,
        outputCols=idx_columns,
        handleInvalid='skip'
    )

    ohe = OneHotEncoder(
        inputCols=idx_columns,
        outputCols=ohe_columns,
        handleInvalid='keep'
    )

    ass = VectorAssembler(
        inputCols=ohe_columns,
        outputCol=vas_column
    )

    # Apply transformations step-by-step
    df_stridx = stridx.fit(df).transform(df)  
    df_ohe = ohe.fit(df_stridx).transform(df_stridx) 
    df_res = ass.transform(df_ohe)

    df_res.show(truncate=False)

if __name__ == "__main__":
    main()
