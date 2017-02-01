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
    std::vector<int> corrected_bad_max_heap;

    std::vector<int> bad_max_heap2;
    std::vector<int> corrected_bad_max_heap2;

protected:
    virtual void SetUp() {
        singleton = {5};
        bad_max_heap = {9, 3, 7, 8, 4, 6, 2, 1, 5, 0};
        corrected_bad_max_heap = {9, 8, 7, 5, 4, 6, 2, 1, 3, 0};
        bad_max_heap2 = {5, 3, 17, 10, 84, 19, 6, 22, 9};
        corrected_bad_max_heap2 = {84, 22, 19, 10, 3, 17, 6, 5, 9};
    }
};

/** Tests the max heapify function on a simple known result.
 */
TEST_F(GeneralHeapTest, MaxHeapifyCorrectsHeap) {
    std::string error_msg = "Heap was incorrectly adjusted by max-heapify";

    MaxHeapify(bad_max_heap, 1);

    EXPECT_EQ(bad_max_heap, corrected_bad_max_heap) << error_msg;
}

/** Tests the max heap builder on a simple known result.
 */
TEST_F(GeneralHeapTest, BuildMaxHeapProducesExpectedHeap) {
    std::string error_msg = "Built heap does not match expected heap.";

    BuildMaxHeap(bad_max_heap2);

    EXPECT_EQ(bad_max_heap2, corrected_bad_max_heap2) << error_msg;
}
