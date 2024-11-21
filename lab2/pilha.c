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
    p->topo -1;
    return p;
}

tPilha *pop(tPilha *p)
{
    tArv *aux = p->array[p->topo];
    p->topo--;
    return aux;
}

void push(tPilha *p, int valor)
{
    tArv *novo = criaArv(valor);
    p->array[p->topo] = novo;
    p->topo++;
}

void non_rec_preorder(tArv *t, void (*visit)(tArv*))
{
    if (t)
    {
        tPilha *p = iniciaPilha();
        push(p, t);
        while (p->topo != -1)
        {
            t = pop(p);
            visit(t);
            if (t)
            {
                /* code */
            }
            
        }
    }
}

void non_rec_inorder(tArv *t, void (*visit)(tArv*))
{

}

void non_rec_postorder(tArv *t, void (*visit)(tArv*))
{

}