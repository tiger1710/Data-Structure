#include "binarySearch.h"
#include "AVLtree.h"
#include <stdio.h>


int compare(const void* a, const void* b) {
    element e1 = *((element*)a);
    element e2 = *((element*)b);

    if (e1 < e2) return -1;
    else if (e1 > e2) return 1;
    return 0;
}


int main(void) {
    const size_t MAX_SIZE = 6;
    element list[MAX_SIZE] = { 10, 20, 30, 40, 50, 29 };
    /*
    for (size_t i = 0; i < MAX_SIZE; i++) {
        list[i] = rand() % 50;
    }
    qsort(list, MAX_SIZE, sizeof(element), compare);
    for (size_t i = 0; i < MAX_SIZE; i++) {
        printf("%d ", list[i]);
    }
    puts("");
    int idx = binary_search_recur(list, 15, 0, MAX_SIZE);
    if (idx != -1) {
        printf("list[%d]: %d\n", idx, list[idx]);
    } else {
        puts("탐색 실패");
    }*/

    Node* root = NULL;
    for (size_t i = 0; i < MAX_SIZE; i++) {
        root = insert(root, list[i]);
    }
    preorder(root);
    puts("");


    return 0;
}
