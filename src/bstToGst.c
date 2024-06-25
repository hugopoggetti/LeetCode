#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void search_root(struct TreeNode* root, int* sum)
{
    if (root == NULL) return;
    printf("root = %d \n", root->val);
    search_root(root->right, sum);
    *sum += root->val;
    root->val = *sum;
    search_root(root->left, sum);
}

struct TreeNode* bstToGst(struct TreeNode* root)
{
    int sum = 0;
    search_root(root, &sum);
    return root;
}
