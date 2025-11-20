// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include "sorts.h"
using namespace std;

const int SIZE = 100;

// Utility function to print arrays
void printArray(const int arr[], int size, string title) {
    cout << title << "\n";
    for (int i = 0; i < size; ++i) {
        cout << setw(4) << arr[i];
        if ((i + 1) % 10 == 0) cout << "\n";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    int original[SIZE];
    for (int i = 0; i < SIZE; ++i)
        original[i] = rand() % 1000; // Random numbers between 0 and 999

    // Create copies for each algorithm
    int arrSelection[SIZE];
    int arrBubble[SIZE];
    int arrInsertion[SIZE];
    int arrMerge[SIZE];

    copy(begin(original), end(original), arrSelection);
    copy(begin(original), end(original), arrBubble);
    copy(begin(original), end(original), arrInsertion);
    copy(begin(original), end(original), arrMerge);

    printArray(original, SIZE, "Original Array:");

    // Apply and print each sort
    selectionSort(arrSelection, SIZE);
    printArray(arrSelection, SIZE, "Selection Sort:");

    bubbleSort(arrBubble, SIZE);
    printArray(arrBubble, SIZE, "Bubble Sort:");

    insertionSort(arrInsertion, SIZE);
    printArray(arrInsertion, SIZE, "Insertion Sort:");

    mergeSort(arrMerge, 0, SIZE - 1);
    printArray(arrMerge, SIZE, "Merge Sort:");

    return 0;
}