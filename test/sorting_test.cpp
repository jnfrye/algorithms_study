/** Unit tests for `sorting.cpp`
 */

#include <vector>

#include "gtest/gtest.h"

#include "sorting.h"


TEST(InsertionSortTest, PreservesSize1Vector) {
    std::vector<int> singleton = {1};
    std::vector<int> original_singleton(singleton);
    InsertionSort(singleton);

    EXPECT_EQ(singleton, original_singleton) <<
        "A singleton should not change when sorted";
}

TEST(InsertionSortTest, CorrectlySortsKnownVector) {
    std::vector<int> vec = {5, 3, 6, 2, 8, 3, 1};
    std::vector<int> expected_vec = {1, 2, 3, 3, 5, 6, 8};
    InsertionSort(vec);

    EXPECT_EQ(vec, expected_vec) <<
        "Sorted vector did not match with vector sorted by hand!";
}
