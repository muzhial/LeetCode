#define TREENODE
#include "../common.hpp"
using std::vector;

/***************
****************/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (key == root->val) {
            if (root->left == nullptr) {
                return root->right;
            } else {
                TreeNode* r_tmp = root->right;
                TreeNode* l_tmp = root->left;
                while (l_tmp->right != nullptr) {
                    l_tmp = l_tmp->right;
                }
                l_tmp->right = r_tmp;
            }
            return root->left;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};