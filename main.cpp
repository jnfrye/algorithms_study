#include <iostream>
#include <vector>

#include "include/sorting.h"

int main() {
    HelloWorld();

    std::vector<int> my_vec = {4, 2, 3};
    std::cout << LinearSearch(my_vec, 2) << std::endl;

    InsertionSort(my_vec, true);

    for(auto i = my_vec.begin(); i != my_vec.end(); ++i)
        std::cout << *i << ' ';

    return 0;
}