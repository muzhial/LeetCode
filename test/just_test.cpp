#include "test.hpp"

using std::cout; using std::endl;
using std::vector;

void Merge(vector<int>& arr, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            i++;
        } else {
            for (int k = j; k > i; k--) {
                std::swap(arr[k], arr[k - 1]);
            }
            i++;
            m++;
            j++;
        }
    }
}
// MergeSort(arr, 0, arr.size() - 1);
void MergeSort(vector<int>& arr, int l, int u) {
    if (l >= u) {
        return;
    }
    int m = l + (u - l) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, u);
    Merge(arr, l, m, u);
}

int main() {
    vector<int> arr = {-1, -12};
    // Merge(arr, 0, 3, arr.size() - 1);
    MergeSort(arr, 0, arr.size() - 1);
    PrintVector(arr);
}