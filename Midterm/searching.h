#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include "nodes.h"

// Problem 1: Linear search on array with comparison count
int linearSearchWithCount(int data[], int n, int item) {
    int comparisons = 0;
    for (int i = 0; i <= n; ++i) {
        comparisons++;
        if (data[i] == item) {
            std::cout << "Searching is successful" << std::endl;
            return comparisons;
        }
    }
    std::cout << "Searching is unsuccessful" << std::endl;
    return comparisons;
}

// Problem 2: Count repeating instances in array
int countRepeatsArray(int data[], int n, int item) {
    int count = 0;
    for (int i = 0; i <= n; ++i) {
        if (data[i] == item) {
            count++;
        }
    }
    return count;
}

// Problem 1: Linear search on linked list with comparison count
template <typename T>
int linearLSWithCount(Node<T>* head, T dataFind) {
    int comparisons = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        comparisons++;
        if (current->data == dataFind) {
            std::cout << "Searching is successful" << std::endl;
            return comparisons;
        }
        current = current->next;
    }
    std::cout << "Searching is unsuccessful" << std::endl;
    return comparisons;
}

// Problem 2: Count repeating instances in linked list
template <typename T>
int countRepeatsList(Node<T>* head, T item) {
    int count = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Problem 3: Binary search with iteration output for arrays
void binarySearchVerbose(int arr[], int n, int no) {
    int low = 0;
    int up = n - 1;
    int iteration = 1;

    while (low <= up) {
        int mid = (low + up) / 2;
        std::cout << "Iteration " << iteration++
                  << ": low=" << low
                  << ", up=" << up
                  << ", mid=" << mid
                  << ", arr[mid]=" << arr[mid] << std::endl;

        if (arr[mid] == no) {
            std::cout << "Search element is found!" << std::endl;
            return;
        } else if (no < arr[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << "Search element is not found" << std::endl;
}

// Problem 4: Recursive binary search on array
int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low > high) return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if (key < arr[mid]) {
        return recursiveBinarySearch(arr, low, mid - 1, key);
    } else {
        return recursiveBinarySearch(arr, mid + 1, high, key);
    }
}

#endif

