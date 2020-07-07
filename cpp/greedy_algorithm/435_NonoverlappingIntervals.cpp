#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        if (sz == 0) return 0;
        std::sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) -> bool { return a[1] < b[1]; });
        int cnt = 1;
        int end = intervals[0][1];
        for (int i = 1; i < sz; ++i) {
            if (intervals[i][0] < end) {
                continue;
            }
            cnt++;
            end = intervals[i][1];
        }
        return sz - cnt;
    }
};