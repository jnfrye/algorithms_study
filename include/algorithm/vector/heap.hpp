/** Functions for binary heaps.
 */

#ifndef ALGORITHMS_STUDY_CPP_HEAP_HPP
#define ALGORITHMS_STUDY_CPP_HEAP_HPP

#include <vector>


/** Return index of left child of the node in a binary heap.
 *
 * @param   node    Index of node in heap.
 * @return  Index of left child of input node.
 */
int LeftChild(int node);

/** Return index of right child of the node in a binary heap.
 *
 * @param   node    Index of node in heap.
 * @return  Index of right child of input node.
 */
int RightChild(int node);

/** Return index of parent of this node.
 *
 * @param node  Index of node to retrieve parent of.
 * @return      Index of parent node.
 */
int Parent(int node);

/** Enforce the max-heap property on the specified node.
 *
 * \warning{
 * Assumes the subtrees rooted at the children of the specified node are max-
 * heaps! This function deoes not check if this is the case, so if it isn't,
 * bad things might happen!}
 *
 * @param heap          Heap containing the node to be max-heapified.
 * @param node          Index of the node to be max-heapified.
 * @param heap_order    Number of nodes in the max-heap.
 */
void MaxHeapify(std::vector<int> &heap, int node, const int heap_order);

/** Rearrange the items in the vector so it becomes a binary max-heap.
 *
 * Rearrangement occurs in-place with constant order memory usage.
 *
 * Worst-case performance: O(lg (heap.size()))
 *
 * @param vec   Vector to be rearranged into a binary max-heap.
 */
void BuildMaxHeap(std::vector<int> &vec);

#endif //ALGORITHMS_STUDY_CPP_HEAP_HPP
