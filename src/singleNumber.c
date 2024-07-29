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
