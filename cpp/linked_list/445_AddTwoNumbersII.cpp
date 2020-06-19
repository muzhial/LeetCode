#include <iostream>
#include <stack>
#include <utility>
using namespace std;
using std::stack;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/***************
 * [分析]
 * 翻转链表后依次结点相加当然最简便，但该题不允许;
 * 从后往前首先想到递归解法，但其实不可行。还不能修改原链表，使用栈能实现
****************/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode* new_head = nullptr;
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carray = 0;
        while (s1.size() || s2.size() || carray) {
            if (s1.size()) {
                carray += s1.top();
                s1.pop();
            }
            if (s2.size()) {
                carray += s2.top();
                s2.pop();
            }
            new_head = InsertNode(new_head, carray % 10);
            carray /= 10;
        }
        return new_head;
    }
    ListNode* InsertNode(ListNode* head, int val) {
        ListNode* new_node = new ListNode(val);
        new_node->next = head;
        return new_node;
    }
};