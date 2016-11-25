#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

#include "algorithm/vector/sort.hpp"
#include "algorithm/vector/search.hpp"


int main() {
    // ---- Testing the run time of my max subvector algorithms ----
    std::srand((unsigned int)std::time(nullptr)); // Seed the RNG

    // Fill a vector with random integers
    int max_exponent = 12;
    int vec_size = (int)pow(2, max_exponent);
    std::vector<int> vec(vec_size);
    for (int i = 0; i < vec.size(); i++)
        vec[i] = std::rand() % 41 - 20; // range -20 to 20

    for (int exponent = 1; exponent <= max_exponent; ++exponent) {
        int end_index = (int)pow(2, exponent);

        auto begin_time = clock();
        auto DAC_results = FindMaxSubvectorDAC(vec, 0, end_index);
        auto end_time = clock();
        double DAC_time = double(end_time - begin_time) / CLOCKS_PER_SEC;
        std::cout << "SIZE: " << end_index << "\tDAC: " << DAC_time;

        begin_time = clock();
        auto BF_results = FindMaxSubvectorBF(vec, 0, end_index);
        end_time = clock();
        double BF_time = double(end_time - begin_time) / CLOCKS_PER_SEC;
        std::cout << "\tBF: " << BF_time;

        if (DAC_time < BF_time)
            std::cout << "\tDAC";
        else
            std::cout << "\tBF";

        std::cout << std::endl;
    }

    return 0;
}
