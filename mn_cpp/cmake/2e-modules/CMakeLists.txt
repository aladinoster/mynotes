cmake_minimum_required(VERSION 3.13)

# message(STATUS "${CMAKE_MODULE_PATH}")

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# message(STATUS "${CMAKE_MODULE_PATH}")

project (TestProject VERSION 1.0.0)

message(STATUS "${CMAKE_BINARY_DIR}")

find_package(GDAL PATHS "/usr/local/Cellar/gdal/2.4.4")
find_package(GDAL)

# find_package(XQilla)

# message(STATUS "${XQILLA_INCLUDE_DIR}")

# if(XQilla_FOUND)
#     message(STATUS "\t XQilla library found") 
# else()
#     message(STATUS "\t XQilla library is missing") 
# endif()