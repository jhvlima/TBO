#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "str.h"

#define R 256
#define CUTOFF 15

typedef struct {
    String *s; // Ponteiro para a string original
    int index; // Índice inicial do sufixo na string original
} Suffix;

// Função para obter o caractere na posição 'd' do sufixo
char char_at(Suffix *suffix, int d) {
    if (d < suffix->s->len - suffix->index) {
        return suffix->s->c[suffix->index + d];
    }
    return -1; // Retorna -1 se o índice estiver fora do limite
}

// Função de comparação para sufixos
int compare_suffixes(const void *a, const void *b) {
    Suffix *suffixA = *(Suffix **)a;
    Suffix *suffixB = *(Suffix **)b;
    return strcmp(suffixA->s->c + suffixA->index, suffixB->s->c + suffixB->index);
}

// Função para criar o array de sufixos
Suffix **create_suffix_array(String *text, int *n) {
    *n = text->len;
    Suffix **suffixes = malloc(text->len * sizeof(Suffix *));

    for (int i = 0; i < text->len; i++) {
        suffixes[i] = malloc(sizeof(Suffix));
        suffixes[i]->s = text;
        suffixes[i]->index = i;
    }

    return suffixes;
}

// Função de busca binária para encontrar a primeira ocorrência de uma substring
int binary_search(Suffix **suffixes, int n, String *query) {
    int low = 0, high = n - 1;
    int query_len = query->len;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strncmp(suffixes[mid]->s->c + suffixes[mid]->index, query->c, query_len);

        if (cmp < 0) {
            low = mid + 1;
        } else if (cmp > 0) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1; // Não encontrado
}

// Função para ler o conteúdo de um arquivo e criar uma String, tratando quebras de linha e espaços repetidos
String *read_file_to_string(const char *filename, int *context_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", filename);
        return NULL;
    }

    // Ler a primeira linha para obter o tamanho do contexto (ou número de caracteres)
    char first_line[256];
    if (fgets(first_line, sizeof(first_line), file) == NULL) {
        printf("Erro ao ler a primeira linha do arquivo.\n");
        fclose(file);
        return NULL;
    }

    // Extrair o número de caracteres da primeira linha
    int num_chars = atoi(first_line);

    // Buffer para armazenar o conteúdo do arquivo
    char *content = malloc(num_chars + 1);
    int content_index = 0;

    // Ler o restante do arquivo linha por linha
    char line[256];
    int prev_char_was_space = 0; // Flag para evitar espaços repetidos

    while (fgets(line, sizeof(line), file) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
                if (!prev_char_was_space && content_index > 0) {
                    content[content_index++] = ' ';
                    prev_char_was_space = 1;
                }
            } else {
                content[content_index++] = line[i];
                prev_char_was_space = 0;
            }
        }
    }

    content[content_index] = '\0'; // Adiciona o terminador nulo

    fclose(file);

    // Criar uma String a partir do conteúdo do arquivo
    String *str = create_string(content);
    free(content); // Libera o conteúdo temporário

    return str;
}

// Função de ordenação por inserção
void insertion_sort(Suffix** suffixes, int low, int high, int d) {
    for (int i = low + 1; i <= high; i++) {
        Suffix* temp = suffixes[i];
        int j = i - 1;
        while (j >= low && strcmp(suffixes[j]->s->c + suffixes[j]->index + d, temp->s->c + temp->index + d) > 0) {
            suffixes[j + 1] = suffixes[j];
            j--;
        }
        suffixes[j + 1] = temp;
    }
}

// Função de ordenação MSD Radix Sort
void msd_radix_sort(Suffix** suffixes, int low, int high, int d, Suffix** aux) {
    if (high <= low + CUTOFF) {
        insertion_sort(suffixes, low, high, d);
        return;
    }

    int count[R + 2] = {0};

    // Contagem
    for (int i = low; i <= high; i++) {
        int c = char_at(suffixes[i], d);
        count[c + 2]++;
    }

    // Acumulação
    for (int r = 0; r < R + 1; r++)
        count[r + 1] += count[r];

    // Distribuição
    for (int i = low; i <= high; i++) {
        int c = char_at(suffixes[i], d);
        aux[count[c + 1]++] = suffixes[i];
    }

    // Cópia
    memcpy(&suffixes[low], aux, (high - low + 1) * sizeof(Suffix*));

    // Recursão
    for (int r = 0; r < R; r++) {
        int new_low = low + count[r];
        int new_high = low + count[r + 1] - 1;
        if (new_low < new_high)
            msd_radix_sort(suffixes, new_low, new_high, d + 1, aux);
    }
}

void sort_suffix_array_msdradix(Suffix** suffixes, int suffix_count) {
    Suffix** aux = malloc(suffix_count * sizeof(Suffix*));
    if (!aux) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    msd_radix_sort(suffixes, 0, suffix_count - 1, 0, aux);
    free(aux);
}

// Função principal
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo_entrada> [tamanho_contexto]\n", argv[0]);
        return 1;
    }

    const char *entradaPath = argv[1];
    int tamContexto = -1; // Valor padrão para o tamanho do contexto

    // Verifica se o tamanho do contexto foi fornecido como argumento
    if (argc >= 3) {
        tamContexto = atoi(argv[2]);
    }

    // Ler o conteúdo do arquivo e criar uma String
    String *str = read_file_to_string(entradaPath, &tamContexto);
    if (str == NULL) {
        return 1;
    }

    // Se o tamanho do contexto não foi fornecido, use um valor padrão (por exemplo, 15)
    if (tamContexto == -1) {
        tamContexto = 15; // Valor padrão
    }

    printf("Tamanho do contexto: %d\n", tamContexto);

    int n;
    Suffix **suffixes = create_suffix_array(str, &n);

    // Medir o tempo de ordenação
    clock_t start = clock();
    sort_suffix_array_msdradix(suffixes, n);
    //qsort(suffixes, n, sizeof(Suffix *), compare_suffixes);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de ordenação: %.6f segundos\n", time_taken);

    // Loop para buscar substrings
    while (1) {
        char query_text[256];
        printf("\nDigite a substring para buscar (ou 'sair' para terminar): ");
        scanf("%255s", query_text);

        if (strcmp(query_text, "sair") == 0) {
            break;
        }

        String *query = create_string(query_text);
        int pos = binary_search(suffixes, n, query);

        if (pos != -1) {
            printf("\nSubstring '");
            print_string(query);
            printf("' encontrada no índice %d:\n", pos);
            for (int i = pos; i < n && equals_substring(suffixes[i]->s, suffixes[i]->index, suffixes[i]->index + query->len, query); i++) {
                // Exibir o contexto ao redor da ocorrência
                int start = suffixes[i]->index - tamContexto;
                int end = suffixes[i]->index + query->len + tamContexto;

                // Garantir que os índices estejam dentro dos limites
                if (start < 0) start = 0;
                if (end > str->len) end = str->len;

                print_substring(str, start, end);
                printf("\n");
            }
        } else {
            printf("\nSubstring '");
            print_string(query);
            printf("' não encontrada.\n");
        }

        destroy_string(query);
    }

    // Liberar memória
    for (int i = 0; i < n; i++) {
        free(suffixes[i]);
    }
    free(suffixes);
    destroy_string(str);

    return 0;
}