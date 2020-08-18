#include "../common.hpp"
using std::vector;
using std::stack;

// DP
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int dep = triangle.size();
        if(dep == 0) {
            return 0;
        }
        for (int i = dep - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] = std::min(triangle[i][j] + triangle[i + 1][j],
                                          triangle[i][j] + triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};

// DFS
class SolutionI {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum = 0;
        int min_ = std::numeric_limits<int>::max();
        // int cols = triangle.size();
        Helper(triangle, 0, 0, sum, min_);
        return min_;
    }
    void Helper(vector<vector<int>>& tri, int dep, int wid, int& sum, int& min_) {
        if (dep == tri.size()) {
            return;
        }
        sum += tri[dep][wid];
        Helper(tri, dep + 1, wid, sum, min_);
        Helper(tri, dep + 1, wid + 1, sum, min_);
        if (dep == tri.size() - 1) {
            min_ = std::min(min_, sum);
        }
        sum -= tri[dep][wid];
    }
};
