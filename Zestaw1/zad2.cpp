#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U>
T convert(U u) {
	try	{
		return static_cast<T>(u);
	} catch (const exception &e) {
		cerr << "Error: " << e.what() << endl;
		return T();
	}
}

template<typename U>
std::string convert(U u) {
    return std::to_string(u);
}


int main() {
	cout << convert<double,int>(5) << endl;
	cout << convert<int,double>(21.37) << endl;
    cout << convert<>(13.37) +"xd"<< endl;

}