#include "../common.hpp"
using std::vector;

/**
* [分析]
* dp[n] 定义为以 nums[n] 结尾的最长递增子序列的长度
* [test]
* [10,9,2,5,3,7,101,18]  4
*/
// Time -> O(n^2)
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

// 二分查找优化 Time -> O(nlogn)
/* [4,3,6,5]
tails      len      num
[]         0        4
[4]        1        3
[3]        1        6
[3,6]      2        5
[3,5]      2        null
*/
class SolutionI {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails(nums.size(), 0);
        int len = 0;
        for (auto num : nums) {
            int idx = helper(tails, len, num);
            tails[idx] = num;
            if (idx == len) {
                len++;
            }
        }
        return len;
    }
    int helper(vector<int>& tails, int len, int num) {
        int l = 0;
        int r = len - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (num == tails[mid]) {
                return mid;
            } else if (num > tails[mid]) {
                l = mid + 1;
            } else if (num < tails[mid]) {
                r = mid - 1;
            }
        }
        return l;
    }
};
