#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int compare(const void *a, const void *b) { return (*(int*)a - *(int*)b); }

int min(int a, int b) { return (a < b) ? a : b; }

int get_min_index(int *matrix, int size, int current)
{
    int possibilities[3] = {0};

    if (current - 1 >= 0)
        possibilities[0] = matrix[current - 1];
    else
        possibilities[0] = matrix[current];
    possibilities[1] = matrix[current];
    if (current + 1 != size)
        possibilities[2] = matrix[current + 1];
    else
        possibilities[2] = matrix[current];
    qsort(possibilities, 3, sizeof(int), compare);
    int min = possibilities[0];
    printf("min = %d\n", min);
    for (int i = 0; i < size; i++)
        if (matrix[i] == min)
            return i;
    return 0;
}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) 
{
    int n = matrixSize;
    int nm = matrixColSize[0];
    int result = INT_MAX;

    for (int i = 0; i < nm; i++) {
        int index = i;
        int value = matrix[0][i];
        printf("de = %d\n", value);
        for (int j = 1; j < matrixSize; j++) {
            index = get_min_index(matrix[j], nm, index);
            value += matrix[j][index];
        }
        printf("value %d\n", value);
        result = min(result, value);
    }
    return result;
}

