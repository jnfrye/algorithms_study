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
	std::vector<int> bad_min_heap;
	std::vector<int> corrected_bad_min_heap;
	std::vector<int> bad_max_heap2;
	std::vector<int> corrected_bad_max_heap2;
	std::vector<int> bad_min_heap2;
	std::vector<int> corrected_bad_min_heap2;

protected:
	virtual void SetUp() {
		singleton = {5};
		bad_max_heap = {9, 3, 7, 8, 4, 6, 2, 1, 5, 0};
		corrected_bad_max_heap = {9, 8, 7, 5, 4, 6, 2, 1, 3, 0};
		bad_min_heap = {0, 9, 2, 3, 1, 5, 6, 7, 8, 4};
		corrected_bad_min_heap = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		bad_max_heap2 = {5, 3, 17, 10, 84, 19, 6, 22, 9};
		corrected_bad_max_heap2 = {84, 22, 19, 10, 3, 17, 6, 5, 9};
		bad_min_heap2 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
		corrected_bad_min_heap2 = {0, 1, 3, 2, 5, 4, 7, 9, 6, 8};
	}
};

/** Tests the max-heapify function on a simple known result.
 */
TEST_F(GeneralHeapTest, MaxHeapifyCorrectsHeap) {
	std::string error_msg = "Heap was incorrectly adjusted by max-heapify";

	MaxHeapify(bad_max_heap, 1, bad_max_heap.size());

	EXPECT_EQ(bad_max_heap, corrected_bad_max_heap) << error_msg;
}

/** Tests the min-heapify function on a simple known result.
 */
TEST_F(GeneralHeapTest, MinHeapifyCorrectsHeap) {
	std::string error_msg = "Heap was incorrectly adjusted by min-heapify";

	MinHeapify(bad_min_heap, 1, bad_min_heap.size());

	EXPECT_EQ(bad_min_heap, corrected_bad_min_heap) << error_msg;
}

/** Tests the max-heap builder on a simple known result.
 */
TEST_F(GeneralHeapTest, BuildMaxHeapProducesExpectedHeap) {
	std::string error_msg = "Built heap does not match expected heap.";

	MaxHeapBuilder(bad_max_heap2);

	EXPECT_EQ(bad_max_heap2, corrected_bad_max_heap2) << error_msg;
}

/** Tests the min-heap builder on a simple known result.
 */
TEST_F(GeneralHeapTest, BuildMinHeapProducesExpectedHeap) {
	std::string error_msg = "Built heap does not match expected heap.";

	MinHeapBuilder(bad_min_heap2);

	EXPECT_EQ(bad_min_heap2, corrected_bad_min_heap2) << error_msg;
}

/** Tests that the max-heap largest node extractor gets the value right.
 */
TEST_F(GeneralHeapTest, ExtractMaxFromHeapProducesExpectedValue) {
	std::string error_msg = "Returned incorrect max value from max heap.";

	auto max_value = MaxHeapExtractMax(corrected_bad_max_heap2);

	EXPECT_EQ(max_value, 84) << error_msg;
}

/** Tests that the min-heap smallest node extractor gets the value right.
 */
TEST_F(GeneralHeapTest, ExtractMinFromHeapProducesExpectedValue) {
	std::string error_msg = "Returned incorrect min value from min-heap.";

	auto min_value = MinHeapExtractMin(corrected_bad_min_heap2);

	EXPECT_EQ(min_value, 0) << error_msg;
}

/** Tests that max-heap largest node extractor has correct max-heap after.
 */
TEST_F(GeneralHeapTest, ExtractMaxFromHeapProducesExpectedMaxHeap) {
	std::string error_msg = "Returned incorrect max-heap after node extraction";

	MaxHeapExtractMax(corrected_bad_max_heap);
	std::vector<int> expected_heap = {8, 5, 7, 3, 4, 6, 2, 1, 0};

	EXPECT_EQ(corrected_bad_max_heap, expected_heap) << error_msg;
}

/** Tests that min-heap smallest node extractor has correct min-heap after.
 */
TEST_F(GeneralHeapTest, ExtractMinFromHeapProducesExpectedMinHeap) {
	std::string error_msg = "Returned incorrect min-heap after node extraction";

	MinHeapExtractMin(corrected_bad_min_heap);
	std::vector<int> expected_heap = {1, 3, 2, 7, 4, 5, 6, 9, 8};

	EXPECT_EQ(corrected_bad_min_heap, expected_heap) << error_msg;
}

/** Tests that max-heap node value increaser produces correct max-heap.
 *
 * In this case, the new node value is a new maximum for the heap.
 */
TEST_F(GeneralHeapTest, IncreaseMaxHeapKeyWithNewMaxProducesCorrectHeap) {
	std::string error_msg = "Got unexpected max-heap from key increase";

	MaxHeapIncreaseKey(corrected_bad_max_heap, 7, 10);
	std::vector<int> expected_heap = {10, 9, 7, 8, 4, 6, 2, 5, 3, 0};

	EXPECT_EQ(corrected_bad_max_heap, expected_heap) << error_msg;
}

/** Tests that min-heap node value increaser produces correct min-heap.
 *
 * In this case, the new node value is a new minimum for the heap.
 */
TEST_F(GeneralHeapTest, DecreaseMinHeapKeyWithNewMinProducesCorrectHeap) {
	std::string error_msg = "Got unexpected min-heap from key decrease";

	MinHeapDecreaseKey(corrected_bad_min_heap, 7, -1);
	std::vector<int> expected_heap = {-1, 0, 2, 1, 4, 5, 6, 3, 8, 9};

	EXPECT_EQ(corrected_bad_min_heap, expected_heap) << error_msg;
}

/** Tests that max-heap node value increaser produces correct max-heap.
 *
 * In this case, the new node value is not a new maximum for the heap.
 */
TEST_F(GeneralHeapTest, IncreaseMaxHeapKeyProducesCorrectHeap) {
	std::string error_msg = "Got unexpected max-heap from key increase";

	MaxHeapIncreaseKey(corrected_bad_max_heap, 7, 8);
	std::vector<int> expected_heap = {9, 8, 7, 8, 4, 6, 2, 5, 3, 0};

	EXPECT_EQ(corrected_bad_max_heap, expected_heap) << error_msg;
}

/** Tests that min-heap node value increaser produces correct min-heap.
 *
 * In this case, the new node value is not a new minimum for the heap.
 */
TEST_F(GeneralHeapTest, DecreaseMinHeapKeyProducesCorrectHeap) {
	std::string error_msg = "Got unexpected min-heap from key decrease";

	MinHeapDecreaseKey(corrected_bad_min_heap, 7, 0);
	std::vector<int> expected_heap = {0, 0, 2, 1, 4, 5, 6, 3, 8, 9};

	EXPECT_EQ(corrected_bad_min_heap, expected_heap) << error_msg;
}

/** Tests max-heap inserter with known result.
 */
TEST_F(GeneralHeapTest, InsertIntoMaxHeapProducesCorrectHeap) {
	std::string error_msg = "Got unexpected max-heap from key insertion";

	MaxHeapInsert(corrected_bad_max_heap2, 25);
	std::vector<int> expected_heap = {84, 25, 19, 10, 22, 17, 6, 5, 9, 3};

	EXPECT_EQ(corrected_bad_max_heap2, expected_heap) << error_msg;
}

/** Tests min-heap inserter with known result.
 */
TEST_F(GeneralHeapTest, InsertIntoMinHeapProducesCorrectHeap) {
	std::string error_msg = "Got unexpected min-heap from key insertion";

	MinHeapInsert(corrected_bad_min_heap2, 0);
	std::vector<int> expected_heap = {0, 0, 3, 2, 1, 4, 7, 9, 6, 8, 5};

	EXPECT_EQ(corrected_bad_min_heap2, expected_heap) << error_msg;
}

/** Tests max-heap node deletion with known result.
 */
TEST_F(GeneralHeapTest, MaxHeapDeleteProducesCorrectHeap) {
	std::string error_msg = "Got unexpected max-heap from node deletion";

	MaxHeapDelete(corrected_bad_max_heap2, 1);
	std::vector<int> expected_heap = {84, 10, 19, 9, 3, 17, 6, 5};

	EXPECT_EQ(corrected_bad_max_heap2, expected_heap) << error_msg;
}

/** Tests min-heap node deletion with known result.
 */
TEST_F(GeneralHeapTest, MinHeapDeleteProducesCorrectHeap) {
	std::string error_msg = "Got unexpected min-heap from node deletion";

	MinHeapDelete(corrected_bad_min_heap2, 1);
	std::vector<int> expected_heap = {0, 2, 3, 6, 5, 4, 7, 9, 8};

	EXPECT_EQ(corrected_bad_min_heap2, expected_heap) << error_msg;
}
