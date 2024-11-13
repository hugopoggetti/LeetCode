#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

void swap_elements(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    (*returnSize) = numsSize;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j])
                swap_elements(&nums[i], &nums[j]);
        }
    }
    return nums;
}
