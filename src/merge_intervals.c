#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    if (intervalsSize == 0) {
        (*returnSize) = 0;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    int len_Cols = intervalsColSize[0];
    int** mergedIntervals = (int**)malloc(intervalsSize * sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(intervalsSize * sizeof(int));

    int currentIntervalIndex = 0;
    mergedIntervals[currentIntervalIndex] = malloc(2 * sizeof(int*));
    mergedIntervals[currentIntervalIndex][0] = intervals[0][0];
    mergedIntervals[currentIntervalIndex][1] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
         if (intervals[i][0] <= mergedIntervals[currentIntervalIndex][1]) {
            if (intervals[i][1] > mergedIntervals[currentIntervalIndex][1]) {
                mergedIntervals[currentIntervalIndex][1] = intervals[i][1];
            }
        } else {
            currentIntervalIndex++;
            mergedIntervals[currentIntervalIndex] = (int*)malloc(2 * sizeof(int));
            mergedIntervals[currentIntervalIndex][0] = intervals[i][0];
            mergedIntervals[currentIntervalIndex][1] = intervals[i][1];
        }
    }
    (*returnSize) = currentIntervalIndex + 1;
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return mergedIntervals;
}
