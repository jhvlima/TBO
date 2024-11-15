#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

struct _tLista
{
    tNode *inicio, *fim;
};

struct _tNode
{
    unsigned long int indice;
    tNode *prox;
};

tLista *iniciaLista(int N)
{
    tLista *l = malloc(sizeof(tLista));
    tNode *ant = NULL, *node = NULL;
    for (int i = 1; i <= N; i++)
    {
        node = malloc(sizeof(tNode));
        node->indice = i;
        node->prox = NULL;
        if (i == 1)
        {
            l->inicio = node;
        }
        else
        {
            ant->prox = node; 
        }
        ant = node;
    }
    node->prox = l->inicio;
    l->fim = node;
    return l;
}

tNode *retiraLista(tLista *l, tNode *ultimaPosicao, int N, int M)
{
    if (ultimaPosicao == NULL)
    {
        ultimaPosicao = l->inicio;
    }
    tNode *aux = ultimaPosicao;
    tNode *ant = NULL;

    for (int i = 1; i < M; i++)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == l->inicio)
    {
        l->inicio = aux->prox;
    }
    if (aux == l->fim)
    {
        l->fim = ant;
    }
    // aqui imprime as pessoas que sairam
    //printf(" %d", aux->indice);
    ant->prox = aux->prox;
    free(aux);
    return ant->prox;
}

int decideLider(int N, int M)
{
    tLista *l = iniciaLista(N);
    tNode *proximoLivre = l->inicio;
    printf("Os eliminados foram:");
    while (l->fim != l->inicio)
    {
        proximoLivre = retiraLista(l, proximoLivre, N, M);
    }
    int lider = l->inicio->indice;
    free(l->fim);
    free(l);
    return lider;
}