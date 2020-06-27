#include "../common.hpp"
using namespace std;
using std::vector;
using std::string;

/***************
****************/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        string select("123456789");
    }
    void Backtrack(vector<vector<char>>& board, string& select, int row, int col) {
        if (row == board.size()) {
            return;
        }
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (board[r][c] == '.') {
                    for (auto chr : select) {
                        if (!Valid(board, r, c, chr)) {
                            continue;
                        }
                        board[r][c] = chr;
                        Backtrack(board, select, row, col);
                        board[r][c] = '.';
                    }
                }
            }
        }
    }
    bool Valid(vector<vector<char>>& board, int r, int c, char i) {
        for (int k = 0; k < 9; ++k) {
            if (i == board[r][k]) {
                return false;
            }
        }
        for (int k = 0; k < 9; ++k) {
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
