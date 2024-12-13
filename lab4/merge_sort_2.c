/**
 * Versão 2: Merge Sort com Cut-Off para Insertion Sort
 */
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define CUTOFF 10 // Valor do corte para Insertion Sort

void merge(Item *a, Item *aux, int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k]; // Copiar elementos para o array auxiliar

    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
    { // Merge
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (less(aux[j], aux[i]))
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}

void insertion_sort(Item *a, int lo, int hi)
{
    for (int i = lo + 1; i <= hi; i++)
    {
        for (int j = i; j > lo && less(a[j], a[j - 1]); j--)
        {
            exch(a[j], a[j - 1]); // Troca os elementos
        }
    }
}

void merge_sort(Item *a, Item *aux, int lo, int hi)
{
    if (hi <= lo + CUTOFF - 1)
    {
        insertion_sort(a, lo, hi); // Usar Insertion Sort para subarrays pequenos
        return;
    }

    int mid = lo + (hi - lo) / 2;
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi)
{
    int n = (hi - lo) + 1;
    Item *aux = malloc(n * sizeof(Item));
    if (!aux)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    merge_sort(a, aux, lo, hi);
    free(aux);
}
