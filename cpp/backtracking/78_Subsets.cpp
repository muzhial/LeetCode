#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        for (int i = 0; i <= nums.size(); ++i) {
            Backtrack(nums, track, 0, i);
        }
        return res_;
    }
    void Backtrack(vector<int>& nums, vector<int>& track, int start, int n) {
        if (n == 0) {
            res_.push_back(track);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            track.push_back(nums[i]);
            Backtrack(nums, track, i + 1, n - 1);
            track.pop_back();
        }
    }
private:
    vector<vector<int>> res_;
};
