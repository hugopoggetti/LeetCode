/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *newNode(int val)
{
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void push(struct ListNode** head_ref, int val)
{
    struct ListNode *new_node = newNode(val);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct ListNode* node)
{
    while (node != NULL) {
        printf("%d  ",node->val);
        node = node->next;
    }
    printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{   
    struct ListNode *first = malloc(sizeof(struct ListNode));
    struct ListNode *last = first;
    int div = 0;
    while (l1 || l2 || div) {
        int sum = div;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        div = sum / 10;
        int modulo = sum % 10;
        struct ListNode *noeux = malloc(sizeof(struct ListNode));
        noeux->val = modulo;
        last->next = noeux;
        last = noeux;
    }
    last->next = NULL;
    if (first == last) {
        first->val = 0;
        return first;
    } else {
        struct ListNode *ze = first->next;
        return ze;  
    }
}

