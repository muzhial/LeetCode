
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/***************
****************/
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