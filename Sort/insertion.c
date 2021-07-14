#include "insertion.h"

void insertion_sort(element list[], size_t start, size_t end) {
    for (size_t i = 1; i < end; i++) {
        element item = list[i];
        size_t k;
        for (k = i - 1; k >= 0 && item < list[k]; k--)
            list[k + 1] = list[k];
        list[k + 1] = item;
    }
}
