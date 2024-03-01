#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
	vector<T> vect;

public:
	typedef T value_type;
	
	void push(const T &x) {
		vect.push_back(x);
	}
	
	T pop() {
		T x = vect.back();
		vect.pop_back();
		return x;
	}

	T top() {
		return vect.back();
	}

	bool empty() {
		return vect.size() == 0;
	}
};

template<typename T>
T sum(Stack<T> S){
    T result=T();
    while(!S.empty()){
        result+=S.pop();
    }
    return result;
}


int main(){
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(1);
    stack.push(1);
    stack.push(1);

    cout<<sum(stack);

        

}