cmake_minimum_required(VERSION 3.2)
project(EMST)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11 -O2")

set(CMAKE_BUILD_TYPE "Release")

find_package(CGAL QUIET COMPONENTS)
include(${CGAL_USE_FILE})
find_package(Boost REQUIRED)

aux_source_directory(src SOURCE_FILES)
add_executable(EMST ${SOURCE_FILES})
