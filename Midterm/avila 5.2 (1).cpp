#include <iostream>
using namespace std;

class LoopQueue {
private:
    int* buffer;      // queue array
    int maxSize;      // total capacity
    int head;         // front index
    int tail;         // rear index
    int itemCount;    // current number of items

public:
    LoopQueue(int limit) {
        maxSize = limit;
        buffer = new int[maxSize];
        head = 0;
        tail = maxSize - 1;
        itemCount = 0;
    }

    ~LoopQueue() {
        delete[] buffer;
    }

    bool isEmpty() {
        return itemCount == 0;
    }

    bool isFull() {
        return itemCount == maxSize;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full! " << data << endl;
            return;
        }
        tail = (tail + 1) % maxSize;
        buffer[tail] = data;
        itemCount++;
        cout << "Enqueued: " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! " << endl;
            return;
        }
        cout << "Dequeued: " << buffer[head] << endl;
        head = (head + 1) % maxSize;
        itemCount--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue contents: ";
        for (int i = 0; i < itemCount; i++) {
            cout << buffer[(head + i) % maxSize] << " ";
        }
        cout << endl;
    }
};

int main() {
    LoopQueue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.display();

    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70); 
    queue.display();

    return 0;
}