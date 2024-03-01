#include <iostream>

template <class arg>
arg maksimum(arg n, arg m){
    return n>m ? n : m;
} 

int main(){
    std::cout<<maksimum(5,1)<<std::endl;
    std::cout<<maksimum(1.32,5.51)<<std::endl;
    return 0;
}