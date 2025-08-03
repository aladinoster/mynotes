cmake_minimum_required(VERSION 3.12)
project(MyProject VERSION 2.4.1)

set(my_list 1 2 3)
# set(target GLOBAL)
set(target DIRECTORY "${PROJECT_SOURCE_DIR}") # To indicate that target ="GLOBAL " no special thing here

set_property(
    ${target} # pass by reference
    PROPERTY FOO 
    "${my_list}"
)

get_cmake_property(foo_value FOO) # This reads only in global 
message(STATUS "Value of FOO: ${foo_value}")

get_property(foo_value ${target} PROPERTY FOO)
message(STATUS "Value of FOO: ${foo_value}")

# Functions

function(do_cmake_good first)
    message(STATUS "Hello world!")
    message(STATUS "This is my first argument ${first}")
endfunction()

do_cmake_good(1)

# Multiple arguments

function(do_another_good first second third fourth)
    message(STATUS "This is my first argument ${first}")
    message(STATUS "This is my second argument ${second}")
    message(STATUS "This is my third argument ${third}")
    message(STATUS "This is my fourth argument ${fourth}")
endfunction()

do_another_good(1 2 3 4)
# Variable arguments

function(variable_argfn)
    foreach(arg IN LISTS ARGN)
        message(STATUS "Got argument: ${arg}")
    endforeach()
endfunction() 

variable_argfn(1 2 3)

#combining

function(variable_argfncmb first two second)
    foreach(arg IN LISTS ARGN)
        message(STATUS "Got argument ARGN: ${arg}")
    endforeach()
    foreach(arg IN LISTS ARGV)
        message(STATUS "Got argument ARV: ${arg}")
    endforeach()    
endfunction() 

variable_argfncmb(1 2 3 4 5 6)

# Scope: Cmake copy variables of the parent scope into the functioin scope 

function(my_scope)
    message(STATUS "Step 1: I am a lyon and I do: ${MY_SOUND}")
    set(MY_SOUND "Grr" PARENT_SCOPE) # Changing variables in the scope of a function  # Change out of the scope if not you are a cat! 
    message(STATUS "Step 2: Now I am a real Lyon and I do: ${MY_SOUND}")
endfunction()

set(MY_SOUND Meow)

my_scope()

# AFter the call remains unchanged
message(STATUS "Step 3: After calling,  I am a real Lyon and I do: ${MY_SOUND}")

# De referencing 
function(increment var)
    message(STATUS "Variable before increment is ${var}") # Dereference a variable (takes its value instead of "value")
    message(STATUS "Variable before increment is ${${var}}") # Dereference a variable (takes its value instead of "var")
    math(EXPR new_value "${${var}} + 1")
    message(STATUS "Variable after increment is ${new_value}")
    set("${var}" "${new_value}" PARENT_SCOPE) # This is super important! 
endfunction()

set(value 14)
increment(value)
message(STATUS "The new value is ${value}")

# Example b sum 
function(addition out a b)
    math(EXPR ret "${a} + ${b}")
    set("${out} ${ret}" PARENT_SCOPE)
    message(STATUS "Sum of ${${a}} + ${${b}} = ${${out}}")
    # cmake_parse_arguments() # Important but 
endfunction()

addition(value 1 1)
message(STATUS "The value of the sum is ${value}")

