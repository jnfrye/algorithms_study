/** Functions for binary heaps.
 */

#ifndef ALGORITHMS_STUDY_CPP_HEAP_HPP
#define ALGORITHMS_STUDY_CPP_HEAP_HPP

#include <vector>


/** Enforce the max-heap property on the specified node.
 *
 * \warning{
 * Assumes the subtrees rooted at the children of the specified node are max-
 * heaps! This function deoes not check if this is the case, so if it isn't,
 * bad things might happen!}
 *
 * @param heap  Heap containing the node to be max-heapified.
 * @param node  Index of the node to be max-heapified.
 */
void MaxHeapify(std::vector<int> heap, int node);

#endif //ALGORITHMS_STUDY_CPP_HEAP_HPP
