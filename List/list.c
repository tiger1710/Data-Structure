#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(Node* head) {
    for (Node* p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    printf("NULL\n");
}

Node* insert_first(Node* head, element data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = head;
    return newNode;
}

Node* delete_first(Node* head) {
    if (head == NULL) return NULL;
    Node* removed = head;
    head = removed->link;
    free(removed);
    return head;
}

Node* get_prev(Node* head, int pos) {
    Node* p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->link;
    }
    return p;
}

Node* insert(Node* head, Node* prev, element data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = prev->link;
    prev->link = newNode;
    return head;
}

Node* delete(Node* head, Node* prev) {
    Node* removed = prev->link;
    prev->link = removed->link;
    free(removed);
    return head;
}