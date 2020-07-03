#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // base case
        for (int k = 1; k <= m; ++k) {
            dp[k][0] = k;
        }
        for (int k = 1; k <=n; ++k) {
            dp[0][k] = k;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j - 1] + 1,
                                        std::min(dp[i - 1][j] + 1,
                                                 dp[i][j - 1] + 1));
                }
            }
        }
        return dp[m][n];
    }
};
