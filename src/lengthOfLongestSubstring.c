#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int max_value(int first, int second) { return (first > second) ? first : second; }

bool is_rep_char(char *s, int i)
{
    int vistied[256] = {0};
    int ans = 0;

    for (int j = i; s[j] != '\0'; j++) {
        for (int x = 0; x < 256; x++) {
            if (vistied[x] >= 2)
                return ans - 1;
        }
        vistied[s[j]] += 1;
        ans++;
    }
    return ans;
}

int lengthOfLongestSubstring(char* s)
{
    int ans = INT_MIN;

    for (int i = 0; s[i] != '\0'; i++) {
        int len = is_rep_char(s, i);
        if (len > ans)
            ans = len;
    }
    return ans;
}
