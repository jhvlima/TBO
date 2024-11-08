#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct _tArv
{
    tArv *esq, *dir;
    int chave;
};

tArv *criaArvVazia()
{
    return NULL;
}

tArv *criaArv(int chave)
{
    tArv *a = calloc(1, sizeof(tArv));
    a->chave = chave;
    return a;
}

tArv * insere(tArv *a, int chave)
{
    if (a == NULL)
    {
        return criaArv(chave);
    }

    if (chave > a->chave)
    {
        a->dir = insere(a->dir, chave);
    }

    else if (chave < a->chave)
    {
        a->esq = insere(a->esq, chave);
    }

    return a;
}

void destroi(tArv *a)
{
    if (a)
    {
        destroi(a->dir);
        destroi(a->esq);
        free(a);
    }
}

int getChave(tArv *a)
{
    return a->chave;
}

void imprimeArv(tArv *a)
{        
    if (a)
    {
        printf("<");
        imprimeArv(a->dir);
        imprimeArv(a->esq);
        printf("|%d|", a->chave);        
        printf(">");

    }
}

int alturaArv(tArv *a)
{
    if (!a)
    {
        return -1;
    }

    if (a->dir)
    {
        alturaArv(a->dir) + 1;
    }
        
    if (a->esq)
    {
       alturaArv(a->esq) + 1;
    }

    return 
}