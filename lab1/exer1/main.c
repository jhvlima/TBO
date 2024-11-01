#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char *argv[])
{
    printf("COMECOU\n");
    int i = 2, num = atoi(argv[1]);
    int *lista = InitLista(num);
    
    while (i =! 0)
    {    
        //printf("NO LOOP %d\n", i);
        MarcaMultiplos(lista, i, num);
        i = ProximoNaoMarcado(lista, num);
    }
    ImprimePrimos(lista, num);
    return 0;
}