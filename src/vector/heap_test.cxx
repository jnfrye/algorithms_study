/** Unit tests for `sorting.cpp`
 */

#include <vector>
#include <string>

#include "gtest/gtest.h"

#include "algorithm/vector/heap.hpp"


class GeneralHeapTest: public ::testing::Test {
public:
    std::vector<int> singleton;
    std::vector<int> bad_max_heap;
    std::vector<int> good_max_heap;

protected:
    virtual void SetUp() {
        singleton = {5};
        bad_max_heap = {9, 3, 7, 8, 4, 6, 2, 1, 5, 0};
        good_max_heap = {9, 8, 7, 5, 4, 6, 2, 1, 3, 0};
    }
};

TEST_F(GeneralHeapTest, MaxHeapifyCorrectsHeap) {
    std::string error_msg = "Heap was incorrectly adjusted by max-heapify";

    std::vector<int> test_heap = {9, 3, 7, 8, 4, 6, 2, 1, 5, 0};
    MaxHeapify(test_heap, 1);

    EXPECT_EQ(test_heap, good_max_heap) << error_msg;
}
