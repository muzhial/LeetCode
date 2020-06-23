#include "../common.hpp"
using namespace std;
using std::string;
using std::unordered_map;

/***************
****************/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> needs, windows;
        for (auto c : t) {
            needs[c]++;
        }

        int l = 0;
        int r = 0;
        int valid = 0;
        int start = 0;
        int len = numeric_limits<int>::min();
        while (r < s.size()) {
            char c = s[r];
            // 窗口右移 [l, r)
            r++;
            // 更新窗口内数据
            if (needs.count(c)) {
                windows[c]++;
                if (windows[c] == needs[c]) {
                    valid++;
                }
            }
            // 判断左窗口是否需要收缩
            while (valid == needs.size()) {
                
            }
        }
    }
};