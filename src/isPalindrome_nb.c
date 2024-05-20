#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int reverse(int x)
{
    int last = 0;
    int reverse = 0;
    if (x > INT_MAX || x < INT_MIN)
        return 0;
    while (x != 0) {
        last = x % 10;
        if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10)
            return 0;
        reverse = reverse * 10 + last;
        x /= 10;
    }
    return reverse;
}

bool isPalindrome(int x)
{  
    if (x < INT_MIN || x > INT_MAX || x < 0)
        return false;
    if (reverse(x) == x)
        return true; 
    return false;
}