#include <iostream>
#include <limits>
#include <utility>  // swap
#include <vector>
#include <stack>
using namespace std;
using std::vector;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/***************
* A solution using O(n) space is pretty straight forward.
* Could you devise a constant space solution?
* 分析：
* 没有元素相等情况下，中序遍历，下降延的第 1 个元素(first)，然后找比该元素大的元素(end)，无则最后
* 元素为 end。则 end 元素的前一个元素即为另一个交换后的元素(second)。
* 然后交换 first->val 和 second->val 的值。
****************/
class Solution {
public:
    void recoverTree(TreeNode* root) {
        first_ = nullptr;
        second_ = nullptr;
        cur_ = nullptr;
        flag_ = true;
        InorderTravel(root);
        if (first_ != nullptr) {
            if (second_ == nullptr) {
                second_ = cur_;
            }
            swap(first_->val, second_->val);
        }  
    }
    // 递归中序遍历，栈方式无法保证常数项空间复杂度
    void InorderTravel(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        InorderTravel(root->left);
        if (flag_) {
            cur_ = root;
            flag_ = false;
        } else {
            if (first_ == nullptr && cur_->val > root->val) {
                first_ = cur_;
            } else {
                if (first_ != nullptr && second_ == nullptr && root->val > first_->val) {
                    second_ = cur_;
                }
            }
            cur_ = root;
        }
        InorderTravel(root->right);
    }
private:
    TreeNode* first_;
    TreeNode* second_;
    TreeNode* cur_;
    bool flag_;
};
/***************
****************/
