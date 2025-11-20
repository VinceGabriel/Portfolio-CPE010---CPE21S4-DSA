#ifndef SORTS_H
#define SORTS_H

#include <iostream>
using namespace std;

// Function to display array
void showArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to copy array
void copyArray(int source[], int dest[], int size) {
    for(int i = 0; i < size; i++)
        dest[i] = source[i];
}

// SHELL SORT
void doShellSort(int arr[], int size) {
    for(int gap = size/2; gap > 0; gap /= 2) {
        for(int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// MERGE SORT
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

// QUICK SORT
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
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
