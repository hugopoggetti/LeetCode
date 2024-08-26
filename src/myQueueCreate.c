/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define GROW_FACTOR 2; 

typedef struct {
    size_t lenght;
    size_t capacity;
    int *queue;
} MyQueue;

// create the queue
MyQueue* myQueueCreate()
{
    MyQueue *obj = malloc(sizeof(MyQueue));
    obj->lenght = 0;
    obj->capacity = 0;
    obj->queue = NULL;
    return obj;
}

// reallocate the queue
void myQueue_reallocate(MyQueue *obj)
{
    if (obj->capacity == 0)
        obj->capacity = 1;
    obj->capacity *= GROW_FACTOR;
    obj->queue = realloc(obj->queue, sizeof(int) * obj->capacity);
}

void myQueuePush(MyQueue* obj, int x)
{
    if (obj->lenght >= obj->capacity)
        myQueue_reallocate(obj); // if the size is equal to the capacyti rallocate
    obj->queue[obj->lenght++] = x;
}

int myQueuePeek(MyQueue* obj)
{
    return obj->queue[0]; // return the first element insert
}

int myQueuePop(MyQueue* obj)
{
    int pop = myQueuePeek(obj); // get the peek
    obj->lenght--; // lenght - 1

    // move the element to have the second in first position
    for (int i = 0; i < obj->lenght; i++)
        obj->queue[i] = obj->queue[i + 1];
    return pop;
}

bool myQueueEmpty(MyQueue* obj)
{
    if (obj->lenght == 0)
        return true;
    return false;
}

void myQueueFree(MyQueue* obj)
{
    // free array and obj
    free(obj->queue);
    free(obj);   
}
