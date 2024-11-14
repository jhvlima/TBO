#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct _tNode tNode;

struct _tNode
{
    void *dado;
    tNode *prox;
};
struct _tPilha
{
    tNode *topo;
};

tPilha *iniciaPilha()
{
    return calloc(1, sizeof(tPilha));
}

void insereOperando(tPilha *p, double  op)
{
    tNode *novo = malloc(sizeof(tNode));
    novo->dado = malloc(sizeof(double));
    *((double *)novo->dado) = op;
    novo->prox = p->topo;
    p->topo = novo;
}

void insereOperador(tPilha *p, char op)
{
    tNode *novo = malloc(sizeof(tNode));
    novo->dado = malloc(sizeof(char));
    *((char *)novo->dado) = op;    
    novo->prox = p->topo;
    p->topo = novo;
}

double retiraOperando(tPilha *p)
{
    double op = *((double *)p->topo->dado);
    tNode *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux->dado);
    free(aux);
    return op;
}

char retiraOperador(tPilha *p)
{
    double op = *((char *)p->topo->dado);
    tNode *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux->dado);
    free(aux);
    return op;
}

void destroiPilha(tPilha *p)
{
    tNode *aux = p->topo;
    while (p->topo)
    {
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
    free(p);
}