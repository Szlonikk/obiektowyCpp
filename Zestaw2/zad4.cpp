#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class SequenceGen {
    int current;
public:
    SequenceGen(int start = 1) : current(start - 2) {} 
    int operator()() { 
        current += 2; 
        return current;
    }
};

int main() {
    std::vector<int> vec(20);
    SequenceGen generator; // Generator liczb nieparzystych

    std::generate_n(vec.begin(), 20, generator);

    std::cout << "Wygenerowane liczby nieparzyste: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    auto it = std::find_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 4));

    if (it != vec.end()) {
        std::cout << "Pierwszy element większy od 4: " << *it << "\n";
    } else {
        std::cout << "Nie znaleziono elementu większego od 4.\n";
    }

    return 0;
}
