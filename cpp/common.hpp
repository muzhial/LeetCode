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

#ifdef NODE
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
#endif

#ifdef LISTNODE
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif