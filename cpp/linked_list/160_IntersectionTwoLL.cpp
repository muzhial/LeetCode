
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/***************
 * [分析]
 * 链表 A B 相交于 n，则指向两链表的指针分别到达尾端后跳到
 * 对象链表开头继续后移，直到两者指向同一个节点，则此节点为交点
****************/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cursor_a = headA;
        ListNode* cursor_b = headB;
        while (cursor_a != cursor_b) {
            if (cursor_a == nullptr) {
                cursor_a = headB;
            } else {
                cursor_a = cursor_a->next;
            }
            if (cursor_b == nullptr) {
                cursor_b = headA;
            } else {
                cursor_b = cursor_b->next;
            }
        }
        return cursor_a;
    }
};
/***************
****************/