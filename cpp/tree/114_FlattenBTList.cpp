#include <iostream>
#include <vector>
using namespace std;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/***************
****************/
class Solution {
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
    TreeNode* helper(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left == nullptr) {
            return root;
        }
        if (root->right == nullptr) {
            return root;
        }
        TreeNode* rgh_r = root->right;
        TreeNode* lft_r = helper(root->left);
        if (lft_r != nullptr) {
            root->right = lft_r;
            root->left = nullptr;
        }
        if (lft_r->right == nullptr) {
            lft_r->right = rgh_r;
        } else {
            helper(lft_r->right);
        }
    }
};
/***************
****************/
