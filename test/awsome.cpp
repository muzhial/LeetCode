#include<iostream>
#include<vector>
#include<stack>
#include <limits>

class Base {
public:
    Base() {
        std::cout << "Default constructor" << std::endl;
    }
    Base(int cnt, int len): cnt_(cnt), len_(len) {
        std::cout << "Constructor with param" << std::endl;
    }
    Base(const Base& orig): cnt_(orig.cnt_), len_(orig.len_) {
        std::cout << "Copy constructor" << std::endl;
    }
    Base& operator=(const Base& rhs) {
        cnt_ = rhs.cnt_;
        len_ = rhs.len_;
        std::cout << "Copy-assignment constructor" << std::endl;

        return *this;
    }
    ~Base() {};
private:
    int cnt_;
    int len_;
};

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

int main() {
    // Base b = {1, 2};
    // Base b1;
    // b1 = b;

    return 0;
}