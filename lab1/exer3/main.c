#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"

int ehOperador(char car)
{
    return car == '*' || car == '+' || car == '-' || car == '/';
}

int ehOperando(char car)
{
    return isdigit(car);
}

double opera(char op, double n1, double n2)
{
    if (op == '+')
    {
        return n1 + n2;
    }
    if (op == '-')
    {
        return n1 - n2;
    }
    if (op == '*')
    {
        return n1 * n2;
    }
    if (op == '/')
    {
        return n1 / n2;
    }
    else
        return 0;
}

int main(int argc, char *argv[])
{
    tPilha *operadores = iniciaPilha();
    tPilha *operandos = iniciaPilha();

    // Lendo a expressão como uma linha completa
    char entrada[100];
    printf("Digite a expressao: ");
    fgets(entrada, sizeof(entrada), stdin);

    // Processando cada caractere da entrada
    for (int i = 0; entrada[i] != '\0'; i++)
    {
        if (entrada[i] == ' ' || entrada[i] == '\n' || entrada[i] == '(')
        {
            continue;
        }

        else if (ehOperador(entrada[i]))
        {
            insereOperador(operadores, entrada[i]);
        }

        else if (ehOperando(entrada[i]))
        {
            // Constrói o número (para números de vários dígitos)
            double num = 0;
            while (isdigit(entrada[i]))
            {
                num = num * 10 + (entrada[i] - '0');
                i++;
            }
            i--; // Corrige o índice após o último dígito do número
            insereOperando(operandos, num);
        }

        else if (entrada[i] == ')')
        {
            double n2 = retiraOperando(operandos);
            double n1 = retiraOperando(operandos);
            char op = retiraOperador(operadores);
            double resultado = opera(op, n1, n2);
            insereOperando(operandos, resultado);
            printf("Resultado da opercao %.2f %c %.2f  : %.2f\n", n1, op, n2, resultado);
        }
    }

    printf("Resultado: %.2f\n", retiraOperando(operandos));

    destroiPilha(operadores);
    destroiPilha(operandos);

    return 0;
}

