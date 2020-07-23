#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // min
#include <limits>     // numeric_limits
#include <unordered_map>
using namespace std;
using std::vector;
using std::unordered_map;


int coinChange(vector<int>& coins, int amount) {
    // 也可以将 MAX_INT 赋给初始 dp
    vector<long long> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (long long i = 1; i <= dp.size(); ++i) {
        for (auto coin: coins) {
            if (i - coin < 0) {
                continue;
            }
            long long subproblem = dp[i - coin];
            dp[i] = std::min(subproblem + 1, dp[i]);
        }
    }
    return dp[amount] != amount + 1 ? dp[amount] : -1;
}

void test_longlong() {
    int a = 1;
    cout << (a << 31) << endl;
    long long i = (a << 30) * (a << 30);
    cout << i << endl;
    long long ii = (static_cast<long long>(a) << 30) * (a << 30);
    cout << ii << endl;
}

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

int main()
{
    int i = 1;
    cout << (i << 31) << endl;  // -2147483648
    // test_longlong();
    cout << static_cast<char>('a' + 2) << endl;
    return 0;
}
