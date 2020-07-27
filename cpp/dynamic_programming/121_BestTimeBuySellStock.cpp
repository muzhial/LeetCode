#include "../common.hpp"
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = std::numeric_limits<int>::max();
        int max_profile = 0;
        for (auto p : prices) {
            max_profile = std::max(max_profile, p - min_price);
            min_price = std::min(min_price, p);
        }
        return max_profile;
    }
};
