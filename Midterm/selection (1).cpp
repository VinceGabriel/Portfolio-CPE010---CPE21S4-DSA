#include <iostream>
using namespace std;

int main() {
    int data[5] = {20, 10, 50, 30, 40};
    int length = 5;

    for(int start = 0; start < length - 1; start++) {
        int pos = start;

        for(int k = start + 1; k < length; k++) {
            if(data[k] < data[pos]) {
                pos = k;
            }
        }
        if(pos != start) {
            int temp = data[start];
            data[start] = data[pos];
            data[pos] = temp;
        }
    }

    for(int x = 0; x < length; x++) {
        cout << data[x] << " ";
    }
    return 0;
}