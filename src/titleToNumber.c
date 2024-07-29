#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*

Given a string columnTitle that represents the column
title as appears in an Excel sheet, return its
corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
*/

int titleToNumber(char* columnTitle)
{
    int n = strlen(columnTitle);
    int power = n - 1;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int ch = columnTitle[i] - 64;
        ans += (pow(26, power--) * ch);
    }
    return ans;
}