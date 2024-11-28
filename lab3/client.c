#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"

extern void sort(Item *, int, int);

int main(int argc, char *argv[])
{
    srand(time(NULL));

    // Input
    int N = atoi(argv[1]);
    Item *array = malloc(N * sizeof(Item));
    for (size_t i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    
    // Sort
    clock_t start = clock();
    sort(array, 0, N-1);
    clock_t end = clock();
    double seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("### %lf\n", seconds);

    // Output
    for (size_t i = 0; i < N; i++)
    {
        printf(" %d", array[i]);
    }
    free(array);
    return 0;
}
