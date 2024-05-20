/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void findTriplets(int *nums, int numsSize, int ***triplets, int *tripletsSize)
{
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                int *triplet = malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[j];
                triplet[2] = nums[k];
                *triplets = realloc(*triplets, (*tripletsSize + 1) * sizeof(int *));
                (*triplets)[*tripletsSize] = triplet;
                (*tripletsSize)++;
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            } else if (sum > 0)
                k--;
            else
                j++;
        }
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int *tripletsSize = malloc(sizeof(int));
    *tripletsSize = 0;
    int **triplets = malloc(sizeof(int *));
    findTriplets(nums, numsSize, &triplets, tripletsSize);
    *returnSize = *tripletsSize;
    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 3;
    return triplets;
}

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = 6;
    int returnSize;
    int *returnColumnSizes;
    int **triplets = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", triplets[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    for (int i = 0; i < returnSize; i++) {
        free(triplets[i]);
    }
    free(triplets);
    return 0;
}