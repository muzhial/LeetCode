#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 1);
        for (int i = 1; i <= s.size(); ++i) {
            if (i == 1) {
                dp[i] = 1;
                continue;
            }
            int pre = s[i - 2] - '0';
            int cur = s[i - 1] - '0';
            int d = pre * 10 + cur;
            if (d == 0) {
                dp[i] = 0;
                return dp[i];
            }
            if (pre == 0) {
                dp[i] = dp[i - 1];
            }
            if (cur == 0) {
                dp[i] = dp[i - 2];
            }

        }
        return dp[s.size()];
    }
};