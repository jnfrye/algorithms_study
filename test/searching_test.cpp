/** Unit tests for `searching.cpp`
 */

#include <string>       // std::string
#include <vector>       // std::vector
#include <algorithm>    // std::find

#include "gtest/gtest.h"

#include "searching.h"
#include "sorting.h"


class GeneralSearchingTest: public ::testing::Test {
public:
    std::vector<int> singleton;
    std::vector<int> vec;

protected:
    virtual void SetUp() {
        singleton = {5};
        vec = {5, 3, 6, 2, 8, 3, 1};
    }
};

TEST_F(GeneralSearchingTest, SearchingFindsKnownItem) {
    int search_value = 2;
    int linear_search_result = LinearSearch(vec, search_value);

    // We can also find the index using the std::find function
    int comparison_index = (int)std::distance(
        vec.begin(), std::find(vec.begin(), vec.end(), search_value));

    EXPECT_EQ(linear_search_result, comparison_index)
        << "Search disagreed with standard library search.";

    // To test binary search, we first sort the vector
    InsertionSort(vec);
    int binary_search_result = BinarySearch(
        vec, 0, (int)vec.size(), search_value);

    // Get the comparison index using standard library again
    comparison_index = (int)std::distance(
        vec.begin(), std::find(vec.begin(), vec.end(), search_value));

    EXPECT_EQ(binary_search_result, comparison_index)
        << "Search disagreed with standard library search.";
}

TEST_F(GeneralSearchingTest, ItemNotFoundThrowsException) {
    EXPECT_THROW(LinearSearch(vec, 20), std::runtime_error);
}
