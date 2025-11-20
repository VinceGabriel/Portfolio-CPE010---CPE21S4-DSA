#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"
using namespace std;

int main() {
    const int SIZE = 100;
    int arr[SIZE];

    srand(time(0));
    for(int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000; // Random values 0-999

    cout << "Original Array (Preparation Task - Table 8-1):\n";
    showArray(arr, SIZE);

    // Arrays for each sorting algorithm
    int arrShell[SIZE], arrMerge[SIZE], arrQuick[SIZE];
    copyArray(arr, arrShell, SIZE);
    copyArray(arr, arrMerge, SIZE);
    copyArray(arr, arrQuick, SIZE);

    // Shell Sort
    doShellSort(arrShell, SIZE);
    cout << "\nShell Sort Result:\n";
    showArray(arrShell, SIZE);

    // Merge Sort
    mergeSort(arrMerge, 0, SIZE-1);
    cout << "\nMerge Sort Result:\n";
    showArray(arrMerge, SIZE);

    // Quick Sort
    quickSort(arrQuick, 0, SIZE-1);
    cout << "\nQuick Sort Result:\n";
    showArray(arrQuick, SIZE);

    return 0;
}
