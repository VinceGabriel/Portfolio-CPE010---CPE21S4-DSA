#include <iostream>
using namespace std;

class BasicQueue {
private:
    int* elements;
    int maxLength;
    int start;
    int end;
    int count;

public:
    BasicQueue(int limit) {
        maxLength = limit;
        elements = new int[maxLength];
        start = 0;
        end = -1;
        count = 0;
    }

    ~BasicQueue() {
        delete[] elements;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == maxLength;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        end = (end + 1) % maxLength;
        elements[end] = item;
        count++;
        cout << "Enqueued: " << item << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Dequeued: " << elements[start] << endl;
        start = (start + 1) % maxLength;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << elements[(start + i) % maxLength] << " ";
        }
        cout << endl;
    }
};

int main() {
    BasicQueue queue(5);

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.display();

    queue.dequeue();
    queue.display();

    queue.enqueue(20);
    queue.display();

    return 0;
}