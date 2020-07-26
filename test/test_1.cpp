#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

// 使用并查集存储，id 为自增序列，p_id 设置成 vector[id] = p_id
// 实现删除
void Delete(vector<int>& table, int target_id) {
    int cnt = 0;
    for (auto& ele : table) {
        if (cnt++ == target_id) {
            ele = -1;
        }
        if (ele == target_id) {
            ele = -1;
        }
    }
}

int main() {
    vector<int> v = {1, 2, 3};
    for (auto& vi : v) {
        vi = 0;
    }
    for (auto& i : v) {
        cout << i << " " << endl;
    }
}
