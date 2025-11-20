#include <iostream>
#include "insertion_sort.h"

using namespace std;

int main() {
    int data[5] = {20, 10, 50, 30, 40};
    int length = 5;

    insertionSort(data, length);

    for (int x = 0; x < length; x++) {
        cout << data[x] << " ";
    }

    return 0;
}