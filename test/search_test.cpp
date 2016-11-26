/** Unit tests for `searching.cpp`
 */

#include <string>       // std::string
#include <vector>       // std::vector
#include <tuple>        // std::tuple
#include <algorithm>    // std::find
#include <ctime>        // std::time

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

/** Randomized test fixture for vector search algorithms.
 */
class RandomizedSearchingTest: public ::testing::Test {
public:
    std::vector<int> random_singleton;
    std::vector<int> random_vec;
    std::vector<int> random_negative_vec;
    std::vector<int> random_positive_vec;

protected:
    virtual void SetUp() {
        std::srand((unsigned int)std::time(nullptr)); // Seed the RNG

        int random_size = std::rand() % 20 + 2; // range of 2 to 21
        random_vec = std::vector<int>((unsigned int)random_size);

        // Fill the vector with random values
        for (int i = 0; i < random_vec.size(); i++)
            random_vec[i] = std::rand() % 41 - 20; // range -20 to 20

        // Fill the positive vector with random values above zero
        random_positive_vec = random_vec;
        for (int i = 0; i < random_positive_vec.size(); i++)
            random_positive_vec[i] = std::rand() % 20 + 1; // range 1 to 20

        // The random negative vector is just the negative of the random
        // positive vector above.
        random_negative_vec = random_positive_vec;
        for (int i = 0; i < random_negative_vec.size(); i++)
            random_negative_vec[i] *= -1;
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
    std::string error_message =
        "Max subvector does not match expected subvector.";

    auto DAC_results = FindMaxSubvectorDAC(vec, 0, (int)vec.size());
    auto BF_results = FindMaxSubvectorBF(vec, 0, (int)vec.size());

    auto expected_results = std::make_tuple(8, 10, 21);

    EXPECT_EQ(DAC_results, expected_results) << error_message;
    EXPECT_EQ(BF_results, expected_results) << error_message;
}

/** Max subvector sum of a singleton should be the value of the item contained.
 */
TEST_F(GeneralSearchingTest, MaxSubvectorOfSingletonIsItself) {
    std::string error_message =
        "Max subvector sum of singleton should be the singleton.";

    auto DAC_results = FindMaxSubvectorDAC(singleton, 0, (int)singleton.size());
    auto BF_results = FindMaxSubvectorBF(singleton, 0, (int)singleton.size());

    auto expected_results = std::make_tuple(0, 1, singleton[0]);

    EXPECT_EQ(DAC_results, expected_results) << error_message;
    EXPECT_EQ(BF_results, expected_results) << error_message;
}

/** Max crossing subvector of a negative vector should be the smallest one.
 */
TEST_F(RandomizedSearchingTest,
        MaxCrossingSubvectorOfRandomNegVecIsSmallestOne) {
    std::string error_message = "Max crossing subvector of a negative vector "
        "should be the smallest one.";

    int middle_index = (int)std::floor(random_negative_vec.size()/2.);

    auto results = FindMaxCrossingSubvector(
        random_negative_vec, 0, middle_index, (int)random_negative_vec.size());

    int middle_sum = random_negative_vec[middle_index - 1] +
        random_negative_vec[middle_index];
    auto expected_results = std::make_tuple(
        middle_index - 1, middle_index + 1, middle_sum);
    EXPECT_EQ(results, expected_results) << error_message;
}

/** Max crossing subvector of a positive vector should be the entire vector.
 */
TEST_F(RandomizedSearchingTest,
        MaxCrossingSubvectorOfRandomPosVecIsEntireVec) {
    int middle_index = (int)std::floor(random_positive_vec.size()/2.);
    auto results = FindMaxCrossingSubvector(
        random_positive_vec, 0, middle_index,
        (int)random_positive_vec.size());

    int expected_sum = 0;
    for (int i = 0; i < random_positive_vec.size(); ++i)
        expected_sum += random_positive_vec[i];

    EXPECT_EQ(results,
        std::make_tuple(0, random_positive_vec.size(), expected_sum))
        << "Max crossing subvector of a positive vector should be the entire "
           "vector.";
}

/** Max subvector of a positive vector should be the entire vector.
 */
TEST_F(RandomizedSearchingTest, MaxSubvectorOfRandomPosVecIsEntireVec) {
    std::string error_message =
        "Max subvector of a positive vector should be the entire vector.";

    auto DAC_results = FindMaxSubvectorDAC(
        random_positive_vec, 0, (int)random_positive_vec.size());
    auto BF_results = FindMaxSubvectorBF(
        random_positive_vec, 0, (int)random_positive_vec.size());
    auto Kadane_results = FindMaxSubvector(
        random_positive_vec, 0, (int)random_positive_vec.size());

    int expected_sum = 0;
    for (int i = 0; i < random_positive_vec.size(); ++i)
        expected_sum += random_positive_vec[i];
    auto expected_results = std::make_tuple(
        0, random_positive_vec.size(), expected_sum);

    EXPECT_EQ(DAC_results, expected_results) << error_message;
    EXPECT_EQ(BF_results, expected_results) << error_message;
    EXPECT_EQ(Kadane_results, expected_results) << error_message;
}

/** Max subvector of a negative vector should be the least negative item.
 */
TEST_F(RandomizedSearchingTest, MaxSubvectorOfRandomNegVecIsMaxItem) {
    std::string error_message =
        "Max subvector of a negative vector should be the least negative item.";

    auto DAC_results = FindMaxSubvectorDAC(
        random_negative_vec, 0, (int)random_negative_vec.size());
    auto BF_results = FindMaxSubvectorBF(
        random_negative_vec, 0, (int)random_negative_vec.size());
    auto Kadane_results = FindMaxSubvector(
        random_negative_vec, 0, (int)random_negative_vec.size());

    auto max_iterator = std::max_element(
        random_negative_vec.begin(), random_negative_vec.end());
    int max_value = *max_iterator;
    int max_index = (int)std::distance(
        random_negative_vec.begin(), max_iterator);
    auto expected_results =
        std::make_tuple(max_index, max_index + 1, max_value);

    // TODO For now I'm only testing the max subvector sum, not the indices,
    // TODO because if there's multiple subvectors with the same max sum the
    // TODO algorithms sometimes return different subvectors.
    EXPECT_EQ(std::get<2>(DAC_results), std::get<2>(expected_results))
        << error_message;
    EXPECT_EQ(std::get<2>(BF_results), std::get<2>(expected_results))
        << error_message;
    EXPECT_EQ(std::get<2>(Kadane_results), std::get<2>(expected_results))
        << error_message;
}

/** Algorithms for max subvector of a random vector should have same result.
 */
TEST_F(RandomizedSearchingTest,
        MaxSubvectorAlgorithmsOnRandomVectorShouldAgree) {
    std::string error_message =
        "Algorithms for max subvector of a random vector should have same "
        "result.";

    auto DAC_results = FindMaxSubvectorDAC(
        random_vec, 0, (int)random_vec.size());
    auto BF_results = FindMaxSubvectorBF(
        random_vec, 0, (int)random_vec.size());
    auto Kadane_results = FindMaxSubvector(
        random_vec, 0, (int)random_vec.size());

    // TODO For now I'm only testing the max subvector sum, not the indices,
    // TODO because if there's multiple subvectors with the same max sum the
    // TODO algorithms sometimes return different subvectors.
    ASSERT_EQ(std::get<2>(DAC_results), std::get<2>(BF_results))
        << error_message;
    EXPECT_EQ(std::get<2>(Kadane_results), std::get<2>(BF_results))
        << error_message;
}
