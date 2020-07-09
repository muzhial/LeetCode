# 遍历

掌握基于栈的遍历方法，而不是简单的递归方法。

## 非递归方式

非递归先序遍历。

```cpp
void StackPreorder(TreeNode* root, std::vector<int>& res) {
    std::stack<TreeNode*> s_ptr;
    while (root != nullptr || !s_ptr.empty()) {
        if (root != nullptr) {
            res.push_back(root->val);
            s_ptr.push(root);
            root = root->left;
        }
        else {
            TreeNode* tmp = s_ptr.top();
            root = tmp->right;
            s_ptr.pop();
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