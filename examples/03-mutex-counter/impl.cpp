#include <format>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void run_benchmark(const std::string &label,
                   std::function<void(int &, int)> func) {
  const int num_threads = 5;
  const int increments_per_thread = 100000;
  int counter = 0;

  std::vector<std::thread> threads;
  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back(func, std::ref(counter), increments_per_thread);
  }

  for (auto &t : threads) {
    t.join();
  }

  int expected_counter = num_threads * increments_per_thread;
  std::cout << std::format("[{}] Expected: {}, Got: {}\n", label,
                           expected_counter, counter);
}

int main() {
  run_benchmark("UNSAFE", [](int &counter, int times) {
    for (int i = 0; i < times; ++i) {
      ++counter;
    }
  });

  std::mutex mutex;
  run_benchmark("SAFE", [&mutex](int &counter, int times) {
    for (int i = 0; i < times; ++i) {
      std::lock_guard<std::mutex> lock(mutex);
      ++counter;
    }
  });

  return 0;
}
