// bubble_sort.h
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <cstddef>   // for size_t
#include <utility>   // for std::swap

// Bubble Sort (Generic - works with any data type supporting > operator)
template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    // Step 1: For i = 0 to N-1 repeat Step 2
    for (size_t i = 0; i < arrSize; ++i) {
        // Step 2: For j = i+1 to N-i repeat
        for (size_t j = i + 1; j < arrSize; ++j) {
            // Step 3: if A[j] > A[i]
            if (arr[j] > arr[i]) {
                // Swap A[j] and A[i]
                std::swap(arr[j], arr[i]);
            }
        }
    }
    // Step 4: Exit
}

#endif // BUBBLE_SORT_H