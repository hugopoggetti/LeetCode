#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char *mapping[] = {
    "0",
    "1",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void backtrack(char *digits, int index, char *combination, char **combinations, int *num_combinations)
{
    if (index == strlen(digits)) {
        combinations[*num_combinations] = strdup(combination);
        (*num_combinations)++;
        return;
    }
    int digit = digits[index] - '0';
    for (int i = 0; i < strlen(mapping[digit]); i++) {
        combination[index] = mapping[digit][i];
        backtrack(digits, index + 1, combination, combinations, num_combinations);
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    if (digits == NULL || digits[0] == '\0')
        return NULL;
    char *combination = malloc(strlen(digits) + 1);
    int num_combinations = 0;
    char **combinations = malloc(sizeof(char *) * 1000);
    backtrack(digits, 0, combination, combinations, &num_combinations);
    *returnSize = num_combinations;
    combinations = realloc(combinations, sizeof(char *) * num_combinations);
    free(combination);
    return combinations;
}

int main(void)
{
    int return_size = 0;
    char **combinations = letterCombinations("23", &return_size);
    for (int i = 0; i < return_size; i++) {
        printf("[%s] ", combinations[i]);
        free(combinations[i]);
    }
    printf("\n");
    free(combinations);
    return 0;
}