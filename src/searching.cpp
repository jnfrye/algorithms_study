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
