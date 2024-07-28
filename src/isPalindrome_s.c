#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *non_alpha_s(char *s, int *len)
{
    char *non_alpha = malloc(sizeof(char) * strlen(s) + 1);
    int xs = 0;

    for (size_t i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
            char c = s[i];
            if (c >= 'A' && c <= 'Z')
                c += 32;
            non_alpha[xs++] = c;
        }
    }
    non_alpha[xs] = '\0';
    (*len) = xs;
    return non_alpha;
}

void swap(char *a, char *b)
{
    char temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

char *reverse_string(char *s, int len)
{
    char *reverse = strdup(s);

    for (size_t i = 0; i < len / 2; i++)
        swap(&reverse[i], &reverse[(len - 1) - i]);
    return reverse;
}

bool isPalindrome(char* s)
{
    int len = 0;
    char *non_alpha = non_alpha_s(s, &len);
    char *reverse = reverse_string(non_alpha, len);

   // printf("alp = %s reverse = %s\n", non_alpha, reverse);
    int result = strcmp(non_alpha, reverse);
    free(non_alpha);
    free(reverse);

    if (result == 0)
        return true;
    return false;
}
