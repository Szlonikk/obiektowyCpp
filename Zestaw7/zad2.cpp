#include <iostream>

template <int N, int M>
struct Pow {
    static const int value = N * Pow<N, M - 1>::value;
};

template <int N>
struct Pow<N, 0> {
    static const int value = 1;
};

int main() {
    std::cout << "3^4 = " << Pow<3, 4>::value << std::endl;  // Wynik: 81
    std::cout << "2^10 = " << Pow<2, 10>::value << std::endl;  // Wynik: 1024
    return 0;
}
