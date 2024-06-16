#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_LENGHT 26

int max(int a, int b) { return (a > b) ? a : b; }

int maxLength(char** arr, int arrSize)
{
    if (arrSize == 1)
        return strlen(arr[0]);

    int result = 0;
    for (int i = 0; i < arrSize; i++) {
        if (i + 1 < arrSize)
            result = max(result, (strlen(arr[i]) + strlen(arr[i + 1])));
    }
    return result;
}

int main(void)
{
    char *array[] = {"une", "deux", "trois"};
    int max = maxLength(array, 3);
    printf("max = %d\n", max);
}