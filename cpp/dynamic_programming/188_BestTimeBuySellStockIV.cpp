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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int max_k = k;
        if (n == 0) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int i = 0; i < n; ++i) {
            for (int j = max_k; j >= 1; --j) {
                if (i == 0) {
                    dp[0][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][max_k][0];
    }
};
