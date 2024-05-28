#include <iostream>
#include <concepts>

template<std::integral T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 56;
    int b = 98;
    std::cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << std::endl;

    long c = 123456;
    long d = 789012;
    std::cout << "GCD of " << c << " and " << d << " is " << gcd(c, d) << std::endl;

    return 0;
}
