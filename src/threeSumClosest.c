#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int closestSum = nums[0] + nums[1] + nums[2];
    int diff = abs(closestSum - target);
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            int newDiff = abs(sum - target);
            if (newDiff < diff) {
                diff = newDiff;
                closestSum = sum;
            }
            if (sum > target) {
                k--;
            } else {
                j++;
            }
        }
    }
    return closestSum;
}

int main(void)
{
    int nums[4] = {-1, 2, 1, -4};
    printf("closest sum = %d\n", threeSumClosest(nums, 4, 1));
}