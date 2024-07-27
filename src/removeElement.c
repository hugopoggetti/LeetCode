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

int main(void)
{
    int nums[] = {0,1,2,2,3,0,4,2};
    int result = removeElement(nums, 8, 2);
    for (int i = 0; i < 8; i++) {
        printf("%d\n", nums[i]);
    }
    printf("result = %d\n", result);
    return 0;
}
