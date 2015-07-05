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

file(GLOB SOURCE_FILES src/*)
set(SOURCE_FILES_TEST ${SOURCE_FILES})
file(GLOB TEST_SOURCE_FILES test/*)
list(REMOVE_ITEM SOURCE_FILES_TEST ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
add_executable(EMST ${SOURCE_FILES})
add_executable(EMST_Test ${TEST_SOURCE_FILES} ${SOURCE_FILES_TEST})
target_link_libraries(EMST ${OpenCV_LIBS})
target_link_libraries(EMST_Test ${OpenCV_LIBS})
