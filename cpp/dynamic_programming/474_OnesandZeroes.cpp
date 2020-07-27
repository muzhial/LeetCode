#include "../common.hpp"
using std::string;
using std::vector;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.empty()) {
            return 0;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto str : strs) {
            int ones = 0;
            int zeros = 0;
            for (auto c : str) {
                if (c == '0') {
                    zeros++;
                } else if (c == '1') {
                    ones++;
                }
            }
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = std::max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
