#include "sort.h"

void swap(element* a, element* b) {
    element t = *a;
    *a = *b;
    *b = t;
}
