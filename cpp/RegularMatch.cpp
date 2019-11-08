#include <iostream>
#include <vector>
#include <string>


class Solution {
typedef typename std::string::iterator iter_t;
public:
    bool IsMatch(std::string s, std::string p)
    {
        auto s_f = s.begin();
        auto s_l = s.end();
        auto p_f = p.begin();
        auto p_l = p.end();        
    
        if (s.empty()) {
            if (p.empty())
                return true;
            else {
                if (*--p_l != '*')
                    return false;
                if (*p_f != '.')
                    return false;
                if (p.size() == 2)
                    return true;
                else
                    return false;
            }
        }
        else {
            if (p.empty())
                return false;
            else {
                // string and pattern all not empty
                for (; s_f != s_l; ++s_f) {
                    if (*s_f != *p_f) {
                        if (*p_f == '.') {
                            ++p_f;
                            if (p_f == p_l) {
                                if (s_f + 1 == s_l)

                            }
                        }
                        else if (*p_f == '*') {

                        }
                        else
                            return false;
                    }
                    else {
                        ++p_f;
                        if (p_f == p_l) {
                            if (s_f + 1 == s_l)
                                return true;
                            else
                                return false;
                        }
                    }
                }
            }
        }    
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
