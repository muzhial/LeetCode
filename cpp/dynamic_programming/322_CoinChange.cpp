#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // min
#include <limits>     // numeric_limits
#include <unordered_map>
using namespace std;
using std::vector;
using std::unordered_map;


/***************
****************/
// ------- Method 1: 备忘录，自顶向下 -------
int helper(vector<int>& coins, int amount, unordered_map<int, int>& memo) {
    // 如果这段判断放到 for 循环里面，将起不到作用，且冗余
    if (memo.find(amount) != memo.end()) {
        return memo[amount];
    }
    if (amount < 0) {
        return -1;
    }
    if (amount == 0) {
        return memo[0];
    }
    int MAX = numeric_limits<int>::max();
    int min_ = MAX;
    for (auto coin: coins) {
        int subproblem = helper(coins, amount - coin, memo);
        if (subproblem == -1) {
            continue;
        }
        min_ = std::min(subproblem + 1, min_);
    }
    memo[amount] = min_ != MAX ? min_ : -1;
    return memo[amount];
}

int coinChange(vector<int>& coins, int amount) {
    unordered_map<int, int> memo;
    memo[0] = 0;
    
    return helper(coins, amount, memo);
}

// ------- Method 2: DP table，自底向上 -------
int coinChange(vector<int>& coins, int amount) {
    // 也可以将 MAX_INT 赋给初始 dp
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    // amount + 1 替代 dp.size() 节省每次计算时间
    for (int i = 1; i < amount + 1; ++i) {
        for (auto coin: coins) {
            if (i - coin < 0) {
                continue;
            }
            dp[i] = std::min(dp[i - coin] + 1, dp[i]);
        }
    }
    return (dp[amount] != amount + 1) ? dp[amount] : -1;
}
/***************
****************/
