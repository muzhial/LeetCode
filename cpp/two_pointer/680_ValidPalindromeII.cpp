#include "../common.hpp"
using std::string;

/***************
 * "cupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupucu"
****************/
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return IsPalindrome(s, l + 1, r) ||
                       IsPalindrome(s, l, r - 1);
            }
        }
        return true;
    }
    bool IsPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};
