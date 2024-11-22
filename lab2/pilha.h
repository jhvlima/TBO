/**
 * 4 - Caminhamento nao-recursivo
 */
#include "arvore.h"

#define MaxTam 100

typedef struct _tPilha tPilha;

tPilha *iniciaPilha();
tArv *pop(tPilha *p);
void push(tPilha *p, tArv *a);

/**
 * 5 - Non-recursive BST traversal
 */
void non_rec_preorder(tArv *t, void (*visit)(tArv *));
void non_rec_inorder(tArv *t, void (*visit)(tArv *));
void non_rec_postorder(tArv *t, void (*visit)(tArv *));