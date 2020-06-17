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
/***************
****************/