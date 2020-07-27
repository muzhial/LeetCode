#include "../common.hpp"
using std::vector;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> track;
        vector<int> visited(nums.size(), false);
        for (int i = 0; i <= nums.size(); ++i) {
            Backtrack(nums, track, visited, 0, i);
        }
        return res_;
    }
    void Backtrack(vector<int>& nums, vector<int>& track, vector<int>& visited, int start, int n) {
        if (n == 0) {
            res_.push_back(track);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            visited[i] = true;
            track.push_back(nums[i]);
            Backtrack(nums, track, visited, i + 1, n - 1);
            visited[i] = false;
            track.pop_back();
        }
    }
private:
    vector<vector<int>> res_;
};
