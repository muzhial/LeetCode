#include <iostream>
#include <vector>


/*
 * inplace
**/
template<typename T>
void SelectionSort(std::vector<T>& arr)
{
    typedef typename std::vector<T>::size_type size_type;
    if (arr.empty())
        std::cout << "The sorting array is empty" << std::endl;
    else {
        for (size_type i=0; i < arr.size() - 1; i++) {
            size_type min_idx = i;
            for (size_type j=i+1; j < arr.size(); j++) {
                if (arr[min_idx] > arr[j]) {
                    min_idx = j;
                }
            }
            if (i != min_idx) {
                T tmp = arr[i];
                arr[i] = arr[min_idx];
                arr[min_idx] = tmp;
            }
        }
    }
}

int main()
{
    std::vector<double> sort_arr{6.3, 5.9, 3.6, 7.9, 8.0, 1.3, 4.0, 2};
    SelectionSort<double>(sort_arr);
    for (auto i=sort_arr.begin(); i!=sort_arr.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}