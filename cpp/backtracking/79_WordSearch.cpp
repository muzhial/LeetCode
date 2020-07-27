#include "../common.hpp"
using std::string;
using std::vector;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        directions_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = board.size();
        int cols = rows != 0 ? board[0].size() : 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == word[0]) {
                    vector<vector<int>> track;
                    track.push_back({r, c});
                    if (Backtrack(board, word, rows, cols, track)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool Backtrack(vector<vector<char>>& board, string& word, int r, int c, vector<vector<int>>& track) {
        if (track.size() == word.size()) {
            return true;
        }
        for (auto dirt : directions_) {
            vector<int> coord = track[track.size() - 1];
            int x = coord[0] + dirt[0];
            int y = coord[1] + dirt[1];
            if (x >= 0 && x < r && y >= 0 && y < c &&
                board[x][y] == word[track.size()]) {

                auto it = std::find(track.begin(), track.end(), vector<int>{x, y});
                if (it != track.end()) {
                    continue;
                }
                track.push_back({x, y});
                bool stat = Backtrack(board, word, r, c, track);
                if (stat) {
                    return true;
                }
                track.pop_back();
            }
        }
        return false;
    }
private:
    vector<vector<int>> directions_;
};

int main() {
    vector<vector<int>> a = {{1, 2}, {3, 5}, {3, 8}};
    auto it = std::find(a.begin(), a.end(), vector<int>{1, 0});
    if (it != a.end()) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
