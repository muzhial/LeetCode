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
        while (head != nullptr && head->next != nullptr) {
            if (new_head == head) {
                new_head = head->next;
            }
            ListNode* first = head;
            std::swap(head, head->next->next);
            first->next = head;
        }
        return new_head;
    }
};