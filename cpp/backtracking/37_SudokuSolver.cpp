#include "../common.hpp"
using std::vector;
using std::string;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        string select("123456789");
        Backtrack(board, select, 0, 0);
    }
    bool Backtrack(vector<vector<char>>& board, string& select, int row, int col) {
        int m = 9;
        int n = 9;

        if (col == n) {
            return Backtrack(board, select, row + 1, 0);
        }
        if (row == m) {
            return true;
        }

        if (board[row][col] != '.') {
            return Backtrack(board, select, row, col + 1);
        }
        for (auto chr : select) {
            if (!Valid(board, row, col, chr)) {
                continue;
            }
            board[row][col] = chr;
            if (Backtrack(board, select, row, col + 1)) {
                return true;
            }
            board[row][col] = '.';
        }
        return false;
    }
    bool Valid(vector<vector<char>>& board, int r, int c, char i) {
        for (int k = 0; k < 9; ++k) {
            if (i == board[r][k]) {
                return false;
            }
            if (i == board[k][c]) {
                return false;
            }
        }
        for (int m = r / 3 * 3; m < r / 3 * 3 + 3; ++m) {
            for (int n = c / 3 * 3; n < c / 3 * 3 + 3; ++n) {
                if (i == board[m][n]) {
                    return false;
                }
            }
        }
        return true;
    }
};
