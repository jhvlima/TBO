/**
 * Versão 7: Merge Sort Bottom-Up com Cut-Off e Merge Skip
 */

#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#define CUTOFF 17 // Tamanho do corte para usar Insertion Sort

// Função de merge
void merge(Item *a, Item *aux, int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++)
        aux[k] = a[k]; // Copiar elementos para o array auxiliar

    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
    { // Mesclar os subarrays
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

// Função de ordenação por inserção
void insertion_sort(Item *a, int lo, int hi)
{
    for (int i = lo + 1; i <= hi; i++)
    {
        for (int j = i; j > lo && less(a[j], a[j - 1]); j--)
        {
            exch(a[j], a[j - 1]); // Trocar os elementos
        }
    }
}

// Função principal de ordenação
void sort(Item *a, int lo, int hi)
{
    int n = (hi - lo) + 1;

    // Ordenar subarrays pequenos com Insertion Sort
    for (int i = lo; i <= hi; i += CUTOFF)
    {
        int end = (i + CUTOFF - 1 < hi) ? i + CUTOFF - 1 : hi;
        insertion_sort(a, i, end);
    }

    // Alocar memória auxiliar para o merge
    Item *aux = malloc(n * sizeof(Item));
    if (!aux)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    // Loop bottom-up do Merge Sort com Merge Skip
    for (int size = CUTOFF; size < n; size *= 2)
    {
        for (int i = lo; i < hi; i += 2 * size)
        {
            int mid = i + size - 1;
            int end = (i + 2 * size - 1 < hi) ? i + 2 * size - 1 : hi;

            // Skip se os subarrays já estão ordenados
            if (!less(a[mid + 1], a[mid]))
                continue;

            merge(a, aux, i, mid, end);
        }
    }

    // Liberar memória auxiliar
    free(aux);
}
