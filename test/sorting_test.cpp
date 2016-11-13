/** Unit tests for `sorting.cpp`
 */

#include <vector>
#include <string>

#include "gtest/gtest.h"

#include "sorting.h"


class GeneralSortingTest: public ::testing::Test {
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

TEST_F(GeneralSortingTest, PreservesSize1Vector) {
    std::string error_msg = "A singleton should not change when sorted!";

    std::vector<int> original_singleton(singleton);

    // We test each sorting algorithm in turn
    // We use ASSERT_EQ because if any of them fails, the others will fail
    // erroneously.
    InsertionSort(singleton);
    ASSERT_EQ(singleton, original_singleton) << error_msg;
    SelectionSort(singleton);
    ASSERT_EQ(singleton, original_singleton) << error_msg;
    MergeSort(singleton, 0, (int)singleton.size());
    ASSERT_EQ(singleton, original_singleton) << error_msg;
}

TEST_F(GeneralSortingTest, CorrectlySortsKnownVector) {
    std::string error_msg =
        "Sorted vector did not match with vector sorted by hand!";

    auto original_vec(vec);

    InsertionSort(vec);
    EXPECT_EQ(vec, vec_sorted) << error_msg;

    vec = original_vec; // reset vector
    SelectionSort(vec);
    EXPECT_EQ(vec, vec_sorted) << error_msg;

    vec = original_vec; // reset vector
    MergeSort(vec, 0, vec.size());
    EXPECT_EQ(vec, vec_sorted) << error_msg;
}
