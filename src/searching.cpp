//
// Created by jfrye on 11/7/16.
//

#include <vector>
#include <iostream>

#include "../include/searching.h"


long LinearSearch(const std::vector<int> &vec, const int value) {
    for(int i = 0; i < vec.size(); i++)
        if (vec[i] == value) return i;

    throw std::runtime_error("Value not found!");
}

long MinIndex(const std::vector<int> &vec) {
    long min_index = 0;
    int min_value = vec[min_index];

    long search_index = 1;
    while (search_index < vec.size()) {
        if (vec[search_index] < min_value) {
            min_value = vec[search_index];
            min_index = search_index;
        }
        search_index++;
    }
    return min_index;
}