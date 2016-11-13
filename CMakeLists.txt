cmake_minimum_required(VERSION 3.5)
project(algorithms_study_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Link to googletest
add_subdirectory(ext/googletest-master)
add_subdirectory(test)

# Gather sources and includes
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
set(SOURCE_FILES main.cpp ${SOURCES})

# Add sources to main executable
add_executable(algorithms_study_cpp ${SOURCE_FILES})
