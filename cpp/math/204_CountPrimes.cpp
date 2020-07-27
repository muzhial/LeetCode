#include "../common.hpp"
using std::vector;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> not_primes(n + 1, false);
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (not_primes[i]) {
                continue;
            }
            cnt++;
            long long j = static_cast<long long>(i) * i;
            for (; j <= n; j += i) {
                not_primes[j] = true;
            }
        }
        return cnt;
    }
};
