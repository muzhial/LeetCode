#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        int h = std::sqrt(n);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2; j <= h; ++j) {
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i / j];
                    break;
                }
            }
        }
        return dp[n];
    }
};
