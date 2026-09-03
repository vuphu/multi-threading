# 03 - Mutex Counter

5 threads increment the same counter. Without protection → wrong result. With `std::mutex` → correct result.

## Key concepts

- `++counter` is actually 3 CPU steps: **read → add 1 → write**. Two threads can read the same value, both add 1, and one write overwrites the other. Increments get lost
- `std::mutex` — a lock. Only one thread can hold it at a time
- `std::lock_guard<std::mutex>` — locks on creation, unlocks automatically when it goes out of scope
