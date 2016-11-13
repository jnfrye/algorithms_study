# Add project sources
include_directories(../include)
file(GLOB SOURCES "../src/*.cpp")

# Add googletest stuff
set(GTEST_ROOT ../ext/googletest-master/googletest)
include_directories(${GTEST_ROOT}/include)
set(TEST_SOURCES sorting_test.cpp)

# Link it all together
add_executable(run_tests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(run_tests gtest_main)
