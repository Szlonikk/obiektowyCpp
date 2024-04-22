#include <iostream>

template <unsigned int n>
struct Factorial {
    static const unsigned int value = n * Factorial<n - 1>::value;
};

template <>
struct Factorial<0> {
    static const unsigned int value = 1;
};

int main() {
    std::cout << Factorial<5>::value << std::endl;  // Wynik: 120
    std::cout << Factorial<10>::value << std::endl;  // Wynik: 3628800
    return 0;
}
