#include "../common.hpp"
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ret;
        while (carry == 1 || i >= 0 || j >= 0) {
            if (i >= 0 && a[i--] == '1') {
                carry++;
            }
            if (j >= 0 && b[j--] == '1') {
                carry++;
            }
            ret.push_back('0' + carry % 2);
            carry /= 2;
        }
        int s = 0;
        int e = ret.size() - 1;
        for (; s <= e; s++, e--) {
            std::swap(ret[s], ret[e]);
        }
        return ret;
    }
};
