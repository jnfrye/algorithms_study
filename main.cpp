#include <iostream>
#include <vector>

#include "include/sorting.h"
#include "include/searching.h"


int main() {
    std::vector<int> my_vec = {4, 2, 3};
    std::cout << LinearSearch(my_vec, 2) << std::endl;

    InsertionSort(my_vec, true);

    for(const auto &item: my_vec)
        std::cout << item << ' ';

    return 0;
}
