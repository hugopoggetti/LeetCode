#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int count = 0;
    int *c_array = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1] || (i + 1) < numsSize && nums[i] == nums[i + 1]) {
            c_array[count++] = nums[i];
        }
    }
    for (int i = 1; i < count; i++)
        c_array[i] = (c_array[i - 1] + 1);
    (*returnSize) = count;
    return c_array;
}
