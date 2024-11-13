#include <stdio.h>
#include <stdlib.h>
#include "arrayInt.h"
#include "arrayChar.h"
#include "arrayBit.h"

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    int *lista = InitLista(num);
    int i = 0;
    while (-1 != i)
    {    
        MarcaMultiplos(lista, i, num);
        i = ProximoNaoMarcado(lista, i, num);
    }
    ImprimePrimos(lista, num);
    free(lista);
    return 0;
}