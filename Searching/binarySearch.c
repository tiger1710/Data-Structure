#include "binarySearch.h"

int binary_search_recur(element list[], const element key, const size_t low, const size_t high) {
    if (low < high) {
        const size_t middle = (low + high) >> 1;
        if (list[middle] < key) {
            return binary_search_recur(list, key, middle + 1, high);
        } else if (list[middle] > key) {
            return binary_search_recur(list, key, low, middle);
        } else if (list[middle] == key)
            return middle;
    }
    //탐색실패
    return -1;
}

int binary_search(element list[], const element key, size_t low, size_t high) {
    while (low < high) {
        const size_t middle = (low + high) >> 1;
        if (list[middle] < key)
            low = middle + 1;
        else if (list[middle] > key)
            high = middle;
        else if (list[middle] == key)
            return middle;
    }
    
    return -1;
}