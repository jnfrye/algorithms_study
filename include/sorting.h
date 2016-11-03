//
// Created by jfrye on 11/2/16.
//

#ifndef ALGORITHMS_STUDY_CPP_SORTING_H
#define ALGORITHMS_STUDY_CPP_SORTING_H

void HelloWorld();

/** Search the vector for a value, return index if found.
 * @param   vec     Vector to be searched
 * @param   value   Value to be searched for
 * @return          Index that the value was found at.
 *      If value was not found, exception is thrown.
 */
long LinearSearch(const std::vector<int> &vec, const int value);

/** Sort the vector (in-place) in ascending or descending order.
 * @param   vec         Vector to be sorted
 * @param   ascending   If true, sort in ascending order.
 *                      Otherwise, sort in descending order.
 */
void InsertionSort(std::vector<int> &vec, const bool ascending = true);

#endif //ALGORITHMS_STUDY_CPP_SORTING_H
