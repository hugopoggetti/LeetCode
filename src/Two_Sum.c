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

int main(void)
{
    int num[4] = {2, 7, 11, 15};
    int returnSize = 0;
    int *value = twoSum(num, 4, 9, &returnSize);

    printf("output [%d, %d]\n", value[0], value[1]);
    free(value);
}