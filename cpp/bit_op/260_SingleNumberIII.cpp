#include "../common.hpp"
using namespace std;

/***************
****************/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret(2, 0);
        int diff = 0;
        for (auto& num : nums) {
            diff ^= num;
        }
        diff &= -diff;
        for (auto& num : nums) {
            if ((diff & num) == 0) {
                ret[0] ^= num;
            } else {
                ret[1] ^= num;
            }
        }
        return ret;
    }
};
