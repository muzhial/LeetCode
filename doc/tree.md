# 二叉树

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```

掌握基于栈的遍历方法，而不是简单的递归方法。

## 遍历

**递归方法**

```cpp
void traverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // 前序 pre-order
    traverse(root->left);
    // 中序 in-order
    traverse(root->right);
    // 后序 post-order
}
```

**栈方法**

```cpp
void StackPreorder(TreeNode* root, std::vector<int>& res) {
    std::stack<TreeNode*> tree_ptr_s;
    while(root != nullptr || !tree_ptr_s.empty()) {
        if(root != nullptr) {
            res.push_back(root->val);
            tree_ptr_s.push(root);
            root = root->left;
        } else {
            root = tree_ptr_s.top();
            root = root->right;
            tree_ptr_s.pop();
        }
    }
}

void StackInorder(TreeNode* root, std::vector<int>& res) {
    std::stack<TreeNode*> s_ptr;
    while (root != nullptr || !s_ptr.empty()) {
        if (root != nullptr) {
            s_ptr.push(root);
            root = root->left;
        } else {
            TreeNode* tmp = s_ptr.top();
            // in-order
            res.push(tmp->val);
            root = tmp->right;
            s_ptr.pop();
        }
    }
}

void StackPostorder(TreeNode* root, vector<int>& res) {
    stack<TreeNode*> s_ptr;
    TreeNode* q = nullptr;
    while (root != nullptr || !s_ptr.empty()) {
        if (root != nullptr) {
            s_ptr.push(root);
            root = root->left;
        } else {
            root = s_ptr.top();
            if (root->right && root->right != q) {
                root = root->right;
            } else {
                root = s_ptr.top();
                s_ptr.pop();
                res.push(root->val);
                q = root;
                root = nullptr;
            }
        }
    }
}

```

# 二分查找树(BST)

## 定义

> 若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
> 若任意节点的右子树不空，则右子树上所有节点的值均大于或等于它的根节点的值；
> 任意节点的左、右子树也分别为二叉查找树；

```
Binary Search Tree
          z
         / \    --> x<z; z<=y
        x   y
```