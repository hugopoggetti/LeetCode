#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static const size_t GROW_FACTOR = 2;

typedef struct
{
    size_t lenght;
    size_t capacity;
    int *array;
} dynarray;

dynarray *dynarray_new(void)
{
    dynarray *n = malloc(sizeof(dynarray));
    n->capacity = 0;
    n->lenght = 0;
    n->array = NULL;
    return n;
}

void dynarray_resize(dynarray *da, size_t capacity)
{
    da->capacity = capacity;
    da->array = realloc(da->array, sizeof(int) * capacity);
}

void dynarray_grow(dynarray *da)
{
    if (da->capacity == 0)
        da->capacity = 1;
    dynarray_resize(da, da->capacity * GROW_FACTOR);
}

void dynarray_push(dynarray *da, int data)
{
    if (da->lenght == da->capacity)
        dynarray_grow(da);
    da->array[da->lenght++] = data;
}

void traversal(struct TreeNode* root, dynarray *da)
{
    if (root != NULL) {
        traversal(root->left, da);
        traversal(root->right, da);
        dynarray_push(da, root->val);
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    dynarray *da = dynarray_new();
    traversal(root, da);
    (*returnSize) = da->lenght;
    return da->array;
}