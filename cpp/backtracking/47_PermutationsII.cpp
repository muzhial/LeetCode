#include "../common.hpp"
using namespace std;
using std::vector;

/***************
 * [分析]
 * 用 set 去重？或用 map 找元素与出现次数对应关系？
 * 先排序
****************/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<bool> track(nums.size(), false);
        vector<int> path;
        Backtrack(nums, track, path);
        return res_;
    }
    void Backtrack(vector<int>& nums, vector<bool>& track, vector<int>& path) {
        if (path.size() == nums.size()) {
            res_.push_back(path);
            return;
        }
        for (int i = 0; i < track.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1] && !track[i - 1]) {
                continue;
            }
            if (track[i]) {
                continue;
            }
            track[i] = true;
            path.push_back(nums[i]);
            Backtrack(nums, track, path);
            path.pop_back();
            track[i] = false;
        }
    }
private:
    vector<vector<int>> res_;
};
