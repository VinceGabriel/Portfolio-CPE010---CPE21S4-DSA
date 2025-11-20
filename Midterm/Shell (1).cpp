#include <iostream>
#include <cstdlib>
#include <ctime>
#include "shell.h"
using namespace std;

int main() {
    const int SIZE = 20; // change to 100 if needed
    int arr[SIZE];

    // Generate random numbers
    srand(time(0));
    for(int i = 0; i < SIZE; i++)
        arr[i] = rand() % 100;

    cout << "Original Array:\n";
    showArray(arr, SIZE);

    doShellSort(arr, SIZE);

    cout << "\nArray After Shell Sort:\n";
    showArray(arr, SIZE);

    return 0;
}
