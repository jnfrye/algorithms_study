//
// Created by jfrye on 11/7/16.
//

#include <vector>
#include <iostream>
#include <cmath>
#include <assert.h>

#include "searching.h"


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
