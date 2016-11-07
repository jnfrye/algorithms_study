//
// Created by jfrye on 11/2/16.
//

#ifndef ALGORITHMS_STUDY_CPP_SORTING_H
#define ALGORITHMS_STUDY_CPP_SORTING_H


/** Sort the vector (in-place) in ascending or descending order.
 *
 *  Uses the "insertion sort" algorithm.
 *  Worst-case: O(n^2)
 *
 * @param   vec         Vector to be sorted
 * @param   ascending   If true, sort in ascending order.
 *          Otherwise, sort in descending order.
 */
void InsertionSort(std::vector<int> &vec, const bool ascending = true);

/** Sort the vector (in-place) in ascending order.
 *
 *  Uses the "selection sort" algorithm.
 *  Worst-case: O(n^2)
 *
 * @param   vec Vector to be sorted.
 */
void SelectionSort(std::vector<int> &vec);

#endif //ALGORITHMS_STUDY_CPP_SORTING_H
