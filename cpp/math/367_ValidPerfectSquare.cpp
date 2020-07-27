#include "../common.hpp"

class Solution {
public:
    bool isPerfectSquare(int num) {
        int gap = 1;
        while (num > 0) {
            num -= gap;
            gap += 2;
        }
        return num == 0;
    }
};
