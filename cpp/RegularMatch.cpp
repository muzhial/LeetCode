#include <iostream>
#include <vector>
#include <string>


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
        if (s_idx == s.size() && p_idx == p.size())
            return true;
        while (p_idx != p.size()) {
            if (s_idx != s.size()) {
                if (p_idx+1 != p.size() && p[p_idx+1] == '*') {
                    p_idx += 2;
                    if (Match(s, p, s_idx, p_idx))
                        return true;
                    else
                        return false;
                }
                else if (p[p_idx] == '.') {
                    ++p_idx;
                    ++s_idx;
                }
                else if (p[p_idx] == s[s_idx]) {
                    ++p_idx;
                    ++s_idx;
                }
                else
                    return false;
            }
            else {
                if (p_idx+2 == p.size() && p[p_idx+1] == '*')
                    return true;
                else
                    return false;
            }
        }
        if (s_idx != s.size())
            return false;
    }
};

int main()
{
    std::string s("kjh");
    std::string p("kjhass");
    Solution so;
    std::cout << "src: " << s
              << "\npat: " << p << std::endl;
    std::cout << ">>> " << (so.IsMatch(s, p) ? "true" : "false") << std::endl;
    return 0;
}
