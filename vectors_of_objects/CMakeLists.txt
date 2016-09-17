cmake_minimum_required(VERSION 3.6)
project(vectors_of_objects)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp)
add_executable(vectors_of_objects ${SOURCE_FILES})