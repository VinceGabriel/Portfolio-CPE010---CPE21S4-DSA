#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// ---------- Bubble Sort ----------
void bubble_sort(vector<int>& nums) {
    int len = nums.size();
    for (int pass = 0; pass < len - 1; ++pass) {
        for (int j = 0; j < len - pass - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

// ---------- Merge Sort ----------
void merge_arrays(vector<int>& nums, int start, int mid, int end) {
    int left_size = mid - start + 1;
    int right_size = end - mid;

    vector<int> left(left_size);
    vector<int> right(right_size);

    for (int i = 0; i < left_size; ++i) left[i] = nums[start + i];
    for (int j = 0; j < right_size; ++j) right[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            nums[k++] = left[i++];
        } else {
            nums[k++] = right[j++];
        }
    }

    while (i < left_size) nums[k++] = left[i++];
    while (j < right_size) nums[k++] = right[j++];
}

void merge_sort(vector<int>& nums, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);
    merge_arrays(nums, start, mid, end);
}

// ---------- Time Measurement ----------
void evaluate_sort(void (*sort_function)(vector<int>&), vector<int> data, const string& label, int size) {
    auto begin = high_resolution_clock::now();
    sort_function(data);
    auto finish = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(finish - begin);
    cout << label << " (n = " << size << ") executed in " << duration.count() << " ms" << endl;
}

// ---------- Main Function ----------
int main() {
    vector<int> data_sizes = {100, 1000, 10000};

    for (int size : data_sizes) {
        vector<int> ascending(size);
        vector<int> descending(size);

        for (int i = 0; i < size; ++i) {
            ascending[i] = i;
            descending[i] = size - i;
        }

        cout << "\n=== Evaluating for n = " << size << " ===" << endl;

        evaluate_sort(bubble_sort, ascending, "Bubble Sort (Best Case)", size);
        evaluate_sort(bubble_sort, descending, "Bubble Sort (Worst Case)", size);

        evaluate_sort([](vector<int>& arr) { merge_sort(arr, 0, arr.size() - 1); }, ascending, "Merge Sort (Best Case)", size);
        evaluate_sort([](vector<int>& arr) { merge_sort(arr, 0, arr.size() - 1); }, descending, "Merge Sort (Worst Case)", size);
    }

    return 0;
}
