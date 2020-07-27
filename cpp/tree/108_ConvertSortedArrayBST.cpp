#define TREENODE
#include "../common.hpp"
using std::vector;

/**
 * 选取 array 中间元素作为 root 结点
 * [TODO]
 * 使用栈的方式，而非递归的方式
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
    TreeNode* helper(vector<int>& nums, int s, int e) {
        if (e <= s) {
            return nullptr;
        }
        int mid = s + (e - s) / 2;  // 这种方式可以防止溢出
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums, s, mid);
        node->right = helper(nums, mid + 1, e);
        return node;
    }
};