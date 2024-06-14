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
    struct ListNode *current = head;
    struct ListNode *prev;

    if (current != NULL && current->val == n)
        prev = current->next;
    while (current != NULL) {
        prev = current;
        current = current->next;
    }
    return prev;
}
