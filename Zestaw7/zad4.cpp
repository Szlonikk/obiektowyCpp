#include <iostream>
#include <cmath> // Dla wartości M_PI i pow()

// Obliczanie silni
template <unsigned int n>
struct Factorial {
    static const unsigned long long value = n * Factorial<n - 1>::value;
};

template <>
struct Factorial<0> {
    static const unsigned long long value = 1;
};

// Obliczanie pojedynczego wyrazu szeregu Taylora dla sin(x)
template <int n, double x>
struct SinTerm {
    static const double value = (n % 2 == 0 ? 1 : -1) * pow(x, 2 * n + 1) / Factorial<2 * n + 1>::value;
};

// Obliczanie sumy N wyrazów szeregu dla sin(x)
template <int N, double x, int current = 0>
struct SinSeries {
    static const double value = SinTerm<current, x>::value + SinSeries<N, x, current + 1>::value;
};

template <int N, double x>
struct SinSeries<N, x, N> {
    static const double value = 0;
};

int main() {
    const double x = M_PI / 3; // x = π/3
    std::cout << "Sin(" << x << ") approximated by series: " << SinSeries<10, x>::value << std::endl;
    std::cout << "Exact Sin(" << x << "): " << sin(x) << std::endl;
    return 0;
}
