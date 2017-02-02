#include <vector>
#include <cmath>
#include <iostream>
#include <utility>

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

void BuildMaxHeap(std::vector<int> &vec) {
    for (int i = (int)std::floor((vec.size() - 1)/2.); i >= 0; --i)
        MaxHeapify(vec, i, vec.size());
}

int ExtractMaxFromHeap(std::vector<int> &max_heap) {
    auto max = max_heap[0];
    max_heap[0] = max_heap[max_heap.size() - 1];
    max_heap.pop_back();
    MaxHeapify(max_heap, 0, max_heap.size());
    return max;
}