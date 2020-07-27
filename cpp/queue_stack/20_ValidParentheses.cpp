#include "../common.hpp"
using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parens;
        for (auto& ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                parens.push(ch);
            }
            if (ch == ')' || ch == ']' || ch == '}') {
                if (parens.empty()) {
                    return false;
                } else {
                    char t = parens.top();
                    bool b1 = t == '(' && ch == ')';
                    bool b2 = t == '[' && ch == ']';
                    bool b3 = t == '{' && ch == '}';
                    if (b1 || b2 || b3) {
                        parens.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return parens.empty();
    }
};