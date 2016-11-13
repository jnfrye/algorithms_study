/** Unit tests for `searching.cpp`
 */

#include <string>       // std::string
#include <vector>       // std::vector
#include <algorithm>    // std::find
#include <exception>    // std::runtime_error

#include "gtest/gtest.h"

#include "searching.h"


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
    int index = LinearSearch(vec, 2);

    // We can also find the index using the std::find function
    auto iterator = std::find(vec.begin(), vec.end(), 2);
    // convert from iterator to integer index
    int comparison_index = std::distance(vec.begin(), iterator);

    EXPECT_EQ(index, 3) << "Search returned incorrect index.";
    EXPECT_EQ(index, comparison_index) 
        << "Search disagreed with standard library search.";
}

TEST_F(GeneralSearchingTest, ItemNotFoundThrowsException) {
    EXPECT_THROW(LinearSearch(vec, 20), std::runtime_error);
}
