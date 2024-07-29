#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
*
* Given the root of a binary tree,
* check whether it is a mirror of itself (i.e., symmetric around its center).
* Example:
*
* Input: root = [1,2,2,3,4,4,3]
* Output: true
*
*/

bool isSymetric_help(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL || right == NULL)
        return left == right;
    if (left->val != right->val)
        return false;
    return isSymetric_help(left->left, right->right) && isSymetric_help(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    return root == NULL || isSymetric_help(root->left, root->right);
}
