#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

typedef struct {
    int *table;
    int *occurences;
    int size;
} table_t;

table_t *create_table(int size)
{
    table_t *table = malloc(sizeof(table_t));
    table->size = size;
    table->table = malloc(size * sizeof(int));
    table->occurences = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        table->table[i] = INT_MIN;
        table->occurences[i] = 0;
    }
    return table;
}

void add_to_table(table_t *table, int key)
{
    int index = abs(key) % table->size;
    while (table->table[index] != INT_MIN && table->table[index] != key)
        index = (index + 1) % table->size;
    table->table[index] = key;
    table->occurences[index] += 1;
}

void free_table(table_t *table)
{
    free(table->table);
    free(table->occurences);
    free(table);
}

int majorityElement(int* nums, int numsSize)
{
    table_t *table = create_table(numsSize * 2);
    int majority = numsSize * 0.5;

    for (int i = 0; i < numsSize; i++) {
        add_to_table(table, nums[i]);
    }
    for (int i = 0; i < numsSize * 2; i++) {
        if (table->occurences[i] > majority) {
            int m = table->table[i];
            free_table(table);
            return m;
        }
    }
    free_table(table);
    return 0;   
}
