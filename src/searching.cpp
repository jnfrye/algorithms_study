//
// Created by jfrye on 11/7/16.
//

#include <vector>
#include <iostream>
#include <assert.h>

#include "../include/searching.h"


long LinearSearch(const std::vector<int> &vec, const int value) {
    for(int i = 0; i < vec.size(); i++)
        if (vec[i] == value) return i;

    throw std::runtime_error("Value not found!");
}

long MinIndex(const std::vector<int> &vec, const long begin_index /*= 0*/) {
    assert(begin_index < vec.size() &&
        "Cannot begin search at index larger than size of vector!");

    long min_index = begin_index;

    long search_index = begin_index + 1;
    while (search_index < vec.size()) {
        if (vec[search_index] < vec[min_index])
            min_index = search_index;

        search_index++;
    }
    return min_index;
}