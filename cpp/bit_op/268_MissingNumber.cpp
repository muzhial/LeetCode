#include "../common.hpp"
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ret = ret ^ i ^ nums[i];
        }
        return ret ^ nums.size();
    }
};
