#include "../common.hpp"
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        int minprice = std::numeric_limits<int>::max();
        for (auto& p : prices) {
            if (p <= minprice) {
                minprice = p;
            } else {
                maxprof += (p - minprice);
                minprice = p;
            }
        }
        return maxprof;
    }
};
