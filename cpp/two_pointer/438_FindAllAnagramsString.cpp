#include "../common.hpp"
using namespace std;
using std::string;
using std::unordered_map;

/***************
****************/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> starts{};
        unordered_map<char, int> need, window;
        for (auto c : p) {
            need[c]++;
        }
        int l = 0;
        int r = 0;
        int valid = 0;
        while (r < s.size()) {
            char c_s = s[r];
            r++;
            if (need.count(c_s)) {
                window[c_s]++;
                if (need[c_s] == window[c_s]) {
                    valid++;
                }
            }
            while (r - l >= p.size()) {
                if (valid == need.size()) {
                    starts.push_back(l);
                }
                char c_d = s[l];
                l++;
                if (need.count(c_d)) {
                    if (need[c_d] == window[c_d]) {
                        valid--;
                    }
                    window[c_d]--;
                }
            }
        }
        return starts;
    }
};
