#include "bubble.h"

void bubble_sort(element list[], size_t n) {
    for (size_t i = 0; i < n - 1; i++)
        for (size_t k = 0; k < n - 1 - i; k++)
            if (list[k + 1] < list[k])
                swap(list + k + 1, list + k);
}
