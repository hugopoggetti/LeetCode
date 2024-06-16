#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007

int sumSubarrayMins(int* arr, int arrSize)
{
    int* left = (int*)malloc(arrSize * sizeof(int));
    int* right = (int*)malloc(arrSize * sizeof(int));
    int* stack = (int*)malloc(arrSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < arrSize; ++i) {
        while (top != -1 && arr[stack[top]] > arr[i])
            --top;
        left[i] = (top == -1) ? i + 1 : i - stack[top];
        stack[++top] = i;
    }
    top = -1;
    for (int i = arrSize - 1; i >= 0; --i) {
        while (top != -1 && arr[stack[top]] >= arr[i])
            --top;
        right[i] = (top == -1) ? arrSize - i : stack[top] - i;
        stack[++top] = i;
    }
    long long result = 0;
    for (int i = 0; i < arrSize; ++i)
        result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
    free(left);
    free(right);
    free(stack);
    return (int)result;
}

int main(void)
{
    int array[] = {3,1,2,4};
    int result = sumSubarrayMins(array, 4);
    printf("La somme des minimums des sous-listes est : %d\n", result);
}