#include <iostream>
#include <vector>

#include "include/sorting.h"
#include "include/searching.h"


int main() {
    std::vector<int> my_vec = {4, 2, 1, 3, 2, 6, 3};
    std::vector<int> my_vec2(my_vec);
    std::vector<int> my_vec3(my_vec);

    std::cout << "Original vector:" << std::endl;
    for(const auto &item: my_vec)
        std::cout << item << ' ';
    std::cout << std::endl;

    int search_value = 2;
    std::cout << "Index of " << search_value << ": "
              << LinearSearch(my_vec, search_value) << std::endl;
    std::cout << "Index of minimum: " << MinIndex(my_vec) << std::endl;
    int begin_index = 4;
    std::cout << "Index of minimum (starting at index " << begin_index << "): "
              << MinIndex(my_vec, begin_index) << std::endl;

    // XXX Testing InsertionSort
    InsertionSort(my_vec, true);

    std::cout << "Insertion sort of vector:" << std::endl;
    for(const auto &item: my_vec)
        std::cout << item << ' ';
    std::cout << std::endl;

    // XXX Testing SelectionSort
    SelectionSort(my_vec2);

    std::cout << "Selection sort of vector:" << std::endl;
    for(const auto &item: my_vec2)
        std::cout << item << ' ';
    std::cout << std::endl;

    // XXX Testing MergeSortedSubvectors
    MergeSortedSubvectors(my_vec3, 2, 4, 6);

    std::cout << "Merged sorted subvectors [2..4..6] " << std::endl;
    for(const auto &item: my_vec3)
        std::cout << item << ' ';
    std::cout << std::endl;

    return 0;
}
