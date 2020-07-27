#include "../common.hpp"
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> track;
        Backtrack(k, n, track, 1);
        return res_;
    }
    void Backtrack(int k, int n, vector<int>& track, int start) {
        if (k == 0 && n == 0) {
            res_.push_back(track);
            return;
        }
        if (k == 0 || n == 0) {
            return;
        }
        for (int i = start; i <= 9; ++i) {
            track.push_back(i);
            Backtrack(k - 1, n - i, track, i + 1);
            track.pop_back();
        }
    }
private:
    vector<vector<int>> res_;
};
