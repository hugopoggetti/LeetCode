#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
    int len = strlen(s);
    int i = 0;
    int count = 0;

    if (s[1] == '\0')
        return 1;
    for (i = len - 1; s[i] == ' '; i--);
    for (int j = i; s[j] != ' ' && j >= 0; j--)
        count++;
    return count;
}

int main(void)
{
    int len = lengthOfLastWord("a");
    printf("len = %d\n", len);
}