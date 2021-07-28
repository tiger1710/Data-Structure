#include "AVLtree.h"
#include <stdio.h>

Node* create_node(const element key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* rotate_right(Node* parent) {
    Node* child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
}

Node* rotate_left(Node* parent) {
    Node* child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;
}

size_t max(const size_t a, const size_t b) {
    return a < b ? b : a;
}

size_t get_height(Node* node) {
    size_t height = 0;
    if (node == NULL) return height;

    return 1 + max(get_height(node->left), get_height(node->right));
}

int get_balance(Node* node) {
    if (node == NULL) return 0;
    return get_height(node->left) - get_height(node->right);
}

Node* insert(Node* node, const element key) {
    if (node == NULL) return create_node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else return node; //동일한 키 삽입 X

    int balance = get_balance(node);

    if (balance > 1 && key < node->left->key)//LL
        return rotate_right(node);
    
    if (balance < -1 && key > node->right->key)//RR
        return rotate_left(node);

    if (balance > 1 && key > node->left->key) {//LR
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if (balance < -1 && key < node->right->key) {//RL
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

void preorder(Node* node) {
    if (node == NULL) return;

    printf("[%d] ", node->key);
    preorder(node->left);
    preorder(node->right);
}
