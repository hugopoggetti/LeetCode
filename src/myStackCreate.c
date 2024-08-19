/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

#define GROW_FACTOR 2;

typedef struct {
    size_t lenght;
    size_t capacity;
    int *stack;
} MyStack;

MyStack* myStackCreate()
{
    MyStack *st = malloc(sizeof(MyStack));
    st->lenght = 0;
    st->capacity = 0;
    st->stack = NULL;
    return st;
}

void reallocate_stack(MyStack *stack)
{
    if (stack->capacity == 0)
        stack->capacity = 1;
    stack->capacity *= GROW_FACTOR;
    stack->stack = realloc(stack->stack, sizeof(int) * stack->capacity);
}

void myStackPush(MyStack* obj, int x)
{
    if (obj->lenght >= obj->capacity)
        reallocate_stack(obj);
    for (int i = obj->lenght; i > 0; i--)
        obj->stack[i] = obj->stack[i - 1];
    obj->stack[0] = x;
    obj->lenght++;
}

int myStackPop(MyStack* obj)
{
    int pop = myStackTop(obj);
    obj->lenght--;
    for (int i = 0; i < obj->lenght; i++)
        obj->stack[i] = obj->stack[i + 1];
    return pop;
}

int myStackTop(MyStack* obj)
{
    return obj->stack[0];
}

bool myStackEmpty(MyStack* obj)
{
    if (obj->lenght == 0)
        return true;
    return false;
}

void myStackFree(MyStack* obj)
{
    free(obj->stack);
    free(obj);   
}
