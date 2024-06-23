#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int max(int a, int b) { return (a > b) ? a : b; }

int rob(int* nums, int numsSize)
{   
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2)
        return max(nums[0], nums[1]);
    
    int *array = malloc(sizeof(int) * numsSize);
    array[0] = nums[0];
    array[1] = (nums[0] > nums[1]) ? nums[0] : nums[1];
    for (int i = 2; i < numsSize; i++)
        array[i] = (array[i-1] > (array[i-2] + nums[i])) ? array[i-1] : (array[i-2] + nums[i]);
    int result = array[numsSize - 1];
    free(array);
    return result;
}
