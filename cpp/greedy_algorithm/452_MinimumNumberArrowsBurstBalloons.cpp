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

int findMinArrowShots(vector<vector<int>>& points) {
    if (!points.size()) return 0;
    std::sort(points.begin(), points.end());
    int count = 1, last = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        if (last > points[i][1]) {
            last = points[i][1];
        } else if (last < points[i][0]) {
            last = points[i][1];
            count++;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> v{{7,0}, {4,4}, {7,1} ,{5,0}, {6,1}, {5,2}};
    std::sort(v.begin(), v.end());
    for (auto& vi : v) {
        cout << vi[0] << " " << vi[1] << endl;
    }
}
