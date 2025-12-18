#include <format>
#include <iostream>
#include <vector>
#include <thread>

void greet(int id) {
    std::string message = std::format("Hello from thread {}\n", id);
    std::cout << message;
}

int main() {
    const int thread_count = 5;
    std::vector<std::thread> threads;

    for (int i = 0; i < thread_count; ++i) {
        threads.emplace_back(greet, i);
    }

    for (auto &t : threads) {
        t.join();
    }

    return 0;
}
