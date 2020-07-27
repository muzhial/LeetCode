#include "../common.hpp"
using std::vector;
using std::list;

/**
 * [Hint]
 * vector 插入很慢
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int sz = people.size();
        if (sz == 0 || people[0].size() == 0) return vector<vector<int>> {};
        vector<vector<int>> res;
        std::sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) -> bool {
            return a[0] == b[0] ? b[1] > a[1] : a[0] > b[0];
        });
        for (auto& p : people) {
            auto pos = res.begin();
            res.insert(pos + p[1], p);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> v{{7,0}, {4,4}, {7,1} ,{5,0}, {6,1}, {5,2}};
    std::sort(v.begin(), v.end(), [](vector<int> a, vector<int> b) -> bool {
        return a[0] == b[0] ? b[1] > a[1] : a[0] > b[0];
    });
    for (auto& i : v) {
        std::cout << i[0] << " " << i[1] << std::endl;
    }
}
