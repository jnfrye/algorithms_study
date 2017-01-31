#include <vector>
#include <cmath>

#include "algorithm/vector/heap.hpp"

int LeftChild(int node) {
    // Part in parenthesis is what this would need to be if the binary tree were
    // not zero-indexed.
    return (2 * node) + 1;
}

int RightChild(int node) {
    // Part in parenthesis is what this would need to be if the binary tree were
    // not zero-indexed.
    return (2 * node + 1) + 1;
}

int Parent(int node) {
    return static_cast<int>(std::floor((node - 1)/2.));
}

void MaxHeapify(std::vector<int> heap, int node) {

}
