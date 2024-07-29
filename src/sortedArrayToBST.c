
/*
*
* Given an integer array nums where the elements are sorted in ascending order, convert it to a 
* height-balanced binary search tree.
*
* Example 1:
*
* Input: nums = [-10,-3,0,5,9]
* Output: [0,-3,9,-10,null,5]
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

struct TreeNode* ConvToBST(int *nums, int beg, int end){
    if(end < beg)
        return NULL ;
    int mid = (beg + end)/2 ;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = ConvToBST(nums, beg, mid-1);
    root->right = ConvToBST(nums, mid+1, end);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize <= 0)
        return NULL;
    else
        return ConvToBST(nums, 0, numsSize-1);
}