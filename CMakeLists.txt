cmake_minimum_required(VERSION 3.5)
project(algorithms_study_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Link to googletest
set(PROJECT_LINK_LIBS libgtest.a)
set(GTEST_BUILD /home/jfrye/Programs/googletest/build)
set(GTEST_ROOT /home/jfrye/Programs/googletest/googletest/googletest)
link_directories(${GTEST_BUILD}/googlemock/gtest)
include_directories(${GTEST_ROOT}/include)

# Gather sources and includes
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
set(SOURCE_FILES main.cpp ${SOURCES})

# Add sources and googletest to executable
add_executable(algorithms_study_cpp ${SOURCE_FILES})
target_link_libraries(algorithms_study_cpp ${PROJECT_LINK_LIBS})