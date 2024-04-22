#include <iostream>

template <size_t N>
double inner(double *x, double *y) {
    return *x * *y + inner<N - 1>(x + 1, y + 1);
}

template <>
double inner<0>(double *x, double *y) {
    return 0;
}

int main() {
    double x[] = {1.0, 2.0, 3.0};
    double y[] = {4.0, 5.0, 6.0};
    std::cout << "Suma: " << inner<3>(x, y) << std::endl;  // Wywołanie dla N = 3
    return 0;
}
