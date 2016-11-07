//
// Created by jfrye on 11/2/16.
//

#ifndef ALGORITHMS_STUDY_CPP_SORTING_H
#define ALGORITHMS_STUDY_CPP_SORTING_H

void HelloWorld();

/** Search the vector for a value, return index if found.
 *
 *  Uses the "linear search" algorithm.
 *  Worst-case: O(n)
 *
 * @param   vec     Vector to be searched
 * @param   value   Value to be searched for
 * @return          Index that the value was found at.
 *      If value was not found, exception is thrown.
 */
long LinearSearch(const std::vector<int> &vec, const int value);

/** Sort the vector (in-place) in ascending or descending order.
 *
 *  Uses the "insertion sort" algorithm.
 *  Worst-case: O(n^2)
 *
 * @param   vec         Vector to be sorted
 * @param   ascending   If true, sort in ascending order.
 *                      Otherwise, sort in descending order.
 */
void InsertionSort(std::vector<int> &vec, const bool ascending = true);

#endif //ALGORITHMS_STUDY_CPP_SORTING_H
