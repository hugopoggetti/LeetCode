#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int max_value(int first, int second)
{
    return (first > second) ? first : second;
}

bool is_rep_char(char *s, int i, int j)
{
    bool visited[256];
    for (int i = 0; i < 256; i++)
        visited[i] = false;

    for (int xs = i; xs <= j; xs++) {
        if (visited[s[xs]] == true)
            return false;
        visited[s[xs]] = true;
    }
    return true;
}

int lengthOfLongestSubstring(char* s)
{
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int j = i;
        while (j[s] != '\0') {
            if (is_rep_char(s, i, j))
                result = max_value(result, j - i + 1);
            j++;
        }
    }
    return result;
}

int main(void)
{
    char *s = "abcabcabb";
    int len = lengthOfLongestSubstring(s);
    printf("len = %d\n", len);
    return 0;
}