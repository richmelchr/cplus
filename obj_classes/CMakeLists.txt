cmake_minimum_required(VERSION 3.6)
project(obj_classes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp)
add_executable(obj_classes ${SOURCE_FILES})