cmake_minimum_required(VERSION 3.26)
project(Nr6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)

add_executable(Nr6
        include/curs.h
        include/materie.h
        include/student.h
        curs.cpp
        main.cpp
        materie.cpp
        student.cpp)
