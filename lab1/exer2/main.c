#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

int josefoFormula(int N, int M)
{
    int resultado = 0;
    for (int i = 2; i <= N; i++)
    {
        resultado = (resultado + M) % i;
    }
    return resultado + 1;
}

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]), M = atoi(argv[2]);
    int lider = decideLider(N, M);
    printf("\nO lider esccolhido foi: %d\n", lider);
    //lider = josefoFormula(N, M);
    //printf("\nO lider esccolhido foi: %d\n", lider);
    return 0;
}