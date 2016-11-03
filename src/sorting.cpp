//
// Created by jfrye on 11/2/16.
//

#include <iostream>
#include <vector>

#include "../include/sorting.h"

void HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}

long LinearSearch(const std::vector<int> &vec, const int value) {
    for(int i=0; i < vec.size(); i++)
        if (vec[i] == value) return i;

    throw std::runtime_error("Value not found!");
}
