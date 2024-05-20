#include <vector>  
#include <algorithm>  
#include <execution>  
#include <mutex>  

int main() {  
    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output;
    std::mutex mtx;

    std::for_each(std::execution::par, vec.begin(), vec.end(), [&output, &mtx](int& elem) {
        if (elem % 2 == 0) {
            std::lock_guard<std::mutex> lock(mtx);
            output.push_back(elem);
        }
    });


}   