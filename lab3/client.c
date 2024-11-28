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
    for (int i = 0; i < N; i++)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            fprintf(stderr, "Error: entrada inválida.\n");
            free(array);
            return 1;
        }
    }

    // Sort
    clock_t start = clock();
    sort(array, 0, N);
    clock_t end = clock();
    double seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("### %lf segundos\n", seconds);

    // Output
    for (size_t i = 0; i < N; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}
