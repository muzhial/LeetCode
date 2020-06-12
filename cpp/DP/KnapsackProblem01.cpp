#include <iostream>
#include <vector>
#include <limits>
using namespace std;
using std::vector;

/***************
* [desc]
*    N = 3, W = 4
*    wt = [2, 1, 3]
*    val = [4, 2, 3]
* [分析]
* 0 1 背包问题，关键在于状态转移与选择的列出，二维动归问题。
* 定义 dp[n][w] 前n个中取且背包容量为w时的最大值。
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
    int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
        // base case 已初始化
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
        for (int w = 1; w <= W; w++) {
            for (int n = 1; n <= N; n++) {
                if (w - wt[n-1] < 0) {
                    // 这种情况下只能选择不装入背包
                    dp[n][w] = dp[n-1][w];
                } else {
                    // 装入或者不装入背包，择优
                    dp[n][w] = std::max(dp[n-1][w - wt[n-1]] + val[n-1], 
                                        dp[n-1][w]);
                }
            }
        }

        return dp[N][W];
    }
};
/***************
****************/

int main() {
    Solution s;
    vector<int> wt = {2, 1, 3};
    vector<int> val = {4, 2, 3};
    cout << s.knapsack(4, 3, wt, val) << endl;
    return 0;
}
