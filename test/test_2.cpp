#include <vector>
#include <iostream>
#include <utility>
using std::vector;

void qsort(vector<int> &arr, vector<int>::iterator l, vector<int>::iterator u)
{
    if (l == u)
        return;
    vector<int>::iterator m = l;
    for (auto i = l + 1; i != u; ++i) {
        if (*i < *l) {
            ++m;
            if (m != i) {
                int tmp = *m;
                *m = *i;
                *i = tmp;
            }
        }
    }
    int tmp_ = *l;
    *l = *m;
    *m = tmp_;
    qsort(arr, l, m);
    qsort(arr, m+1, u);
}
vector<int> solution(vector<int>& arr) {
    int k = 4;
    vector<int> ret;
    qsort(arr, arr.begin(), arr.end());
    
    for (int i = 0; i < k; ++i) {
        ret.push_back(arr[i]);
    }
    return ret;
}

int main() {
    vector<int> v = {-1, 2, 2, 6, 7, 2, -1, 67, 3, -9, 76};
    QsortIn(v, 0, v.size() - 1);
    for (auto r : v) {
        std::cout << r << " ";
    }
    std::cout << std::endl;
}