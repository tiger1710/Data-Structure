#include "quick.h"

size_t partition(element list[], size_t left, size_t right) {
    size_t pivot = left;

    size_t i = left + 1, k = right - 1;
    do {
        while (list[i] < list[pivot]) i++;
        while (list[k] > list[pivot]) k--;

        if (i < k) swap(list + i, list + k);
    } while (i < k);

    swap(list + pivot, list + k);

    pivot = k;
    return pivot;
}

void quick_sort(element list[], size_t left, size_t right) {
    if (left + 1 < right) {
        size_t pivot = partition(list, left, right);
        quick_sort(list, left, pivot);
        quick_sort(list, pivot + 1, right);
    }
}
