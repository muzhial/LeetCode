#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//     }
// };

int main() {
    vector<int> vi = {1, 2, 3, 4};
    vector<int> vii = {3, 4, 5, 6};
    std::swap(vi, vii);

    for (auto v : vii) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
