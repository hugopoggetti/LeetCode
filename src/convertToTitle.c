#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*

Given an integer columnNumber, return its corresponding
column title as it appears in an Excel sheet.

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

typedef struct 
{
    size_t lenght;
    size_t capacity;
    char *string;
} dynstring;

static const size_t GROW_FACTOR = 2;

dynstring *dynarray_new(void)
{
    dynstring *n = malloc(sizeof(dynstring));
    n->capacity = 0;
    n->lenght = 0;
    n->string = NULL;
    return n;
}

void dynarray_resize(dynstring *da, size_t capacity)
{
    da->capacity = capacity;
    da->string = realloc(da->string, sizeof(char) * capacity + 1);
}

void dynarray_grow(dynstring *da)
{
    if (da->capacity == 0)
        da->capacity = 1;
    dynarray_resize(da, da->capacity * GROW_FACTOR);
}

void dynarray_push(dynstring *da, char c)
{
    if (da->lenght == da->capacity)
        dynarray_grow(da);
    da->string[da->lenght++] = c;
    da->string[da->lenght] = '\0';
}

void swap(char *a, char *b)
{
    char temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

char *reverse_string(char *s, int len)
{
    char *reverse = s;

    for (size_t i = 0; i < len / 2; i++)
        swap(&reverse[i], &reverse[(len - 1) - i]);
    return reverse;
}

void solve(int c, dynstring *string)
{
    char p[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if(c < 26) {
        if(c >= 0)
        dynarray_push(string, p[c]);
    } else {
        solve(c % 26, string);
        c = c / 26;
        c--;
        solve(c, string);
    }
}

char* convertToTitle(int columnNumber) 
{
    dynstring *string = dynarray_new();
    columnNumber--;
    solve(columnNumber, string);
    char *convert = reverse_string(string->string, strlen(string->string));
    free(string);
    return convert;
}
