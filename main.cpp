#include <iostream>
#include <vector>

#include "include/sorting.h"

int main() {
    HelloWorld();

    std::vector<int> my_vec = {1, 2, 3};
    std::cout << LinearSearch(my_vec, 2) << std::endl;
    return 0;
}