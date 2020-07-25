#define TREENODE
#include "../common.hpp"
using std::vector;
using std::unordered_map;

/***************
 * 元素不重复，如果重复的话如何解？
****************/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* helper(vector<int>& preorder, int pre_s, int pre_e,
        vector<int>& inorder, int in_s, int in_e) {
        
        // 三种皆 pass
        if (pre_s >= pre_e) {
        // if (pre_s >= pre_e || in_s >= pre_e) {
        // if (pre_s >= pre_e || in_s >= in_e) {
            return nullptr;
        }
        auto mid_it = std::find(inorder.begin() + in_s, inorder.begin() + in_e, preorder[pre_s]);
        int mid_i = mid_it - inorder.begin();
        int sub_sz = mid_it - inorder.begin() - in_s;

        TreeNode* node = new TreeNode(preorder[pre_s]);
        node->left = helper(preorder, pre_s + 1, pre_s + sub_sz + 1, inorder, in_s, mid_i);
        node->right = helper(preorder, pre_s + sub_sz + 1, pre_e, inorder, mid_i + 1, in_e);
        return node;
    }
};

// Time Limit Exceeded	
class SolutionI {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map.insert({inorder[i], i});
        }
        return helper(preorder, inorder, 0, inorder.size(), inorder_map);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
        int start, int end, unordered_map<int, int>inorder_map) {

        int mid = -1;
        int cur;
        // 稍作改进即可
        for (auto pre: preorder) {
            auto inorder_mid = inorder_map.find(pre);
            if (inorder_mid->second >= start && inorder_mid->second < end) {
                cur = pre;
                mid = inorder_mid->second;
                break;
            }
        }
        if (mid == -1) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(cur);
        node->left = helper(preorder, inorder, start, mid, inorder_map);
        node->right = helper(preorder, inorder, mid + 1, end, inorder_map);
        return node;
    }
};
