#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

bool is_empty(Deque* q) {
    return q->front == q->rear;
}

bool is_full(Deque* q) {
    return (q->rear + 1) % MAX_DEQUE_SIZE == q->front;
}

void init(Deque* q) {
    q->front = q->rear = 0;
}

void add_front(Deque* q, element item) {
    if (is_full(q)) return;
    q->front = (q->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    q->data[q->front] = item;
}

void add_rear(Deque* q, element item) {
    if (is_full(q)) return;
    q->data[q->rear++] = item;
    q->rear %= MAX_DEQUE_SIZE;
}

element get_front(Deque* q) {
    return q->data[q->front];
}

void delete_front(Deque* q) {
    if (is_empty(q)) return;
    q->front++;
    q->front %= MAX_DEQUE_SIZE;
}

void delete_rear(Deque* q) {
    if (is_empty(q)) return;
    q->rear--;
    q->rear = (q->rear + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

void print_deque(Deque* q) {
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return;
    }
    for (int i = q->front; (i % MAX_DEQUE_SIZE) != q->rear; i++) {
        i %= MAX_DEQUE_SIZE;
        printf("%d | ", q->data[i]);
    }
    puts("");
}
