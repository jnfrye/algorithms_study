#include <iostream>
#include <vector>

#include "include/sorting.h"
#include "include/searching.h"


int main() {
    std::vector<int> my_vec = {4, 2, 1, 3, 1, 6, 3};

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

    InsertionSort(my_vec, true);

    std::cout << "Sorted vector:" << std::endl;
    for(const auto &item: my_vec)
        std::cout << item << ' ';
    std::cout << std::endl;

    return 0;
}
