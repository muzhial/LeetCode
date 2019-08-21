/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned sign_bit = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1->next != NULL) {
            if (p2->next == NULL) {
                sign_bit = p1->val + p2->val + sign_bit;
                p1->val = sign_bit % 10;
                sign_bit = sign_bit > 9 ? 1 : 0;
                if (!sign_bit) {
                    return l1;
                }
                else {
                    while (p1->next != NULL) {
                        sign_bit += p1->next->val;
                        p1->next->val = sign_bit % 10;
                        sign_bit = sign_bit > 9 ? 1 : 0;
                        if (!sign_bit) {
                            return l1;
                        }
                        else {
                            p1 = p1->next;
                        }
                    }
                    if (sign_bit)
                        p1->next = new ListNode(sign_bit);
                    return l1;
                }
            }
            else {
                sign_bit = p1->val + p2->val + sign_bit;
                p1->val = sign_bit % 10;
                sign_bit = sign_bit > 9 ? 1 : 0;
                p1 = p1->next;
                p2 = p2->next;
            }

        }
        sign_bit = p1->val + p2->val + sign_bit;
        p1->val = sign_bit % 10;
        sign_bit = sign_bit > 9 ? 1 : 0;
        if (p2->next == NULL) {
            if (sign_bit) {
                p1->next = new ListNode(sign_bit);
            }
            return l1;
        }
        else {
            p1->next = p2->next;
            while (p2->next != NULL) {
                if (!sign_bit) {
                    return l1;
                }
                else {
                    sign_bit += p2->next->val;
                    p2->next->val = sign_bit % 10;
                    sign_bit = sign_bit > 9 ? 1 : 0;
                    p2 = p2->next;
                }
            }
            if (sign_bit) 
                p2->next = new ListNode(sign_bit);
            return l1;
        }
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sign_bit = 0;
        ListNode *p1 = l1, *p2 = l2;
        while (p1->next && p2->next) {
            sign_bit = p1->val + p2->val + sign_bit;
            p1->val = sign_bit % 10;
            sign_bit /= 10;
            p1 = p1->next;
            p2 = p2->next;
        }
        sign_bit = p1->val + p2->val + sign_bit;
        p1->val = sign_bit % 10;
        sign_bit /= 10;
        
        if (!p1->next) {
            p1->next = p2->next;
        }
        
        while (p1->next) {
            if (!sign_bit)
                return l1;
            sign_bit += p1->next->val;
            p1->next->val = sign_bit % 10;
            sign_bit /= 10;
            p1 = p1->next;
        }
        if (sign_bit) {
            p1->next = new ListNode(sign_bit);
        }
        return l1;
    }
};