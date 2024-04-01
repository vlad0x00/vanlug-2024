#include "../common.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <random>

void read_sequentially(int fd) {
    constexpr size_t BUFFER_SIZE = 4096 * 4;
    char buffer[BUFFER_SIZE];

    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {}
    if (bytes_read == -1) {
        std::cerr << "Read error\n";
        std::exit(-1);
    }
}

void read_randomly(int fd, size_t file_size) {
    constexpr size_t BUFFER_SIZE = 64;
    char buffer[BUFFER_SIZE];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long> dis(0, file_size / BUFFER_SIZE);
    for (long i = 0; i < file_size / BUFFER_SIZE / 2048; ++i) {
        const auto pos = dis(gen) * BUFFER_SIZE;
        lseek(fd, pos, SEEK_SET);

        ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            std::cerr << "Read error\n";
            std::exit(-1);
        }
    }
}

int open_file(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        std::cerr << "Error opening file\n";
        std::exit(-1);
    }
    return fd;
}

int main() {
    auto fd = open_file("large_file");
    const auto file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    //posix_fadvise(fd, 0, 0, POSIX_FADV_SEQUENTIAL); std::cerr << "Advise sequential\n";
    posix_fadvise(fd, 0, 0, POSIX_FADV_RANDOM); std::cerr << "Advise random\n";
    
    //BENCHMARK(read_sequentially(fd), "Read sequential: ");
    BENCHMARK(read_randomly(fd, file_size), "Read random: ");

    close(fd);

    return 0;
}
