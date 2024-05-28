#include <iostream>
#include <compare>
#include <concepts>

template<std::three_way_comparable T>
void compare(const T& a, const T& b) {
    auto result = a <=> b;
    if (result < 0) {
        std::cout << a << " is less than " << b << std::endl;
    } else if (result > 0) {
        std::cout << a << " is greater than " << b << std::endl;
    } else {
        std::cout << a << " is equal to " << b << std::endl;
    }
}

int main() {
    int x = 5;
    int y = 10;

    compare(x, y); 
    compare(y, x); 
    compare(x, x); 

    std::string str1 = "apple";
    std::string str2 = "banana";

    compare(str1, str2);
    compare(str2, str1); 
    compare(str1, str1); 


    return 0;
}
