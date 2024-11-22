#include <stdio.h>
#include <math.h>

void calcularMediaDesvioPadrao(double dados[], int tamanho, double *media, double *desvioPadrao) {
    double soma = 0.0, somaQuadrados = 0.0;

    // Calcula a soma dos elementos
    for (int i = 0; i < tamanho; i++) {
        soma += dados[i];
    }

    // Calcula a média
    *media = soma / tamanho;

    // Calcula a soma dos quadrados das diferenças para o desvio padrão
    for (int i = 0; i < tamanho; i++) {
        somaQuadrados += pow(dados[i] - *media, 2);
    }

    // Calcula o desvio padrão
    *desvioPadrao = sqrt(somaQuadrados / tamanho);
}

int main() {
    double dados[] = {39,42,40,48,42,38,38,36,41,40};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    double media, desvioPadrao;

    calcularMediaDesvioPadrao(dados, tamanho, &media, &desvioPadrao);

    printf("Média: %.2f\n", media);
    printf("Desvio Padrão: %.2f\n", desvioPadrao);

    return 0;
}
