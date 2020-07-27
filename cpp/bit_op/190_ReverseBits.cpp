#include "../common.hpp"
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a = 0;
        uint32_t k = 32;
        while (k--) {
            a = (a << 1) | (n & 1);
            n >>= 1;
        }
        return a;
    }
};
