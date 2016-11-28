cmake_minimum_required(VERSION 3.5)
project(algorithms_study_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

### MAIN EXECUTABLE
# Gather sources and includes
include_directories(include)
file(GLOB VECTOR_SOURCES "src/vector/*.cpp")
file(GLOB MATRIX_SOURCES "src/matrix/*.cpp")
set(SOURCES ${VECTOR_SOURCES} ${MATRIX_SOURCES})

# Add sources to main executable
add_executable(algorithms_study main.cpp ${SOURCES})

### UNIT TESTING
# Gather test sources
file(GLOB VECTOR_TEST_SOURCES "src/vector/*.cxx")
file(GLOB MATRIX_TEST_SOURCES "src/matrix/*.cxx")
set(TEST_SOURCES ${VECTOR_TEST_SOURCES} ${MATRIX_TEST_SOURCES})

# Add googletest stuff
add_subdirectory(ext/googletest-master)
set(GTEST_ROOT ext/googletest-master/googletest)
include_directories(${GTEST_ROOT}/include)

# Link it all together
add_executable(run_tests ${SOURCES} ${TEST_SOURCES})
target_link_libraries(run_tests gtest_main)