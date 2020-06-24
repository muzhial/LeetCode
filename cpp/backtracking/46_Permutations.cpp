#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        Backtrack(nums, track);
        return res_;
    }
    // track 走过的路径
    // 选择列表：nums 中不存在与 track 中的元素
    // 结束条件：nums 中元素全部被走过
    void Backtrack(vector<int>& nums, vector<int>& track) {
        if (track.size() == nums.size()) {
            res_.push_back(track);
            return;
        }
        for (auto num : nums) {
            if (std::find(track.begin(), track.end(), num) != track.end()) {
                continue;
            }
            track.push_back(num);
            Backtrack(nums, track);
            track.pop_back();
        }
    }
private:
    vector<vector<int>> res_;
};