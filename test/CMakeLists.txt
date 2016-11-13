# Add project sources
include_directories(../include)
file(GLOB SOURCES "../src/*.cpp")

# Add googletest stuff
set(GTEST_ROOT ../ext/googletest-master/googletest)
include_directories(${GTEST_ROOT}/include)
file(GLOB TEST_SOURCES "./*.cpp")

# Link it all together
add_executable(run_tests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(run_tests gtest_main)
