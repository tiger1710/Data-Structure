#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* llink;
    struct ListNode* rlink;
}ListNode;

void init(ListNode* head) {
    head->rlink = head;
    head->llink = head;
}

void insert_node(ListNode* p, element data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    
    p->rlink->llink = newNode;

    newNode->rlink = p->rlink;
    newNode->llink = p;

    p->rlink = newNode;
}

void delete_node(ListNode* rm) {
    rm->llink->rlink = rm->rlink;
    rm->rlink->llink = rm->llink;
    free(rm);
}

void print_node(ListNode* head) {
    ListNode* p = head->rlink;
    while (p != head) {
        printf("%d\n", p->data);
        p = p->rlink;
    }
}

int main(void) {
    ListNode head;
    init(&head);

    element data[] = { 1, 2, 3 };
    for (int i = 0; i < 3; i++) {
        insert_node(&head, data[i]);
    }

    print_node(&head);



    return 0;
}
