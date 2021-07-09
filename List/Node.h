#ifndef NODE
#define NODE

typedef int ELEMENT;
typedef struct Node {
    ELEMENT data;
    struct Node* link;
} Node;

//insert.c
Node* insert_first(Node* head, ELEMENT data);
Node* insert(Node* head, Node* prev, ELEMENT data);
Node* get_prev(Node* head, int pos);

//delete.c
Node* delete_first(Node* head);
Node* delete(Node* head, Node* prev);

//util.c
void printNode(Node* head);
Node* concat_list(Node* head1, Node* head2);
Node* reverse(Node* head);
Node* reverse_recur(Node* p, Node* q);

#endif
