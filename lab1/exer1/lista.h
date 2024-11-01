
typedef struct _tLista tLista;

struct _tLista
{
    char flag;
    int num;
    tLista *prox;
};

// Inicializa estrutura com objetos numerados de 2 a N.
tLista *InitLista(int N);

// Marca os multiplos de i da lista l
void MarcaMultiplos(tLista *l, int i);

// Retorna o menor numero da lista que não foi marcado
// caso não encontre retorna 0
int ProximoNaoMarcado(tLista *l);

// Imprime os primos de 2 a N
void ImprimePrimos(tLista *l);