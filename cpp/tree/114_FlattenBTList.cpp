#define TREENODE
#include "../common.hpp"
using std::vector;

/**
 * [TODO]
 * postorder solution and non-recursive solution
*/
class Solution {
public:
    // preorder recursive
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        TreeNode* lft = root->left;
        TreeNode* rht = root->right;
        
        if (top == nullptr) {
            top = root;
        } else {
            top->right = root;
            top->left = nullptr;
            top = root;
        }
        flatten(lft);
        flatten(rht);
    }
private:
    TreeNode* top = nullptr;

public:
    // non-recursive
    void flattenI(TreeNode* root) {
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                TreeNode* top = cur->left;
                while (top->right != nullptr) {
                    top = top->right;
                }
                top->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};
