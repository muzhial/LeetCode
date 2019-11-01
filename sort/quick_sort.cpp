#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void NaiveQuickSort(std::vector<T> &arr)
{
    typedef typename std::vector<T>::iterator iter_t;
    if (arr.size() == 1 || arr.empty())    
        return;

    T pivot = arr[0];
    std::vector<T> l_sub_arr;
    std::vector<T> r_sub_arr;

    for (iter_t i = arr.begin()+1; i != arr.end(); ++i) {
        if (*i < pivot)
            l_sub_arr.push_back(*i)
        else
            r_sub_arr.push_back(*i);
    }

    NaiveQuickSort(l_sub_arr);
    l_sub_arr.push_back(pivot);

    NaiveQuickSort(r_sub_arr);
    if (!r_sub_arr.empty()) {
        for (auto &k : r_sub_arr) {
            l_sub_arr.push_back(k)
        }
    }

}

int main()
{
    return 0;
}
