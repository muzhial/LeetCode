#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int sz = points.size();
        if (sz == 0) return 0;
        std::sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) -> bool { return a[1] < b[1]; });
        int cnt = 1;
        int end = points[0][1];
        for (int i = 1; i < sz; ++i) {
            if (points[i][0] <= end) {
                continue;
            }
            cnt++;
            end = points[i][1];
        }
        return cnt;
    }
};
