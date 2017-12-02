/** Functions for binary heaps.
 */

#ifndef ALGORITHMS_STUDY_CPP_HEAP_HPP
#define ALGORITHMS_STUDY_CPP_HEAP_HPP

#include <vector>


/** Return index of left child of the node in a binary heap.
 *
 * @param   node	Index of node in heap.
 * @return  Index of left child of input node.
 */
int LeftChild(int node);

/** Return index of right child of the node in a binary heap.
 *
 * @param   node	Index of node in heap.
 * @return  Index of right child of input node.
 */
int RightChild(int node);

/** Return index of parent of this node.
 *
 * @param node  Index of node to retrieve parent of.
 * @return	  Index of parent node.
 */
int Parent(int node);

/** Enforce the max-heap property on the specified node.
 *
 * \warning{
 * Assumes the subtrees rooted at the children of the specified node are max-
 * heaps! This function deoes not check if this is the case, so if it isn't,
 * bad things might happen!}
 *
 * @param heap		  Heap containing the node to be max-heapified.
 * @param node		  Index of the node to be max-heapified.
 * @param heap_order	Number of nodes in the max-heap.
 */
void MaxHeapify(std::vector<int> &heap, int node, const int heap_order);

/** Enforce the min-heap property on the specified node.
 *
 * \warning{
 * Assumes the subtrees rooted at the children of the specified node are min-
 * heaps! This function deoes not check if this is the case, so if it isn't,
 * bad things might happen!}
 *
 * @param heap		  Heap containing the node to be min-heapified.
 * @param node		  Index of the node to be min-heapified.
 * @param heap_order	Number of nodes in the min-heap.
 */
void MinHeapify(std::vector<int> &heap, int node, const int heap_order);

/** Rearrange the items in the vector so it becomes a binary max-heap.
 *
 * Rearrangement occurs in-place with constant order memory usage.
 *
 * Worst-case performance: O(lg (heap.size()))
 *
 * @param vec   Vector to be rearranged into a binary max-heap.
 */
void MaxHeapBuilder(std::vector<int> &vec);

/** Rearrange the items in the vector so it becomes a binary min-heap.
 *
 * Rearrangement occurs in-place with constant order memory usage.
 *
 * Worst-case performance: O(lg (heap.size()))
 *
 * @param vec   Vector to be rearranged into a binary min-heap.
 */
void MinHeapBuilder(std::vector<int> &vec);

/** Removes and returns the largest value from a max-heap.
 *
 * \warning{
 * Assumes the input satisfies the properties of a max-heap!}
 *
 * @param max_heap  Max heap to have max value extracted
 * @return		  Largest value from the max heap
 */
int MaxHeapExtractMax(std::vector<int> &max_heap);

/** Removes and returns the smallest value from a min-heap.
 *
 * \warning{
 * Assumes the input satisfies the properties of a min-heap!}
 *
 * @param max_heap  Min-heap to have min value extracted
 * @return		  Smallest value from the min-heap
 */
int MinHeapExtractMin(std::vector<int> &min_heap);

/** Sets the key of a node in a max heap to a larger value.
 *
 * \warning{The new key value must be larger than the previous value!}
 *
 * @param max_heap  Max heap containing the node to be modified
 * @param node	  Index of the node to be modified
 * @param new_key   New value for the node; must be larger than old value!
 */
void MaxHeapIncreaseKey(std::vector<int> &max_heap, const int node, const int new_key);

/** Sets the key of a node in a min-heap to a smaller value.
 *
 * \warning{The new key value must be smaller than the previous value!}
 *
 * @param min_heap  Min-heap containing the node to be modified
 * @param node	  Index of the node to be modified
 * @param new_key   New value for the node; must be smaller than old value!
 */
void MinHeapDecreaseKey(std::vector<int> &min_heap, const int node, const int new_key);

/** Inserts the key into a max heap in the appropriate location.
 *
 * The key is inserted into a location that preserves the max-heap property.
 *
 * @param max_heap  Max-heap to be modified
 * @param key	   Key to be inserted
 */
void MaxHeapInsert(std::vector<int> &max_heap, const int key);

/** Inserts the key into a min-heap in the appropriate location.
 *
 * The key is inserted into a location that preserves the min-heap property.
 *
 * @param min_heap  Min-heap to be modified
 * @param key	   Key to be inserted
 */
void MinHeapInsert(std::vector<int> &min_heap, const int key);

/** Delete the node from the max-heap while maintaining max-heap properties.
 *
 * @param max_heap  Max-heap to have node deleted from
 * @param node	  Index of node to be deleted
 */
void MaxHeapDelete(std::vector<int> &max_heap, const int node);

/** Delete the node from the min-heap while maintaining min-heap properties.
 *
 * @param min_heap  Min-heap to have node deleted from
 * @param node	  Index of node to be deleted
 */
void MinHeapDelete(std::vector<int> &min_heap, const int node);

#endif //ALGORITHMS_STUDY_CPP_HEAP_HPP
