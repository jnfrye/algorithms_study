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

/** Return a random real number in the desired range.
 *
 * The possible returned values includes the minimum and excludes the maximum.
 *
 * @param min           (Inclusive) lower bound for random range.
 * @param max           (Exclusive) upper bound for random range.
 * @param power_of_two  Controls how 'fine grained' the randomness is. The
 *        interval is divided evenly into two to this power. For example, if
 *        this value is 3, there will be 8 possible returned values with equal
 *        probability.
 * @return              Random real number in the desired range.
 */
double RandomReal(const double min, const double max, const int power_of_two);

/** Generate a random integer in the (inclusive) interval.
 *
 * This procedure allows you to control how uniformly random the results are.
 *
 * @param min           (Inclusive) lower bound for random range.
 * @param max           (Inclusive) upper bound for random range.
 * @param iterations    Number of iterations of the binary RNG procedure to run.
 *        The more iterations, the more uniformly random the results are. There
 *        must be at least `ceiling(log_2(max - min))` iterations to ensure all
 *        numbers in the range can actually be returned.
 *
 *        The default is 0, which lets the code decide how many iterations
 *        (for now it chooses twice the minimum number of iterations).
 * @return              Random number in desired range.
 */
int RandomIntervalBinary(
        const int min, const int max, const int iterations = 0);

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
