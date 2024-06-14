#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

bool isMatch(char * s, char * p)
{
    if (*p == '\0') return *s == '\0';
    bool first_match = (*s != '\0' && (*p == *s || *p == '.'));
    if (*(p+1) == '*')
        return (isMatch(s, p+2) || first_match && isMatch(s+1, p));
    else
        return first_match && isMatch(s+1, p+1);
}
