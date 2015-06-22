cmake_minimum_required(VERSION 3.2)
project(EMST)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

set(CMAKE_BUILD_TYPE "Release")

find_package(CGAL QUIET COMPONENTS)
include(${CGAL_USE_FILE})
find_package(Boost REQUIRED)
find_package(OpenCV REQUIRED)
set(OpenCV_INCLUDE_DIRS "${OpenCV_CONFIG_PATH}/include" "${OpenCV_CONFIG_PATH}/include/opencv")
include_directories(${OpenCV_INCLUDE_DIRS})

aux_source_directory(src SOURCE_FILES)
aux_source_directory(test TEST_SOURCE_FILES)
add_executable(EMST ${SOURCE_FILES})
target_link_libraries(EMST ${OpenCV_LIBS})
