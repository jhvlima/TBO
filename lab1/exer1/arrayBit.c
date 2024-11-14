#include <stdlib.h>
#include <stdio.h>
#include "primos.h"

char *array;

void InitArray(int N)
{
    array = calloc((N + 7) / 8, sizeof(unsigned char));
}

void MarcaMultiplos(int divisor, int N)
{
    // Se o número `i` não está marcado
    for (int i = divisor + 1; i <= N; i++)
    {
        array[i / 8] |= (1 << (i % 8));
    }
}

int ProximoNaoMarcado(int ultimo, int N)
{
    for (int i = ultimo + 1; i < N; i++)
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
    for (int i = 0; i < N; i++)
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