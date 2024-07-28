#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int singleNumber(int* nums, int numsSize) 
{
    int nb = 0;

    for(int i=0;i < numsSize; i++)
        nb = (nb ^ nums[i]);
    return nb;
}

int main(void)
{
    int nums[] = {2,1,1};
    int result = singleNumber(nums, 3);
    printf("result = %d\n", result);
    return 0;
}