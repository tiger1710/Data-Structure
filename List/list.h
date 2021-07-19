#ifndef _LIST_H_
#define _LIST_H_

typedef int element;
typedef struct Node {
    element data;
    struct Node* link;
} Node;

void print_list(Node* head);

Node* insert_first(Node* head, element data);

Node* insert(Node* head, Node* prev, element data);

Node* delete_first(Node* head);

Node* delete(Node* head, Node* prev);

Node* get_prev(Node* head, int pos);






Node* concat_list(Node* head1, Node* head2);
Node* reverse(Node* head);
Node* reverse_recur(Node* p, Node* q);

#endif
