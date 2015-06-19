cmake_minimum_required(VERSION 3.2)
project(EMST)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(src SOURCE_FILES)
add_executable(EMST ${SOURCE_FILES})