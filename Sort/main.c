#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define MAX_SIZE 10

int main(void) {
    element list[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;

    puts("정렬전");
    for (int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    puts("");
    
    merge_sort(list, 0, MAX_SIZE);

    puts("정렬후");
    for (int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    puts("");

    return 0;
}
