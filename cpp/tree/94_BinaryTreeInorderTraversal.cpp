#define TREENODE
#include "../common.hpp"
using std::vector;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> nodes;
        std::vector<int> res;
        while (root != NULL || !nodes.empty()) {
            if (root != NULL) {
                nodes.push(root);
                root = root->left;
            } else {
                root = nodes.top();
                res.push_back(root->val);
                root = root->right;
                nodes.pop();
            }
        }
        
        return res;
    }
};
