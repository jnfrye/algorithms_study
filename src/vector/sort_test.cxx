/** Unit tests for `sorting.cpp`
 */

#include "algorithm/vector/sort.hpp"

#include "algorithm/random.hpp"

#include "gtest/gtest.h"

#include <vector>
#include <string>
#include <algorithm>


/** General test fixture for vector sort algorithms.
 */
class GeneralSortingTest: public ::testing::Test
{
public:
	std::vector<int> singleton;
	std::vector<int> vec;
	std::vector<int> vec_sorted;
	std::vector<int> vec2;
	std::vector<int> vec3;
	std::vector<int> vec4;

protected:
	virtual void SetUp()
	{
		singleton = {5};
		vec = {5, 3, 6, 2, 8, 3, 1};
		vec_sorted = {1, 2, 3, 3, 5, 6, 8};
		vec2 = {2, 8, 7, 1, 3, 5, 6, 4};
		vec3 = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
		vec4 = {2, 8, 7, 4, 3, 4, 6, 4};
	}
};

/** Randomized test fixture for vector sort algorithms.
 */
class RandomizedSortingTest: public ::testing::Test
{
public:
	std::vector<int> random_vec;

protected:
	virtual void SetUp()
	{
		std::srand((unsigned int)std::time(nullptr)); // Seed the RNG

		int random_size = RandomInteger(2, 500);
		random_vec = std::vector<int>((unsigned int)random_size);
		RandomlyFillVector(random_vec, -20, 20);
	}
};

TEST_F(GeneralSortingTest, PreservesSize1Vector)
{
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
	HeapSort(singleton);
	ASSERT_EQ(singleton, original_singleton) << error_msg;
	Quicksort(singleton, 0, (int)singleton.size());
	ASSERT_EQ(singleton, original_singleton) << error_msg;
	RandomizedQuicksort(singleton, 0, (int)singleton.size());
	ASSERT_EQ(singleton, original_singleton) << error_msg;
	RandomizedEqCheckQuicksort(singleton, 0, (int)singleton.size());
	ASSERT_EQ(singleton, original_singleton) << error_msg;
	HoareQuicksort(singleton, 0, (int)singleton.size());
	ASSERT_EQ(singleton, original_singleton) << error_msg;
	auto out = CountingSort(
		singleton,
		*std::min_element(singleton.begin(), singleton.end()),
		*std::max_element(singleton.begin(), singleton.end())
	);
	ASSERT_EQ(out, original_singleton) << error_msg;
}

TEST_F(GeneralSortingTest, CorrectlySortsKnownVector)
{
	std::string error_msg = "Sorted vector did not match with vector sorted by hand!";

	auto test_vec(vec); // copy the vector so we don't alter it

	InsertionSort(test_vec);
	EXPECT_EQ(test_vec, vec_sorted) << error_msg;

	test_vec = vec; // reset vector
	SelectionSort(test_vec);
	EXPECT_EQ(test_vec, vec_sorted) << error_msg;

	test_vec = vec; // reset vector
	MergeSort(test_vec, 0, (int)test_vec.size());
	EXPECT_EQ(test_vec, vec_sorted) << error_msg;

	test_vec = vec; // reset vector
	HeapSort(test_vec);
	EXPECT_EQ(test_vec, vec_sorted) << error_msg;

	test_vec = vec; // reset vector
	Quicksort(test_vec, 0, (int)test_vec.size());
	EXPECT_EQ(test_vec, vec_sorted) << error_msg;

	test_vec = vec; // reset vector
	RandomizedQuicksort(test_vec, 0, (int)test_vec.size());
	EXPECT_EQ(test_vec, vec_sorted) << error_msg;

	test_vec = vec; // reset vector
	RandomizedEqCheckQuicksort(test_vec, 0, (int)test_vec.size());
	EXPECT_EQ(test_vec, vec_sorted) << error_msg;

	test_vec = vec; // reset vector
	HoareQuicksort(test_vec, 0, (int)test_vec.size());
	EXPECT_EQ(test_vec, vec_sorted) << error_msg;

	test_vec = vec; // reset vector
	auto out_vec = CountingSort(
		test_vec,
		*std::min_element(test_vec.begin(), test_vec.end()),
		*std::max_element(test_vec.begin(), test_vec.end())
	);
	EXPECT_EQ(out_vec, vec_sorted) << error_msg;
}

TEST(MergeSortedSubvectorsTest, CorrectlyMergesKnownVectors)
{
	std::vector<int> test_vec =	 {2, 5, 6, 3, 5, 5, 8};
	std::vector<int> expected_vec = {2, 3, 5, 5, 5, 6, 8};

	MergeSortedSubvectors(test_vec, 0, 3, test_vec.size());
	EXPECT_EQ(test_vec, expected_vec) << "Merged vector does not match expected vector.";
}

TEST_F(GeneralSortingTest, CorrectlyPartitionsKnownVector)
{
	std::string error_msg =
		"Partitioned vector did not match with vector partitioned by hand!";

	auto test_vec = vec2;
	std::vector<int> expected_vec = {2, 1, 3, 4, 7, 5, 6, 8};

	int p = QuicksortPartition(test_vec, 0, test_vec.size());
	EXPECT_EQ(test_vec, expected_vec) << error_msg;
	EXPECT_EQ(p, 3) << "Unexpected value for partition index";
}

TEST_F(GeneralSortingTest, HoareCorrectlyPartitionsKnownVector)
{
	std::string error_msg = "Hoare-partitioned vector did not match with expected partition!";

	auto test_vec = vec3;
	std::vector<int> expected_vec = {6, 2, 9, 5, 12, 8, 7, 4, 11, 19, 13, 21};

	int p = HoareQuicksortPartition(test_vec, 0, test_vec.size());
	EXPECT_EQ(test_vec, expected_vec) << error_msg;
	EXPECT_EQ(p, 8) << "Unexpected value for partition index";
}

TEST_F(GeneralSortingTest, EqCheckCorrectlyPartitionsKnownVector)
{
	std::string error_msg =
		"Partitioned vector did not match with vector partitioned by hand!";

	auto test_vec = vec4;
	std::vector<int> expected_vec = {2, 3, 4, 4, 4, 8, 6, 7};

	std::tuple<int, int> p = EqCheckQuicksortPartition(test_vec, 0, test_vec.size());
	EXPECT_EQ(test_vec, expected_vec) << error_msg;
	EXPECT_EQ(p, std::make_tuple(2, 5)) << "Unexpected values for partition indices";
}

/** Checks that all sorting algorithms produce the same sort of a random vector.
 *
 * NOTE: If this passes, either all are correct or all are incorrect in the
 * same way. If not all pass, then some are guaranteed to be incorrect.
 */
TEST_F(RandomizedSortingTest, CorrectlySortsRandomVector)
{
	std::string error_msg = "Sorting algorithms disagree when sorting random vector!";

	auto insertion_sort_vec(random_vec);
	InsertionSort(insertion_sort_vec);

	auto selection_sort_vec(random_vec);
	SelectionSort(selection_sort_vec);
	ASSERT_EQ(insertion_sort_vec, selection_sort_vec) << error_msg;

	auto merge_sort_vec(random_vec);
	MergeSort(merge_sort_vec, 0, (int)merge_sort_vec.size());
	ASSERT_EQ(merge_sort_vec, insertion_sort_vec) << error_msg;

	auto heap_sort_vec(random_vec);
	HeapSort(heap_sort_vec);
	ASSERT_EQ(heap_sort_vec, merge_sort_vec) << error_msg;

	auto quick_sort_vec(random_vec);
	Quicksort(quick_sort_vec, 0, (int)quick_sort_vec.size());
	EXPECT_EQ(quick_sort_vec, heap_sort_vec) << error_msg;

	auto randomized_quick_sort_vec(random_vec);
	RandomizedQuicksort(randomized_quick_sort_vec, 0, (int)randomized_quick_sort_vec.size());
	EXPECT_EQ(randomized_quick_sort_vec, quick_sort_vec) << error_msg;

	auto randomized_eqcheck_quick_sort_vec(random_vec);
	RandomizedEqCheckQuicksort(
		randomized_eqcheck_quick_sort_vec, 0,
		(int)randomized_eqcheck_quick_sort_vec.size());
	EXPECT_EQ(randomized_eqcheck_quick_sort_vec, randomized_quick_sort_vec) << error_msg;

	auto hoare_quick_sort_vec(random_vec);
	HoareQuicksort(hoare_quick_sort_vec, 0, (int)hoare_quick_sort_vec.size());
	EXPECT_EQ(randomized_eqcheck_quick_sort_vec, hoare_quick_sort_vec) << error_msg;

	auto count_sort_vec(random_vec);
	auto out_vec = CountingSort(
		count_sort_vec,
		*std::min_element(count_sort_vec.begin(), count_sort_vec.end()),
		*std::max_element(count_sort_vec.begin(), count_sort_vec.end())
	);
	EXPECT_EQ(hoare_quick_sort_vec, out_vec) << error_msg;
}

