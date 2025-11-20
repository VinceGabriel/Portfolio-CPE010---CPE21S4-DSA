#include "searching.h"
#include <iostream>
#include "nodes.h"

// Helper function to build linked list from array
template <typename T>
Node<T>* buildLinkedList(T arr[], int size) {
    if (size == 0) return nullptr;
    Node<T>* head = new_node(arr[0]);
    Node<T>* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new_node(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Problem 1 & 2 data setup
    int data[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int n = sizeof(data)/sizeof(data[0]) - 1;

    // Problem 1: Linear search on array with comparisons
    std::cout << "Problem 1 - Linear search in array for '18':\n";
    int compsArray = linearSearchWithCount(data, n, 18);
    std::cout << "Comparisons made: " << compsArray << "\n\n";

    // Problem 1: Linear search on linked list with comparisons
    Node<int>* head = buildLinkedList(data, n+1);
    std::cout << "Problem 1 - Linear search in linked list for '18':\n";
    int compsList = linearLSWithCount(head, 18);
    std::cout << "Comparisons made: " << compsList << "\n\n";

    // Problem 2: Count repeating instances in array
    int repeatsArray = countRepeatsArray(data, n, 18);
    std::cout << "Problem 2 - Count repeats of '18' in array: " << repeatsArray << "\n";

    // Problem 2: Count repeating instances in linked list
    int repeatsList = countRepeatsList(head, 18);
    std::cout << "Problem 2 - Count repeats of '18' in linked list: " << repeatsList << "\n\n";

    // Problem 3: Binary search verbose
    int sortedData[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int sortedSize = sizeof(sortedData)/sizeof(sortedData[0]);
    std::cout << "Problem 3 - Iteration verbose binary search for key '8':\n";
    binarySearchVerbose(sortedData, sortedSize, 8);
    std::cout << "\n";

    // Problem 4: Recursive binary search
    std::cout << "Problem 4 - Recursive binary search for key '8':\n";
    int index = recursiveBinarySearch(sortedData, 0, sortedSize - 1, 8);
    if (index != -1) {
        std::cout << "Search element found at index " << index << std::endl;
    } else {
        std::cout << "Search element not found" << std::endl;
    }

    // Clean linked list memory
    Node<int>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

