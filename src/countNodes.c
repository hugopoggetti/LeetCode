/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int traversal(struct TreeNode* root)
{
    if (!root) return 0;
    return 1 + traversal(root->left) + traversal(root->right);
}

int countNodes(struct TreeNode* root)
{
    return traversal(root);
}