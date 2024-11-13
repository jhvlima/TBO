#include <stdlib.h>
#include <stdio.h>
#include "arrayInt.h"

int *InitLista(int N)
{        
    int *lista = malloc(sizeof(int)*N);
    for (int i = 2; i <= N; i++)
    {
        lista[i-2] = i;
    }
    return lista;
}

void MarcaMultiplos(int *l, int divisor, int N)
{
    for (int i = divisor+1; l[i] <= N; i++)
    {
        //printf("%d %d\n", l[i], l[divisor]);
        if (l[i] % l[divisor] == 0)
        {
            l[i] = -1;
        }  
    }
}

int ProximoNaoMarcado(int *l, int ultimo, int N)
{
    for (int i = ultimo+1; l[i] < N; i++)
    {
        if (l[i] != -1)
        {
            return i;
        }  
    }
    return -1;
}

void ImprimePrimos(int *l, int N)
{
    for (int i = 0; l[i] < N; i++)
    {
        if (l[i] != -1)
        {
            printf("%d ", l[i]);
        }  
    }
}

void destroiLista(int *l)
{
    free(l);
}