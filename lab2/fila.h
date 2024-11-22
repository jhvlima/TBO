/**
 * 7 – TAD Fila
 */
#include "arvore.h"

typedef struct _tFila tFila;

tFila *iniciaFila();
tArv *dequeue(tFila *f);
void enqueue(tFila *f, tArv *a);

/**
 * 8 - Level-order traversal
 */
void nonRecursiveLevelOrderTraversal(tArv *t, void (*visit)(tArv *));
