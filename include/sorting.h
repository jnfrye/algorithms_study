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

/** Merge (in-place) two adjacent sorted subvectors into one sorted subvector.
 *
 *  Worst-case: O(n)
 *
 * @param vec           Vector whose subvectors are to be merged.
 * @param begin_index   Index of the first item of the first subvector.
 * @param middle_index  Index of the first item of the second subvector.
 * @param end_index     Index after the last item of the second subvector.
 */
void MergeSortedSubvectors(
        std::vector<int> &vec, const int begin_index, const int middle_index,
        const int end_index);

/** Sort the vector (in-place) in ascending order.
 *
 *  Uses the "merge sort" algorithm.
 *  Worst-case performance: O(n log n)
 *
 * @param vec
 * @param begin_index
 * @param end_index
 */
void MergeSort(
        std::vector<int> &vec, const int begin_index, const int end_index);

#endif //ALGORITHMS_STUDY_CPP_SORTING_H
