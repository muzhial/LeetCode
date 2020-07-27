#define TREENODE
#include "../common.hpp"
using std::vector;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};