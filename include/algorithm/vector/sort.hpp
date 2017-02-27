/** Sorting functions.
 */

#ifndef ALGORITHMS_STUDY_CPP_SORTING_H
#define ALGORITHMS_STUDY_CPP_SORTING_H


/** Insert value into correct place in sorted vector.
 *
 *  It is assumed that the vector is sorted in ascending order, from index 0
 *  to `index - 1`.
 *
 * @param   vec         Vector whose head is sorted.
 * @param   index       Index of the item to be inserted into its place in the
 *          sorted head.
 * @param   ascending   If true, sort in ascending order.
 *          Otherwise, sort in descending order.
 */
void InsertIntoSortedSubvector(
        std::vector<int> &vec, const int index, const bool ascending = true);

/** Sort the vector (in-place) in ascending or descending order.
 *
 *  Uses the "insertion sort" algorithm.
 *
 *  In insertion sort, we start with the second item in the vector and compare
 *  it to each item before it until a smaller one is found (or run out of
 *  items), and we place it in front of that (there's only the first item in the
 *  vector, so it swaps with this one if smaller than it). Then we compare the
 *  third item to each item before it until we find one that's smaller (or run
 *  out of items), and put it in front of that one, and so on for the rest of
 *  the items in the vector.
 *
 *  Worst-case performance: O(n^2)
 *
 * @param   vec         Vector to be sorted
 * @param   ascending   If true, sort in ascending order.
 *          Otherwise, sort in descending order.
 */
void InsertionSort(std::vector<int> &vec, const bool ascending = true);

/** Sort the vector (in-place) in ascending order.
 *
 *  A recursive version of the insertion sort algorithm is used.
 *
 * @param vec            Vector to be sorted.
 * @param subvector_size Size of subvector to be sorted (assumed to start from
 *        head of vector).
 */
void InsertionSortRecursive(std::vector<int> &vec, const int subvector_size);

/** Sort the vector (in-place) in ascending order.
 *
 *  Uses the "selection sort" algorithm.
 *
 *  In selection sort, the smallest item is found and moved to the first spot in
 *  the vector, then the second smallest item is found and moved to the second
 *  spot in the vector, and so on.
 *
 *  Worst-case performance: O(n^2)
 *
 * @param   vec Vector to be sorted.
 */
void SelectionSort(std::vector<int> &vec);

/** Merge (in-place) two adjacent sorted subvectors into one sorted subvector.
 *
 *  Worst-case performance: O(n)
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
 *
 *  Merge sort is a recursive algorithm. Consider a vector that is a power of
 *  two. The idea is to merge each pair of adjacent items into sorted 2-item
 *  subvectors, then merge each pair of adjacent 2-item subvectors into sorted
 *  4-item subvectors, and so on until the whole vector is sorted. If the vector
 *  is not a power of two, it ends up working out anyway lol.
 *
 *  Worst-case performance: O(n log n)
 *
 * @param vec           Vector to be sorted
 * @param begin_index   Index of the first item to be merge-sorted.
 * @param end_index     Index after the last item to be merge-sorted.
 */
void MergeSort(
        std::vector<int> &vec, const int begin_index, const int end_index);

/** Sort the vector (in-place) in ascending order.
 *
 * Uses the "heapsort" algorithm.
 *
 * Heapsort rearranges the vector into a nearly complete binary tree called a
 * "max-heap", then moves the largest item to the end of the vector and
 * rearranges the remaining items until it is again a max-heap, and so on.
 *
 * Worst-case performance: Theta(n lg n)
 *
 * @param vec   Vector to be sorted.
 */
void HeapSort(std::vector<int> &vec);

/** Rearrange the subvector (in-place), partitioning it for quicksort.
 *
 * Uses the end of the subvector as a 'pivot', and partitions the subvector
 * such that elements before the pivot are less than or equal to it, and
 * elements after the pivot are greater than it.
 *
 * This is the part of quicksort that performs the rearrangements.
 *
 * Worst-case performance: Theta(n)
 *
 * @param vec           Vector containing the subvector to be partitioned
 * @param begin_index   Index of the first item in the subvector to be
 *          partitioned
 * @param end_index     Index after the last item in the subvector to be
 *          partitioned
 * @return              Index of the item dividing the partitions (the 'pivot')
 */
int QuicksortPartition(std::vector<int> &vec, const int begin, const int end);

/** Rearrange the subvector (in-place), partitioning it randomly for quicksort.
 *
 * Uses a random item in subvector as a 'pivot', and partitions the subvector
 * such that elements before the pivot are less than or equal to it, and
 * elements after the pivot are greater than it.
 *
 * This is the part of quicksort that performs the rearrangements.
 *
 * Worst-case performance: Theta(n)
 *
 * @param vec           Vector containing the subvector to be partitioned
 * @param begin_index   Index of the first item in the subvector to be
 *          partitioned
 * @param end_index     Index after the last item in the subvector to be
 *          partitioned
 * @return              Index of the item dividing the partitions (the 'pivot')
 */
int RandomizedQuicksortPartition(
        std::vector<int> &vec, const int begin, const int end);

/** Rearrange the subvector (in-place), partitioning it for quicksort.
 *
 * Uses Hoare's partitioning algorithm.
 *
 * This is the part of quicksort that performs the rearrangements.
 *
 * Worst-case performance: Theta(n)
 *
 * @param vec           Vector containing the subvector to be partitioned
 * @param begin_index   Index of the first item in the subvector to be
 *          partitioned
 * @param end_index     Index after the last item in the subvector to be
 *          partitioned
 * @return              Index of the item dividing the partitions (the 'pivot')
 */
int HoareQuicksortPartition(
        std::vector<int> &vec, const int begin, const int end);

/** Sort the vector (in-place) in ascending order.
 *
 * Uses the quicksort recursive algorithm.
 *
 * Worst-case performance: Theta(n^2)
 * Average-case performance: Theta(n lg n)
 */
void Quicksort(std::vector<int> &vec, const int begin, const int end);

/** Sort the vector (in-place) in ascending order.
 *
 * Uses the randomized quicksort recursive algorithm.
 *
 * Worst-case performance: Theta(n^2)
 * Average-case performance: Theta(n lg n)
 */
void RandomizedQuicksort(std::vector<int> &vec, const int begin, const int end);

/** Sort the vector (in-place) in ascending order.
 *
 * Uses the Hoare quicksort recursive algorithm.
 *
 * Worst-case performance: Theta(n^2)
 * Average-case performance: Theta(n lg n)
 */
void HoareQuicksort(std::vector<int> &vec, const int begin, const int end);

#endif //ALGORITHMS_STUDY_CPP_SORTING_H

