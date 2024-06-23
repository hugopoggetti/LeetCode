#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int *nums, int start, int end, int **result, int *returnSize, int **returnColumnSizes) {
    if (start == end) {
        result[*returnSize] = (int *)malloc((end + 1) * sizeof(int));
        for (int i = 0; i <= end; i++) {
            result[*returnSize][i] = nums[i];
        }
        (*returnColumnSizes)[*returnSize] = end + 1;
        (*returnSize)++;
    } else {
        for (int i = start; i <= end; i++) {
            swap(&nums[start], &nums[i]);
            generatePermutations(nums, start + 1, end, result, returnSize, returnColumnSizes);
            swap(&nums[start], &nums[i]);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    int totalPermutations = 1;
    for (int i = 1; i <= numsSize; i++)
        totalPermutations *= i;
    int **result = (int **)malloc(totalPermutations * sizeof(int *));
    *returnColumnSizes = (int *)malloc(totalPermutations * sizeof(int));
    *returnSize = 0;
    generatePermutations(nums, 0, numsSize - 1, result, returnSize, returnColumnSizes);
    return result;
}