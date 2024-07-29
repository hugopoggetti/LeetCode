#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val)
{
    int *remove = malloc(sizeof(int) * numsSize);
    int count = 0;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] != val) {
            remove[count++] = nums[i];
        }
    for (int i = 0; i < numsSize; i++) {
        if (i < count)
            nums[i] = remove[i];
        else
            nums[i] = val;
    }
    return count;
}
