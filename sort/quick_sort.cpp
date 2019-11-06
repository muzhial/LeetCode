#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void NaiveQuickSort(std::vector<T> &arr, std::vector<T> &res_arr)
{
    typedef typename std::vector<T>::iterator iter_t;
    if (arr.empty())    
        return;

    T pivot = arr[0];
    std::vector<T> l_sub_arr;
    std::vector<T> r_sub_arr;

    for (iter_t i = arr.begin()+1; i != arr.end(); ++i) {
        if (*i < pivot)
            l_sub_arr.push_back(*i);
        else
            r_sub_arr.push_back(*i);
    }

    NaiveQuickSort(l_sub_arr, res_arr);
    res_arr.push_back(pivot);

    NaiveQuickSort(r_sub_arr, res_arr);
    if (!r_sub_arr.empty()) {
        for (auto &k : r_sub_arr) {
            res_arr.push_back(k);
        }
    }

}

int main()
{
    std::vector<int> res;
    std::vector<int> v_i{9, 8, 1, 11, 2, 3, 7};
    NaiveQuickSort(v_i, res);

    return 0;
}
