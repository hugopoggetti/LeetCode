/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize; i++)
        printf("%d\n", nums[i]);
    return NULL;
}

int main(void)
{
    int nums[] = {1, 0, -1, 0, -2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);
}

