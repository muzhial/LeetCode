#include "../common.hpp"
using std::vector;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int MAX = std::numeric_limits<int>::max();
        int m = grid.size();
        int n = m != 0 ? grid[0].size() : 0;
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    res[i][j] = grid[i][j];
                    continue;
                }
                int up = i - 1 < 0 ? MAX : res[i - 1][j];
                int left = j - 1 < 0 ? MAX : res[i][j - 1];
                res[i][j] = std::min(up, left) + grid[i][j];
            }
        }
        return res[m - 1][n - 1];
    }
};
