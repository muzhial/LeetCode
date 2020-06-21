#include "../common.hpp"
using namespace std;

/***************
 * [分析]
 * 此题关键在溢出问题把握，位操作
****************/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int MIN = std::numeric_limits<int>::min();
        int MAX = std::numeric_limits<int>::max();
        int sign = true;  // true for positive
        // divisor is -2^31
        if (divisor == MIN) {
            if (dividend == MIN) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dividend < 0) {
            if (dividend == MIN) {
                dividend = MAX;
            } else {
                dividend = -1 * dividend - 1;
            }
            sign = !sign;
        } else {
            dividend -= 1;
        }
        if (divisor < 0) {
            divisor = -1 * divisor;
            sign = !sign;
        }
        int l = divisor;
        int r = dividend;
        int count = 0;
        while (l - 1 <= r) {
            l = l + divisor;
            count++;
        }
        if (sign) {
            return count;
        } else {
            return -1 * count;
        }
    }
};

int main() {
    Solution s;
    cout << s.divide(-2147483648, -1) << endl;
}
