// Inicializa estrutura com objetos numerados de 2 a N.
char *InitLista(int N);

// Marca os multiplos de @divisor da lista l
void MarcaMultiplos(char *l, int divisor, int N);

// Retorna o indice do menor numero da lista que não foi marcado
// caso não encontre retorna -1
int ProximoNaoMarcado(char *l, int ultimo, int N);

// Imprime os primos de 2 a N que estão na lista l
void ImprimePrimos(char *l, int N);

void destroiLista(char *l);
