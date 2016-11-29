/** Convenience functions for random numbers.
 *
 * All functions assume that the random seed (std::srand) has been set!
 */

#ifndef ALGORITHMS_STUDY_CPP_RANDOM_HPP
#define ALGORITHMS_STUDY_CPP_RANDOM_HPP

/** Generate a random integer in an inclusive interval.
 *
 * That is, returned integer could be `min`, `max`, or any integer between.
 *
 * @param min   (Inclusive) lower bound for random range.
 * @param max   (Inclusive) upper bound for random range.
 * @return      Random number in desired range.
 */
int random_interval(const int min, const int max);

#endif //ALGORITHMS_STUDY_CPP_RANDOM_HPP
