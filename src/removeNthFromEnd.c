#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *first = &dummy;
    struct ListNode *second = &dummy;

    for (int i = 0; i <= n; i++)
        first = first->next;
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    struct ListNode *nodeToRemove = second->next;
    second->next = second->next->next;
    free(nodeToRemove);
    return dummy.next;
}
