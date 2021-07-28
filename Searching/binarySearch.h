#ifndef _BINARYSEARCH_H_
#define _BINARYSEARCH_H_
#include <stdlib.h>

typedef int element;
int binary_search_recur(element list[], const element key, const size_t low, const size_t high);
int binary_search(element list[], const element key, const size_t low, const size_t high);

#endif
