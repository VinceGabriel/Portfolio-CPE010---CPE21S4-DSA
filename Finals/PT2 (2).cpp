#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>

std::mutex cout_mutex; 

void print(int n, const std::string &str) {
    std::string msg = std::to_string(n) + ". " + str;

    std::lock_guard<std::mutex> guard(cout_mutex);
    std::cout << msg << std::endl;
}

int main() {
    std::vector<std::string> s = {
        "T.I.P.",
        "Competent",
        "Computer",
        "Engineers"
    };

    std::vector<std::thread> threads;

    for (int i = 0; i < s.size(); i++) {
        threads.emplace_back(print, i, s[i]);
    }

    for (auto &th : threads) {
        th.join();
    }

    return 0;
}