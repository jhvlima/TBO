#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"
#include "pilha.h"
#include "fila.h"
// srand(time(NULL)); // should only be called once
// int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int N = atoi(argv[1]);
    tArv *arv = criaArvVazia();

    for (int i = 0; i < N; i++)
    {
        int chave = rand();
        arv = insere(arv, chave);
    }
    // Exercicio 2
    // imprimeArv(arv);
    // printf("%d\n", alturaArv(arv));

    clock_t start = clock();
    printf("rec_preorder\n");
    rec_preorder(arv, visit);
    clock_t end = clock();
    double seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", seconds);

    start = clock();
    printf("rec_inorder\n");
    rec_inorder(arv, visit);
    end = clock();
    seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", seconds);

    start = clock();
    printf("rec_postorder\n");
    rec_postorder(arv, visit);
    end = clock();
    seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", seconds);

    start = clock();
    printf("non_rec_inorder\n");
    non_rec_inorder(arv, visit);
    end = clock();
    seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", seconds);

    start = clock();
    printf("non_rec_postorder\n");
    non_rec_postorder(arv, visit);
    end = clock();
    seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", seconds);

    start = clock();
    printf("non_rec_preorder\n");
    non_rec_preorder(arv, visit);
    end = clock();
    seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", seconds);

    start = clock();
    printf("nonRecursiveLevelOrderTraversal\n");
    nonRecursiveLevelOrderTraversal(arv, visit);
    end = clock();
    seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", seconds);

    destroi(arv);

    return 0;
}