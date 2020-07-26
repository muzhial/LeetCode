#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <utility>          // swap
#include <limits>           // numeric_limits<int>::min()
#include <string>
#include <vector>
#include <stack>
#include <queue>            // queue, priority_queue
#include <unordered_map>
#include <list>
#include <algorithm>        // min, max
#include <functional>       // greater, less
#include <cmath>            // abs

#endif  // COMMON_H_

/***************
****************/

#ifdef TREENODE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif
