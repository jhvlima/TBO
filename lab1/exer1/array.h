// Inicializa estrutura com objetos numerados de 2 a N.
int *InitLista(int N);

// Marca os multiplos de i da lista l
void MarcaMultiplos(int *l, int divisor, int N);

// Retorna o menor numero da lista que não foi marcado
// caso não encontre retorna 0
int ProximoNaoMarcado(int *l, int N);

// Imprime os primos de 2 a N
void ImprimePrimos(int *l, int N);
