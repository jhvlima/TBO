#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

//srand(time(NULL)); // should only be called once
//int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int N = atoi(argv[1]);
    tArv *arv = criaArvVazia();

    for (int i = 0; i < N; i++)
    {
        int chave = rand();
        arv = insere(arv, chave);
    }

    //imprimeArv(arv);
    printf("%d\n", alturaArv(arv));
    destroi(arv);

    return 0;
}