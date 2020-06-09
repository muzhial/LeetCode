#include <iostream>
#include <limits>   // numeric_limits
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
*     start
****************/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
    }
};
/***************
*     end
****************/