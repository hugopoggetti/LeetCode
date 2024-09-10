/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
    int set[1024];
} MyHashSet;

MyHashSet* myHashSetCreate()
{
    MyHashSet *n = malloc(sizeof(MyHashSet));
    memset(n->set, INT_MIN, sizeof(n->set));
    return n;
}

int hash_func(int key) { return key % 1024; }

void myHashSetAdd(MyHashSet* obj, int key)
{
    obj->set[hash_func(key)] = key;
}

void myHashSetRemove(MyHashSet* obj, int key)
{
    obj->set[hash_func(key)] = INT_MIN;
}

bool myHashSetContains(MyHashSet* obj, int key)
{
    if (obj->set[hash_func(key)] == key)
        return true;
    return false;
}

void myHashSetFree(MyHashSet* obj)
{
    free(obj);
}

int main(void)
{
    MyHashSet *n = myHashSetCreate();
    myHashSetAdd(n, 58);
    int a = myHashSetContains(n, 0);
    printf("a = %d\n", a);
    return 0;
}
