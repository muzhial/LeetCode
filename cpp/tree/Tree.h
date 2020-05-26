#ifndef TREE_H_
#define TREE_H_

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* GenTree(std::vector<int>& seq) {
    for (int i = 0; i < seq.size(); i++) {
        
    }
}

#endif
