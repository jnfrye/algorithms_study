#include <vector>
#include <cmath>
#include <iostream>
#include <utility>
#include <assert.h>
#include <limits>

#include "algorithm/vector/heap.hpp"

int LeftChild(const int node) {
    // Part in parenthesis is what this would need to be if the binary tree were
    // not zero-indexed.
    return (2 * node) + 1;
}

int RightChild(const int node) {
    // Part in parenthesis is what this would need to be if the binary tree were
    // not zero-indexed.
    return (2 * node + 1) + 1;
}

int Parent(const int node) {
    return static_cast<int>(std::floor((node - 1)/2.));
}

void MaxHeapify(std::vector<int> &heap, const int node, const int heap_order) {
    int left_child = LeftChild(node);
    int right_child = RightChild(node);

    int largest_node;
    if (left_child < heap_order && heap[left_child] > heap[node]) {
        largest_node = left_child;
    }
    else {
        largest_node = node;
    }
    if (right_child < heap_order && heap[right_child] > heap[largest_node]) {
        largest_node = right_child;
    }

    if (largest_node != node) {
        std::swap(heap[node], heap[largest_node]);
        MaxHeapify(heap, largest_node, heap_order);
    }
}

void MinHeapify(std::vector<int> &heap, const int node, const int heap_order) {
    int left_child = LeftChild(node);
    int right_child = RightChild(node);

    int smallest_node;
    if (left_child < heap_order && heap[left_child] < heap[node])
        smallest_node = left_child;
    else
        smallest_node = node;
    if (right_child < heap_order && heap[right_child] < heap[smallest_node])
        smallest_node = right_child;

    if (smallest_node != node) {
        std::swap(heap[node], heap[smallest_node]);
        MinHeapify(heap, smallest_node, heap_order);
    }
}

void MaxHeapBuilder(std::vector<int> &vec) {
    for (int i = (int)std::floor((vec.size() - 1)/2.); i >= 0; --i)
        MaxHeapify(vec, i, vec.size());
}

void MinHeapBuilder(std::vector<int> &vec) {
    for (int i = (int)std::floor((vec.size() - 1)/2.); i >= 0; --i)
        MinHeapify(vec, i, vec.size());
}

int MaxHeapExtractMax(std::vector<int> &max_heap) {
    auto max = max_heap[0];
    max_heap[0] = max_heap[max_heap.size() - 1];
    max_heap.pop_back();
    MaxHeapify(max_heap, 0, max_heap.size());
    return max;
}

int MinHeapExtractMin(std::vector<int> &min_heap) {
    auto min = min_heap[0];
    min_heap[0] = min_heap[min_heap.size() - 1];
    min_heap.pop_back();
    MinHeapify(min_heap, 0, min_heap.size());
    return min;
}

void MaxHeapIncreaseKey(
        std::vector<int> &max_heap, const int node, const int new_key) {
    assert (new_key > max_heap[node] && "New key must be larger than old key!");

    max_heap[node] = new_key;
    int current_node = node;
    while (current_node > 0 &&
            max_heap[Parent(current_node)] < new_key) {
        max_heap[current_node] = max_heap[Parent(current_node)];
        current_node = Parent(current_node);
    }
    max_heap[current_node] = new_key;
}

void MinHeapDecreaseKey(
        std::vector<int> &min_heap, const int node, const int new_key) {
    assert (new_key < min_heap[node]
            && "New key must be smaller than old key!");

    min_heap[node] = new_key;
    int current_node = node;
    while (current_node > 0 &&
            min_heap[Parent(current_node)] > new_key) {
        min_heap[current_node] = min_heap[Parent(current_node)];
        current_node = Parent(current_node);
    }
    min_heap[current_node] = new_key;
}

void MaxHeapInsert(std::vector<int> &max_heap, const int key) {
    // First append "negative infinity" to the end of the vector
    max_heap.push_back(-std::numeric_limits<int>::max());
    // Then increase this key to the appropriate value
    MaxHeapIncreaseKey(max_heap, max_heap.size() - 1, key);
}

void MinHeapInsert(std::vector<int> &min_heap, const int key) {
    // First append "postive infinity" to the end of the vector
    min_heap.push_back(std::numeric_limits<int>::max());
    // Then increase this key to the appropriate value
    MinHeapDecreaseKey(min_heap, min_heap.size() - 1, key);
}

void MaxHeapDelete(std::vector<int> &max_heap, const int node) {
    max_heap[node] = max_heap[max_heap.size() - 1];
    MaxHeapify(max_heap, node, max_heap.size());
    max_heap.pop_back();
}
