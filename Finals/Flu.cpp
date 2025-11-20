#include "Flu.h"
#include <iostream>
int main() {
    auto p = generate_random_Student(1000);

    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);

    return 0;
}
