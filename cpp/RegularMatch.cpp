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
    
        if (!p.empty) {
            while (true) {
                if (*--p_l == "." || *--p_l == "*") {

                }
            }
        }
        while (true) {
            if (s_f == s_l && p_f == p_l) {
                if (s.empty() && p.empty())
                    return true;
                if (p.empty())
                    return false;
                if (s.empty()) {
                    if (*p_f != ".")
                }
            }
        }

        while (p_f != p.end() && s_f != s.end()) {
            if (*p_f == ".") {
                
            }
            else if (*p_f == "*") {
                if (*(p_f - 1) != ".") {
                    if (*(p_f - 1) != *s_f)
                        return false;
                    else
                        ++s_f;
                }
            }
            else {
                if (*p_f == *s_f) {
                    ++p_f;
                    ++s_f;
                }
                else
                    return false;
                
            }
        }
        if (s_begin == s_end && )
    }
};

int main()
{
    std::string s("aaqwq");
    std::string p(".*");
    Solution s;
    std::cout << "src: " << s
              << "\npat: " << p << std::endl;
    std::cout << ">>> " << s.IsMatch(s, p) << std::endl;
    return 0;
}
