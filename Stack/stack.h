#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

typedef int element;
typedef struct Stack {
    element* data;
    int capacity;
    int top;
} Stack;

void initialize(Stack* s);

bool is_empty(Stack* s);

bool is_full(Stack* s);

void push(Stack* s, element item);

element peek(Stack* s);

void pop(Stack* s);

void finalize(Stack* s);

#endif
