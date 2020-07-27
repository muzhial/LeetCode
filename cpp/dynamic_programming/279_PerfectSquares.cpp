#include "../common.hpp"
using std::vector;

class Solution {
public:
    int numSquares(int n) {
        // generate square vector
        vector<int> sq;
        int diff = 3;
        int square = 1;
        while (square <= n) {
            sq.push_back(square);
            square += diff;
            diff += 2;
        }

        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (auto sq_ : sq) {
                if (i < sq_) {
                    break;
                }
                dp[i] = std::min(dp[i], dp[i - sq_] + 1);
            }
        }
        return dp[n];
    }
};
