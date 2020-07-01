#include "../common.hpp"
using namespace std;
using std::vector;

/***************
* [desc]
* N = 3, W = 4
* wt = [2, 1, 3]
* val = [4, 2, 3]
* [分析]
* 0 1 背包问题，关键在于状态转移与选择的列出，二维动归问题。
* 定义 dp[n][w] 前 n 个中取且背包容量为 w 时的最大值。
****************/
class Solution {
public:
    int Knapsack01(int W, int N, vector<int>& wt, vector<int>& val) {
        // base case: dp[0, ...] = 0
        // and dp[..., 0] = 0 
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
        for (int n = 1; n < N + 1; ++n) {
            for (int w = 1; w < W + 1; ++w) {
                int w_idx = w - wt[n-1];
                if (w_idx < 0) {
                    dp[n][w] = dp[n-1][w];
                } else {
                    dp[n][w] = std::max(dp[n-1][w],
                                        dp[n-1][w_idx] + val[n-1]);
                }
            }
        }
        return dp[N][W];
    }

    //TODO 状态压缩
};
