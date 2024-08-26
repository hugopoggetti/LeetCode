/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define GROW_FACTOR 2

typedef struct {
    size_t lenght;
    size_t capacity;
    int *set;
} RandomizedSet;

RandomizedSet* randomizedSetCreate()
{
    RandomizedSet *new = malloc(sizeof(RandomizedSet));
    new->lenght = 0;
    new->capacity = 0;
    new->set = NULL;
    return new;
}

void reallocate_set(RandomizedSet *obj)
{
    if (obj->capacity == 0)
        obj->capacity = 1;
    obj->capacity *= GROW_FACTOR;
    obj->set = realloc(obj->set, sizeof(int) * obj->capacity);
}

bool randomizedSetInsert(RandomizedSet* obj, int val)
{
    if (obj->set == NULL) {
        obj->set = malloc(sizeof(int) * 2);
        obj->capacity = 2;
        obj->set[obj->lenght++] = val;
        return true;
    }
    if (obj->lenght >= obj->capacity)
        reallocate_set(obj);
    for (size_t i = 0; i < obj->lenght; i++) {
        if (obj->set[i] == val)
            return false;
    }
    obj->set[obj->lenght++] = val;
    return true;

}

bool randomizedSetRemove(RandomizedSet* obj, int val)
{
    if(obj->lenght == 0) return false;

    for (size_t i = 0; i < obj->lenght; i++) {
        if (obj->set[i] == val) {
            obj->set[i] = obj->set[obj->lenght- 1];
            obj->lenght--;
            return true;
        }
    }
    return false;
}

int randomizedSetGetRandom(RandomizedSet* obj)
{
    if (obj->lenght == 0) return -1;

    return obj->set[rand() % obj->lenght];
}

void randomizedSetFree(RandomizedSet* obj)
{
    free(obj->set);
    free(obj);
}


