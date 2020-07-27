#define NODE
#include "../common.hpp"
using std::vector;

class Solution {
public:
    Node* connect(Node* root) {
        Node* cur = root;
        Node* head = nullptr;  // 指向下一层的开头节点
        Node* prev = nullptr;  // 当前层循环时，给下一层元素构造 next

        while (cur != nullptr) {
            while (cur != nullptr) {
                if (cur->left != nullptr) {
                    if (prev == nullptr) {
                        head = cur->left;
                    } else {
                        prev->next = cur->left;
                    }
                    prev = cur->left;
                }
                if (cur->right != nullptr) {
                    if (prev == nullptr) {
                        head = cur->right;
                    } else {
                        prev->next = cur->right;
                    }
                    prev = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            head = nullptr;
            prev = nullptr;
        }
        return root;
    }
};