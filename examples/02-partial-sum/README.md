# 02 - Partial Sum

Add numbers 1 to 100,000 by splitting the work across 4 threads.

## Key concepts

- `std::async(std::launch::async, func, args)` — start a thread that **returns a value**
- `future.get()` — wait for the thread and get its result
- Always use `std::launch::async` to ensure a real thread is created
