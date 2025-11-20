// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "bubble_sort.h"

using namespace std;

const int SIZE = 100;

void printArray(const int arr[], int size, const string& title) {
    cout << title << "\n";
    for (int i = 0; i < size; ++i) {
        cout << setw(4) << arr[i];
        if ((i + 1) % 10 == 0)
            cout << "\n";
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i)
        arr[i] = rand() % 1000; // Random values between 0 and 999

    printArray(arr, SIZE, "Original Array:");

    // Apply Bubble Sort
    bubbleSort(arr, SIZE);

    printArray(arr, SIZE, "Sorted Array (Descending Order using Bubble Sort):");

    return 0;
}