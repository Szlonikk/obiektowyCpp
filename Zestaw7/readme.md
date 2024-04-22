
Zestaw nr 7

1. Napisz szablon funkcji lub klasy wyliczający funkcję silnia.

2. Zaimplementuj szablon Pow<N,M> obliczający N^M.

3. Wymyśl i zaimplementuj jako metaprogram szybszy algorytm funkcji pow(x).

4. Napisz szablon generujący pierwsze N wyrazów rozwinięcia funkcji sin(x).

5. Napisz szablon generujący funkcję implementującą iloczyn skalarny dwu wektorów.

template<size_t N> double inner(double *x, double *y);

6. Rozszerz powyższy szablon tak, aby również typ elementów wektora był parametrem szablonu:

template<size_t N, typename T> T dot(T *x, T *y);