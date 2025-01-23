# Selection
- Anda com o indice para direita e trás o menor valor para frente do vetor
- Invariancia: todos os elementos a esquerda do ponteriro são menores que o elemento do ponteiro e estão em ordem ascendente
- Faz `N trocas`
- Faz N²/2 comparações
- `Sempre quadrático`
- `inplace`

# Insertion
- Anda com o indice para a direita e troca o valor do ponteiro com todos os maiores que estão na esquerda
- No inicio de cada interção os elementos da esquerda estão em ordem ascendete e os da direita ainda não foram vistos
- o indice i determina até onde foi ordenado e o j o ponteiro do valor que está sendo trocado(indo para esquerda até encontra um valor menor ou o fim do vetor)
- Faz em media `N²/4 comparações e trocas`
- Melhor caso: N-1 comparações
- Vetor parcialmente ordenados se tornam lineares

# Shell
- usa varios h-sorts com valores de decrescentes de h
- h-sort: mesma ideia do insertion sort mas, salta h indices para a esquerda ao invés de 1 
- 1-sort == insertion sort
- valores ok de h: 3x + 1
- valores bom de h: 1,5,19,41,109,209,505,929,2161,3095,... 


# Merge
- Divide o vetor de 2, ordena recursivamente cada metade, unifica(merge) as duas metades
- no maximo N log(N) comparaçoes
- melhoriras: usar inserton sort para sub-arrays pequenos (menor que 10), parar quando ja estiver ordenado



# Resumo
Método          | Inplace  | Estável  | Melhor  | Médio  | Pior  |
:-------------: | :------: | :------: | :-----: | :----: | :---: |
Selection       | X        |          |         |        |       |
Insertion       | X        | X        |         |        |       |
Shell           | X        |          |         |        |       |
Merge           |          |          |         |        |       |
Tim             |          |          |         |        |       |
Quick           |          |          |         |        |       |
3-way Quick     |          |          |         |        |       |
Heap            |          |          |         |        |       |