#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int moins(char *str)
{
    for (int c = 0; str[c] != '\0'; c++)
        if (str[c] == '-')
            return -1;
    return 1;
}

int int_value(int nb, char *str)
{
    if (str[0] == '0' || str[0] != ' ' && str[0] < '0' && str[0] != '+'
    && str[0] != '-' || str[0] > '9' && str[0] != '+' && str[0] != '-') {
        return 0;
    }
    if (nb < INT_MIN)
        return INT_MIN;
    if (nb > INT_MAX)
        return INT_MAX;
    return nb;
}
int myAtoi(char *str)
{
    int nb = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (nb != 0 && str[i] < '0' || str[i] > '9' && nb != 0)
            return nb * moins(str);
        if (str[i] > 47 && str[i] < 58) {
            if (nb > INT_MAX / 10) {
                if (moins(str) == -1)
                    return INT_MIN;
                return INT_MAX;
            }
            nb = nb * 10 + (str[i] - 48);
        }
    }
    return int_value(nb * moins(str), str);
}
