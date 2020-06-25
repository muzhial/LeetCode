#include "../common.hpp"
using namespace std;
using std::string;
using std::vector;

/***************
****************/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = board.size();
        int cols = rows != 0 ? board[0].size() : 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == word[0]) {
                    vector<vector<int>> track;
                    track.push_back({r, c});
                    Backtrack(board, word, rows, cols, track);
                }
            }
        }
    }
    void Backtrack(vector<vector<char>>& board, string& word, int r, int c, vector<vector<int>>& track) {

        // for (int i )
    }
};

int main() {
    vector<vector<int>> a = {{1, 2, 3}, {3, 5, 6}};
}
