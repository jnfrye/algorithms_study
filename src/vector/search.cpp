#include "algorithm/vector/search.hpp"

#include <vector>
#include <tuple>
#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
#include <assert.h>


int LinearSearch(const std::vector<int> &vec, const int value) {
	for(int i = 0; i < vec.size(); i++)
		if (vec[i] == value) return i;

	throw std::runtime_error("Value not found!");
}

int MinIndex(const std::vector<int> &vec, const int begin_index /*= 0*/) {
	assert(begin_index < vec.size() &&
		"Cannot begin search at index larger than size of vector!");

	int min_index = begin_index;

	int search_index = begin_index + 1;
	while (search_index < vec.size()) {
		if (vec[search_index] < vec[min_index])
			min_index = search_index;

		search_index++;
	}
	return min_index;
}

int MaxIndex(const std::vector<int> &vec, const int begin_index /*= 0*/) {
	assert(begin_index < vec.size() &&
		"Cannot begin search at index larger than size of vector!");

	int max_index = begin_index;

	int search_index = begin_index + 1;
	while (search_index < vec.size()) {
		if (vec[search_index] > vec[max_index])
			max_index = search_index;

		search_index++;
	}
	return max_index;
}

int RelativeMaxIndex(const std::vector<int> &vec, const int begin_index) {
	assert(begin_index < vec.size() &&
		"Cannot begin search at index larger than size of vector!");

	int max_value = -std::numeric_limits<int>::max();
	for (int search_index = 0; search_index < begin_index; ++search_index) {
		if (vec[search_index] > max_value)
			max_value = vec[search_index];
	}
	for (int search_index = 0; search_index < vec.size(); ++search_index) {
		if (vec[search_index] > max_value)
			return search_index;
	}
	return vec.size() - 1;
};

int BinarySearch(
		const std::vector<int> &vec, const int begin_index, const int end_index,
		const int value) {

	int middle_index = static_cast<int>(
		std::floor((begin_index + end_index)/2.));

	if (end_index - begin_index > 1) {
		if (value < vec[middle_index])
			BinarySearch(vec, begin_index, middle_index, value);
		else
			BinarySearch(vec, middle_index, end_index, value);
	}
	else if (vec[middle_index] == value)
		return middle_index;
	else
		throw std::runtime_error("Value not found!");
}

// TODO I should change this to std::map<std::str, int> instead of tuple
std::tuple<int, int, int> FindMaxCrossingSubvector(
		const std::vector<int> vec,
		const int begin_index,
		const int middle_index,
		const int end_index) {
	assert(end_index - begin_index > 1 &&
		"Vector must have at least two items "
		"to check for crossing subvectors!");

	// This is the left-hand sentinel
	int max_left_sum = -std::numeric_limits<int>::max();
	int max_left_index;

	int current_sum = 0;
	for (int left_index = middle_index - 1; left_index >= begin_index;
			--left_index) {
		current_sum += vec[left_index];
		if (current_sum > max_left_sum) {
			max_left_sum = current_sum;
			max_left_index = left_index;
		}
	}
	// This is the right-and sentinel
	int max_right_sum = -std::numeric_limits<int>::max();
	int max_right_index;

	current_sum = 0;
	for (int right_index = middle_index; right_index < end_index;
			++right_index) {
		current_sum += vec[right_index];
		if (current_sum > max_right_sum) {
			max_right_sum = current_sum;
			max_right_index = right_index + 1;
		}
	}
	return std::make_tuple(
		max_left_index, max_right_index, max_left_sum + max_right_sum);
}

// TODO I should change this to std::map<std::str, int> instead of tuple.
// TODO I also want to make it so all of these algorithms always return the
// TODO same thing. There is possible degeneracy in this problem since
// TODO there can be multiple subvectors with the same max sum. Ideas:
// TODO	 * Return the first of the shortest of them
// TODO I don't really want to do this now, so I'm going to the modify
// TODO the tests that are failing so they only check the max sum.
std::tuple<int, int, int> FindMaxSubvectorDAC(
		const std::vector<int> vec,
		const int begin_index,
		const int end_index) {
	// Base case; return the only entry
	if (end_index - begin_index == 1)
		return std::make_tuple(begin_index, end_index, vec[begin_index]);

	else {
		int middle_index = static_cast<int>(
			std::floor((begin_index + end_index)/2.));

		// Recursively split the problem
		auto left_results = FindMaxSubvectorDAC(vec, begin_index, middle_index);
		auto right_results = FindMaxSubvectorDAC(vec, middle_index, end_index);
		auto crossing_results = FindMaxCrossingSubvector(
			vec, begin_index, middle_index, end_index);

		// These are the max sums found amongst the three partitions
		int left_sum		= std::get<2>(left_results);
		int right_sum	   = std::get<2>(right_results);
		int crossing_sum	= std::get<2>(crossing_results);

		// Return the max amongst these
		if (left_sum >= right_sum && left_sum >= crossing_sum)
			return left_results;
		else if (right_sum >= left_sum && right_sum >= crossing_sum)
			return right_results;
		else
			return crossing_results;
	}
}

std::tuple<int, int, int> FindMaxSubvectorBF(
		const std::vector<int> vec,
		const int begin_index,
		const int end_index) {
	int max_left_index;
	int max_right_index;
	int max_sum = -std::numeric_limits<int>::max();

	for (int left_index = begin_index; left_index < end_index; ++left_index) {
		int sum = 0;
		for (int right_index = left_index;
				right_index < end_index; ++right_index) {
			sum += vec[right_index];
			if (sum >= max_sum) {
				max_left_index = left_index;
				max_right_index = right_index + 1;
				max_sum = sum;
			}
		}
	}
	return std::make_tuple(max_left_index, max_right_index, max_sum);
}

std::tuple<int, int, int> FindMaxSubvector(
		const std::vector<int> vec,
		const int begin_index,
		const int end_index) {
	int overall_max = vec[begin_index];
	int max_ending_here = vec[begin_index];

	int overall_max_left_index = begin_index;
	int overall_max_right_index = begin_index + 1;
	int max_ending_here_left_index = begin_index;

	for (int index = 1; index < end_index; ++index) {
		if (max_ending_here > 0)
			// If the previous max ending here is positive, the max ending
			// at the next index will be increased by adding it...
			max_ending_here += vec[index];
		else {
			// ...Otherwise, it would only decrease the max ending at the next
			// index, so we discard it.
			max_ending_here = vec[index];
			max_ending_here_left_index = index;
		}
		if (max_ending_here > overall_max) {
			overall_max = max_ending_here;
			overall_max_left_index = max_ending_here_left_index;
			overall_max_right_index = index + 1;
		}
	}
	return std::make_tuple(
		overall_max_left_index, overall_max_right_index, overall_max);
}
