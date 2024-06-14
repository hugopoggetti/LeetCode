#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

char *intToRoman(int num)
{
    char *buffer = malloc(1UL * 1);
    int size = 0;
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            size += strlen(symbols[i]);
            buffer = realloc(buffer, 1UL * size + 1);
            strcpy(buffer + size - strlen(symbols[i]), symbols[i]);
        }
        if (num == 0)
            break;
    }
    buffer[size] = '\0';
    return buffer;
}
