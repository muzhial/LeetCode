#include "../common.hpp"
using namespace std;
using std::string;
using std::vector;

/***************
****************/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        res_ = vector<string> {};
        vector<string> track;
        Backtrack(s, 0, track);
        return res_;
    }
    void Backtrack(string& s, int start, vector<string>& track) {
        if (track.size() == 4) {
            if (start == s.size()) {
                string res("");
                for (auto sub : track) {
                    res += sub + ".";
                }
                res_.push_back(res.substr(0, res.size() - 1));
            }
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            string sub;
            if (s.size() - start >= len) {
                sub = s.substr(start, len);
                if (sub.size() >= 2 && sub[0] == '0' || std::stoi(sub) > 255) {
                    return;
                }
            } else {
                return;
            }
            track.push_back(sub);
            start = start + len;
            Backtrack(s, start, track);
            start = start - len;
            track.pop_back();
        }
    }
private:
    vector<string> res_;
};

int main() {
    string s1 = "255";  // "010010"
    Solution sol;
    for (auto r : sol.restoreIpAddresses(s1)) {
        cout << r << endl;
    }
    
    return 0;
}
