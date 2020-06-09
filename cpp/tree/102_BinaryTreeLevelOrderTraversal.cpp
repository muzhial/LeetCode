#include <iostream>
#include <limits>   // numeric_limits
#include <utility>  // swap
#include <vector>
#include <stack>
#include <queue>
using namespace std;
using std::vector;
using std::stack;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/***************
*     start
****************/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            // 存储每层的 nodes
            vector<int> level_nodes;
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                TreeNode* cur = q.front();
                level_nodes.push_back(cur->val);
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
                q.pop();
            }
            res.push_back(level_nodes);
        }
        return res;
    }
};
/***************
*     end
****************/