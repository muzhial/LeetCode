#include "../common.hpp"

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;
            b = static_cast<unsigned int>(a & b) << 1;
            a = sum;
        }
        return a;
    }
};
