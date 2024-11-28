#include <stdio.h>
#include "item.h"

void sort(Item *a, int lo, int hi)
{
   for (size_t i = lo; i < hi; i++)
   {
      compexch(a[i], a[i + 1])
   }
}
