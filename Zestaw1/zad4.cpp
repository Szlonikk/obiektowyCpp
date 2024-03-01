#include <iostream>
using namespace std;

template <template <int N> class T, int K>
void function(T<K> t) {
	cout << K << endl;
}

template <int N>
class X {};

int main() {
	function(X<7>());
	function(X<15>());
	function(X<-3>());
}