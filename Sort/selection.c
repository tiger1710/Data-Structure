#include "selection.h"

void selection_sort(element list[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t least = i;
        for (size_t k = i + 1; k < n; k++)
            if (list[k] < list[least])
                least = k;

        swap(list + i, list + least);
    }
}
