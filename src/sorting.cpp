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
    for(int i = 0; i < vec.size(); i++)
        if (vec[i] == value) return i;

    throw std::runtime_error("Value not found!");
}

void InsertionSort(std::vector<int> &vec, const bool ascending /*= true*/) {
    for(int key_index = 1; key_index < vec.size(); key_index++) {
        // This item will be moved to a sorted position
        int key_value = vec[key_index];

        // We compare the key to each item before it in the vector
        int search_index = key_index - 1;
        while(search_index >= 0 &&
                (ascending == (key_value < vec[search_index]))) {
            vec[search_index + 1] = vec[search_index];
            search_index--;
        }
        vec[search_index + 1] = key_value;
    }
}
