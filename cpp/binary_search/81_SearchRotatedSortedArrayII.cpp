#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        int sz = nums.size() - 1;
        while (sz > 0 && nums[0] == nums[sz]) sz--;
        int l = 0;
        int r = sz;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target < nums[mid] && (target >= nums[0] || nums[mid] < nums[0])) {
                r = mid - 1;
            } else if (target < nums[mid] && (nums[mid] >= nums[0])) {
                l = mid + 1;
            } else if (target > nums[mid] && (nums[mid] >= nums[0] || target < nums[0])) {
                l = mid + 1;
            } else if (target > nums[mid] && nums[mid] < nums[0]) {
                r = r - 1;
            } else if (target == nums[mid]) {
                return true;
            }
        }
        return false;
    }
};
