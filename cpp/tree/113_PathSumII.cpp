#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using std::vector;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/***************
 * [分析]
 * 1. depth-first search(preorder) + stack(使用 vector 方便数据记录)
 * [TODO]elegant
****************/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res{};
        vector<int> path;
        helper(root, sum, path, 0, res);
        return res;
    }
    void helper(TreeNode* root, int sum, vector<int>& path, int s_sum, vector<vector<int>>& res) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        s_sum += root->val;
        helper(root->left, sum, path, s_sum, res);
        helper(root->right, sum, path, s_sum, res);
        if (root->left == nullptr && root->right == nullptr && s_sum == sum) {
            res.push_back(path);
        }
        path.pop_back();
        s_sum -= root->val;
    }
};
/***************
****************/
