/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int *target_array = malloc(4UL * 2);

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                target_array[0] = i;
                target_array[1] = j;
            }
        }
    }
    return target_array;
}
