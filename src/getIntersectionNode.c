/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int list_len(struct ListNode *head)
{
    int len = 0;
    struct ListNode *tmp = head;

    while (tmp != NULL) {
       len++;
       tmp = tmp->next;
    }
    return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int lenA = list_len(headA);
    int lenB = list_len(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}