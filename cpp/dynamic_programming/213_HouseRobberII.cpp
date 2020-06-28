#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        return std::max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() - 1));
    }
    int helper(vector<int>& nums, int start, int end) {
        if (end - start == 0) {
            return nums[start];
        }
        int max_ = std::numeric_limits<int>::min();
        vector<int> dp(nums.size(), 0);
        dp[0] = 0;
        dp[1] = nums[start];
        for (int i = 2; i <= nums.size() - 1; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[start + i - 1]);
            max_ = std::max(max_, dp[i]);
        }
        return max_;
    }
};
