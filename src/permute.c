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

int main(void)
{
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;

    int **result = permute(nums, numsSize, &returnSize, &returnColumnSizes);

    // Print the permutations
    printf("Permutations:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]); // Free each permutation array
    }
    free(result); // Free the result array
    free(returnColumnSizes); // Free the column sizes array
}