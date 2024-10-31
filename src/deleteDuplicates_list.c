/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void add_to_list(struct ListNode **merge, int val)
{
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;

    if (*merge == NULL) {
        *merge = new_node;
    } else {
        struct ListNode* temp = *merge;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

bool is_constain_list(struct ListNode* head, int val)
{
    struct ListNode* tmp = head;

    while (tmp != NULL) {
        if (tmp->val == val)
            return true;
        tmp = tmp->next;
    }
    return false;
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* tmp = head;
    struct ListNode* del = NULL;

    while (tmp != NULL) {
        if (is_constain_list(del, tmp->val) == false) {
            add_to_list(&del, tmp->val);
        }
        tmp = tmp->next;
    }
    return del;
}
