# Árvores
- Estruturas de dados hierárquicas usadas para representar relações entre elementos.
- Cada nó pode ter filhos, e o nó superior é chamado de raiz.
- Usadas em diversas aplicações, como bancos de dados, sistemas de arquivos, e algoritmos de busca.

### Propriedades gerais:
- **Altura**: Número de arestas do nó raiz até a folha mais distante.
- **Profundidade**: Número de arestas do nó até a raiz.
- **Balanceamento**: Diferença entre as alturas das subárvores esquerda e direita.
### Links úteis:
[Conteúdo de Árvores](https://kubokovac.eu/gnarley-trees/)

# Árvore Binária de Busca - BST
- Cada nó tem no máximo dois filhos: esquerdo e direito.
- Propriedade: Para cada nó, todos os valores na subárvore esquerda são menores, e todos os valores na subárvore direita são maiores.

### Operações:
- **Busca**: Percorre a árvore comparando o valor com o nó atual.
- **Inserção**: Insere o valor na posição correta, mantendo a propriedade da BST.
- **Remoção**: Remove o nó e reorganiza a árvore para manter a propriedade.

### Complexidade:
| Operação   | Melhor caso | Médio caso | Pior caso |
|------------|-------------|------------|-----------|
| Busca      | O(log n)    | O(log n)   | O(n)      |
| Inserção   | O(log n)    | O(log n)   | O(n)      |
| Remoção    | O(log n)    | O(log n)   | O(n)      |

### Links úteis:
- [Visualizador BST](https://visualgo.net/en/bst)

# Árvore 2-3
- Cada nó pode ter 2 ou 3 filhos.
- Propriedade: Todos os caminhos da raiz até as folhas têm o mesmo comprimento (árvore balanceada).
- Cresce de baixo para cima

### Operações:
- **Inserção**: Insere o valor em um nó folha. Se o nó exceder 3 chaves, ele é dividido.
- **Busca**: Percorre os nós comparando o valor com as chaves.
- **Remoção**: Remove o valor e reorganiza a árvore para manter o balanceamento.

### Complexidade:
| Operação   | Melhor caso | Médio caso | Pior caso |
|------------|-------------|------------|-----------|
| Busca      | O(log n)    | O(log n)   | O(log n)  |
| Inserção   | O(log n)    | O(log n)   | O(log n)  |
| Remoção    | O(log n)    | O(log n)   | O(log n)  |

### Links úteis:
- [Conteúdo Árvore 2-3](https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/st-twothree.html)
- [Visualizador Árvore 2-3](https://kubokovac.eu/gnarley-trees/23tree.html)

# Árvore Rubro Negra - LLRBT
- Representa uma árvore 2-3 em uma BST com cores (vermelho e preto).
- Sedgewick, Robert. "Left-leaning red-black trees." Dagstuhl Workshop on Data Structures. 2008.
- Invariantes:
    - não pode ter nó vermelho como um filho a direita
    - não pode ter 2 nós vermelhos seguidos
    - cada caminho até cada folha deve ter a mesma quantidadte de nós pretos
    - a raiz sempre é preta

### Operações:
- **Inserção**:
  - Sempre insere um nó vermelho.
  - Corrige as propriedades da árvore com rotações e mudanças de cor.
- **Remoção**:
  - Remove o nó e reorganiza a árvore para manter as propriedades.

### Rotações:
- **Rotação à esquerda**: Corrige quando um nó vermelho está à direita.
- **Rotação à direita**: Corrige quando há dois nós vermelhos consecutivos à esquerda.
- **Flip de cores**: Divide um nó 4-nó em dois 2-nós.

### Pseudo código de uma inserção
```
insert(node, key, value)
    if node == NULL
        return create(key, value, RED)              <- sempre cria um nó vermelho
    
    if key > node.key                               <- verifica onde o nó deve ser criado recursivamente
        insert(node.r, key, value)
    else if key < node.key
        insert(node.l, key, value)
    else
        node.value = value

    if ehVermelho(node.r) && !ehVermelho(node.l)    <- após a insercao do novo nó corrige as invariantes
        node = rotateLeft(node)
    if ehVermelho(node.l) && ehVermelho(node.l.l)   <- balanceia um 4 node
        node = rotateRight(node)
    if ehVermelho(node.r) && ehVermelho(node.l)     <- dividi um 4 node
        flipColors(node)

    return node
```

### Complexidade:
| Operação   | Melhor caso | Médio caso | Pior caso |
|------------|-------------|------------|-----------|
| Busca      | O(log n)    | O(log n)   | O(log n)  |
| Inserção   | O(log n)    | O(log n)   | O(log n)  |
| Remoção    | O(log n)    | O(log n)   | O(log n)  |


### Links úteis:
- [Visualizador LLRBT](https://tjkendev.github.io/bst-visualization/red-black-tree/left-leaning.html)

# Árvore AVL
- Árvore binária de busca balanceada.
- Propriedade: A diferença de altura entre as subárvores esquerda e direita de qualquer nó é no máximo 1.

### Operações:
- **Inserção**: Insere o valor e realiza rotações para manter o balanceamento.
- **Remoção**: Remove o valor e realiza rotações para manter o balanceamento.

### Rotações:
- **Rotação simples**: Corrige o balanceamento quando há um desbalanceamento em uma única direção.
- **Rotação dupla**: Corrige o balanceamento quando há um desbalanceamento em duas direções.

### Complexidade:
| Operação   | Melhor caso | Médio caso | Pior caso |
|------------|-------------|------------|-----------|
| Busca      | O(log n)    | O(log n)   | O(log n)  |
| Inserção   | O(log n)    | O(log n)   | O(log n)  |
| Remoção    | O(log n)    | O(log n)   | O(log n)  |

### Links úteis:
- [Visualizador AVL](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)

# Árvore B
- Árvore balanceada usada em bancos de dados e sistemas de arquivos.
- Propriedade: Cada nó pode ter múltiplos filhos e chaves.

### Operações:
- **Inserção**: Insere o valor em um nó folha. Se o nó exceder o número máximo de chaves, ele é dividido.
- **Busca**: Percorre os nós comparando o valor com as chaves.
- **Remoção**: Remove o valor e reorganiza a árvore para manter o balanceamento.

### Complexidade:
| Operação   | Melhor caso | Médio caso | Pior caso |
|------------|-------------|------------|-----------|
| Busca      | O(log n)    | O(log n)   | O(log n)  |
| Inserção   | O(log n)    | O(log n)   | O(log n)  |
| Remoção    | O(log n)    | O(log n)   | O(log n)  |

### Links úteis:
- [Visualizador Árvore B](https://www.cs.usfca.edu/~galles/visualization/BTree.html)


### Comparação entre árvores

| Tipo de Árvore   | Balanceada | Complexidade (Busca) | Complexidade (Inserção) | Complexidade (Remoção) | Aplicações                     |
|------------------|------------|----------------------|--------------------------|-------------------------|--------------------------------|
| BST              | Não        | O(n)                | O(n)                    | O(n)                   | Estruturas simples             |
| AVL              | Sim        | O(log n)            | O(log n)                | O(log n)               | Sistemas que exigem balanceamento rigoroso |
| Rubro-Negra      | Sim        | O(log n)            | O(log n)                | O(log n)               | Bancos de dados, compiladores |
| 2-3              | Sim        | O(log n)            | O(log n)                | O(log n)               | Implementação teórica          |
| B                | Sim        | O(log n)            | O(log n)                | O(log n)               | Bancos de dados, sistemas de arquivos |