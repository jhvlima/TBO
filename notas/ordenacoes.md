# Selection
- Anda com o indice para direita e trás o menor valor para frente do vetor
- Invariancia: todos os elementos a esquerda do ponteriro são menores que o elemento do ponteiro e estão em ordem ascendente
- Faz `N trocas`
- Faz N²/2 comparações
- `Sempre quadrático`
- `inplace`

```
for i++ = 0 to n                  <- O(n)
    m = findMinimum()           <- O(n/2)
    exch(a[i], a[m])
```

# Insertion
- Anda com o indice para a direita e troca o valor do ponteiro com todos os maiores que estão na esquerda
- No inicio de cada interção os elementos da esquerda estão em ordem ascendete e os da direita ainda não foram vistos
- o indice i determina até onde foi ordenado e o j o ponteiro do valor que está sendo trocado(indo para esquerda até encontra um valor menor ou o fim do vetor)
- Faz em media `N²/4 comparações e trocas`
- Melhor caso: N-1 comparações
- Vetor parcialmente ordenados se tornam lineares

```
for i++ = 0 to n                  <- O(n)
    for j-- = i to 0              <- O(n/2)
        if a[j] < a[j-1]
            exch(a[j], a[j-1])
        else break;
```

# Shell
- usa varios h-sorts com valores de decrescentes de h
- h-sort: mesma ideia do insertion sort mas, salta h indices para a esquerda ao invés de 1 
- 1-sort == insertion sort
- valores ok de h: 3x + 1
- valores bom de h: 1,5,19,41,109,209,505,929,2161,3095,... 
```
h = 1
while (h < n/3) h = 3*h + 1             <- começa com o maior numero da sequencia 3x + 1
    while h >= 1
        for i++ = 0 to n                  <- O(n)
            for j-- = i to 0              <- O(n/2)
                if a[j] < a[j-h]
                    exch(a[j], a[j-h])
                else break;
    h = h/3                             <- vai diminuindo o h até chegar em 1
```

# Merge
- Divide o vetor de 2, ordena recursivamente cada metade, unifica(merge) as duas metades
- no maximo N log(N) comparaçoes
- **melhoriras**: 
    - usar inserton sort para sub-arrays pequenos (menor que 10)
    - parar quando ja estiver ordenado

## Padrão
```
sort(a, aux, lo, hi)
    aux = malloc(n)
    mergeSort(a, aux, lo, hi)
    free(aux)
```
```
mergeSort(a, aux, lo, hi)
    if hi < lo
        return
    mid = lo + (hi-lo)/2
    mergeSort(a, aux, lo, mid)
    mergeSort(a, aux, mid+1, hi)
    merge(a, aux, lo, mid, hi)
```
```
merge(a, aux, lo, mid, hi)
    for i++ = lo to hi
        aux[i] = a[i]

    k = lo, j = mid + 1
    for i++ = lo to hi
        if k > mid
            a[i] = aux[j++]
        else if j > hi
            a[i] = aux[k++]
        else if aux[j] < aux[k]
            a[i] = aux[j++]
        else 
            a[i] = aux[k++]
```

## Cutoff + parar quando as metades já estão ordenadas
```
sort(a, aux, lo, hi)
    aux = malloc(n)
    mergeSort(a, aux, lo, hi)
    free(aux)
```
```
mergeSort(a, aux, lo, hi)
    if hi < lo + CUTOFF + 1             <- Cutoff qaundo tiver poucos elementos evita o aumento de chamadas recursivas
        insertion(a, lo, hi)
        return
    mid = lo + (hi-lo)/2
    mergeSort(a, aux, lo, mid)
    mergeSort(a, aux, mid+1, hi)
    if a[mid] < a[mid+1]                <- se a maior chave da primeira metade for menor que a menor da segunda, então tudo está em ordem no array 
       return
    merge(a, aux, lo, mid, hi)
```
```
merge(a, aux, lo, mid, hi)
    for i++ = lo to hi
        aux[i] = a[i]

    k = lo, j = mid + 1
    for i++ = lo to hi
        if k > mid
            a[i] = aux[j++]
        else if j > hi
            a[i] = aux[k++]
        else if aux[j] < aux[k]
            a[i] = aux[j++]
        else 
            a[i] = aux[k++]
```

# Quick
- no pior caso é quadratico, mas o shufle não deixa isso acontecer
- **melhoriras** 
    - usar insertion sort para sub-arrays pequenos (menor que 10)
    - usar o primeiro partition como a mediana de 3 do array
    - o pivo junta todas as chaves iguais entre os ponteiros lessThen, greaterThen 
## Padrão
```
suffle(a)
quick(a, 0, n-1)
```
```
void quick(a, lo, hi)
if hi <= lo
    return
j = partition(a, lo, hi)
quick(a, lo, j-1)
quick(a, j+1, hi)
```
```
int partition(a, lo, hi)
i = lo, j = hi + 1
while true
    while a[++i] < a[lo]    <- encontra um valor menor que o pivo na direita
        if i == hi
    while a[lo] < a[--j]    <- encontra um valor maior que o pivo na esquerda 
        if j == lo           

    if a[j] <= a[i]         <- verfica se os ponteiro se cruzaram 
        break;

    exch(a[j], a[i])

exch(a[lo], a[j])
return j                    <- retorna o indice que está na posicao correta
```

## Cutoff
```
void quick_cutoff(a, lo, hi)
if hi <= lo + CUTOFF - 1
    insertion(a, lo, hi)        <- usa o insertion pq ele é mais rápido para vetores pequenos, inplace e estável 
    return
j = partition(a, lo, hi)
quick(a, lo, j-1)
quick(a, j+1, hi)
```

## Mediana de 3
```
void quick_cutoff_median(a, lo, hi)
if hi <= lo + CUTOFF - 1
    insertion(a, lo, hi)
    return
mediana = mediana(a, lo, hi)
exch(a[lo], a[mediana])         <- leva o valor da mediana para o inicio para ser usado no partition

j = partition(a, lo, hi)
quick(a, lo, j-1)
quick(a, j+1, hi)
```

## 3-way partition
```
void quick_3_way(a, lo, hi)
if hi <= lo
    return
lt = lo, gt = hi, i = lo
while i < gt
    if a[i] < a[lo]
        exch(a[lt], a[i])
        lt++, i++
    else if a[i] > a[lo]
        exch(a[i], a[gt])
        gt--
    else
        i++

quick(a, lo, lt-1)
quick(a, gt+1, hi)
```

# Heap
- usa uma fila de prioridade para retirar as chaves em ordem
- pode ser feito em um vetor onde os filhos de a[i] são a[2*i], a[(2*i)+1] como filho da esquerda e da direita respectivamente
- insere na fila, reordena a fila e retira a proxima chave

## Padrão
```
inicia_PQ
for i++ = 0 to n                <- O(n)
    insere_PQ(a[i])             <- Aqui deve ser reodenado a fila após a inserção

for i-- = n-1 to 0
    a[i] = retiraPrimeiro_PQ
```

## In-place e top-down
```
void sort(a, lo, hi)            <- a é um array desordenado
for i++ = lo to hi              <- O(n)
    fix_up(a[i])                <- O(log (n)) Aqui deve ser reordenado a fila após a inserção para construir a heap

while n > 1
    exch(a[1], a[n])        
    fix_down(a, --n, 1)         < Aqui ordena a heap
```

## In-place e botton-up
```
void sort(a, lo, hi)            <- a é uma arvore binária completa em um array
for i++ = lo to hi              <- O(n)
    fix_up(a[i])                <- O(log (n)) Aqui deve ser reordenado a fila após a inserção

while n > 1
    exch(a[1], a[n])        
    fix_down(a, --n, 1)         <- 
```
# Radix
```
countSort(a, aux, count, R)
    for i++ = 0 to n                <- conta a frequencia de cada caracter
        count[a[i]+1]++             <- deixa o primeiro indice vazio

    for i++ = 0 to R                <- acumular a frequencia de todos os caracteres anteriores até o caracter atual
        count[i+1] += count[i]

    for i++ = 0 to n                <- movimenta os caracteres para o auxiliar
        aux[count[a[i]]++] = a[i]

    for i++ = 0 to n                <- coloca o vetor ordenado no vetor original
        a[i] = aux[i]

```
## Mais detalhado
```
for i++ = 0 to n                <- conta a frequencia de cada caracter
    index = a[i] + 1
    count[index]++             <- começa do indice 1

for i++ = 0 to R                <- acumular a frequencia de todos os caracteres anteriores até o caracter atual
    prev_count = count[i]  
    count[i + 1] += prev_count

for i++ = 0 to n                <- movimenta os caracteres para o auxiliar
    int pos = count[a[i]]       <- Obtém a posição correta para a[i] no vetor auxiliar
    aux[pos] = a[i]             <- Insere o elemento na posição correta
    count[a[i]]++               <- Atualiza a posição para a próxima ocorrência de a[i]

for i++ = 0 to n
    a[i] = aux[i]               <- coloca o vetor ordenado no vetor original

```
## MSD
- Ordena os elementos começando pelo dígito mais significativo (da esquerda para a direita).
- Usa uma abordagem recursiva para dividir os elementos em grupos com base no dígito atual.
- É eficiente para strings ou números com comprimentos variáveis.

## LSD
Ordena strings de tamanho fixo de forma estável, ordenando da direita para a esquerda
- Ordena os elementos começando pelo dígito menos significativo (da direita para a esquerda).
- É mais comum e fácil de implementar.
- Ideal para números inteiros ou strings de mesmo comprimento.

# Resumo

Método          | Inplace  | Estável  | Melhor  | Médio  | Pior   | Espaço
:-------------: | :------: | :------: | :-----: | :----: | :----: | :----:
Selection       | X        |          | n²/2    | n²/2   | n²/2   | O(1)
Insertion       | X        | X        | n       | n²/4   | n²/2   | O(1)
Shell           | X        |          | n log n | ?      | n^(3/2)| O(1)
Merge           |          | X        | n log n | n log n| n log n| O(n)
Quick           | X        |          | n log n | n log n| n²     | O(log n)
3-way Quick     |          |          |         |        |        |
Heap            | X        |          | n log n | n log n| n log n| O(1)
Radix (LSD)     |          | X        | n*k     | n*k    | n*k    | O(n+k)

---

### Casos de Uso
- **Selection Sort**: Útil para listas pequenas onde o custo de troca é baixo.
- **Insertion Sort**: Ideal para listas quase ordenadas, como logs de eventos.
- **Merge Sort**: Usado em sistemas que precisam de estabilidade, como ordenação de registros em bancos de dados.
- **Quick Sort**: Amplamente usado em bibliotecas padrão devido à sua eficiência em listas grandes.
- **Heap Sort**: Útil em sistemas embarcados onde o espaço extra é limitado.
- **Radix Sort**: Usado para ordenar números inteiros ou strings, como em sistemas de classificação de documentos.

---

### Comparação entre algoritmos
| Algoritmo      | Melhor para               | Limitações                     |
|----------------|---------------------------|--------------------------------|
| Selection Sort | Listas pequenas           | Sempre quadrático              |
| Insertion Sort | Listas quase ordenadas    | Ineficiente para listas grandes|
| Merge Sort     | Estabilidade necessária   | Requer espaço extra            |
| Quick Sort     | Listas grandes            | Não é estável                  |
| Heap Sort      | Espaço limitado           | Não é estável                  |
| Radix Sort     | Números inteiros/strings  | Requer espaço extra            |

---

### **Tipos de entradas**
1. **Aleatória**: Elementos estão em uma ordem completamente aleatória.
2. **Ordenada (crescente)**: Elementos já estão em ordem crescente.
3. **Ordenada (decrescente)**: Elementos estão em ordem decrescente.
4. **Entrada conhecida**: Estruturas específicas, como muitos elementos repetidos ou padrões previsíveis.

### **Comportamento dos algoritmos**

| Algoritmo      | Aleatória                  | Crescente                 | Decrescente               | Entrada conhecida          |
|----------------|----------------------------|---------------------------|---------------------------|----------------------------|
| **Selection**  | Sempre O(n²)              | Sempre O(n²)              | Sempre O(n²)              | Sempre O(n²)               |
| **Insertion**  | O(n²/4) (médio caso)      | O(n) (melhor caso)        | O(n²) (pior caso)         | Bom para quase ordenados   |
| **Shell**      | O(n log²n) (médio caso)   | O(n log n) (melhor caso)  | O(n log²n) (médio caso)   | Depende da sequência de h  |
| **Merge**      | O(n log n)                | O(n log n)                | O(n log n)                | O(n log n)                 |
| **Quick**      | O(n log n) (médio caso)   | O(n²) (pior caso)         | O(n²) (pior caso)         | O(n log n) com shuffle     |
| **3-way Quick**| O(n log n)                | O(n log n)                | O(n log n)                | Excelente para repetidos   |
| **Heap**       | O(n log n)                | O(n log n)                | O(n log n)                | O(n log n)                 |
| **Radix (LSD)**| O(n*k)                    | O(n*k)                    | O(n*k)                    | O(n*k)                     |

---

#### **1. Selection Sort**
- **Aleatória**: Sempre realiza `n²/2` comparações e `n` trocas, independentemente da entrada.
- **Crescente/Decrescente**: Não aproveita nenhuma ordenação prévia.
- **Entrada conhecida**: Não há otimizações para padrões específicos.

#### **2. Insertion Sort**
- **Aleatória**: Realiza cerca de `n²/4` comparações e trocas no médio caso.
- **Crescente**: Melhor caso, apenas `n-1` comparações, pois não há trocas.
- **Decrescente**: Pior caso, realiza `n²/2` comparações e trocas.
- **Entrada conhecida**: Excelente para entradas quase ordenadas.

#### **3. Shell Sort**
- **Aleatória**: Depende da sequência de incrementos (h). Geralmente O(n log²n).
- **Crescente**: Melhor caso, O(n log n), pois há menos trocas.
- **Decrescente**: Similar ao caso aleatório, O(n log²n).
- **Entrada conhecida**: Pode ser eficiente, mas depende da sequência de h.

#### **4. Merge Sort**
- **Aleatória**: Sempre O(n log n), pois divide e conquista de forma consistente.
- **Crescente/Decrescente**: Não aproveita ordenação prévia, mas mantém O(n log n).
- **Entrada conhecida**: Não há otimizações específicas, mas é estável.

#### **5. Quick Sort**
- **Aleatória**: O(n log n) no médio caso, especialmente com embaralhamento (shuffle).
- **Crescente/Decrescente**: Pior caso, O(n²), se o pivô escolhido for o menor ou maior elemento.
- **Entrada conhecida**: Shuffle ou mediana de 3 ajuda a evitar o pior caso.

#### **6. 3-way Quick Sort**
- **Aleatória**: O(n log n), similar ao Quick Sort.
- **Crescente/Decrescente**: Melhor que o Quick Sort em entradas com muitos elementos repetidos.
- **Entrada conhecida**: Excelente para entradas com muitos valores iguais.

#### **7. Heap Sort**
- **Aleatória**: Sempre O(n log n), pois constrói e ajusta a heap de forma consistente.
- **Crescente/Decrescente**: Não aproveita ordenação prévia.
- **Entrada conhecida**: Não há otimizações específicas.

#### **8. Radix Sort (LSD)**
- **Aleatória**: Sempre O(n*k), onde `k` é o número de dígitos.
- **Crescente/Decrescente**: Não depende da ordem inicial.
- **Entrada conhecida**: Muito eficiente para números inteiros ou strings de tamanho fixo.

---

### **Resumo**
- **Insertion Sort** é ideal para entradas quase ordenadas.
- **Quick Sort** é rápido para entradas aleatórias, mas precisa de melhorias (shuffle ou mediana de 3) para evitar o pior caso.
- **3-way Quick Sort** é excelente para entradas com muitos elementos repetidos.
- **Merge Sort** e **Heap Sort** têm desempenho consistente, independentemente da entrada.
- **Radix Sort** é eficiente para números inteiros ou strings, mas requer espaço extra.


# Referências
### Ferramentas de Visualização
- [Visualgo](https://visualgo.net/en/sorting): Ferramenta interativa para visualizar algoritmos de ordenação.
- [Algorithm Visualizer](https://algorithm-visualizer.org/): Plataforma para simular algoritmos.
- [Sorting Algorithm Animations](https://www.toptal.com/developers/sorting-algorithms): Animações de diferentes algoritmos de ordenação.

### [Visualizador](https://csvistool.com/)

### [Slides](../slides/)

### [Algorithms, 4th Edition, 2nd captcher](https://algs4.cs.princeton.edu/home/)

### [Playlist do Sedgewick](https://www.youtube.com/playlist?list=PLRdD1c6QbAqJn0606RlOR6T3yUqFWKwmX)

### [Playlist dos robos](https://youtube.com/playlist?list=PL2aHrV9pFqNS79ZKnGLw-RG5gH01bcjRZ&si=mb6EwmCQDdCoHSgw)
