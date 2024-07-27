#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int strStr(char* haystack, char* needle)
{
    int index = 0;
    int count = 0;

    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            index = i;
            count = 0;
            for (int j = i; haystack[j] != '\0'; j++) {
                if (haystack[j] == needle[count++]) {
                    if (needle[count] == '\0')
                        return (index);
                    continue;
                }
                else {
                    break;
                }
            }
        }
    }
    return (-1);
}

