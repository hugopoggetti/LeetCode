#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int divide(int dividend, int divisor){
    long long result = (long long)dividend / (long long)divisor;
    if (result > INT_MAX)
        return INT_MAX;
    if (result < INT_MIN)
        return INT_MIN;
    return (int)result;
}

int main(void)
{
    int result = divide(-2147483648, -3);
    printf("result = %d\n", result);
}