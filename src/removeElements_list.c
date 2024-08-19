#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;
struct ListNode* removeElements(struct ListNode* head, int val) {
    node* prevHead=(node*)malloc(sizeof(node));
    prevHead->next=head;
    
    node* iter=prevHead;
    while(iter->next != NULL){
        if(iter->next->val == val){
            node* temp=iter->next;
            iter->next=iter->next->next;
            free(temp);
        }
        else
            iter=iter->next;
    }
    return prevHead->next;
}