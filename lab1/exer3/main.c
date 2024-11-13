#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int ehOperador(char car)
{
    return car == '*' || car == '+' || car == '-' || car == '/';
}

int main(int argc, char *argv[])
{
    char car;
    tPilha *operadores = iniciaPilha();
    tPilha *operandos = iniciaPilha();

    while (scanf("%c", &car))
    {
        if (ehOperador(car))
        {
            insereOperador(operadores, car);
        }
        else
        {
            insereOperando(operandos, car);
        }
    }
    return 0;
}