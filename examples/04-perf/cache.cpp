#include "../common.hpp"

#include <cstdlib>

static constexpr size_t SIZE = 20'000;

int** make_array(size_t rows, size_t cols) {
    int** array = new int*[rows];
    for (size_t i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            array[i][j] = i + j;
        }
    }
    return array;
}

void read_by_row(int** array, size_t rows, size_t cols) {
    volatile int sum = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            sum += array[i][j];
        }
    }
}

void read_by_col(int** array, size_t rows, size_t cols) {
    volatile int sum = 0;
    for (size_t i = 0; i < cols; ++i) {
        for (size_t j = 0; j < rows; ++j) {
            sum += array[j][i];
        }
    }
}

int main() {
    int** array = make_array(SIZE, SIZE);

    // Warm up the cache
    // read_by_row(array, SIZE, SIZE);

    //BENCHMARK(read_by_row(array, SIZE, SIZE), "Read by row: ");

    // Warm up the cache
    // read_by_col(array, SIZE, SIZE);

    BENCHMARK(read_by_col(array, SIZE, SIZE), "Read by col: ");

    return 0;
}
