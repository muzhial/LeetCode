#include "../common.hpp"
using namespace std;
using std::vector;

/***************
 * [分析]
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i] - fee)
 * ==>
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
****************/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        int dp_i_0 = 0;
        int dp_i_1 = std::numeric_limits<int>::min();
        for (int i = 0; i < n; ++i) {
            int tmp = dp_i_0;
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = std::max(dp_i_1, tmp - prices[i] - fee);
        }
        return dp_i_0;
    }
};
