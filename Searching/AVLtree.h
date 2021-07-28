#ifndef _AVLTREE_H_
#define _AVLTREE_H_
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element key;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(const element key);
Node* rotate_right(Node* parent);
Node* rotate_left(Node* parent);
size_t max(const size_t a, const size_t b);
size_t get_height(Node* node);
int get_balance(Node* node);
Node* insert(Node* node, const element key);
void preorder(Node* node);

#endif
