//
// Created by jfrye on 11/7/16.
//

#include <vector>
#include <tuple>
#include <iostream>
#include <cmath>
#include <limits>
#include <assert.h>

#include "algorithm/vector/search.h"


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
            max_right_index = right_index;
        }
    }
    return std::make_tuple(
        max_left_index, max_right_index, max_left_sum + max_right_sum);
}
