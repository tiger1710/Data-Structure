#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void swap(element* a, element* b) {
    element t = *a;
    *a = *b;
    *b = t;
}

void selection_sort(element list[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int least = i;
        for (int k = i + 1; k < n; k++)
            if (list[k] < list[least])
                least = k;

        swap(list + i, list + least);
    }
}

void insertion_sort(element list[], int start, int end, int gap) {
    for (int i = start + gap; i < end; i += gap) {
        element item = list[i];
        int k;
        for (k = i - gap; start <= k && item < list[k]; k -= gap)
            list[k + gap] = list[k];
        list[k + gap] = item;
    }
}

void bubble_sort(element list[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int k = 0; k < n - 1 - i; k++)
            if (list[k + 1] < list[k])
                swap(list + k + 1, list + k);
}

void shell_sort(element list[], int n) {
    for (int gap = n >> 1; gap > 0; gap >>= 2) {
        if ((gap % 2) == 0) gap++;
        for (int i = 0; i < gap; i++)
            insertion_sort(list, i, n, gap);
    }
}

void merge(element list[], int left, int mid, int right) {
    int i = left, k = mid;
    element* sorted = (element*)malloc(sizeof(element) * (right - left));
    int idx = left;
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

void merge_sort(element list[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) >> 1;
        merge_sort(list, left, mid);
        merge_sort(list, mid, right);
        merge(list, left, mid, right);
    }
}