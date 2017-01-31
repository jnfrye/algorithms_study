#include <vector>
#include <cmath>

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

void MaxHeapify(std::vector<int> heap, const int node) {
    int left_child = LeftChild(node);
    int right_child = RightChild(node);

    int largest_node;
    if (left_child < heap.size() && heap[left_child] > heap[node])
        largest_node = left_child;
    else
        largest_node = node;
    if (right_child < heap.size() && heap[right_child] > heap[largest_node])
        largest_node = right_child;

    if (largest_node != node) {
        // If this is the case, the node is not in the right position and must
        // be moved. After, we must check if it needs to moved again.
        int temp = heap[node];
        heap[node] = heap[largest_node];
        heap[largest_node] = temp;
        MaxHeapify(heap, largest_node);
    }
}
