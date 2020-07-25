#include "../common.hpp"
using std::vector;

/***************
****************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target > nums[mid] && (nums[mid] >= nums[0] || target < nums[0])) {
                l = mid + 1;
            } else if (target > nums[mid] && nums[mid] < nums[0]) {
                r = mid - 1;
            } else if (target < nums[mid] && (target >= nums[0] || nums[mid] < nums[0])) {
                r = mid - 1;
            } else if (target < nums[mid] && nums[mid] >= nums[0]) {
                l = mid + 1;
            }
            else if (target == nums[mid]) {
                return mid;
            }
        }
        return -1;
    }
};