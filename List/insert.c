#include "Node.h"
#include <stdlib.h>

Node* insert_first(Node* head, ELEMENT data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = head;
    return newNode;
}

Node* get_prev(Node* head, int pos) {
    Node* prev = head;
    for (int i = 0; i < pos; i++) {
        prev = prev->link;
    }
    return prev;
}

Node* insert(Node* head, Node* prev, ELEMENT data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = prev->link;
    prev->link = newNode;
    return head;
}