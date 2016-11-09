//
// Created by jfrye on 11/2/16.
//

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

#include "searching.h"
#include "sorting.h"


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

void SelectionSort(std::vector<int> &vec) {
    for (int index = 0; index < vec.size() - 1; index++) {
        int min_index = MinIndex(vec, index);
        if (min_index != index) {
            // Swap the two values
            int temp = vec[min_index];
            vec[min_index] = vec[index];
            vec[index] = temp;
        }
    }
}

void MergeSortedSubvectors(
        std::vector<int> &vec, const int begin_index, const int middle_index,
        const int end_index) {
    // Extract the subvectors
    std::vector<int> subvec1(
        vec.begin() + begin_index, vec.begin() + middle_index);
    std::vector<int> subvec2(
        vec.begin() + middle_index, vec.begin() + end_index);

    // Add the sentinels (largest possible integer is used)
    subvec1.push_back(std::numeric_limits<int>::max());
    subvec2.push_back(std::numeric_limits<int>::max());

    int subvec1_index = 0;
    int subvec2_index = 0;

    for (int main_index = begin_index; main_index < end_index; main_index++) {
        if (subvec1[subvec1_index] <= subvec2[subvec2_index]) {
            vec[main_index] = subvec1[subvec1_index];
            subvec1_index++;
        }
        else {
            vec[main_index] = subvec2[subvec2_index];
            subvec2_index++;
        }
    }
}

void MergeSort(
        std::vector<int> &vec, const int begin_index, const int end_index) {
    if (begin_index < end_index - 1) {
        int middle_index = static_cast<int>(
            std::floor((begin_index + end_index)/2.));

        MergeSort(vec, begin_index, middle_index);
        MergeSort(vec, middle_index, end_index);
        MergeSortedSubvectors(vec, begin_index, middle_index, end_index);
    }
}
