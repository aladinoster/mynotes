cmake_minimum_required(VERSION 3.13)

# Good to do this at the beginning of the project 

project(MyProject VERSION 2.1.3) # Everything is a string

if("FALSE")
    message(STATUS "Condition was met")
else()
    message(STATUS "Condition failed")
endif()

set(MY_BOOL TRUE)

if(MY_BOOL)
    message(STATUS "Your variable is ${MY_BOOL}")
else()
    message(STATUS "Your variable is ${MY_BOOL}")
endif()


set(MY_STRING "I am your brother")
set(MY_OTHER_STRING "I am your brother")

if(NOT MY_STRING STREQUAL MY_OTHER_STRING) # Do not try "MY_OTHER_STRING" or "${MY_OTHER_STRING}"
    message(STATUS "We are brothers")
elseif(MY_STRING MATCHES "brother$") # Regex
    message(STATUS "You end with the word brother")
endif()

set(my_value 1)

while(my_value LESS 10)
    message(STATUS "While is ${my_value}")
    math(EXPR my_value "${my_value} + 1")
endwhile()

foreach(idx RANGE 0 10 2)
    message(STATUS "For is in ${idx}")
endforeach()