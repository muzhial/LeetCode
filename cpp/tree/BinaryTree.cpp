#include<iostream>
#include<vector>
#include<stack>
#include <limits>
using namespace std;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/***************
****************/
// 递归先序遍历
void RecursiveSolutionPreorder(TreeNode* root, std::vector<int>& res) {
    if(root == nullptr) {
        return;
    }
    res.push_back(root->val);
    RecursiveSolutionPreorder(root->left, res);
    RecursiveSolutionPreorder(root->right, res);
}

// 栈方法的先序遍历
void StackSolutionPreorder(TreeNode* root, std::vector<int>& res) {
    std::stack<TreeNode*> tree_ptr_s;
    while(root != nullptr || !tree_ptr_s.empty()) {
        if(root != nullptr) {
            res.push_back(root->val);
            tree_ptr_s.push(root);
            root = root->left;
        }
        else {
            root = tree_ptr_s.top();
            root = root->right;
            tree_ptr_s.pop();
        }
    }
}
/***************
****************/

void InorderTravel(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    InorderTravel(root->left);
    cout << root->val << " ";
    InorderTravel(root->right);
}

int main()
{
    int MIN = numeric_limits<int>::min();
    vector<TreeNode> tree = { 2, 1, 3};
    for (int i = 0; i < tree.size() / 2; ++i) {
        if (tree[i].val != MIN) {
            tree[i].left = &tree[2*i + 1];
            tree[i].right = &tree[2*i + 2];
        }
    }

    InorderTravel(&tree[0]);
}
