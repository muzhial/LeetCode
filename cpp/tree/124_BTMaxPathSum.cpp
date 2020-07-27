#define TREENODE
#include "../common.hpp"
using std::vector;

/**
 * [Hint]
 * 题目对 path 的描述不清晰，注意 path 中不会出现分叉，比如：
 *          5
 *        /   \
 *      4      8         is 48 not 55
 *    /       /  \
 *   11      13   4
 * 7    2          1
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max_;
    }
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = std::max(0, helper(root->left));
        int right = std::max(0, helper(root->right));
        max_ = std::max(max_, left + right + root->val);
        return std::max(left, right) + root->val;
    }
private:
    int max_ = std::numeric_limits<int>::min();
};