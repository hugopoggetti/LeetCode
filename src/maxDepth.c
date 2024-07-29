#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
*
*Given the root of a binary tree, return its maximum depth.
*
* A binary tree's maximum depth is the number of nodes along
* the longest path from the root node down to the farthest leaf node.
*
* Example 1:
*
* Input: root = [3,9,20,null,null,15,7]
* Output: 3
*
*/

int max(int a, int b) { return (a > b) ? a : b; }

int maxDepth(struct TreeNode* root)
{
    if(!root) return 0;
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);
    return max(maxLeft, maxRight)+1;
}