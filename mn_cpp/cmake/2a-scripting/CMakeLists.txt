cmake_minimum_required(VERSION 3.13)

# Good to do this at the beginning of the project 

project(MyProject VERSION 2.1.3) # Everything is a string

message(STATUS "I am a message") # Quotes are important when there are spaces to avoid multiple arguments

set(MY_VARIABLE "I am a variable")

message(STATUS "${MY_VARIABLE}")

message(STATUS "The name of this project is: ${PROJECT_NAME}")

message(STATUS "Major version of this project  is: ${PROJECT_VERSION_MAJOR}")

message(STATUS "Minor version of this project  is: ${PROJECT_VERSION_MINOR}")