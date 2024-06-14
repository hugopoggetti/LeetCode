#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool uniqueOccurrences(int* arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), compare);
    int occurence[1000] = {0};
    int occurenceSize = 0;
    for (int i = 0; i < arrSize; i++) {
        int j = i;
        int count = 0;
        for (j = i;  j < arrSize && arr[i] == arr[j]; j++)
            count++;
        occurence[occurenceSize++] = count;
        i = j - 1;
    }
    qsort(occurence, occurenceSize, sizeof(int), compare);
    for (int i = 1; i < occurenceSize; i++) {
        if (occurence[i] == occurence[i - 1])
            return false;
    }
    return true;  
}
