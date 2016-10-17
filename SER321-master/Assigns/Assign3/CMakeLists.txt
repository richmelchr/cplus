cmake_minimum_required(VERSION 3.6)
project(Assign3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES
    src/cpp/main.cpp
    src/cpp/MovieDescription.cpp
    src/cpp/MovieDescription.hpp
    src/cpp/MovieLibrary.cpp
    src/cpp/MovieLibrary.hpp
    lib/jsoncpp/src/lib_json/json_reader.cpp
    lib/jsoncpp/src/lib_json/json_value.cpp
    lib/jsoncpp/src/lib_json/json_writer.cpp
    src/cpp/media.json
    src/cpp/media-cpp.json)

add_executable(Assign3 ${SOURCE_FILES})