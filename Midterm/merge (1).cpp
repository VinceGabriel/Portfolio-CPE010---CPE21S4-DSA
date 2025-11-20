#include <iostream>
#include <cstdlib>
#include <ctime>
#include "merge.h"
using namespace std;

int main() {
    const int SIZE = 20; 
    int arr[SIZE];

    
    srand(time(0));
    for(int i = 0; i < SIZE; i++)
        arr[i] = rand() % 100;

    cout << "Original Array:\n";
    showArray(arr, SIZE);

    mergeSort(arr, 0, SIZE - 1);

    cout << "\nArray After Merge Sort:\n";
    showArray(arr, SIZE);

    return 0;
}
