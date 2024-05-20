#include <algorithm>
#include <execution>
#include <vector>
#include <iostream>
#include <numeric>

int main() {
    std::vector<int> data(1000000);
    std::iota(data.begin(), data.end(), 1); 

    // Sekwencyjne wykonanie
    std::for_each(std::execution::seq, data.begin(), data.end(), [](int& n) {
        n *= 2;
    });

    // Równoległe wykonanie
    std::for_each(std::execution::par, data.begin(), data.end(), [](int& n) {
        n *= 2;
    });

    // Równoległe i niesekwencyjne wykonanie
    std::for_each(std::execution::par_unseq, data.begin(), data.end(), [](int& n) {
        n *= 2;
    });

    for (const auto& n : data) {
        if (n % 100000 == 0) {
            std::cout << n << " ";
        }
    }


    return 0;
}
