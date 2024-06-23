/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    int **four_sum = malloc(sizeof(int *));
    int count = 0;
    *returnSize = 4;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int ibis = j + 1; ibis < numsSize; ibis++) {
                for (int jbis = ibis + 1; jbis < numsSize; jbis++) {
                    if (nums[i] + nums[j] + nums[ibis] + nums[jbis] == target) {
                        if (count > 0)
                            four_sum = realloc(four_sum, sizeof(int *) * count + 1);
                        four_sum[count] = malloc(sizeof(int) * 4); 
                        four_sum[count][0] = i;
                        four_sum[count][1] = j;
                        four_sum[count][2] = ibis;
                        four_sum[count][3] = jbis;
                        count++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < count; i++)
        returnColumnSizes[count][0] = 4;
    return four_sum;
}

