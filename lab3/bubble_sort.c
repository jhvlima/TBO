#include <stdio.h>
#include "item.h"

void sort(Item *a, int lo, int hi)
{
   for (int i = lo; i < hi - 1; i++)
   {
      int flag = 0;
      for (int j = lo; j < hi - i - 1; j++)
      {
         if (less(a[j + 1], a[j]))
         {
            exch(a[j], a[j + 1]);
            flag = 1;
         }
      }
      if (!flag)
      {
         break;
      }
   }
}
