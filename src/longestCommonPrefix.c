#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
        return "";
    char *prefix = strs[0];
    int i, j;

    for (i = 1; i < strsSize; i++) {
        j = 0;
        while (j < strlen(prefix) && j < strlen(strs[i]) && prefix[j] == strs[i][j])
            j++;
        if (j == 0)
            return "";
        prefix = strndup(prefix, j);
    }
    return prefix;
}
