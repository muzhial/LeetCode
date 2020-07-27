#include "../common.hpp"
using std::string;

// 二分递归进行求解 因为最长回文字串不可能超过整个字串的一半
// 错误: string test_str = "12ababa";
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1) {
            return "";
        }
        else
        {
            return recurSearch(s, 0, s.size()-1);
        }
    }
    string recurSearch(const string &s, size_t st, size_t ed) {
        size_t center_index = (st + ed) / 2;
        if(center_index == st) {
            return "";
        }
        string sub_result_left = recurSearch(s, st, center_index);
        string sub_result_right = recurSearch(s, center_index, ed);
        // 从 center_index 分别向两端比较 是否相等
        size_t palindrome_len = 0;
        size_t cusor = 1;
        while(center_index - cusor >= st \
            && center_index + cusor <= ed \
            && s[center_index - cusor] == s[center_index + cusor]) {
                ++cusor;
            }
        palindrome_len = cusor == 1 ? 0 : 2 * (cusor - 1) + 1;
        if(palindrome_len != 0) {
            std::cout << s.substr(center_index - cusor + 1, palindrome_len) << std::endl;
            return s.substr(center_index - cusor + 1, palindrome_len);
        }
        else
        {
            return "";
        }
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        size_t start_pos = 0;
        size_t palindrome_len = 0;
        if (s.size() == 0) {
            return "";
        }
        else if (s.size() == 1)
        {
            return s.substr(0, 1);
        }
        
        else
        {
            for (size_t i = 0; i < s.size(); ++i) {
                size_t bin_len = 1;
                size_t tmp_len = 0;
                /**
                 * 以i为中心 比较两边 形如"babc"
                 */
                // std::cout << i - bin_len << std::endl;
                // 注意此处 i - bin_len >= 0 当差为负时会一直大于0
                while (i >= bin_len && i + bin_len <= s.size() - 1 && \
                    s.at(i-bin_len) == s.at(i+bin_len))
                    ++bin_len;
                tmp_len = bin_len == 1 ? 0 : 2 * (bin_len - 1) + 1;
                if (tmp_len > palindrome_len) {
                    palindrome_len = tmp_len;
                    start_pos = i - (bin_len - 1);
                }
                /**
                 * 以i为左边 形如"baac"
                 */
                bin_len = 1;
                while (i + bin_len <= s.size() - 1 && i >= bin_len - 1 && \
                    s.at(i-bin_len+1) == s.at(i+bin_len))
                    ++bin_len;
                tmp_len = bin_len == 1 ? 0 : 2 * (bin_len - 1);
                if (tmp_len > palindrome_len) {
                    palindrome_len = tmp_len;
                    start_pos = i - (bin_len - 2);
                }
            }

            if (palindrome_len == 0) {
                std::cout << s.substr(0, 1) << std::endl;
                return s.substr(0, 1);
            }
            else {
                std::cout << s.substr(start_pos, palindrome_len) << std::endl;
                return s.substr(start_pos, palindrome_len);
            }
        }
    }
};