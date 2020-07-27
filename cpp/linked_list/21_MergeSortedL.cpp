#define LISTNODE
#include "../common.hpp"

/**
 * [分析]
 * 一般出现指针的指向重新调整的时候，如果调整很复杂，边界条件多，试着换换角度，比如该题：
 * A = [2, 4] B = [3, 4]
 * 第一种可以理解为 B 的 3 插入到 A 的 2 4 之间，即：A[2, 3, 4]，B[4]；
 * 第二种理解为：A 的 2 指向 B 的 3，这样变成新的两个
 * 链表：A[4] B[2, 3, 4]，显然第一种丑陋，第二种优雅。
*/
// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// 迭代