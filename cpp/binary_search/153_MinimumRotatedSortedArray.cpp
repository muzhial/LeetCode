#include "../common.hpp"
using std::vector;

/***************
****************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            if (nums[l] <= nums[r]) {
                return nums[l];
            }
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else if (nums[mid] < nums[r]) {
                r = mid;
            } 
        }
        return nums[l];
    }
};
