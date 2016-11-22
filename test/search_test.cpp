/** Unit tests for `searching.cpp`
 */

#include <string>       // std::string
#include <vector>       // std::vector
#include <tuple>        // std::tuple
#include <algorithm>    // std::find
#include <cmath>        // std::floor

#include "gtest/gtest.h"

#include "algorithm/vector/search.hpp"
#include "algorithm/vector/sort.hpp"


/** General test fixture for vector search algorithms.
 */
class GeneralSearchingTest: public ::testing::Test {
public:
    std::vector<int> singleton;
    std::vector<int> vec;

protected:
    virtual void SetUp() {
        singleton = {5};
        vec = {-10, 3, -5, -3, 6, 2, 8, -24, 10, 11, -3};
    }
};

/** Basic test of vector item search algorithms.
 */
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

/** Item search algorithms should throw exception if item not found.
 */
TEST_F(GeneralSearchingTest, ItemNotFoundThrowsException) {
    EXPECT_THROW(LinearSearch(vec, 20), std::runtime_error);

    // To test binary search, we first sort the vector
    InsertionSort(vec);
    EXPECT_THROW(BinarySearch(vec, 0, vec.size(), 20), std::runtime_error);
}

/** Basic test of crossing subvector max sum search.
 */
TEST_F(GeneralSearchingTest, MaxCrossingSubvectorWorksOnBasicVector) {
    auto results  = FindMaxCrossingSubvector(
        vec, 0, (int)std::floor(vec.size()/2.), (int)vec.size());

    EXPECT_EQ(results, std::make_tuple(4, 7, 16))
        << "Max crossing subvector does not match expected subvector.";
}

/** Basic test of subvector max sum search.
 */
TEST_F(GeneralSearchingTest, MaxSubvectorWorksOnBasicVector) {
    auto results = FindMaxSubvector(vec, 0, (int)vec.size());

    EXPECT_EQ(results, std::make_tuple(8, 10, 21))
        << "Max subvector does not match expected subvector.";
}

/** Max subvector sum of a singleton should be the value of the item contained.
 */
TEST_F(GeneralSearchingTest, MaxSubvectorOfSingletonIsItself) {
    auto results = FindMaxSubvector(singleton, 0, (int)singleton.size());

    EXPECT_EQ(results, std::make_tuple(0, 1, singleton[0]))
        << "Max subvector sum of singleton should be the singleton.";
}
