#include "../common.hpp"
using std::vector;

/**
 * [分析]
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        // 不加这段，如果 k 太大将导致 dp 太大超内存
        if (k > n / 2) {
            return MaxprofitInf(prices);
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int i = 0; i < n; ++i) {
            // This is also right
            // for (int j = 1; j <= k; ++j) {
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
    int MaxprofitInf(vector<int>& prices) {
        int maxprof = 0;
        int minprice = std::numeric_limits<int>::max();
        for (auto& p : prices) {
            if (p <= minprice) {
                minprice = p;
            } else {
                maxprof += (p - minprice);
                minprice = p;
            }
        }
        return maxprof;
    }
};
