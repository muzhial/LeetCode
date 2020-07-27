#include "../common.hpp"
using std::vector;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        int i = 0, j = cols - 1;
        while (i < rows && i >= 0 && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};