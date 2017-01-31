#include <vector>

#include "algorithm/vector/heap.hpp"

int LeftChild(int node) {
    return 2 * node;
}

int RightChild(int node) {
    return 2 * node + 1;
}

void MaxHeapify(std::vector<int> heap, int node) {

}
