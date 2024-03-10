#include <iostream>

// Polimorfizm statyczny - przeciążenie funkcji
class PrintData {
public:
    void print(int i) {
        std::cout << "Printing int: " << i << std::endl;
    }
    void print(double f) {
        std::cout << "Printing float: " << f << std::endl;
    }
    void print(char* c) {
        std::cout << "Printing character: " << c << std::endl;
    }
};

// Polimorfizm dynamiczny - wirtualne funkcje
class Ptak {
public:
    virtual void sound() = 0; 
};

class Bociek : public Ptak {
public:
    void sound() override {
        std::cout << "Kle Kle" << std::endl;
    }
};

class Sowa : public Ptak {
public:
    void sound() override {
        std::cout << "Hu hu" << std::endl;
    }
};

int main() {
    PrintData pd;

    // Demonstracja polimorfizmu statycznego
    pd.print(5);
    pd.print(500.263);
    char c[] = "Hello C++";
    pd.print(c);

    // Demonstracja polimorfizmu dynamicznego
    Ptak* ptak;
    Bociek Dzony;
    Sowa Palony;

    ptak = &Dzony;
    ptak->sound(); // Wywołuje Circle::draw()

    ptak = &Palony;
    ptak->sound(); // Wywołuje Square::draw()

    return 0;
}
