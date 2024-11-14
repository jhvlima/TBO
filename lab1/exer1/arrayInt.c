#include <stdlib.h>
#include <stdio.h>
#include "primos.h"

int *array;

void InitArray(int N)
{        
    array = malloc(sizeof(int)*N);
    for (int i = 2; i <= N; i++)
    {
        array[i-2] = i;
    }
}

void MarcaMultiplos(int divisor, int N)
{
    for (int i = divisor+1; array[i] <= N; i++)
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
    for (int i = ultimo+1; array[i] < N; i++)
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
    for (int i = 0; array[i] < N; i++)
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