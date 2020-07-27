#include "../common.hpp"
using std::vector;

/**
 * [分析]
 * dp[i] 为当前 amount 为 i 时的组合数
*/
class Solution {
public:
    // 压缩状态后
    int change(int amount, vector<int>& coins) {
        // 这个边界限定多余
        // if (coins.size() == 0) {
        //     return 0;
        // }
        vector<int> dp(amount + 1, 0);
        // base case
        dp[0] = 1;
        /**
         * 注意该处：假设  coins -> [1, 2, 5]
         * 1. 如果 amount 循环在外面，则会重复计算可能性，比如 dp[3] 时，dp[3-1] 和 dp[3-2] 会有重叠
         * 2. 如果外层循环为 coins 则无此问题 
         ***/
        // method 1 is error!!!
        // for (int i = 1; i <= amount; ++i) {
        //     for (auto coin: coins) {
        //         if (i - coin >= 0) {
        //             dp[i] += dp[i-coin];
        //         }
        //     }
        // }
        // method 2 is correct
        for (auto coin: coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i - coin >= 0) {
                    dp[i] += dp[i-coin];
                }
            }
        }
        return dp[amount];
    }
    //TODO 使用二维状态方法 熟练度
};
