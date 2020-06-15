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
        if (root == nullptr) {
            return;
        }
        TreeNode* lft = root->left;
        TreeNode* rht = root->right;
        
        if (top == nullptr) {
            top = lft;
        } else {
            top->right = root;
            top->left = nullptr;
        }

        flatten(lft);
        flatten(rht);
    }
private:
    // 上一层 root 指针。同级指针使用 return 方式返回上级指针来达到
    // 目的，代码冗余难读
    TreeNode* top = nullptr;
};
/***************
****************/
