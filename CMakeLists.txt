cmake_minimum_required(VERSION 3.29)
project(laborator)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(laborator main.cpp
        include/variousProblems.h
        src/variousProblems.cpp
        src/sortingAlgorithms.cpp
        include/sortingAlgorithms.h
        src/dynamicLists.cpp
        include/dynamicLists.h
        src/graphs.cpp
        include/graphs.h
        src/inputValidation.cpp
        include/inputValidation.h
        src/trees.cpp
        include/trees.h)
