#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        Backtrack(n, k, 1, track);
        return res_;
    }
    void Backtrack(int n, int k, int start, vector<int>& track) {
        if (track.size() == k) {
            res_.push_back(track);
            return;
        }
        for (int i = start; i <= n; ++i) {
            track.push_back(i);
            Backtrack(n, k, i + 1, track);
            track.pop_back();
        }
    }
private:
    vector<vector<int>> res_;
};
