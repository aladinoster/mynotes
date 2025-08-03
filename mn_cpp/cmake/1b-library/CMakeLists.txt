cmake_minimum_required(VERSION 3.13)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

project(sample VERSION 1.0.0)

add_library(
    say-hello SHARED
    hello.hpp
    hello.cpp
)


add_executable(
    sample
    main.cpp
)

target_link_libraries(sample PRIVATE say-hello)