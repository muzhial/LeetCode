#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                dp[i] = std::max(dp[i], std::max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};
