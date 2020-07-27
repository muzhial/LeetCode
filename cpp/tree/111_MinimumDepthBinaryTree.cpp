#define TREENODE
#include "../common.hpp"
using std::vector;
using std::queue;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;  // BFS 使用队列
        int depth = 1;
        q.push(root);
        
        while (!q.empty()) {
            int level_cap = q.size();
            for (int i = 0; i < level_cap; ++i) {
                TreeNode* first = q.front();
                if (first->left == nullptr && first->right == nullptr) {
                    return depth;
                }
                if (first->left != nullptr) {
                    q.push(first->left);
                }
                if (first->right != nullptr) {
                    q.push(first->right);
                }
                q.pop();
            }
            depth++;
        }
        return depth;
    }
};