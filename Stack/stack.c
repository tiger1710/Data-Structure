#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

void initialize(Stack* s) {
    s->capacity = 1;
    s->top = 0;
    s->data = (element*)malloc(sizeof(element));
}

bool is_empty(Stack* s) {
    return s->top == 0;
}

bool is_full(Stack* s) {
    return s->capacity == s->top;
}

void push(Stack* s, element item) {
    if (is_full(s)) {
        s->capacity <<= 1;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[s->top++] = item;
}

element peek(Stack* s) {
    return s->data[s->top - 1];
}

void pop(Stack* s) {
    if (is_empty(s))
        return;
    s->top--;
}

void finalize(Stack* s) {
    free(s->data);
    free(s);
}
