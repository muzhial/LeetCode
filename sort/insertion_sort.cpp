#include <iostream>
#include <vector>


template <typename T>
void InsertionSort(std::vector<T>& arr)
{
    typedef typename std::vector<T>::size_type size_type;

    if (arr.empty())
        std::cout << "Array is empty" << std::endl;
    else {
        for (size_type i=1; i < arr.size(); i++) {
            size_type index = i;
            T tmp = arr[i];
            while (index > 0 && arr[index-1] > tmp) {
                arr[index] = arr[index-1];
                index--;
            }
            arr[index] = tmp;
        }
    }
}

int main()
{
    std::vector<double> sort_arr{6.3, 5.9, 3.6, 7.9, 8.0, 1.3, 4.0, 2};
    InsertionSort<double>(sort_arr);
    for (auto i=sort_arr.begin(); i!=sort_arr.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
