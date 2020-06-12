#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // min
#include <limits>     // numeric_limits
#include <unordered_map>
using namespace std;
using std::vector;
using std::unordered_map;


int coinChange(vector<int>& coins, int amount) {
    // 也可以将 MAX_INT 赋给初始 dp
    vector<long long> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (long long i = 1; i <= dp.size(); ++i) {
        for (auto coin: coins) {
            if (i - coin < 0) {
                continue;
            }
            long long subproblem = dp[i - coin];
            dp[i] = std::min(subproblem + 1, dp[i]);
        }
    }
    return dp[amount] != amount + 1 ? dp[amount] : -1;
}

int main()
{
    return 0;
}