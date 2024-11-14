// essa implementação precisa da definição de um array 

// Inicializa estrutura com objetos numerados de 2 a N.
void InitArray(int N);

// Marca os multiplos de 'divisor' da Array 
void MarcaMultiplos(int divisor, int N);

// Retorna o indice do menor numero da Array que não foi marcado
// caso não encontre retorna -1
int ProximoNaoMarcado(int ultimo, int N);

// Imprime os primos de 2 a N que estão na Array 
void ImprimePrimos(int N);

void destroiArray();