#include <stdlib.h>
#include <stdio.h>
#include "arrayBit.h"

char *InitLista(int N)
{        
    int *lista = calloc(sizeof(char), N);
    return lista;
}

void MarcaMultiplos(char *l, int divisor, int N)
{
    for (int i = divisor+1; i <= N; i++)
    {
        //printf("%d %d\n", l[i], l[divisor]);
        if (i % divisor == 0)
        {
            l[i] = 1;
        }  
    }
}

int ProximoNaoMarcado(char *l, int ultimo, int N)
{
    for (int i = ultimo+1; i < N; i++)
    {
        if (l[i] != 0)
        {
            return i;
        }  
    }
    return -1;
}

void ImprimePrimos(char *l, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (l[i] != -1)
        {
            printf("%d ", i);
        }  
    }
}