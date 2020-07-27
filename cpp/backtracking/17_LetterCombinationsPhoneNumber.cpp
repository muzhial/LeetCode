#include "../common.hpp"
using std::string;
using std::vector;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>{};
        map_ = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string track;
        Backtrack(track, digits);
        return res_;
    }
    void Backtrack(string& track, string& digits) {
        if (track.size() == digits.size()) {
            res_.push_back(track);
            return;
        }
        int map_idx = digits[track.size()] - '0';
        for (auto c : map_[map_idx]) {
            track.push_back(c);
            Backtrack(track, digits);
            track.pop_back();
        }
    }
private:
    vector<string> res_;
    vector<string> map_;
};

int main() {
    string s = "123456";
    for (auto c : s) {
        std::cout << c - '0' << " ";
    }
    std::cout << std::endl;
    return 0;
}
