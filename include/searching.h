//
// Created by jfrye on 11/7/16.
//

#ifndef ALGORITHMS_STUDY_CPP_SEARCHING_H
#define ALGORITHMS_STUDY_CPP_SEARCHING_H


/** Search the vector for a value, return index if found.
 *
 *  Uses the "linear search" algorithm.
 *  Worst-case: O(n)
 *
 * @param   vec     Vector to be searched
 * @param   value   Value to be searched for
 * @return          Index that the value was found at.
 *          If value was not found, exception is thrown.
 */
long LinearSearch(const std::vector<int> &vec, const int value);

/** Find the index of the minimum value in a vector.
 *
 * @param   vec         Vector to be searched.
 * @param   begin_index Searching for minimum begins at this index.
 * @return              Index that the value was found at.
 */
long MinIndex(const std::vector<int> &vec, const long begin_index = 0);

#endif //ALGORITHMS_STUDY_CPP_SEARCHING_H
