#1. Opisz wykorzystując funkcjonalne przykłady występujące w C++17 execution policy  :  

std::execution::sequenced_policy,  std::execution::parallel_policy  

std::execution::parallel_unsequenced_policy,  

#2. Wykonanie bardzo prostego programu:  

#include <vector>  

#include <algorithm>  

#include <execution>  

#include <mutex>  

  

int main() {  

  std::vector<int> vec(10'000'000);   std::iota(vec.begin(), vec.end(), 0);   std::vector<int> output;   std::for_each(std::execution::par, vec.begin(), vec.end(),  

  [&output](int& elem) {       if (elem % 2 == 0) {           output.push_back(elem);  

      }  

  });  

}  

  

zakończy się tragicznie z punktu widzenia programisty (core dupmed).  Wykorzystując std::lock_guard zmodyfikuj lambda expression tak aby nie dochodziło do niezsynchronizowanego dostępu do wektora wyjściowego. Porównaj wydajność przy wykorzystaniu polityki typu seq.  

  

#3. Wybierz z listy algorytmów:  

  

adjacent_difference inplace_merge 	replace_copy  

adjacent_find  

is_heap 	replace_copy_if  

all_of  

is_heap_until 	replace_if  

any_of  

is_partitioned 	reverse  

copy  

is_sorted 	reverse_copy  

copy_if  

is_sorted 	rotate  

copy_n  

is_sorted_until 	rotate_copy  

count  

lexicographical_compare search  

count_if  

max_element 	search_n  

equal  

merge 	set_difference  

exclusive_scan  

min_element 	set_intersection  

fill  

minmax_element 	set_symmetric_difference  

fill_n  

mismatch  

set_union  

find  

move  

sort  

find_end  

none_of  

stable_partition  

find_first_of  

nth_element  

stable_sort  

find_if  

partial_sort  

swap_ranges  

find_if_not  

partial_sort_copy  

transform  

for_each  

partition  

transform_exclusive_scan  

for_each_n  

partition_copy  

transform_inclusive_scan  

generate  

remove  

transform_reduce  

generate_n  

remove_copy  

uninitialized_copy  

includes  

remove_copy_if  

uninitialized_copy_n  

inclusive_scan  

remove_if  

uninitialized_fill  

inner_product  

replace  

uninitialized_fill_n  

   

unique  

unique_copy  

  

  

pięć różnych algorytmów i przedstaw przykład wykorzystania, w którym równoległe obliczenia przyśpieszą obliczenia proporcjonalnie do ilości występujących w procesorze rdzeni.  

  

  

#4. Niektóre z tych algorytmów są nowe   

std::for_each_n  

 std::exclusive_scan std::inclusive_scan  

 std::transform_exclusive_scan std::transform_inclusive_scan  

 std::parallel::reduce std::parallel::transform_reduce  

ósmy algorytm std::for_each różni się i też uważamy go za nowy, ponieważ oprócz dodatkowej polityki wykonywania teraz zwracanym typem jest void…. Przygotuj na podstawie dokumentacji (https://en.cppreference.com/w/cpp/experimental/parallelism) przykłady wykorzystania tych algorytmów. W przypadku reduce wykorzystaj alfa expression ( [](auto fir, auto sec){ return fir + ":" + sec; }); ) do zdefiniowania BinaryOp w celu dodawania stringów