cmake_minimum_required(VERSION 3.15)

# set the project name
project(21f-pa01)

# add the executable
add_executable(21f-pa01 main.cpp readInput.h painting.cpp painting.h readInput.cpp wallPlacement.cpp wallPlacement.h)
set(CMAKE_CXX_STANDARD 14)
set (input01 "/Users/kyledoran/Documents/GitHub/21f-pa01-kyle-d/test/input.txt")
set (input02 "")
set (input03 "")
foreach(file IN LISTS input01 input02 input03)
    configure_file(${file} ${file} COPYONLY)
endforeach()

#
##########################################


