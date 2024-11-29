#include <stdio.h>
#include "item.h"
/**
 * anda pra direita com o i e troca ele com todos os maiores até acabar o vetor ou encontrar um menor
 */
void sort(Item *a, int lo, int hi)
{
    for (int i = lo + 1; i <= hi; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (less(a[j], a[j - 1]))
            {
                exch(a[j], a[j - 1])
            }
            else
            {
                break;
            }
        }
    }
}
