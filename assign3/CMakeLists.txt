cmake_minimum_required(VERSION 3.6)
project(assign3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/cpp/json/json-forwards.h
    src/cpp/json/json.h
    src/cpp/jsoncpp.cpp
    src/cpp/main.cpp
    src/cpp/MovieDescription.cpp
    src/cpp/MovieDescription.hpp
    src/cpp/MovieLibrary.cpp
    src/cpp/MovieLibrary.hpp)

add_executable(assign3 ${SOURCE_FILES})