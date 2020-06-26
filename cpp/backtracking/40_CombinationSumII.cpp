#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> track(candidates.size(), false);
        std::sort(candidates.begin(), candidates.end());

        return res_;
    }
    void Backtrack(vector<int>& cands, int target, vector<int>& track) {
        if (target == 0) {
            res_.push_back(track);
            return;
        }
    }
private:
    vector<vector<int>> res_;
};
