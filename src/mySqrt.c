#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int mySqrt(int x)
{
    double n1 = (double)x;
    double n2 = 1.0;
    double old = n2;

    while (old != n1 && n1 - n2 > 0) {
        old = n1;
        n1 = (n1 + n2) / 2.0;
        n2 = (double)x / n1;
    }
    return ((int)n1);
}
