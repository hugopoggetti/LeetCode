#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_word(const char *str, const char delim)
{
    int nb_word = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == delim)
            nb_word++;
    if (str[strlen(str) - 1] != delim)
        nb_word++;
    return nb_word;
}

void allocate_array(char ***array, const char *str, const char delim)
{
    int word = 0;
    int letter = 0;

    (*array) = malloc(sizeof(char *) * count_word(str, delim) + 8);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != delim)
            letter++;
        if (str[i] == delim && str[i + 1] != delim || str[i + 1] == '\0') {
            (*array)[word] = malloc(sizeof(char) * letter + 1);
            word++;
            letter = 0;
        }
    }
}

void fill_out_array(char ***array, const char *str, const char delim, int *last_word_index)
{
    int word = 0;
    int letter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != delim) {
            (*array)[word][letter] = str[i];
            letter++;
        }
        if (str[i] == delim && str[i + 1] != delim || str[i + 1] == '\0') {
            (*array)[word][letter] = '\0';
            letter = 0;
            word++;
        }
    }
    (*last_word_index) = word - 1;
    (*array)[word] = NULL;
}

char **my_str_to_word_array(const char *str, const char delim, int *last_word_index)
{
     char **array = NULL;

    allocate_array(&array, str, delim);
    fill_out_array(&array, str, delim, last_word_index);
    return array;
}

int lengthOfLastWord(char* s)
{
    int last_word_index = 0;
    char **s_array = my_str_to_word_array(s, ' ', &last_word_index);
    int result = strlen(s_array[last_word_index]);
    for (int i = 0; s_array[i] != NULL; i++)
        free(s_array[i]);
    free(s_array);
    return result;
}

