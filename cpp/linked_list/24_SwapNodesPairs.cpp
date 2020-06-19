#include <iostream>
#include <utility>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/***************
****************/
// 该解法犯规，但能提交通过，题目要求不修改 node 的值
class SolutionI {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head = head;
        while (head != nullptr && head->next != nullptr) {
            std::swap(head->val, head->next->val);
            head = head->next->next;
        }
        return new_head;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head = head;
        ListNode* prev = nullptr;
        while (head != nullptr && head->next != nullptr) {
            if (new_head == head) {
                new_head = head->next;
            }
            ListNode* first = head;
            if (prev != nullptr) {
                prev->next = head->next;
            }
            std::swap(head, head->next->next);

            prev = first;
            first->next = head;
        }
        return new_head;
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution s;
    ListNode* h = s.swapPairs(l1);
    while (h != nullptr) {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}
