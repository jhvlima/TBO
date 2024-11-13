// Inicializa estrutura com objetos numerados de 2 a N.
int *InitLista(int N);

// Marca os multiplos de @divisor da lista l
void MarcaMultiplos(int *l, int divisor, int N);

// Retorna o indice do menor numero da lista que não foi marcado
// caso não encontre retorna -1
int ProximoNaoMarcado(int *l, int ultimo, int N);

// Imprime os primos de 2 a N que estão na lista l
void ImprimePrimos(int *l, int N);

void destroiLista(int *l);