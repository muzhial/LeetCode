#include "../common.hpp"
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> track;
        Backtrack(candidates, target, 0, track);
        return res_;
    }
    void Backtrack(vector<int>& cands, int target, int start, vector<int>& track) {
        if (target == 0) {
            res_.push_back(track);
            return;
        }
        for (int i = start; i < cands.size(); ++i) {
            if (cands[i] <= target) {
                track.push_back(cands[i]);
                Backtrack(cands, target - cands[i], i, track);
                track.pop_back();
            }
        }
    }
private:
    vector<vector<int>> res_;
};

// 下述解法为最初版本，时间复杂度略高于上面版本
class SolutionI {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> track;
        Backtrack(candidates, target, track);
        return res_;
    }
    void Backtrack(vector<int>& cands, int target, vector<int>& track) {
        if (target == 0) {
            res_.push_back(track);
            return;
        }
        for (int i = 0; i < cands.size(); ++i) {
            if (track.size() > 0 && cands[i] < track[track.size() - 1]) {
                continue;
            }
            if (cands[i] <= target) {
                track.push_back(cands[i]);
                Backtrack(cands, target - cands[i], track);
                track.pop_back();
            }
        }
    }
private:
    vector<vector<int>> res_;
};
