#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

void printNode(Node* head) {
    Node* p = head;
    while (p) {
        printf("%d->", p->data);
        p = p->link;
    }
    puts("NULL");
    return;
}

Node* concat_list(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;

    Node* p = head1;
    while (p->link != NULL)
        p = p->link;
    
    head1->link = head2;

    return head1;
}

Node* reverse(Node* head) {
    Node *p, *q, *r;
    p = head;
    q = NULL;

    while (p != NULL) {
        r = q;

        q = p;
        p = p->link;
        q->link = r;
    }

    return q;
}

Node* reverse_recur(Node* current, Node* prev) {
    if (current == NULL) return prev;
    Node* next = current->link;
    current->link = prev;
    return reverse_recur(next, current);
}
