#include "../common.hpp"
using std::string;
using std::unordered_map;

// 滑动窗口解法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int l = 0;
        int r = 0;
        int len = 0;
        while (r < s.size()) {
            char c = s[r];
            window[c]++;
            r++;
            while (window[c] > 1) {
                window[s[l]]--;
                l++;
            }
            len = std::max(r - l, len);
        }
        return len;
    }
};

// 使用了 string 库方法，本质也是滑动窗口，推荐上面的写法
class SolutionI {
public:
    int lengthOfLongestSubstring(string s) {
        int s_i = 0;
        int e_i = 0;
        int max_len = 0;
        for(auto &c : s) {
            if(s_i != e_i) {
                const std::string &subs = s.substr(s_i, e_i - s_i);
                std::size_t found = subs.rfind(c);
                if(found != std::string::npos) {
                    max_len = (e_i - s_i) > max_len ? (e_i - s_i) : max_len;
                    s_i = s_i + found + 1;
                }
            }
            ++e_i;
            max_len = (e_i - s_i) > max_len ? (e_i - s_i) : max_len;
        }
        return max_len;
    }
};