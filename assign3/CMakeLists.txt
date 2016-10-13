cmake_minimum_required(VERSION 3.6)
project(assign3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES
    main.cpp
    MovieDescription.cpp
    MovieDescription.hpp
    MovieLibrary.cpp
    MovieLibrary.hpp
        lib/jsoncpp/src/lib_json/json_reader.cpp
        lib/jsoncpp/src/lib_json/json_value.cpp
        lib/jsoncpp/src/lib_json/json_writer.cpp
        )
add_executable(assign3 ${SOURCE_FILES})