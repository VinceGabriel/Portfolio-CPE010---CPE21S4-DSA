
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

void selectionSort(int data[], int length) {
    for (int start = 0; start < length - 1; start++) {
        int pos = start;

        for (int k = start + 1; k < length; k++) {
            if (data[k] < data[pos]) {
                pos = k;
            }
        }

        if (pos != start) {
            int temp = data[start];
            data[start] = data[pos];
            data[pos] = temp;
        }
    }
}

#endif 