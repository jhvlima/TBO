#include <stdio.h>
#include "item.h"
/**
 *  um bubble do início ao fim e do fim ao início
 */
void sort(Item *a, int lo, int hi)
{
    for (int i = lo; i < (hi - lo) / 2; i++)
    {
        int flag = 0;

        // início ao final
        for (int j = lo; j < hi - i - 1; j++)
        {
            if (less(a[j + 1], a[j]))
            {
                exch(a[j], a[j + 1]);
                flag = 1;
            }
        }

        // final ao início
        for (int k = hi - i - 2; k > lo + i; k--)
        {
            if (less(a[k], a[k - 1]))
            {
                exch(a[k - 1], a[k]);
                flag = 1;
            }
        }

        if (!flag)
        {
            break;
        }
    }
}