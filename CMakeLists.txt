cmake_minimum_required(VERSION 3.30)
project(EX3CPP)

set(CMAKE_CXX_STANDARD 11)

add_executable(EX3CPP main.cpp
        Cell.cpp
        Cell.h
        Forest.cpp
        Forest.h
        Drone.cpp
        Drone.h
        Search.cpp
        Search.h
        TDVector.cpp
        TDVector.h)
