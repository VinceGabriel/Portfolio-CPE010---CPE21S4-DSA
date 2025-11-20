#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> heroQueue;
    std::string heroList[] = {"Pau", "Alexcy", "Rose Ann", "Nievelyn"};

    // Enqueue heroes
    for (auto& hero : heroList) {
        std::cout << "Enqueue: " << hero << std::endl;
        heroQueue.push(hero);
    }

    // Display queue content
    std::cout << "Queue after enqueues: ";
    std::queue<std::string> copyQueue = heroQueue;
    while (!copyQueue.empty()) {
        std::cout << copyQueue.front() << " ";
        copyQueue.pop();
    }
    std::cout << "\n";

    // Dequeue heroes
    while (!heroQueue.empty()) {
        std::cout << "Dequeue: " << heroQueue.front() << std::endl;
        heroQueue.pop();
    }

    return 0;
}