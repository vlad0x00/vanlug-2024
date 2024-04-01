#include "../common.hpp"

#include <cmath>
#include <vector>
#include <iostream>

void f() {
    size_t num_elements = 1'000'000'000;
    std::vector<double> data(num_elements);

    // Initialize the array with some values
    for(size_t i = 0; i < num_elements; ++i) {
        data[i] = i * 0.001;
    }

    // Perform a computationally intensive operation and accumulate the results
    double sum = 0.0;
    for(size_t i = 0; i < num_elements; ++i) {
        data[i] = std::sin(data[i]);
        sum += data[i];
    }

    // Print the sum to introduce a side effect
    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    BENCHMARK(f(), "Execution time: ");

    return 0;
}
