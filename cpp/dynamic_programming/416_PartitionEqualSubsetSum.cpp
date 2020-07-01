#include "../common.hpp"
using namespace std;
using std::vector;

/***************
 * [分析]
 * dp 数组中状态为 bool 值
 * 状态压缩：dp[n][w] 只由上一行 dp[n-1][...] 转移而来，所以可以
 * 使用一维 dp 进行存储。
****************/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int W = sum / 2;
        int N = nums.size();
        vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
        for (auto& d: dp) {
            d[0] = true;
        }
        for (int n = 1; n <= N; ++n) {
            for (int w = 1; w <= W; ++w) {
                if (w - nums[n-1] < 0) {
                    dp[n][w] = dp[n-1][w];
                } else {
                    dp[n][w] = dp[n-1][w] | dp[n-1][w-nums[n-1]];
                }
            }
        }
        return dp[N][W];
    }
    // 状态压缩：time{O(N*W)} space{O(W)}
    bool canPartitionCompress(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int W = sum / 2;
        int N = nums.size();
        vector<bool> dp(W + 1, false);
        dp[0] = true;
        for (int n = 1; n <= N; ++n) {
            for (int w = W; w > 0; --w) {
                if (w - nums[n-1] >= 0) {
                    dp[w] = dp[w] || dp[w-nums[n-1]];
                }
            }
        }
        return dp[W];
    }
};
/***************
****************/

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    s.canPartition(nums);
}
