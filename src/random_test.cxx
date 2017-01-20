/** Unit tests for `sorting.cpp`
 */

#include <vector>
#include <string>

#include "gtest/gtest.h"

#include "algorithm/random.hpp"


class GeneralRandomTest: public ::testing::Test {
public:
    std::vector<int> singleton;
    std::vector<int> vec;
    std::vector<int> vec_sorted;

protected:
    virtual void SetUp() {
        singleton = {5};
        vec = {5, 3, 6, 2, 8, 3, 1};
        vec_sorted = {1, 2, 3, 3, 5, 6, 8};
    }
};

TEST_F(GeneralRandomTest, PreservesSize1Vector) {
    std::string error_msg = "A singleton should not change when permuted!";

    std::vector<int> original_singleton(singleton);

    // We test each sorting algorithm in turn
    // We use ASSERT_EQ because if any of them fails, the others will fail
    // erroneously.
    RandomlyPermute(singleton);
    ASSERT_EQ(singleton, original_singleton) << error_msg;
}
