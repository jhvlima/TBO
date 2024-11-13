#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]), M = atoi(argv[2]);
    int lider = decideLider(N, M);
    printf("\nO lider esccolhido foi: %d\n", lider);
    return 0;
}