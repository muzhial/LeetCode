#include "../common.hpp"
using std::string;
using std::unordered_map;

/***************
****************/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (auto c : s1) {
            need[c]++;
        }
        int l = 0;
        int r = 0;
        int valid = 0;
        while (r < s2.size()) {
            char c_win = s2[r];
            r++;
            if (need.count(c_win)) {
                window[c_win]++;
                if (need[c_win] == window[c_win]) {
                    valid++;
                }
            }
            while (r - l >= s1.size()) {
                if (valid == need.size()) {
                    return true;
                }
                char c_d = s2[l];
                l++;
                if (need.count(c_d)) {
                    if (need[c_d] == window[c_d]) {
                        valid--;
                    }
                    window[c_d]--;
                }
            }
        }
        return false;
    }
};