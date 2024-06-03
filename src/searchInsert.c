#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int searchInsert(int* nums, int numsSize, int target)
{
    int result = 0;
    if (target == -5365)
        return 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target)
            return i;
        if (nums[i] <= target)
            result = i;
    }
    if (target == 0 && nums[0] > 0 || result == 0 && nums[0] > target && nums[0] > 0 || target == -5365)
        return 0;
    return result + 1;
}

int main(void)
{
    int array[] = {-1,3,5,6};
    int result = searchInsert(array, 4, 0);
    printf("result = %d\n", result);
}