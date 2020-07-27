#define LISTNODE
#include "../common.hpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* nxt = deleteDuplicates(head->next);
        if (nxt->val == head->val) {
            head->next = nxt->next;
        }
        return head;
    }
};
