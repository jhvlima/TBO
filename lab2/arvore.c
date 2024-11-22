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

tArv *insere(tArv *a, int chave)
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

tArv *retornaDir(tArv *a)
{
    if (a->dir)
    {
        return a->dir;
    }
    return NULL;
}

tArv *retornaEsq(tArv *a)
{
    if (a->esq)
    {
        return a->esq;
    }
    return NULL;
}

void imprimeArv(tArv *a)
{
    if (a)
    {
        printf("<");
        imprimeArv(a->esq);
        printf(">");
        imprimeArv(a->dir);
        printf("|%d|", a->chave);
    }
}

int alturaArv(tArv *a)
{
    if (!a)
    {
        return -1;
    }

    int alturaEsq = alturaArv(a->esq) + 1;
    int alturaDir = alturaArv(a->dir) + 1;

    return (alturaDir > alturaEsq) ? alturaDir : alturaEsq;
}

/**
 * 3 - Caminhamento em  ́arvore (tree traversal)
 */
void visit(tArv *a)
{
    if (a)
    {
        //printf(" %d", a->chave);
    }
}

void rec_preorder(tArv *a, void (*visit)(tArv *))
{
    if (a)
    {
        visit(a);
        if (a->esq)
        {
            rec_preorder(a->esq, visit);
        }
        if (a->dir)
        {
            rec_preorder(a->dir, visit);
        }
    }
}

void rec_inorder(tArv *a, void (*visit)(tArv *))
{
    if (a)
    {
        if (a->esq)
        {
            rec_preorder(a->esq, visit);
        }
        visit(a);
        if (a->dir)
        {
            rec_preorder(a->dir, visit);
        }
    }
}

void rec_postorder(tArv *a, void (*visit)(tArv *))
{
    if (a)
    {
        if (a->esq)
        {
            rec_preorder(a->esq, visit);
        }
        if (a->dir)
        {
            rec_preorder(a->dir, visit);
        }
        visit(a);
    }
}