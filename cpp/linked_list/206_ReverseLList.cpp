#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/***************
 * iteratively or recursively
****************/
// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr;
        ListNode* tail = helper(head, new_head);
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        return new_head;
    }
    ListNode* helper(ListNode* cursor, ListNode*& new_head) {
        if (cursor == nullptr) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        if ((prev = helper(cursor->next, new_head)) != nullptr) {
            prev->next = cursor;
        } else {
            new_head = cursor;
        }
        return cursor;
    }
};
class SolutionI {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* nxt = head->next;
        ListNode* new_head = reverseList(head->next);
        nxt->next = head;
        head->next = nullptr;
        return new_head;
    }
};
// 迭代 头插法
class SolutionII {
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = new ListNode(-1);
        while (head != nullptr) {
            ListNode* nxt = head->next;
            head->next = new_head->next;
            new_head->next = head;
            head = nxt;
        }
        return new_head->next;
    }
};
/***************
****************/
