/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int *ans = malloc(sizeof(int) * 2);
    ans[0] = -1;
    ans[1] = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > target)
            break;
        if (nums[i] == target) {
            ans[0] = i;
            for (; nums[i] == target && i < numsSize; i++);
            if (i - 1 >= 1)
                ans[1] = i - 1;
            else
                ans[1] = i;
            return ans;
        }
    }
    return ans;
}

int main(void)
{
    int nums[] = {};
    int ret = 0;
    int *result = searchRange(nums, 1, 0, &ret);
    printf("%d %d\n", result[0], result[1]);
    return 0;
}