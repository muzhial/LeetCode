#include "../common.hpp"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        long long r = n;
        if (n < 0) {
            x = 1.0 / x;
            r = std::abs(r);
        }
        // 对 n 进行二分
        long long l = 1;
        double res = 1.0;
        while (0 < r) {
            double base = x;
            l = 1;
            while (l << 1 <= r) {
                l <<= 1;
                base = base * base;
            }
            if (l == 1) {
                res *= x;
            } else {
                res *= base;
            }
            r -= l;
        }
        return res;
    }
};
