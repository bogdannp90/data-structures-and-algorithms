cmake_minimum_required(VERSION 3.29)
project(laborator)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(laborator main.cpp
        include/probleme_diverse.h
        src/probleme_diverse.cpp
        src/algoritmi_sortare.cpp
        include/algoritmi_sortare.h
        src/liste_dinamice.cpp
        include/liste_dinamice.h
        src/grafuri.cpp
        include/grafuri.h)
