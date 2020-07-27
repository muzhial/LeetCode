#include "../common.hpp"
using std::vector;
using std::unordered_map;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto num : nums) {
            if (cnt.count(num)) {
                return num;
            } else {
                cnt[num]++;
            }
        }
        return -1;
    }
};