typedef struct _tNode tNode;
typedef struct _tLista tLista;

tLista *iniciaLista(int N);
tNode *retiraLista(tLista *l, tNode *ultimaPosicao, int N, int M);
int decideLider(int N, int M);