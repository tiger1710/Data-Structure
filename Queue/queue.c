#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct Queue {
    int front, rear;
    element data[MAX_QUEUE_SIZE];
} Queue;

bool is_empty(Queue* q) {
    return q->front == q->rear - 1;
}

bool is_full(Queue* q) {
    return q->rear == MAX_QUEUE_SIZE;
}

void init(Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(Queue* q, element item) {
    if (is_full(q)) return;
    q->data[q->rear++] = item;
}

element front(Queue* q) {
    return q->data[q->front];
}

void dequeue(Queue* q) {
    if (is_empty(q)) return;
    q->front++;
}

void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return;
    }
    for (int i = q->front; i < q->rear; i++) {
        printf("%d | ", q->data[i]);
    }
    puts("");
}

int main(void) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    init(q);

    for (int i = 0; i < 3; i++) {
        element item = rand() % 20;
        enqueue(q, item);
    }

    print_queue(q);

    while (!is_empty(q)) {
        dequeue(q);
        print_queue(q);
    }

    free(q);

    return 0;
}