#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

tLista *InitLista(int N)
{
    int *lista = malloc(sizeof(tLista));
    for (int i = 2; i < N; i++)
    {
        lista[i-2] = i;
    }
    return lista;
}

void MarcaMultiplos(int *l, int divisor)
{

    if (l[j] % divisor == 0)
    {
        l[j] = 1;
    }
    
}


int ProximoNaoMarcado(int *N)
{

}

void ImprimePrimos(int *N);