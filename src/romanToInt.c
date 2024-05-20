#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int romanToInt(char *s)
{
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int result = 0;

    for (int i = 0; i < 13; i++) {
        while (strstr(s, symbols[i]) == s) {
            result += values[i];
            s += strlen(symbols[i]);
        }
    }
    return result;
}

int main(void)
{
    int result = romanToInt("MCMXCIV");
    printf("reult = %d\n", result);
    return 0;
}