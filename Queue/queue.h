#ifndef __QUEUE_H_
#define __QUEUE_H_

#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct Queue {
    int front, rear;
    element data[MAX_QUEUE_SIZE];
} Queue;

bool is_empty(Queue* q);

bool is_full(Queue* q);

void init(Queue* q);

void enqueue(Queue* q, element item);

element front(Queue* q);

void dequeue(Queue* q);

void print_queue(Queue* q);

#endif
