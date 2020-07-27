#include "../common.hpp"
using std::vector;

/**
 * W = (sum + target) / 2
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum < S || (sum + S) % 2 != 0) {
            return 0;
        }
        int w = (sum + S) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        // base case
        for (int k = 0; k <= n; ++k) {
            if (k == 0) {
                dp[0][0] = 1;
                continue;
            }
            if (nums[k - 1] == 0) {
                dp[k][0] = 2 * dp[k - 1][0];
            } else {
                dp[k][0] = dp[k - 1][0];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= w; ++j) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][w];
    }
};

class SolutionI {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if ((sum + S) % 2 != 0 || sum < S) {
            return 0;
        }
        int w = (sum + S) / 2;
        int n = nums.size();

        vector<int> dp(w + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = w; j >= num; --j) {
                dp[j] = dp[j] + dp[j - num];
            }
        }
        return dp[w];
    }
};
