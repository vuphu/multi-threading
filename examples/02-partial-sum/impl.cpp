#include <iostream>
#include <vector>
#include <future>

long long calculate_sum(int id, int start, int end) {
    long long sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += i;
    }
    std::cout << std::format("Thread {} finished range [{}, {}) with sum: {}\n", id, start, end, sum);
    return sum;
}

int main() {
    const int N = 100000;
    const int num_threads = 4;

    int chunk_size = N / num_threads;
    std::vector<std::future<long long>> tasks;

    for (int i = 0; i < num_threads; ++i) {
        int start = (i * chunk_size) + 1;
        int end = std::min((i + 1) * chunk_size, N);
        tasks.emplace_back(std::async(std::launch::async, calculate_sum, i, start, end));
    }

    long long total_sum = 0;
    for (auto &task: tasks) {
        total_sum += task.get();
    }

    std::cout << std::format("Result: {}\n", total_sum);

    return 0;
}
