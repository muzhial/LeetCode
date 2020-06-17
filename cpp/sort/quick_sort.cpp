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
    //if (!r_sub_arr.empty()) {
    //    for (auto &k : r_sub_arr) {
    //        res_arr.push_back(k);
    //    }
    //}
}


template <typename T>
void InplaceQuickSort(std::vector<T> &arr, typename std::vector<T>::iterator l, typename std::vector<T>::iterator u)
{
    if (l == u)
        return;

    typename std::vector<T>::iterator m = l;
    for (auto i = l + 1; i != u; ++i) {
        if (*i < *l) {
            ++m;
            if (m != i) {
                T tmp = *m;
                *m = *i;
                *i = tmp;
            }
        }
    }
    T tmp_ = *l;
    *l = *m;
    *m = tmp_;

    InplaceQuickSort(arr, l, m);
    InplaceQuickSort(arr, m+1, u);
}

int main()
{
    std::vector<int> res;
    // std::vector<int> v_i{6, 5, 3, 1, 8, 7, 2, 4};
    std::vector<int> v_i{2, 1, 2};
    // NaiveQuickSort(v_i, res);
    // for (auto &i : res)
    //     std::cout << i << " ";
    // std::cout << std::endl;
    
    auto l = v_i.begin();
    auto u = v_i.end();
    InplaceQuickSort(v_i, l, u);
    for (auto &i : v_i)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
