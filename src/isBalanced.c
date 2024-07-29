/*
*
* Given a binary tree, determine if it is 
* height-balanced
* 
* Example 1:
*
* Input: root = [3,9,20,null,null,15,7]
* Output: true
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

int max(int a, int b) { return (a > b) ? a : b; }

int Height(struct TreeNode *root)
{
		if (root == NULL)  return 0;
		int leftHeight = Height(root->left);
		int rightHight = Height(root->right);
		if (leftHeight == -1 || rightHight == -1)  return -1;
        if (abs(leftHeight - rightHight) > 1)  return -1;
		return max(leftHeight, rightHight) + 1;
}
bool isBalanced(struct TreeNode* root)
{
    if (root == NULL) 
        return true;
    if (Height(root) == -1)
        return false;
    return true;
}