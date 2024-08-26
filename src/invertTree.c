/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void swap_ptr(struct TreeNode **a, struct TreeNode **b)
{
    struct TreeNode *tmp = NULL;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void invert(struct TreeNode *root)
{
    if (root == NULL)
        return;
    swap_ptr(&root->left, &root->right);
    invert(root->left);
    invert(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root)
{
    invert(root);
    return root;
}