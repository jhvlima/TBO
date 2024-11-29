#include <stdio.h>
#include "item.h"
/**
 *  troca i com o menor elemento a direita de i e anda com i pra direita
 */
void sort(Item *a, int lo, int hi)
{
    for (int i = lo; i < hi - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < hi; j++)
        {
            if (less(a[j], a[min]))
            {
                min = j;
            }
        }
        exch(a[i], a[min]);
    }
}
