cmake_minimum_required(VERSION 3.6)
project(assign3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES
    main.cpp
    MovieDescription.cpp
    MovieDescription.hpp
    MovieLibrary.cpp
    MovieLibrary.hpp)

add_executable(assign3 ${SOURCE_FILES})