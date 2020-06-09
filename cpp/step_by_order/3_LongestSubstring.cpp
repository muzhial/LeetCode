/**
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


// test  `abcd12134daccc`, `abchksgd12k34faccc`, `abchksgd12k34daccc`
class Solution {
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