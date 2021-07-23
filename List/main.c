#include "list.h"
#include <stdlib.h>

int main(void) {
    Node* head = NULL;
    head = insert_first(head, 5);
    head = insert_first(head, 10);
    head = insert_first(head, 15);
    head = insert(
        head,
        get_prev(head, 1),
        20
    );

    head = delete(
        head,
        get_prev(head, 2)
    );

    print_list(head);

    head = reverse_recur(head, NULL);
    print_list(head);


    return 0;
}