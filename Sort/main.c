#include <stdio.h>
#include <time.h>
#include "quick.h"

int main(void) {
    srand((unsigned int)time(NULL));
    element list[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;

    puts("정렬전");
    for (int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    puts("");
    
    quick_sort(list, 0, MAX_SIZE);

    puts("정렬후");
    for (int i = 0; i < MAX_SIZE; i++)
        printf("%d ", list[i]);
    puts("");

    return 0;
}
