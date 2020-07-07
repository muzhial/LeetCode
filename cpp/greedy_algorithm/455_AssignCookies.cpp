#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int g_sz = g.size();
        int s_sz = s.size();
        if (g_sz == 0 || s_sz == 0) return 0;
        std::sort(g.begin(), g.end());  // default acsend
        std::sort(s.begin(), s.end());
        int gi = 0;
        int si = 0;
        while (gi < g_sz && si < s_sz) {
            if (g[gi] <= s[si]) {
                ++gi;
            }
            ++si;
        }
        return gi;
    }
};
