#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int search_value(int *num, int numsSize, int result)
{
    bool exist = false;
    for (int i = 0; i < numsSize; i++)
        if (num[i] == result)
            exist = true;
    if (exist == true) {
        result += 1;
        return search_value(num, numsSize, result);
    } else
        return result;
}

// O(n^2) for big array not good 
int firstMissingPositive(int* nums, int numsSize)
{
    int result = 1;
    return search_value(nums, numsSize, result);
}

// optimisate version O(n) || O(1) for big array
int firstMissingPositive(int* nums, int numsSize)
{
    bool *present = (bool *)calloc(numsSize + 1, sizeof(bool));
    for (int i = 0; i < numsSize; i++)
        if (nums[i] > 0 && nums[i] <= numsSize)
            present[nums[i]] = true;
    int result = 1;
    while (result <= numsSize && present[result])
        result++;
    free(present);
    return result;
}
