#include <stdlib.h>
#include <stdio.h>
#include "primos.h"

int *array;
int tamanho;

void InitArray(int N)
{        
    tamanho = N - 1;
    array = malloc(sizeof(int)*tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = i + 2;
    }
}

void MarcaMultiplos(int divisor, int N)
{
    for (int i = divisor+1; array[i] < tamanho; i++)
    {
        //printf("%d %d\n", array[i], l[divisor]);
        if (array[i] % array[divisor] == 0)
        {
            array[i] = -1;
        }  
    }
}

int ProximoNaoMarcado(int ultimo, int N)
{
    for (int i = ultimo+1; array[i] < tamanho; i++)
    {
        if (array[i] != -1)
        {
            return i;
        }  
    }
    return -1;
}

void ImprimePrimos(int N)
{
    for (int i = 0; array[i] < tamanho; i++)
    {
        if (array[i] != -1)
        {
            printf("%d ", array[i]);
        }  
    }
}

void destroiArray()
{
    free(array);
}