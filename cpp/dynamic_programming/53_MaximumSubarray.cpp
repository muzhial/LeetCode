#include "../common.hpp"
using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return std::numeric_limits<int>::min();
        }
        vector<int> dp(sz, 0);
        dp[0] = nums[0];
        int max_ = nums[0];
        for (int i = 1; i < sz; ++i) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            max_ = max_ > dp[i] ? max_ : dp[i];
        }
        return max_;
    }
};
