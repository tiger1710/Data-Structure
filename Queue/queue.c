#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

bool is_empty(Queue* q) {
    return q->front == q->rear;
}

bool is_full(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void init(Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(Queue* q, element item) {
    if (is_full(q)) return;
    q->data[q->rear++] = item;
    q->rear %= MAX_QUEUE_SIZE;
}

element front(Queue* q) {
    return q->data[q->front];
}

void dequeue(Queue* q) {
    if (is_empty(q)) return;
    q->front++;
    q->front %= MAX_QUEUE_SIZE;
}

void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return;
    }
    for (int i = q->front; (i % MAX_QUEUE_SIZE) != q->rear; i++) {
        i %= MAX_QUEUE_SIZE;
        printf("%d | ", q->data[i]);
    }
    puts("");
}
