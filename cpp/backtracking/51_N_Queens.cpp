#include "../common.hpp"
using namespace std;
using std::vector;
using std::string;

/***************
****************/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        Backtrack(board, 0);
        return res_;
    }
    void Backtrack(vector<string>& board, int row) {
        if (row == board.size()) {
            res_.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int col = 0; col < n; ++col) {
            if (!Valid(board, row, col)) {
                continue;
            }
            board[row][col] = 'Q';
            Backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    bool Valid(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
private:
    vector<vector<string>> res_;
};
