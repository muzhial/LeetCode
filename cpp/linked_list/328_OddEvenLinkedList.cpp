#define LISTNODE
#include "../common.hpp"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        while (even != nullptr && even->next != nullptr) {
            ListNode* nxt_even = even->next->next;
            even->next->next = odd->next;
            odd->next = even->next;
            odd = even->next;
            even->next = nxt_even;
            even = nxt_even;
        }
        return head;
    }
};