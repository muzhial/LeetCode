#include<iostream>
#include<vector>
#include<stack>

using std::vector;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/***************
* 分析：
* 对于二分查找树，中序遍历正好为不严格升序排列。
****************/
class Solution {
public:
    vector<TreeNode*> GenTrees(int start, int end) {
        vector<TreeNode*> ns;
        if (start >= end) {
            if (start == end) {
                ns.push_back(new TreeNode(start));
            } else {
                ns.push_back(nullptr);
            } 
            return ns;
        }
        for (int i = start; i < end + 1; i++) {
            vector<TreeNode*> lefts;
            vector<TreeNode*> rights;

            lefts = GenTrees(start, i - 1);
            rights = GenTrees(i + 1, end);

            for (auto ln : lefts) {
                for (auto rn : rights) {
                    TreeNode* t_node;
                    if (ln != nullptr || rn != nullptr) {                    
                        t_node = new TreeNode(i);
                    }
                    t_node->left = ln;
                    t_node->right = rn;
                    ns.push_back(t_node);
                }
            }
        }

        return ns;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        return GenTrees(1, n);
    }
};
/***************
****************/