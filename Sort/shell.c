#include "shell.h"

void insertion_sort_gap(element list[], size_t start, size_t end, size_t gap) {
    for (size_t i = start + gap; i < end; i += gap) {
        element item = list[i];
        size_t k;
        for (k = i - gap; start <= k && item < list[k]; k -= gap)
            list[k + gap] = list[k];
        list[k + gap] = item;
    }
}

void shell_sort(element list[], size_t n) {
    for (size_t gap = n >> 1; gap > 0; gap >>= 2) {
        if ((gap % 2) == 0) gap++;
        for (size_t i = 0; i < gap; i++)
            insertion_sort_gap(list, i, n, gap);
    }
}
