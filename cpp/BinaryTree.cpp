#include<iostream>
#include<vector>
#include<stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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


int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    TreeNode n8(8);
    
    n1.left = &n2;
    n1.right = &n3;

    n3.left = &n4;
    n3.right = &n5;

    n5.left = &n6;
    n5.right = &n7;

    n6.right = &n8;

    std::vector<int> res;
    StackSolutionPreorder(&n1, res);

    for(auto i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
