#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> 

using namespace std;
using namespace chrono;

// ---------- Bubble Sort ----------
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// ---------- Merge Sort ----------
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void measureSort(void (*sortFunc)(vector<int>&), vector<int> arr, string name, int n) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << name << " (n = " << n << ") took " << duration.count() << " ms" << endl;
}

int main() {
    vector<int> sizes = {100, 1000, 10000};

    for (int n : sizes) {
        vector<int> best(n), worst(n);
        for (int i = 0; i < n; i++) {
            best[i] = i;
            worst[i] = n - i;
        }

        cout << "\n===== Size n = " << n << " =====" << endl;
        measureSort(bubbleSort, best, "Bubble Sort (Best Case)", n);
        measureSort(bubbleSort, worst, "Bubble Sort (Worst Case)", n);

        measureSort([](vector<int>& a){ mergeSort(a, 0, a.size() - 1); }, best, "Merge Sort (Best Case)", n);
        measureSort([](vector<int>& a){ mergeSort(a, 0, a.size() - 1); }, worst, "Merge Sort (Worst Case)", n);
    }
    return 0;
}
