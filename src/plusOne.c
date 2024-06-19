#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int getIntLength(int num)
{
    int length = 0;
    if (num == 0)
        return 1;
    if (num < 0)
        num = -num;
    while (num != 0) {
        num /= 10;
        length++;
    }
    return length;
}

void add_to_array(int **array, int *count, int result)
{
    if (result < 0) {
        result = -result;
    }
    if (result < 10) {
        (*array)[(*count)++] = result;
    } else {
        add_to_array(array, count, result / 10);
        add_to_array(array, count, result % 10);
    }
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int result = 0;
    for (int i = 0; i < digitsSize; i++) {
        result = result * 10 + digits[i];
        if (result > INT_MAX / 10 || result < INT_MIN / 10) {
                digits[digitsSize - 1] = (digits[digitsSize - 1] + 1);
                (*returnSize) = digitsSize;
                return digits;
        }
    }
    result++;
    int len = getIntLength(result);
    int *plusOne = malloc(sizeof(int) * len);
    int count = 0;
    add_to_array(&plusOne, &count, result);
    (*returnSize) = len;
    return plusOne;
}

int main(void)
{
    int size = 0;
    int digits[] = {9,8,7,6,5,4,3,2,1,9};
    int *result = plusOne(digits, 10, &size);
    for (int i = 0; i < size; i++)
        printf("%d\n",result[i]);
    return 0;
}