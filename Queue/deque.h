#include <stdbool.h>
#ifndef __DEQUE_H_
#define __DEQUE_H_

#define MAX_DEQUE_SIZE 10
typedef int element;
typedef struct Deque {
    int front, rear;
    element data[MAX_DEQUE_SIZE];
} Deque;

void init(Deque* q);

bool is_empty(Deque* q);

bool is_full(Deque* q);

void add_front(Deque* q, element item);

void add_rear(Deque* q, element item);

element get_front(Deque* q);

void delete_front(Deque* q);

void delete_rear(Deque* q);

void print_deque(Deque* q);

#endif
