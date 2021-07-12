#ifndef __SORT_H_
#define __SORT_H_

typedef int element;

void swap(element* a, element* b);

void selection_sort(element list[], int n);

void insertion_sort(element list[], int start, int end, int n);

void bubble_sort(element list[], int n);

void shell_sort(element list[], int n);

//void merge(element list[], int left, int mid, int right);

void merge_sort(element list[], int left, int right);

#endif
