/*
Uma ´arvore bin´aria de busca (binary search tree – BST ) ´e uma
´arvore bin´aria aonde cada n´o possui uma chave, e satisfaz a seguinte propriedade adicional:
para qualquer n´o n da ´arvore, a chave de n ´e (i) maior do que as chaves de todos os n´os da
sub-´arvore da esquerda de n; e (ii) menor do que as chaves de todos os n´os da sub-´arvore da
direita de n. Por essa defini¸c˜ao ´e imediato notar que uma BST n˜ao admite chaves repetidas.

*/

#ifndef ARVORE
#define ARVORE

typedef struct _tArv tArv;

tArv *criaArv(int chave);
tArv *criaArvVazia();
tArv *insere(tArv *a, int chave);
void destroi(tArv *a);
int getChave(tArv *a);
void imprimeArv(tArv *a);
int alturaArv(tArv *a);

/**
 * 3 - Caminhamento em  ́arvore (tree traversal)
 */
void visit(tArv *a);
void rec_preorder(tArv *t, void (*visit)(tArv*));
void rec_inorder(tArv *t, void (*visit)(tArv*));
void rec_postorder(tArv *t, void (*visit)(tArv*));

#endif