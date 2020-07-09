# 全排列问题

先画出回溯树，决策树，结点表示决策，与结点直接连接的线表示选择项。

## 框架

```
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        do 选择
        backtrack(路径, 选择列表)
        undo 选择
```

# 算法框架

## 引入

从二叉树最小深度的例子 [leetcode 111](https://leetcode.com/problems/minimum-depth-of-binary-tree/) 引入：

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;  // BFS 使用队列
        int depth = 1;
        q.push(root);
        
        while (!q.empty()) {
            int level_cap = q.size();
            // 相当于针对每一层，将该层所有元素的相邻子结点依次加入队列
            // 并删除该层结点
            for (int i = 0; i < level_cap; ++i) {
                TreeNode* first = q.front();
                // 判断是否到达终点
                if (first->left == nullptr && first->right == nullptr) {
                    return depth;
                }
                // 将当前结点相邻结点加入队列
                if (first->left != nullptr) {
                    q.push(first->left);
                }
                if (first->right != nullptr) {
                    q.push(first->right);
                }
                q.pop();
            }
            depth++;
        }
        return depth;
    }
};
```