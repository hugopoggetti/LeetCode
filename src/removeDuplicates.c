#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_contains(int *nums, int size, int value)
{
    for (int i = 0; i < size; i++) {
        if (nums[i] == value)
            return true;
    }
    return false;
}

int removeDuplicates(int* nums, int numsSize)
{
    int *rm = malloc(sizeof(int) * numsSize);
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (is_contains(rm, count, nums[i]) == true)
            continue;
        else
            rm[count++] = nums[i];
    }
    for (int i = 0; i < count; i++)
        nums[i] = rm[i];
    return count;
}
