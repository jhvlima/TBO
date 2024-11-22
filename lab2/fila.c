/**
 * 7 – TAD Fila
 */
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "fila.h"

typedef struct _tNode tNode;
struct _tNode
{
    tArv *arv;
    tNode *proxima;
};

struct _tFila
{
    tNode *primeiro, *ultimo;
};

tFila *iniciaFila()
{
    tFila *fila = calloc(1, sizeof(tFila));
    return fila;
}

int taVazia(tFila *f)
{
    if (f->primeiro)
    {
        return 0;
    }
    return 1;
}

tArv *dequeue(tFila *f)
{
    if (!taVazia(f))
    {
        tNode *node = f->primeiro;
        tArv *arv = node->arv;
        f->primeiro = f->primeiro->proxima;
        free(node);
        return arv;
    }
    return NULL;
}

void enqueue(tFila *f, tArv *a)
{
    tNode *nova = calloc(1, sizeof(tNode));
    nova->arv = a;
    nova->proxima = NULL;

    // caso fila vazia
    if (taVazia(f))
    {
        f->primeiro = f->ultimo = nova;
    }

    // insere no final
    else
    {
        f->ultimo->proxima = nova;
        f->ultimo = nova;
    }
}

void liberaFila(tFila *f)
{
    while (!taVazia(f))
    {
        dequeue(f);
    }
    free(f);
}

/**
 * 8 - Level-order traversal
 */
void nonRecursiveLevelOrderTraversal(tArv *t, void (*visit)(tArv *))
{
    if (t)
    {
        tFila *f = iniciaFila();
        enqueue(f, t);

        while (!taVazia(f))
        {
            tArv *atual = dequeue(f);
            visit(atual);

            if (retornaEsq(atual))
            {
                enqueue(f, retornaEsq(atual));
            }
            if (retornaDir(atual))
            {
                enqueue(f, retornaDir(atual));
            }
        }
        liberaFila(f);
    }
}