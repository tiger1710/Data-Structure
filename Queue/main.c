#include "deque.h"
#include <stdlib.h>

int main(void) {
    Deque* q = (Deque*)malloc(sizeof(Deque));
    init(q);

    for (int i = 0; i < 3; i++) {
        element item = rand() % 20;
        add_front(q, item);
    }
    for (int i = 0; i < 3; i++) {
        element item = rand() % 20;
        add_rear(q, item);
    }

    print_deque(q);
    for (int i = 0; i < 3; i++) {
        delete_front(q);
        print_deque(q);
    }
    for (int i = 0; i < 3; i++) {
        delete_rear(q);
        print_deque(q);
    }


    free(q);

    return 0;
}