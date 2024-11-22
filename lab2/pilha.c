#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct _tPilha
{
    tArv *array[MaxTam];
    int topo;
};

tPilha *iniciaPilha()
{
    tPilha *p = calloc(1, sizeof(tPilha));
    p->topo = -1;
    return p;
}

tArv *pop(tPilha *p)
{
    tArv *aux = p->array[p->topo];
    p->topo--;
    return aux;
}

void push(tPilha *p, tArv *a)
{
    p->topo++;
    p->array[p->topo] = a;
}

void non_rec_preorder(tArv *t, void (*visit)(tArv *))
{
    if (t)
    {
        tPilha *p = iniciaPilha();
        push(p, t);
        while (p->topo != -1)
        {
            t = pop(p);
            visit(t);
            if (retornaDir(t))
            {
                push(p, retornaDir(t));
            }
            if (retornaEsq(t))
            {
                push(p, retornaEsq(t));
            }
        }
        free(p);
    }
}

void non_rec_inorder(tArv *t, void (*visit)(tArv *))
{
    if (t)
    {
        tPilha *p = iniciaPilha();
        while (p->topo != -1 || t)
        {
            if (t)
            {
                push(p, t);
                t = retornaEsq(t);
            }
            else
            {
                t = pop(p);
                visit(t);
                t = retornaDir(t);
            }
        }
        free(p);
    }
}

void non_rec_postorder(tArv *t, void (*visit)(tArv *))
{
    if (t)
    {
        tPilha *p = iniciaPilha();
        tArv *ultimoVisitado = NULL;
        while (p->topo != -1 || t)
        {
            if (t)
            {
                push(p, t);
                t = retornaEsq(t);
            }
            else
            {
                if (retornaDir(p->array[p->topo]) && ultimoVisitado != retornaDir(p->array[p->topo]))
                {
                    push(p, retornaDir(p->array[p->topo]));
                }
                else
                {
                    visit(p->array[p->topo]);
                    ultimoVisitado = pop(p);
                }
            }
        }
        free(p);
    }
}