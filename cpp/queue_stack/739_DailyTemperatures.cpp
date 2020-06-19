#include "../common.hpp"
using namespace std;
using std::vector;
using std::stack;

/***************
****************/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int sz = T.size();
        vector<int> res(sz, 0);
        stack<int> indexes;
        indexes.push(0);
        for (int i = 1; i < sz; ++i) {
            while (!indexes.empty()) {
                int top_idx = indexes.top();
                if (T[i] > T[top_idx]) {
                    res[top_idx] = i - top_idx;
                    indexes.pop();
                } else {
                    break;
                }
            }
            indexes.push(i);
        }
        return res;
    }
};
