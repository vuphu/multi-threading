# 01 - Greeting

Create 5 threads, each prints "Hello" with its number.

## Key concepts

- `std::thread(func, args)` — start a new thread
- `.join()` — wait for the thread to finish
- Output order is random because threads run at the same time
