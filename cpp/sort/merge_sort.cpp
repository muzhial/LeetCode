#include <iostream>
#include <vector>
#include <string>

/*
 * in-place
 *
 * This maybe a naive in-place merge, it downgrades the
 * performance to O(N^2) not O(N*lg(N))
 *
 * so the SortBiSubArray method not the correct complement.
**/
template <typename T>
class Sort { 
public:
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::vector<T>::iterator iter;

    void MergeSortMain(std::vector<T>& arr)
    {
        if (arr.empty())
            std::cout << "The array is empty" << std::endl;
        else {
            auto first = arr.begin();
            auto last = arr.end();
            MergeSort(arr, first, last);
        }
    }

    void MergeSort(std::vector<T>& arr, iter first, iter last)
    {
        // the recursive return
        if (first + 1 == last) {
            return;
        }
        // the left branch start and end index of iterator
        auto l_first = first;
        // exclude end end iterator
        auto l_last = first + (last - first) / 2;
        MergeSort(arr, l_first, l_last);
        
        auto r_first = l_last;
        // exclude end iterator
        auto r_last = last;
        MergeSort(arr, r_first, r_last);
        // naive in-place
        // SortBiSubArray(arr, l_first, r_first, r_last);
        // not in-place
        NotSortBiSubArray(arr, l_first, r_first, r_last);
    }

    void SortBiSubArray(std::vector<T>& arr, iter first, iter mid, iter last)
    {
        /*
         * in-place
         * exclude the end of iterator
        **/
        iter i = first, j = mid;
        while (i != mid && j != last) {
            if (*i > *j) {
                T tmp = *j;
                for (iter k = mid; k != i; --k)
                    *k = *(k - 1);
                *i = tmp;
                ++i;
                ++mid;
                ++j;
            }
            else {
                ++i;
            }
        }
    }

    void NotSortBiSubArray(std::vector<T>& arr, iter first, iter mid, iter last)
    {
        /*
         * Not in-place
         * */
        std::vector<T> tmp_;
        iter i = first, j = mid;
        while (i != mid && j != last) {
            if (*i > *j) {
                tmp_.push_back(*j);
                ++j;
            }
            else {
                tmp_.push_back(*i);
                ++i;
            }
        }
        if (i == mid) {
            for (; j != last; ++j)
                tmp_.push_back(*j);
        }
        else {
            for (; i != mid; ++i)
                tmp_.push_back(*i);
        }
        for (size_type k = 0; k < tmp_.size() && first != last; k++) {
            *first = tmp_.at(k);
            ++first;
        }
    }
};


// ********* bellow is only merging 
// ********* operator on tow group sorted vector
void inplace_merge_subscript()
{
    /*
     * just test in-place merge
     * index not iterator
     */
    typedef typename std::vector<int>::size_type size_type;

    std::vector<int> v_i{1, 4, 9, 2, 3, 5, 10};
    size_type first = 0, mid = v_i.size() / 2, last = v_i.size() - 1;   
    size_type i = first, j = mid;
    // i index the left part of vector
    // j index the right part of vector
    while (i < mid && j <= last) {
        if (v_i[i] > v_i[j]) {
            int tmp = v_i[j];
            /*
             * CATION: if type is unsigned, be careful that
             *         negative converted to positive when minus
             * */
            for (size_type idx = mid; idx > i; idx--) {
                v_i.at(idx) = v_i.at(idx-1);
            }
            v_i[i] = tmp;
            i++;
            mid++;
            j++;
        }
        else {
            i++;
        }
    }
    
    for (auto &i : v_i)
        std::cout << " " << i;
    std::cout << std::endl;
}

void inplace_merge_iter()
{
    typedef typename std::vector<int>::iterator iter_t;

    std::vector<int> v_i{0, 2, 6, 1, 1, 2, 3, 9};
    iter_t first = v_i.begin();
    iter_t last = v_i.end();
    iter_t mid = first + 3;
    //iter_t mid = first + (last - first) / 2;
    iter_t i = first, j = mid;
    while (i != mid && j != last) {
        if (*i > *j) {
            int tmp = *j;
            for (iter_t k = mid; k != i; --k)
                *k = *(k - 1);
            *i = tmp;
            ++i;
            ++mid;
            ++j;
        }
        else {
            ++i;
        }
    }
    // output the result vector
    for (auto &i : v_i)
        std::cout << " " << i;
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v_i{8, 2, 3, 4, 0, 1, 2, 9, 1};
    std::cout << "e.g.";
    for (auto &c : v_i)
        std::cout << " " << c;
    std::cout << std::endl;

    Sort<int> sort;
    sort.MergeSortMain(v_i);
    for (auto &i : v_i)
        std::cout << " " << i;
    std::cout << std::endl;

    // std::cout << std::endl;
    // inplace_merge_subscript();
    // inplace_merge_iter();
    return 0;
}

