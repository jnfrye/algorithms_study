cmake_minimum_required(VERSION 3.5)
project(algorithms_study_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/sorting.cpp)
add_executable(algorithms_study_cpp ${SOURCE_FILES})