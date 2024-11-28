#include <stdio.h>
#include "item.h"

void sort(Item *a, int lo, int hi)
{
   for (size_t i = lo; i < hi - 1; i++)
   {
      int flag = 0;
      for (size_t j = i + 1; j < hi - 1; j++)
      {
         compexch(a[j], a[j - 1])
         flag = 1;
      }
      if (!flag)
      {
         break;
      }
   }
}
