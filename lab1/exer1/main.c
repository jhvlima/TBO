#include <stdio.h>
#include <stdlib.h>
#include "primos.h"

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    InitArray(num);
    int i = 0;
    while (-1 != i)
    {    
        MarcaMultiplos(i, num);
        i = ProximoNaoMarcado(i, num);
    }
    ImprimePrimos(num);
    destroiArray();
    return 0;
}