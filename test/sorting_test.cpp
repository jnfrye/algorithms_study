/** Unit tests for `sorting.cpp`
 */

#include <vector>

#include "sorting.h"
#include "gtest/gtest.h"

TEST(InsertionSortTest, Size1Vector) {
    std::vector<int> singleton = {1};
    std::vector<int> original_singleton(singleton);
    InsertionSort(singleton);

    EXPECT_EQ(singleton, original_singleton) <<
        "A singleton should not change when sorted";
}
