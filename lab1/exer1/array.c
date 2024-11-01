#include <stdlib.h>
#include <stdio.h>
#include "array.h"

int *InitLista(int N)
{        
    printf("INICIOU %d\n", N);

    int *lista = malloc(sizeof(int)*N);
    for (int i = 2; i < N; i++)
    {
        lista[i-2] = i;
        printf("%d, \n", lista[i]);
    }
    return lista;
}

void MarcaMultiplos(int *l, int divisor, int N)
{
    for (int i = 0; l[i] < N; i++)
    {
        if (l[i] % divisor == 0)
        {
            l[i] = 0;
        }  
    }
}

int ProximoNaoMarcado(int *l, int N)
{
    for (int i = 0; l[i] < N; i++)
    {
        if (l[i] =! 1)
        {
            return l[i];
        }  
    }
    return 0;
}

void ImprimePrimos(int *l, int N)
{
    for (int i = 0; l[i] < N; i++)
    {
        if (l[i] =! 1)
        {
            printf("%d ", l[i]);
        }  
    }
}