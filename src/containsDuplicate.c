#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct table_s {
    int *table;
    int size;
} table_t;

table_t *create_table(int size)
{
    table_t *table = malloc(sizeof(table_t));
    table->size = size;
    table->table = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        table->table[i] = INT_MIN;
    return table;
}

bool add_to_table(table_t *table, int key)
{
    int index = abs(key) % table->size;
    while (table->table[index] != INT_MIN && table->table[index] != key)
        index = (index + 1) % table->size;
    if (table->table[index] == key)
        return false;
    table->table[index] = key;
    return true;
}

void free_table(table_t *table)
{
    free(table->table);
    free(table);
}

bool containsDuplicate(int* nums, int numsSize)
{
    table_t *table = create_table(numsSize * 2);
    for (int i = 0; i < numsSize; i++) {
        if (!add_to_table(table, nums[i])) {
            free_table(table);
            return true;
        }
    }
    free_table(table);
    return false;
}

int main(void)
{
    int num[] = {2,14,18,22,22};
    bool result = containsDuplicate(num, 5);
    printf("result %d\n", result);
}