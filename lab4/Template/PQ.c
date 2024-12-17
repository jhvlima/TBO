#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

struct pq
{
    int size;         
    int capacity;     
    Event **array;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ *PQ_create(int max_N)
{
    PQ *pq = (PQ*)malloc(sizeof(PQ));
    pq->array = (Event**)malloc(max_N * sizeof(Event*));
    pq->size = 0;
    pq->capacity = max_N;
    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq)
{
    while (!PQ_is_empty(pq))
    {
        free(PQ_delmin(pq));
    }
    free(pq->array);
    free(pq);
}

static void swap(Event **a, Event **b)
{
    Event *temp = *a;
    *a = *b;
    *b = temp;
}

// Função auxiliar heapify-up (subindo o elemento no heap)
static void heapify_up(PQ *pq, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (get_time(pq->array[parent]) <= get_time(pq->array[index]))
            break;

        swap(&pq->array[parent], &pq->array[index]);
        index = parent;
    }
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e)
{
    // TODO: Implemente essa função que insere o evento dado na fila segundo
    //       o tempo do evento.
    //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
    //       em uma fila que já contém o número máximo de eventos) para evitar
    //       dores de cabeça com acessos inválidos na memória.
    if (pq->size > pq->capacity)
    {
        fprintf(stderr, "Erro: FIla Cheia!\n");
        return;
    }

    pq->array[pq->size] = e;  // Insere no final do heap
    heapify_up(pq, pq->size); // Reorganiza o heap
    pq->size++;

}

// Função auxiliar heapify-down (descendo o elemento no heap)
static void heapify_down(PQ *pq, int index)
{
    int left, right, smallest;

    while (1)
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        // Verifica o filho da esquerda
        if (left < pq->size && get_time(pq->array[left]) < get_time(pq->array[smallest]))
            smallest = left;

        // Verifica o filho da direita
        if (right < pq->size && get_time(pq->array[right]) < get_time(pq->array[smallest]))
            smallest = right;

        if (smallest == index)
            break;

        swap(&pq->array[index], &pq->array[smallest]);
        index = smallest;
    }
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event *PQ_delmin(PQ *pq)
{
    if (pq->size <= 0)
    {
        fprintf(stderr, "Erro: Heap vazio!\n");
        exit(EXIT_FAILURE);
    }

    Event *min_event = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;

    heapify_down(pq, 0); // Reorganiza o heap
    return min_event;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq)
{
    return pq->size == 0;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq)
{
    return pq->size;
}
