#include "algorithm/random.hpp"
#include "algorithm/matrix/matrix.hpp"

#include <random>
#include <cmath>
#include <vector>
#include <algorithm>


std::random_device rng_seed;	 // only used once to initialise (seed) engine
std::mt19937 rng(rng_seed());	// random-number engine used (Mersenne-Twister in this case)


int RandomInteger(const int min, const int max) {
	std::uniform_int_distribution<int> random_distribution(min, max);
	return random_distribution(rng);
}

double RandomReal(const double min, const double max, const int iterations) {
	// Create coin flip RNG
	std::uniform_int_distribution<int> coin_flip(0, 1);

	// First we get a random integer in [0, 2^iterations)
	int random_integer = 0;
	for (int exponent = 0; exponent < iterations; ++exponent)
		// The expression (1 << exponent) is equivalent to
		// ((int)pow(2, exponent))
		random_integer += coin_flip(rng) * (1 << exponent);

	double zero_to_one = random_integer / (double)(1 << iterations);
	return min + zero_to_one * (max - min);
}

int RandomIntegerBinaryMethod(
		const int min, const int max, const int iterations /*= 0*/) {
	int minimum_iterations = (int)std::ceil(std::log2(max - min + 1));

	int max_exponent;
	if (iterations == 0)
		max_exponent = 2 * minimum_iterations;
	else if (iterations < minimum_iterations)
		max_exponent = minimum_iterations;
	else
		max_exponent = iterations;

	return (int)std::floor(RandomReal(min, max + 1, max_exponent));
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

void RandomlyPermute(std::vector<int> &vec) {
	for (int i = 0; i < vec.size(); ++i) {
		int swap = vec[i];
		int random_index = RandomInteger(i, vec.size() - 1);
		vec[i] = vec[random_index];
		vec[random_index] = swap;
	}
};

std::vector<int> RandomlySample(std::vector<int> &vec, int num_samples) {
	std::vector<int> sample_vec;
	for (int i = 0; i < num_samples; ++i) {
		int sample_range = vec.size() - num_samples + i;
		auto random_int = RandomInteger(0, sample_range);
		if ( // This just checks if the item is already in the sample
				std::find(
					sample_vec.begin(), sample_vec.end(), vec[random_int]
				) != sample_vec.end())
			sample_vec.push_back(vec[sample_range]);
		else
			sample_vec.push_back(vec[random_int]);
	}
	return sample_vec;
};
