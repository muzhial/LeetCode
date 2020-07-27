#include "../common.hpp"

/**
 * [分析]
 * 此题关键在溢出问题把握，位操作
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int MIN = std::numeric_limits<int>::min();
        int MAX = std::numeric_limits<int>::max();
        if(divisor == 1) return dividend;
        
        if(dividend == MIN && divisor == -1) return MAX;
        
        long long ans = 0;
        long long a = std::abs(dividend);
        long long b = std::abs(divisor);
        
        while(a >= b) {
            long long t = b;
            long long m = 1;
            
            while(t<<1 < a) {
                t <<= 1;
                m <<= 1;
            }
            
            ans += m;
            a -= t;
        }
        
        return dividend > 0 == divisor > 0 ? ans : -ans;
    }
};

int main() {
    Solution s;
    std::cout << s.divide(-2147483648, -1) << std::endl;
}
