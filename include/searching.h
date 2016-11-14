//
// Created by jfrye on 11/7/16.
//

#ifndef ALGORITHMS_STUDY_CPP_SEARCHING_H
#define ALGORITHMS_STUDY_CPP_SEARCHING_H


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

/** Search a sorted vector for a value; return index if found; else throw.
 *
 *  Note that the input vector must be sorted; if it isn't, errors can occur.
 *  Recursive algorithm.
 *  Throws an exception if index is not found.
 *
 *  Worst-case performance: O(log n)
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

#endif //ALGORITHMS_STUDY_CPP_SEARCHING_H
