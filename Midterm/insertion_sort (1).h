#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H


void insertionSort(int data[], int length) {
    for (int pos = 1; pos < length; pos++) {
        int value = data[pos];
        int k = pos;

        while (k > 0 && data[k - 1] > value) {
            data[k] = data[k - 1];
            k--;
        }
        data[k] = value;
    }
}

#endif // INSERTION_SORT_H