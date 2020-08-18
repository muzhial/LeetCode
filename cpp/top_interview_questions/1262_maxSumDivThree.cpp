#include "../common.hpp"
using std::vector;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = std::numeric_limits<int>::min();
        dp[0][2] = std::numeric_limits<int>::min();

        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] % 3 == 0) {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][0] + nums[i - 1]);
                dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][1] + nums[i - 1]);
                dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][2] + nums[i - 1]);
            } else if (nums[i - 1] % 3 == 1) {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] + nums[i - 1]);
                dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + nums[i - 1]);
                dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + nums[i - 1]);
            } else if (nums[i - 1] % 3 == 2) {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + nums[i - 1]);
                dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][2] + nums[i - 1]);
                dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][0] + nums[i - 1]);
            }
        }
        return dp[n][0];
    }
};