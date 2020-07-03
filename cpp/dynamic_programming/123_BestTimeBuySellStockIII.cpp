#include "../common.hpp"
using namespace std;
using std::vector;

/***************
 * [分析]
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
****************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        if (n == 0) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 1; --j) {
                if (i == 0) {
                    dp[0][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][k][0];
    }
};

// 状态压缩
class SolutionI {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        if (n == 0) return 0;
        int dp_10 = 0, dp_11 = std::numeric_limits<int>::min();
        int dp_20 = 0, dp_21 = std::numeric_limits<int>::min();
        for (int i = 0; i < n; ++i) {
            dp_20 = std::max(dp_20, dp_21 + prices[i]);
            dp_21 = std::max(dp_21, dp_10 - prices[i]);
            dp_10 = std::max(dp_10, dp_11 + prices[i]);
            dp_11 = std::max(dp_11, - prices[i]);
        }
        return dp_20;
    }
};
