// -O3 -std=c++20 -ffast-math

// constexpr int ackermann(int m, int n) {
//     if (m == 0) {
//         return n + 1;
//     } else if (n == 0) {
//         return ackermann(m - 1, 1);
//     } else {
//         return ackermann(m - 1, ackermann(m, n - 1));
//     }
// }

// static int f(int n) {
//     return n + 1;
// }

int main(int argc, char** argv) {
    double a = argc;
    // b = a * a;
    // c = b * b;
    // return c * c;
    return a * a * a * a * a * a * a * a;
}
