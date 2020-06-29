#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<int> dp(A.size(), 0);
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        int total = 0;
        for (auto it : dp) {
            total += it;
        }
        return total;
    }
};
