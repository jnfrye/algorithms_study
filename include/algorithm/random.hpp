/** Convenience functions for random numbers.
 *
 * All functions assume that the random seed (std::srand) has been set!
 */

#ifndef ALGORITHMS_STUDY_CPP_RANDOM_HPP
#define ALGORITHMS_STUDY_CPP_RANDOM_HPP

#include "algorithm/matrix/matrix.hpp"


/** Generate a random integer in an inclusive interval.
 *
 * That is, returned integer could be `min`, `max`, or any integer between.
 *
 * @param min   (Inclusive) lower bound for random range.
 * @param max   (Inclusive) upper bound for random range.
 * @return      Random number in desired range.
 */
int RandomInterval(const int min, const int max);

/** Fill a vector with random values in the specified range.
 *
 * @param vec           Vector to be filled.
 * @param lower_bound   Lowest possible random value.
 * @param upper_bound   Highest possible random value.
 */
void RandomlyFillVector(
        std::vector<int> &vec, const int lower_bound, const int upper_bound);

/** Fill a matrix with random values in the specified range.
 *
 * @param A             Matrix to be filled.
 * @param lower_bound   Lowest possible random value.
 * @param upper_bound   Highest possible random value.
 */
void RandomlyFillMatrix(
        Matrix &A, const int lower_bound, const int upper_bound);

#endif //ALGORITHMS_STUDY_CPP_RANDOM_HPP
