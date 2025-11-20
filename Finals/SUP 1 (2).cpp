#include <iostream>
#include <thread>

int totalValue = 0;

void increase(int num) {
    totalValue += num;
}

int main() {
    std::thread threadA(increase, 10);
    std::thread threadB(increase, 20);
    std::thread threadC(increase, 30);

    std::cout << "Before any join, totalValue = " << totalValue << std::endl;

    threadA.join();
    std::cout << "After threadA.join(), totalValue = " << totalValue << std::endl;

    threadB.join();
    std::cout << "After threadB.join(), totalValue = " << totalValue << std::endl;

    threadC.join();
    std::cout << "After threadC.join(), totalValue = " << totalValue << std::endl;

    return 0;
}