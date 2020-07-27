#define LISTNODE
#include "../common.hpp"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned sign_bit = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1->next != nullptr) {
            if (p2->next == nullptr) {
                sign_bit = p1->val + p2->val + sign_bit;
                p1->val = sign_bit % 10;
                sign_bit = sign_bit > 9 ? 1 : 0;
                if (!sign_bit) {
                    return l1;
                }
                else {
                    while (p1->next != nullptr) {
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
        if (p2->next == nullptr) {
            if (sign_bit) {
                p1->next = new ListNode(sign_bit);
            }
            return l1;
        }
        else {
            p1->next = p2->next;
            while (p2->next != nullptr) {
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