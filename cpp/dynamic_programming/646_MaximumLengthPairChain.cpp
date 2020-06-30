#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) {
            return 0;
        }
        std::sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) -> bool { return a[0] < b[0]; }); 

        int sz = pairs.size();
        int max_ = 1;
        vector<int> dp(sz, 1);
        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            max_ = std::max(max_, dp[i]);
        }
        return max_;
    }
    // bool Overlap(vector<vector<int>>& pairs, int i, int j) {
    //     vector<int> x1 = pairs[i];
    //     vector<int> x2 = pairs[j];
    //     int union_ = x1[1] - x1[0] + x2[1] - x2[0];
    //     int inter_ = std::max(x1[1], x2[1]) - std::min(x1[0], x2[0]);
    //     return inter_ <= union_ ? true : false;
    // }
};

int main() {
    vector<vector<int>> a{{3, 4}, {5, 6}, {1, 2}};
    std::sort(a.begin(), a.end(), [](vector<int> i, vector<int> j) -> bool { return i[0] < j[0]; });
    for (auto it : a) {
        cout << it[0] << " " << it[1] << endl;
    }
    return 0;
}
