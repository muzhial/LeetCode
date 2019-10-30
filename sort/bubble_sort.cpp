#include <vector>
#include <iostream>

/*
 * in-place
**/
template<typename T>
const std::vector<T>& BubbleSort(std::vector<T>& arr)
{
    for (decltype(arr.size()) i=arr.size()-1; i > 0; i--) {
        for (decltype(arr.size()) j=0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                T tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    return arr;
}

int main()
{
    std::vector<int> sort_arr{6, 5, 3, 7, 8, 1, 4, 2};
    const std::vector<int> res = BubbleSort<int>(sort_arr);
    for (auto i=res.begin(); i!=res.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}