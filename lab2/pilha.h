/**
* 4 - Caminhamento nao-recursivo
*/
#include "arvore.h"

#define MaxTam 1000000

typedef struct _tPilha tPilha;

tPilha *iniciaPilha();
tPilha *pop(tPilha *p);
void push(tPilha *p, int valor);

/**
* 5 - Non-recursive BST traversal
*/
void non_rec_preorder(tArv *t, void (*visit)(tArv*));
void non_rec_inorder(tArv *t, void (*visit)(tArv*));
void non_rec_postorder(tArv *t, void (*visit)(tArv*));