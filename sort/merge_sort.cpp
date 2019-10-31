#include <iostream>
#include <vector>
#include <string>

/*
 * in-place
**/
#include <iterator>

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
        // the recurrive return
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

        SortBiArray(arr, l_first, l_last, r_first, r_last);
    }

    void SortBiArray(std::vector<T>& arr,
            iter l_first, iter l_last,
            iter r_first, iter r_last)
    {
        /*
         * exclude the end of iterator
        **/
        std::cout << ">>>>>>>>>" << std::endl;
        std::cout << "(" << *l_first << " " << *(l_last-1) << ")" \
                  << "(" << *r_first << " " << *(r_last-1) << ")" \
                  << std::endl;
    }
};

void inplace_test()
{
    /*
     * just test in-place merge
     * index not iterator
     */
    typedef typename std::vector<int>::size_type size_type;

    std::vector<int> v_i{0, 0, 0, 0, 3, 5};
    size_type first = 0, mid = v_i.size() / 2, last = v_i.size() - 1;   
    size_type i = first, j = mid;
    // i index the left part of vector
    // j index the right part of vector
    while (i < mid && j <= last) {
        if (v_i[i] > v_i[j]) {
            int tmp = v_i[j];
            for (size_type idx=mid-1; idx>=i; idx--) {
                v_i[idx+1] = v_i[idx];
            }
            v_i[i] = tmp;
            i++;
            mid++;
        }
        else {
            i++;
        }
    }
    
    for (auto &i : v_i)
        std::cout << " " << i;
    std::cout << std::endl;
}

template <typename T>
void MergeSort(std::vector<T>& arr, )
{
    std::string a("null");
}

int main()
{
    std::vector<int> vi{0, 1, 2, 3};
    Sort<int> sort;
    sort.MergeSortMain(vi);

    std::cout << std::endl;
    inplace_test();
    return 0;
}


