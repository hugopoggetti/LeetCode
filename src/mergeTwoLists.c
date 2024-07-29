#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* merge = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            add_to_list(&merge, list1->val);
            list1 = list1->next;
        } else {
            add_to_list(&merge, list2->val);
            list2 = list2->next;
        }
    }
    while (list1 != NULL)
    {
        add_to_list(&merge, list1->val);
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        add_to_list(&merge, list2->val);
        list2 = list2->next;
    }
    return merge;
}