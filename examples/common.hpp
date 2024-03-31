#include <chrono>
#include <iostream>

#define BENCHMARK(f, msg) \
    { \
        const auto start = std::chrono::high_resolution_clock::now(); \
        f; \
        const auto end = std::chrono::high_resolution_clock::now(); \
        std::chrono::duration<double> elapsed = end - start; \
        std::cout << msg << elapsed.count() << "s\n"; \
    }
