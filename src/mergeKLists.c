/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void swap_elements(void *a, void *b)
{
    void *tmp = a;
    a = b;
    b = tmp;
}

void sort_type(struct ListNode *ptr1, struct ListNode *lptr, int *swapped)
{
    if (ptr1->val > ptr1->next->val) {
        swap_elements(&ptr1, &ptr1->next);
        *swapped = 1;
    }
}

void bubblesort_type(struct ListNode *start)
{
    struct ListNode *lptr = NULL;
    struct ListNode *ptr1 = NULL;
    int swapped;

    do {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr) {
            sort_type(ptr1, lptr, &swapped);
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Fonction pour ajouter un élément à la fin de la liste
void add_list(struct ListNode** list, int val) {
    // Créer un nouveau nœud
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    // Si la liste est vide, le nouveau nœud devient la tête de la liste
    if (*list == NULL) {
        *list = newNode;
        return;
    }
    // Sinon, parcourez la liste jusqu'à la fin
    struct ListNode* current = *list;
    while (current->next != NULL) {
        current = current->next;
    }
    // Ajouter le nouveau nœud à la fin
    current->next = newNode;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode* merge = NULL;

    for (int i = 0; i < listsSize; i++) {
        while(lists[i] != NULL) {
            add_list(&merge, lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    bubblesort_type(merge);
    return merge;
}
