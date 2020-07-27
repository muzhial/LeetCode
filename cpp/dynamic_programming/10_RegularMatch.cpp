#include "../common.hpp"

class Solution {
public:
    bool IsMatch(std::string s, std::string p)
    {
        std::string::size_type s_idx = 0, p_idx = 0;
        return Match(s, p, s_idx, p_idx);
    }

    bool Match(std::string &s, std::string &p,
            std::string::size_type s_idx, std::string::size_type p_idx)
    {
        if (s_idx >= s.size() && p_idx >= p.size())
            return true;
        else if (p_idx+1 < p.size() && p.at(p_idx+1) == '*') {
            if (Match(s, p, s_idx, p_idx+2))
                return true;
            if (s_idx < s.size() && p.at(p_idx) == s.at(s_idx)
                    || s_idx < s.size() && p.at(p_idx) == '.') {

                return Match(s, p, s_idx+1, p_idx);
            }
        } else if (s_idx < s.size() && p_idx < p.size() 
                && (p.at(p_idx) == s.at(s_idx) || p.at(p_idx) == '.')) {

            return Match(s, p, s_idx+1, p_idx+1);
        } else {
            return false;    
        }
    }
};

// another solution --> DP algorithm
class SolutionI {

};

int main()
{
    std::vector<std::string> col{"kjh",      "aas", "", \
        "",  "s", "aklsw", "",   "aaa", "bbb", "aaab", \
        "aaabcdwww", "ab", "mississippi", "bbabacccbcbbcaaab"};
    std::vector<std::string> col_p{"kjhass", "a",   "", \
        "a", "",  "aklsw", "a*", "a*",  "b*b", "a*b",  \
        "a*b*cdw*",  ".*", "mis*is*p*.",  "a*b*a*a*c*aa*c*bc*"};
    std::vector<std::string>::size_type i = 0;
    auto sz = col.size();

    Solution so;
    for (; i < sz; ++i) {
        std::cout << "src: " << col.at(i)
                  << "\npat: " << col_p.at(i) << std::endl;
        std::cout << ">>> " << (so.IsMatch(col.at(i), col_p.at(i)) ? "true" : "false") << std::endl;
    }

    return 0;
}
