#include <vector>
using namespace std;
using std::vector;

/***************
*     start
* [分析]
* 遇到最值问题可先想想 DP 解法，将一列数放在 2-D 坐标轴上思考，便于抓住问题特性，
* 状态转移方程为： dp(n) = max(dp(n - 1), dp(dp - 2))
* [test]
* [10,9,2,5,3,7,101,18]  4
****************/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int sz = nums.size();
        vector<int> dp(sz, 1);
        int res = 1;
        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            res = std::max(dp[i], res);
        }
        return res;
    }
};
/***************
*     end
****************/
