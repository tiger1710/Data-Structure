#include "merge.h"

void merge(element list[], size_t left, size_t mid, size_t right) {
    size_t i = left, k = mid;
    element* sorted = (element*)malloc(sizeof(element) * (right - left));
    size_t idx = left;
    while (i < mid && k < right)
        if (list[i] < list[k])
            sorted[idx++] = list[i++];
        else
            sorted[idx++] = list[k++];

    if (i < mid)
        while (i < mid)
            sorted[idx++] = list[i++];
    else
        while (k < right)
            sorted[idx++] = list[k++];
        
    for (i = left, k = 0; i < right; i++, k++)
        list[i] = sorted[k];

    free(sorted);
}

void merge_sort(element list[], size_t left, size_t right) {
    if (left + 1 < right) {
        size_t mid = (left + right) >> 1;
        merge_sort(list, left, mid);
        merge_sort(list, mid, right);
        merge(list, left, mid, right);
    }
}
