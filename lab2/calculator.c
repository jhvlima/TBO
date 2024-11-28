#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Função para calcular a média e o desvio padrão
void calcularMediaDesvioPadrao(int dados[], int tamanho, double *media, double *desvioPadrao)
{
    double soma = 0.0, somaQuadrados = 0.0;

    // Calcula a soma dos elementos
    for (int i = 0; i < tamanho; i++)
    {
        soma += dados[i];
    }

    // Calcula a média
    *media = soma / tamanho;

    // Calcula a soma dos quadrados das diferenças para o desvio padrão
    for (int i = 0; i < tamanho; i++)
    {
        somaQuadrados += pow(dados[i] - *media, 2);
    }

    // Calcula o desvio padrão
    *desvioPadrao = sqrt(somaQuadrados / tamanho);
}

// Função para comparar dois valores (necessário para a função qsort)
int comparar(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

// Função para calcular a mediana
double calcularMediana(int dados[], int tamanho)
{
    qsort(dados, tamanho, sizeof(int), comparar);  // Ordena o array

    if (tamanho % 2 == 1) {
        return dados[tamanho / 2];  // Se o tamanho é ímpar, retorna o valor central
    } else {
        return (dados[tamanho / 2 - 1] + dados[tamanho / 2]) / 2.0;  // Se o tamanho é par, retorna a média dos dois valores centrais
    }
}

// Função para calcular a moda
int calcularModa(int dados[], int tamanho)
{
    int contagem[tamanho];  // Array para contar a frequência de cada número
    int moda = dados[0], maiorContagem = 1;

    for (int i = 0; i < tamanho; i++) {
        contagem[i] = 0;
        for (int j = 0; j < tamanho; j++) {
            if (dados[i] == dados[j]) {
                contagem[i]++;
            }
        }

        // Atualiza a moda se encontrar uma contagem maior
        if (contagem[i] > maiorContagem) {
            maiorContagem = contagem[i];
            moda = dados[i];
        }
    }
    return moda;
}

int main()
{
    //int dados[] = {3, 5, 4, 6, 3, 7, 5, 4, 6, 5, 4, 8, 6, 5, 4};
    int dados[] = {7, 8, 6, 9, 7, 8, 8, 9, 10, 6, 7, 8, 9, 8, 7, 6, 8, 9, 10, 8}; 
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    double media, desvioPadrao;
    int moda;
    double mediana;

    // Calcula a média e o desvio padrão
    calcularMediaDesvioPadrao(dados, tamanho, &media, &desvioPadrao);

    // Calcula a mediana
    mediana = calcularMediana(dados, tamanho);

    // Calcula a moda
    moda = calcularModa(dados, tamanho);

    // Exibe os resultados
    printf("Média: %.2f\n", media);
    printf("Desvio Padrão: %.2f\n", desvioPadrao);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    return 0;
}
