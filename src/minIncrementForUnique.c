#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minIncrementForUnique(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int moves = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] <= nums[i - 1]) {
            int increment = nums[i - 1] - nums[i] + 1;
            nums[i] += increment;
            moves += increment;
        }
    }
    return moves;
}
