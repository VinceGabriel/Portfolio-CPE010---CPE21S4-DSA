#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int linearSearch(vector<int> arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i;
    }
    return -1; 
}

int binarySearch(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

int main() {
    vector<int> sizes = {1000, 10000, 100000};
    cout << "Empirical Analysis: Linear Search vs Binary Search\n";

    for (int n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        int target = -1; 

        auto start1 = high_resolution_clock::now();
        linearSearch(arr, target);
        auto end1 = high_resolution_clock::now();
        auto linearTime = duration_cast<microseconds>(end1 - start1).count();

        auto start2 = high_resolution_clock::now();
        binarySearch(arr, target);
        auto end2 = high_resolution_clock::now();
        auto binaryTime = duration_cast<microseconds>(end2 - start2).count();

        cout << "\nInput Size (N) = " << n << endl;
        cout << "Linear Search (Worst Case): " << linearTime << " microseconds" << endl;
        cout << "Binary Search (Worst Case): " << binaryTime << " microseconds" << endl;
    }

    return 0;
}