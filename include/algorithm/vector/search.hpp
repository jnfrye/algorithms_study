/** Vector searching functions.
 */

#ifndef ALGORITHMS_STUDY_CPP_SEARCHING_H
#define ALGORITHMS_STUDY_CPP_SEARCHING_H

#include <tuple>


/** Search the vector for a value, return index if found.
 *
 *  Uses the "linear search" algorithm.
 *  Worst-case performance: O(n)
 *
 * @param   vec     Vector to be searched
 * @param   value   Value to be searched for
 * @return          Index that the value was found at.
 *          If value was not found, exception is thrown.
 */
int LinearSearch(const std::vector<int> &vec, const int value);

/** Find the index of the minimum value in a vector.
 *
 *  If there are two or more minima, the index of the first is returned.
 *  Worst-case performance: O(n)
 *
 * @param   vec         Vector to be searched.
 * @param   begin_index Searching for minimum begins at this index.
 * @return              Index that the value was found at.
 */
int MinIndex(const std::vector<int> &vec, const int begin_index = 0);

/** Find the index of the maximum value in a vector.
 *
 *  If there are two or more maxima, the index of the first is returned.
 *  Worst-case performance: O(n)
 *
 *  Note that this is isomorphic to the "hiring problem" in the algorithms book.
 *
 * @param   vec         Vector to be searched.
 * @param   begin_index Searching for maximum begins at this index.
 * @return              Index that the value was found at.
 */
int MaxIndex(const std::vector<int> &vec, const int begin_index = 0);

/** Find the index of the relative maximum value in a vector.
 *
 *  This returns the first value larger than the values before `begin_index`;
 *  if none are larger, the last item is returned.
 *  Worst-case performance: O(n)
 *
 *  Note that this is isomorphic to the "blind hiring problem" in the
 *  algorithms book.
 *
 * @param   vec         Vector to be searched.
 * @param   begin_index Searching for maximum begins at this index.
 * @return              Index that the value was found at.
 */
int RelativeMaxIndex(const std::vector<int> &vec, const int begin_index);

/** Search a sorted vector for a value; return index if found; else throw.
 *
 *  Note that the input vector must be sorted; if it isn't, errors can occur.
 *  Recursive algorithm.
 *  Throws an exception if index is not found.
 *
 *  Worst-case performance: Theta(log n)
 *
 * @param vec           Vector to be searched.
 * @param begin_index   First index in the search range.
 * @param end_index     Index after the last index in the search range.
 * @param value         Value to be searched for.
 * @return              Index of search value in vector.
 */
int BinarySearch(
        const std::vector<int> &vec, const int begin_index, const int end_index,
        const int value);

/** Search vector for the "crossing" congruent subvector with the largest sum.
 *
 *  A subvector is said to be "crossing" if it includes the two items straddling
 *  the midpoint (that is, items at indices `middle_index` and
 *  `middle_index - 1`.
 *
 *  Worst-case performance: Theta(n)
 *
 * @param   vec           Vector to be searched
 * @param   begin_index   First index in the search range.
 * @param   middle_index  Index of the item right after the midpoint.
 * @param   end_index     Index after the last index in the search range.
 * @returns               `std::tuple` with three items:
 *          1. Beginning index of the result subvector.
 *          2. Index after the ending index of the result subvector.
 *          3. Sum of the result subvector.
 */
std::tuple<int, int, int> FindMaxCrossingSubvector(
        const std::vector<int> vec,
        const int begin_index,
        const int middle_index,
        const int end_index);

/** Search vector for the congruent subvector with the largest sum.
 *
 *  DAC stands for "divide and conquer", which is the algorithm used here.
 *  Recursive function.
 *
 *  Worst-case performance: Theta(n lg n)
 *
 * @param   vec         Vector to be searched
 * @param   begin_index First index in the search range.
 * @param   end_index   Index after the last index in the search range.
 * @returns             `std::tuple` with three items:
 *          1. Beginning index of the result subvector.
 *          2. Index after the ending index of the result subvector.
 *          3. Sum of the result subvector.
 */
std::tuple<int, int, int> FindMaxSubvectorDAC(
        const std::vector<int> vec,
        const int begin_index,
        const int end_index);

/** Search vector for the congruent subvector with the largest sum.
 *
 * BF stands for "brute force", which is the algorithm used here.
 *
 * Worst-case performance: Theta(n^2)
 *
 * @param   vec         Vector to be searched
 * @param   begin_index First index in the search range.
 * @param   end_index   Index after the last index in the search range.
 * @returns             `std::tuple` with three items:
 *          1. Beginning index of the result subvector.
 *          2. Index after the ending index of the result subvector.
 *          3. Sum of the result subvector.
 */
std::tuple<int, int, int> FindMaxSubvectorBF(
        const std::vector<int> vec,
        const int begin_index,
        const int end_index);

/** Search vector for the congruent subvector with the largest sum.
 *
 * This uses Kadane's algorithm (see https://goo.gl/odjGIx).
 *
 * Worst-case performance: Theta(n)
 *
 * @param   vec         Vector to be searched
 * @param   begin_index First index in the search range.
 * @param   end_index   Index after the last index in the search range.
 * @returns             `std::tuple` with three items:
 *          1. Beginning index of the result subvector.
 *          2. Index after the ending index of the result subvector.
 *          3. Sum of the result subvector.
 */
std::tuple<int, int, int> FindMaxSubvector(
        const std::vector<int> vec,
        const int begin_index,
        const int end_index);

#endif //ALGORITHMS_STUDY_CPP_SEARCHING_H
