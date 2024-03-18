#include <iostream>
#include <set>
#include <functional>

int main() {

    std::set<int, std::greater<>> reverseSortedSet;

    reverseSortedSet.insert(10);
    reverseSortedSet.insert(5);
    reverseSortedSet.insert(20);
    reverseSortedSet.insert(15);

    std::cout << "Zbiór liczb posortowany odwrotnie: ";
    for (int element : reverseSortedSet) {
        std::cout << element << " ";
    }

    return 0;
}
