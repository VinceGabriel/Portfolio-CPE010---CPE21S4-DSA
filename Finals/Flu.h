#ifndef FLU_H
#define FLU_H

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cmath>

class Student {
private:
    std::pair<int, int> name;
    bool vaccinated;

public:
    Student(std::pair<int, int> n, bool v) : name(n), vaccinated(v) {}

    std::pair<int, int> get_name() const { return name; }
    bool is_vaccinated() const { return vaccinated; }

    bool operator==(const Student& p) const { return this->name == p.name; }
    bool operator<(const Student& p) const { return this->name < p.name; }
    bool operator>(const Student& p) const { return this->name > p.name; }
};

Student generate_random_Student(int max) {
    static std::random_device rd;
    static std::mt19937 rand(rd());
    std::uniform_int_distribution<> uniform_dist(1, max);

    auto random_name = std::make_pair(uniform_dist(rand), uniform_dist(rand));
    bool is_vaccinated = uniform_dist(rand) % 2 == 1;
    return Student(random_name, is_vaccinated);
}

bool needs_vaccination(const Student& P, const std::vector<Student>& people) {
    int left = 0;
    int right = static_cast<int>(people.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        const Student& mid_student = people[mid];

        if (mid_student == P)
            return !mid_student.is_vaccinated();
        else if (mid_student < P)
            left = mid + 1;
        else
            right = mid - 1;
    }

    // Student not found
    return true;
}

void search_test(int size, const Student& p) {
    std::vector<Student> people;
    people.reserve(size);

    for (int i = 0; i < size; ++i)
        people.push_back(generate_random_Student(size));

    std::sort(people.begin(), people.end());

    auto begin = std::chrono::steady_clock::now();
    bool search_result = needs_vaccination(p, people);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Time taken to search = "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
              << " nanoseconds" << std::endl;

    std::cout << "Student (" << p.get_name().first << " " << p.get_name().second << ") "
              << (search_result ? "needs vaccination." : "does not need vaccination.") << std::endl;
}

#endif
