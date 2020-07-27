#include "../common.hpp"
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int l_r = 0;
        int r_r = rows - 1;
        while (l_r <= r_r) {
            int mid = l_r + (r_r - l_r) / 2;
            if (target < matrix[mid][0]) {
                r_r = mid - 1;
            } else if (target > matrix[mid][0]) {
                l_r = mid + 1;
            } else if (target == matrix[mid][0]) {
                return true;
            }
        }
        if (r_r < 0) {
            return false;
        }
        // row --> l_r - 1
        int l_c = 0;
        int r_c = cols - 1;
        while (l_c <= r_c) {
            int mid = l_c + (r_c - l_c) / 2;
            if (target < matrix[l_r - 1][mid]) {
                r_c = mid - 1;
            } else if (target > matrix[l_r - 1][mid]) {
                l_c = mid + 1;
            } else if (target == matrix[l_r - 1][mid]) {
                return true;
            }
        }
        return false;
    }
};
