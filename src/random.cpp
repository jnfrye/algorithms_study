#include "algorithm/random.hpp"

#include <random>
#include <vector>


std::random_device rng_seed;     // only used once to initialise (seed) engine
std::mt19937 rng(rng_seed());    // random-number engine used (Mersenne-Twister in this case)


int RandomInteger(const int min, const int max) {
    std::uniform_int_distribution<int> random_distribution(min, max);
    return random_distribution(rng);
}

double RandomReal(const double min, const double max, const int power_of_two) {
    // Create coin flip RNG
    std::uniform_int_distribution<int> coin_flip(0, 1);

    // First we get a random integer in [0, 2^power_of_two)
    int random_integer = 0;
    for (int exponent = 0; exponent < power_of_two; ++exponent)
        // The expression (1 << exponent) is equivalent to
        // ((int)pow(2, exponent))
        random_integer += coin_flip(rng) * (1 << exponent);

    double zero_to_one = random_integer / (double)(1 << power_of_two);
    return min + zero_to_one * (max - min);
}

int RandomIntegerBinaryMethod(
        const int min, const int max, const int iterations /*= 0*/) {

}

void RandomlyFillVector(
        std::vector<int> &vec, const int lower_bound, const int upper_bound) {
    for (int i = 0; i < vec.size(); ++i)
        vec[i] = RandomInteger(lower_bound, upper_bound);
}

void RandomlyFillMatrix(
        Matrix &A, const int lower_bound, const int upper_bound) {
    for (int row = 0; row < A.size(); ++row)
        for (int col = 0; col < A[0].size(); ++col)
            A[row][col] = RandomInteger(lower_bound, upper_bound);
}
