#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[l]) {
                l = mid + 1;
            } else if (nums[mid] < nums[r]) {
                r = mid - 1;
            } 
        }
        return nums[l];
    }
};
