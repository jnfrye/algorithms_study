#include "algorithm/random.hpp"

#include <random>
#include <vector>


std::random_device rng_seed;     // only used once to initialise (seed) engine
std::mt19937 rng(rng_seed());    // random-number engine used (Mersenne-Twister in this case)


int RandomInterval(const int min, const int max) {
    std::uniform_int_distribution<int> random_distribution(min, max);
    return random_distribution(rng);
}

double RandomReal(const double min, const double max, const int power_of_two) {
    std::uniform_int_distribution<int> coin_flip(0, 1);


}

int RandomIntervalBinary(
        const int min, const int max, const int iterations /*= 0*/) {

}

void RandomlyFillVector(
        std::vector<int> &vec, const int lower_bound, const int upper_bound) {
    for (int i = 0; i < vec.size(); ++i)
        vec[i] = RandomInterval(lower_bound, upper_bound);
}

void RandomlyFillMatrix(
        Matrix &A, const int lower_bound, const int upper_bound) {
    for (int row = 0; row < A.size(); ++row)
        for (int col = 0; col < A[0].size(); ++col)
            A[row][col] = RandomInterval(lower_bound, upper_bound);
}
