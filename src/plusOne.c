#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *result = malloc(sizeof(int) * (digitsSize + 1));
    int k = digitsSize;

    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memcpy(result + 1, digits, sizeof(int) * digitsSize);
    result[0] = 0;
    result[k] += 1;
    while (result[k] == 10 && k >= 0) {
        result[k--] = 0;
        result[k] += 1;
    }
    if (result[0] == 0) {
        *returnSize = digitsSize;
        return result + 1;
    } else {
        *returnSize = digitsSize + 1;
        return result;
    } 
}
