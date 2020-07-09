#include "../common.hpp"
using namespace std;

/***************
****************/
class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        long long mask = 1 << 30;
        while ((mask & num) == 0) {
            mask >>= 1;
        }
        mask = (mask << 1) - 1;
        return num ^ mask;
    }
};
