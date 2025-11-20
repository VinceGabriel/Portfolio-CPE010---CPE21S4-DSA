#include <iostream>
#include <vector>
#include <thread>

void combine(std::vector<int>& data, int begin, int midPoint, int end) {
    int leftSize = midPoint - begin + 1;
    int rightSize = end - midPoint;

    std::vector<int> leftPart(leftSize), rightPart(rightSize);

    for (int a = 0; a < leftSize; a++)
        leftPart[a] = data[begin + a];
    for (int b = 0; b < rightSize; b++)
        rightPart[b] = data[midPoint + 1 + b];

    int i = 0, j = 0, k = begin;
    while (i < leftSize && j < rightSize) {
        if (leftPart[i] <= rightPart[j]) {
            data[k] = leftPart[i];
            i++;
        } else {
            data[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        data[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        data[k] = rightPart[j];
        j++;
        k++;
    }
}

void threadedMergeSort(std::vector<int>& data, int begin, int end) {
    if (begin < end) {
        int midPoint = begin + (end - begin) / 2;

        std::thread worker1(threadedMergeSort, std::ref(data), begin, midPoint);
        std::thread worker2(threadedMergeSort, std::ref(data), midPoint + 1, end);

        worker1.join();
        worker2.join();

        combine(data, begin, midPoint, end);
    }
}

int main() {
    std::vector<int> numbers = {12, 11, 13, 5, 6, 7};

    std::cout << "Unsorted list: ";
    for (int n : numbers)
        std::cout << n << " ";
    std::cout << std::endl;

    threadedMergeSort(numbers, 0, numbers.size() - 1);

    std::cout << "Sorted list: ";
    for (int n : numbers)
        std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}