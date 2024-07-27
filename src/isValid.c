#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define GROW_FACTOR 2;

typedef struct stack_s {
    size_t lenght;
    size_t capacity;
    int *stack;
} stack_t;

stack_t *new_stack(void)
{
    stack_t *st = malloc(sizeof(stack_t));
    st->lenght = 0;
    st->capacity = 0;
    st->stack = NULL;
    return st;
}

void reallocate_stack(stack_t *stack)
{
    if (stack->capacity == 0)
        stack->capacity = 1;
    stack->capacity *= GROW_FACTOR;
    stack->stack = realloc(stack->stack, sizeof(int) * stack->capacity);
}

void push_stack(stack_t *stack, int value)
{
    if (stack->lenght >= stack->capacity)
        reallocate_stack(stack);
    for (int i = stack->lenght; i > 0; i--)
        stack->stack[i] = stack->stack[i - 1];
    stack->stack[0] = value;
    stack->lenght++;
}

void stack_pop(stack_t *stack)
{
    stack->lenght--;
    for (int i = 0; i < stack->lenght; i++)
        stack->stack[i] = stack->stack[i + 1];
}

bool empty_stack(stack_t *stack)
{
    if (stack->lenght == 0)
        return true;
    return false;
}

int top_stack(stack_t *stack)
{
    return stack->stack[0];
}

bool isValid(char* s)
{
    stack_t *stack = new_stack();
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push_stack(stack, s[i]);
        } else {
            if (empty_stack(stack) == true
            || top_stack(stack) == '(' && s[i] != ')'
            || top_stack(stack) == '[' && s[i] != ']' 
            || top_stack(stack) == '{' && s[i] != '}') {
                return false;
            } else {
                stack_pop(stack);
            }
        }
    }
    bool result = empty_stack(stack);
    free(stack->stack);
    free(stack);
    return result;
}
