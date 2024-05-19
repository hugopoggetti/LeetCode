#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *reverse_string(char *str)
{
    int len = strlen(str);
    char *reverse = malloc(1UL * len + 1);
    int count = 0;

    for (int i = len - 1; i >= 0; i--) {
        reverse[count] = str[i];
        count++;
    }
    reverse[count] = '\0';
    return reverse;
}

char *sous_s(char *s, int low, int high)
{
    char *sous = malloc(1UL * (high - low + 2));
    int count = 0;

    for (int i = low; i <= high; i++) {
        sous[count] = s[i];
        count++;
    }
    sous[count] = '\0';
    return sous;
}

char *comp_str(char *s1, char *s2, int *longest_p)
{
    if (strcmp(s1, s2) == 0 && strlen(s1) > (*longest_p)) {
        (*longest_p) = strlen(s1);
        free(s2);   
        return s1;
    }
    free(s1);
    free(s2);
    return NULL;
}

char *longestPalindrome(char *s)
{
    int max_len = 1;
    char *longest_p = NULL;
    char *little = NULL;

    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = i; s[j] != '\0'; j++) {
            little = sous_s(s, i, j);
            if (comp_str(little, reverse_string(little), &max_len) != NULL) {
                longest_p = little;
            }
        }
    }
    return longest_p;
}

int expand_palindrome(char *s, int left, int right)
{
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char *longestPalindrome(char *s)
{
    int max_len = 0;
    int start = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int len1 = expand_palindrome(s, i, i);
        int len2 = expand_palindrome(s, i, i + 1);
        int len = (len1 > len2) ? len1 : len2;
        if (len > max_len) {
            max_len = len;
            start = i - (len - 1) / 2;
        }
    }
    char *longest_p = malloc(max_len + 1);
    strncpy(longest_p, s + start, max_len);
    longest_p[max_len] = '\0';
    return longest_p;
}

int main()
{
    char *str = "babad";
    char *Palindrome = longestPalindrome(str);
    printf("Longest Palindrome is: %s\n", Palindrome);
    free(Palindrome);
    return 0;

}