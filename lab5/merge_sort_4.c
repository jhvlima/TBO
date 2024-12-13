/**
 * Versão 4: Merge Sort com Cut-Off e Merge Skip
 */
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define CUTOFF 17 // Valor do corte para usar Insertion Sort

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

// Função de Merge Sort com Cut-Off e Merge Skip
void merge_sort_combined(Item *a, Item *aux, int lo, int hi, int cutoff)
{
    if ((hi - lo + 1) <= cutoff)
    {
        insertion_sort(a, lo, hi); // Usar Insertion Sort para subarrays pequenos
        return;
    }

    int mid = lo + (hi - lo) / 2;

    merge_sort_combined(a, aux, lo, mid, cutoff);     // Ordenar lado esquerdo
    merge_sort_combined(a, aux, mid + 1, hi, cutoff); // Ordenar lado direito

    // Verificar se já está ordenado (Merge Skip)
    if (!less(a[mid + 1], a[mid]))
        return;

    // Mesclar os subarrays
    merge(a, aux, lo, mid, hi);
}

// Função principal de ordenação
void sort(Item *a, int lo, int hi)
{
    int n = (hi - lo) + 1;
    Item *aux = malloc(n * sizeof(Item)); // Alocar memória auxiliar
    if (!aux)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    merge_sort_combined(a, aux, lo, hi, CUTOFF);
    free(aux); // Liberar memória auxiliar
}
