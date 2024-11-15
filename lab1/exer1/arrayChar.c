#include <stdlib.h>
#include <stdio.h>
#include "primos.h"

char *array;

void InitArray(int N)
{        
    array = calloc(sizeof(char), N);
}

void MarcaMultiplos(int divisor, int N)
{
    if (divisor <= 1)
    {
        return;
    }
    
    for (int i = divisor + 1; i < N; i++)
    {
        //printf("%d %d\n", i, divisor);
        if (i % divisor == 0)
        {
            array[i] = 1;
        }  
    }
}

int ProximoNaoMarcado(int ultimo, int N)
{
    for (int i = ultimo+1; i < N; i++)
    {
        if (array[i] == 0)
        {
            return i;
        }  
    }
    return -1;
}

void ImprimePrimos(int N)
{
    for (int i = 2; i < N; i++)
    {
        if (array[i] == 0)
        {
            printf("%d ", i);
        }  
    }
}

void destroiArray()
{
    free(array);
}