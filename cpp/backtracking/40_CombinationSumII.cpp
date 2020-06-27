#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> track(candidates.size(), false);
        vector<int> item;
        std::sort(candidates.begin(), candidates.end());
        Backtrack(candidates, target, track, 0, item);
        return res_;
    }
    void Backtrack(vector<int>& cands, int target, vector<bool>& track, int start, vector<int>& item) {
        if (target == 0) {
            res_.push_back(item);
            return;
        }
        for (int i = start; i < cands.size(); ++i) {
            if (i != 0 && cands[i] == cands[i - 1] && !track[i - 1]) {
                continue;
            }
            if (cands[i] <= target) {
                track[i] = true;
                item.push_back(cands[i]);
                Backtrack(cands, target- cands[i], track, i + 1, item);
                track[i] = false;
                item.pop_back();
            }
        }
    }
private:
    vector<vector<int>> res_;
};
