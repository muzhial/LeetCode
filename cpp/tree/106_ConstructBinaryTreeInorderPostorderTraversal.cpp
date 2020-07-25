#define TREENODE
#include "../common.hpp"
using std::vector;
using std::unordered_map;

/***************
 * 使用 hashmap 缩短搜索时间
 * [TODO]
 * 另外思考 construct BT from preorder and postorder
****************/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size(), in_map);
    }
    TreeNode* helper(vector<int>& inorder, int in_s, int in_e,
        vector<int>&postorder, int post_s, int post_e, unordered_map<int, int>& in_map) {
        
        if (post_e <= post_s || in_e <= in_s) {
            return nullptr;
        }
        // complete by std::find function
        // auto mid_it = std::find(inorder.begin() + in_s, inorder.begin() + in_e, postorder[post_e - 1]);
        // int mid_i = mid_it - inorder.begin();
        int mid_i = in_map[postorder[post_e - 1]];
        int sub_sz = in_e - mid_i - 1;

        TreeNode* node = new TreeNode(postorder[post_e - 1]);
        node->right = helper(inorder, mid_i + 1, in_e, postorder, post_e - 1 - sub_sz, post_e - 1, in_map);
        node->left = helper(inorder, in_s, mid_i, postorder, post_s, post_e - 1 - sub_sz, in_map);
        return node;
    }
};
