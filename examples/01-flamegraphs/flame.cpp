#include <chrono>
#include <thread>

void do_work(long work) {
    double sum = 0;
    for (long i = 0; i < work; i++) {
        for (long j = 0; j < work; j++) {
            sum += i * j / i / j;
        }
    }
}

void f1() {
    do_work(10000);
}

void f2() {
    f1();
    do_work(10000);
}

void f3() {
    f2();
    do_work(5000);
}

void f4() {
    do_work(10000);
}

void f5() {
    do_work(40000);
}

void f6() {
    f4();
    f5();
    do_work(10000);
}

int main() {
    f3();
    f6();
    return 0;
}
