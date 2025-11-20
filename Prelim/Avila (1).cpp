#include <iostream>

int computeFibonacciRecursively(int number) {
    if (number <= 1) {
        return number;
    }
    return computeFibonacciRecursively(number - 1) + computeFibonacciRecursively(number - 2);
}

int computeFibonacciIteratively(int number) {
    if (number <= 1) {
        return number;
    }

    int first = 0, second = 1, sum;

    for (int i = 2; i <= number; ++i) {
        sum = first + second;
        first = second;
        second = sum;
    }

    return second;
}

int main() {
    int position;

       std::cout << "Enter a non-negative integer for the Fibonacci position: ";
    std::cin >> position;

       if (position < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer." << std::endl;
        return 1; // Exit with error code
    }

        std::cout << "Fibonacci number at position " << position << " (recursive): "
              << computeFibonacciRecursively(position) << std::endl;

    std::cout << "Fibonacci number at position " << position << " (non-recursive): "
              << computeFibonacciIteratively(position) << std::endl;

    return 0;
}