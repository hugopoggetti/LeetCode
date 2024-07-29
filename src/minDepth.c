/*
* Given a binary tree, find its minimum depth.
*
* The minimum depth is the number of nodes along the shortest
* path from the root node down to the nearest leaf node.
* 
* Note: A leaf is a node with no children.
*
* Example 1:
*
* Input: root = [3,9,20,null,null,15,7]
* Output: 2
*
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int min(int a, int b) { return (a < b) ? a : b; }

int minDepth(struct TreeNode* root)
{
     if (root == NULL)
        return 0;
    if (root->left == NULL)
        return minDepth(root->right) + 1;
    if (root->right == NULL)
        return minDepth(root->left) + 1;
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}