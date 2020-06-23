#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(r > 0 && nums[r] == nums[r-1]) r--;
        n = r;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= nums[n])
                l = mid+1;
            else
                r = mid;
        }
        return nums[l];
    }
};