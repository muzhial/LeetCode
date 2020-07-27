#include "../common.hpp"
using std::string;

class Solution {
public:
    string convertToBase7(int num) {
        string ret;
        string res;
        long long d = num < 0 ? -1 * static_cast<long long>(num) : num;
        long long m = 0;
        while (d >= 7) {
            m = d % 7;
            d = d / 7;
            ret.push_back(static_cast<char>('0' + m));
        }
        ret.push_back(static_cast<char>('0' + d));

        if (num < 0) {
            res.push_back('-');
        }
        for (int i = ret.size() - 1; i >= 0; --i) {
            res.push_back(ret[i]);
        }
        return res;
    }
};
