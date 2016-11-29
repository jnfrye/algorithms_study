#include "algorithm/random.hpp"

#include <random>


std::random_device rng_seed;     // only used once to initialise (seed) engine
std::mt19937 rng(rng_seed());    // random-number engine used (Mersenne-Twister in this case)


int random_interval(const int min, const int max) {
    std::uniform_int_distribution<int> random_distribution(min, max);
    return random_distribution(rng);
}