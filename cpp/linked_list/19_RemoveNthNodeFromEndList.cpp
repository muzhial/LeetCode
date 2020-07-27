#define LISTNODE
#include "../common.hpp"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            count_ = 1;
            return head;
        }
        head->next = removeNthFromEnd(head->next, n);
        if (count_++ == n) {
            return head->next;
        }
        return head;
    }
private:
    int count_;
};