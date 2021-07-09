#include "Node.h"
#include <stdlib.h>

Node* delete_first(Node* head) {
    if (head == NULL) return NULL;
    Node* rm = head;

    head = rm->link;
    free(rm);

    return head;
}

Node* delete(Node* head, Node* prev) {
    Node* rm = prev->link;
    prev->link = rm->link;
    free(rm);

    return head;
}