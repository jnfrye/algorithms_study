#include "algorithm/vector/sort.hpp"

#include "algorithm/vector/search.hpp"
#include "algorithm/vector/heap.hpp"
#include "algorithm/random.hpp"

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <utility>

void InsertIntoSortedSubvector(
        std::vector<int> &vec, const int index,
        const bool ascending /*= true*/) {
    int value_to_be_inserted = vec[index];

    // We compare the index to each item before it in the vector
    int search_index = index - 1;
    while(search_index >= 0 &&
            (ascending == (value_to_be_inserted < vec[search_index]))) {
        vec[search_index + 1] = vec[search_index];
        --search_index;
    }
    vec[search_index + 1] = value_to_be_inserted;
}

void InsertionSort(std::vector<int> &vec, const bool ascending /*= true*/) {
    for(int key_index = 1; key_index < vec.size(); ++key_index) {
        InsertIntoSortedSubvector(vec, key_index, ascending);
    }
}

void InsertionSortRecursive(std::vector<int> &vec, const int subvector_size) {
    if (subvector_size > 1)
        InsertionSortRecursive(vec, subvector_size - 1);

    InsertIntoSortedSubvector(vec, subvector_size - 1);
}

void SelectionSort(std::vector<int> &vec) {
    for (int index = 0; index < vec.size() - 1; ++index) {
        int min_index = MinIndex(vec, index);
        if (min_index != index) {
            // Swap the two values
            int temp = vec[min_index];
            vec[min_index] = vec[index];
            vec[index] = temp;
        }
    }
}

void MergeSortedSubvectors(
        std::vector<int> &vec, const int begin_index, const int middle_index,
        const int end_index) {
    // Extract the subvectors
    std::vector<int> subvec1(
        vec.begin() + begin_index, vec.begin() + middle_index);
    std::vector<int> subvec2(
        vec.begin() + middle_index, vec.begin() + end_index);

    // Add the sentinels (largest possible integer is used)
    subvec1.push_back(std::numeric_limits<int>::max());
    subvec2.push_back(std::numeric_limits<int>::max());

    int subvec1_index = 0;
    int subvec2_index = 0;

    for (int main_index = begin_index; main_index < end_index; ++main_index) {
        if (subvec1[subvec1_index] <= subvec2[subvec2_index]) {
            vec[main_index] = subvec1[subvec1_index];
            ++subvec1_index;
        }
        else {
            vec[main_index] = subvec2[subvec2_index];
            ++subvec2_index;
        }
    }
}

void MergeSort(
        std::vector<int> &vec, const int begin_index, const int end_index) {
    if (begin_index < end_index - 1) {
        int middle_index = static_cast<int>(
            std::floor((begin_index + end_index)/2.));

        MergeSort(vec, begin_index, middle_index);
        MergeSort(vec, middle_index, end_index);
        MergeSortedSubvectors(vec, begin_index, middle_index, end_index);
    }
}

void HeapSort(std::vector<int> &vec) {
    MaxHeapBuilder(vec);
    int heap_order = vec.size();
    for (int i = vec.size() - 1; i >= 1; i--) {
        std::swap(vec[0], vec[i]);
        --heap_order;
        MaxHeapify(vec, 0, heap_order);
    }
}

int QuicksortPartition(
        std::vector<int> &vec, const int begin, const int end,
        const bool equality_check /*= true*/) {
    auto pivot = vec[end - 1];
    int left = begin - 1;
    for (int right = begin; right < end - 1; ++right)
        if (vec[right] < pivot || (equality_check && vec[right] == pivot)) {
            ++left;
            std::swap(vec[left], vec[right]);
        }
    std::swap(vec[left + 1], vec[end - 1]);
    return left + 1;
}

std::tuple<int, int> EqCheckQuicksortPartition(
        std::vector<int> &vec, const int begin, const int end) {
    int pivot_end = QuicksortPartition(vec, begin, end) + 1;
    int pivot_begin = QuicksortPartition(vec, begin, pivot_end, false);
    return std::make_tuple(pivot_begin, pivot_end);
}

int RandomizedQuicksortPartition(
        std::vector<int> &vec, const int begin, const int end) {
    int pivot = RandomInteger(begin, end - 1);
    std::swap(vec[end - 1], vec[pivot]);
    return QuicksortPartition(vec, begin, end);
}

std::tuple<int, int> RandomizedEqCheckQuicksortPartition(
        std::vector<int> &vec, const int begin, const int end) {
    int pivot = RandomInteger(begin, end - 1);
    std::swap(vec[end - 1], vec[pivot]);
    return EqCheckQuicksortPartition(vec, begin, end);
}

int HoareQuicksortPartition(
        std::vector<int> &vec, const int begin, const int end) {
    auto pivot = vec[begin];
    int left = begin - 1;
    int right = end;
    while (true) {
        do {
        --right;
        } while (vec[right] > pivot);
        do {
        ++left;
        } while (vec[left] < pivot);

        if (left < right) std::swap(vec[left], vec[right]);
        else return right;
    }
}

void Quicksort(std::vector<int> &vec, const int begin, const int end) {
    // Terminate recursion if subvector is singleton
    if (1 < end - begin) {
        int pivot = QuicksortPartition(vec, begin, end);
        Quicksort(vec, begin, pivot);
        Quicksort(vec, pivot + 1, end);
    }
}

void RandomizedQuicksort(
        std::vector<int> &vec, const int begin, const int end) {
    // Terminate recursion if subvector is singleton
    if (1 < end - begin) {
        int pivot = RandomizedQuicksortPartition(vec, begin, end);
        RandomizedQuicksort(vec, begin, pivot);
        RandomizedQuicksort(vec, pivot + 1, end);
    }
}

void RandomizedEqCheckQuicksort(
        std::vector<int> &vec, const int begin, const int end) {
    // Terminate recursion if subvector is singleton
    if (1 < end - begin) {
        auto pivot = RandomizedEqCheckQuicksortPartition(vec, begin, end);
        RandomizedQuicksort(vec, begin, std::get<0>(pivot));
        RandomizedQuicksort(vec, std::get<1>(pivot), end);
    }
}

void HoareQuicksort(std::vector<int> &vec, const int begin, const int end) {
    // Terminate recursion if subvector is singleton
    if (1 < end - begin) {
        int pivot = HoareQuicksortPartition(vec, begin, end);
        HoareQuicksort(vec, begin, pivot + 1);
        HoareQuicksort(vec, pivot + 1, end);
    }
}

std::vector<int> CountingSort(
        std::vector<int> &input_vec, const int min, const int max) {
    auto possible_values = max - min + 1;
    std::vector<int> value_counts(possible_values, 0);

    // This vector contains the counts of each value in the input vector
    // It is zero-indexed; the item in index 0 is the number of times the min
    // value shows up in the input vector, the item in index 1 is the number of
    // times the min + 1 shows up, and so on up to the max value
    for (int i = 0; i < input_vec.size(); ++i)
        ++value_counts[input_vec[i] - min];

    // This causes the vector to contain the number of entries that have value
    // less than or equal to this value
    for (int value_index = 1; value_index < possible_values; ++value_index)
        value_counts[value_index] += value_counts[value_index - 1];

    std::vector<int> output_vec(input_vec.size());
    for (int j = (int)input_vec.size() - 1; j >= 0; --j) {
        output_vec[value_counts[input_vec[j] - min] - 1] = input_vec[j];
        --value_counts[input_vec[j] - min];
    }
    return output_vec;
}
