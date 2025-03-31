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
- melhoriras: usar inserton sort para sub-arrays pequenos (menor que 10), parar quando ja estiver ordenado


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
    fix_down(a, --n, 1)         <
```
# Radix
## MSD
## LSD

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

# Referências
### [Visualizador](https://csvistool.com/)

### [Slides](../slides/)

### [Algorithms, 4th Edition, 2nd captcher](https://algs4.cs.princeton.edu/home/)

### [Playlist do Sedgewick](https://www.youtube.com/playlist?list=PLRdD1c6QbAqJn0606RlOR6T3yUqFWKwmX)
