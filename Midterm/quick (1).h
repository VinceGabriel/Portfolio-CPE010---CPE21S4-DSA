#ifndef SORTS_H
#define SORTS_H

#include <iostream>
using namespace std;


void showArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void copyArray(int source[], int dest[], int size) {
    for(int i = 0; i < size; i++)
        dest[i] = source[i];
}

// ---------- Quick Sort ----------
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while(true) {
        while(i <= high && arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < j) swap(arr[i], arr[j]);
        else break;
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

#endif
