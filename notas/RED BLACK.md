## Complexidades
PIOR CASO        |      MÉDIO CASO     |      MELHOR CASO
2log N                |           log N              |              log N
## Sobre
Uma BST rubro-negra (BST) é uma simulação da arvore 2-3
- cada nó duplo (com duas chaves) na 2-3 é representador por dois nós simples(uma pra cada chave) ligados por um link rubro.
- Trataremos da esquerdista(left-leaning), onde os links rubros estão sempre  a esquerda
## Propriedades
- links rubros se inclinam para esquerda, o filho esquerdo é vermelho;
- nenhum nó possui dois links rubros nos filhos;
- balanceamento negro perfeito: o numero de nós negros indo da raiz até o nulo é o mesmo para qualquer caminho 
- todos os links null estão a mesma profundidade negra
- a profundidade negra de um nó x, é o numero de links negros no caminha da raiz até x.
- a altura negra da árvore é o maximo da profundidade negra de todos os nós 
- a altura total da árvore é a maior quantidade de nós independente da cor da raiz até null
- raiz é sempre negra

## OBSERVAÇÕES
tanto na inserção quanto na remoção, fazemos os consertos, rotateRight rotateLeft, flipColors

- se a inserção tem vermelho na direita, rotateLeft
- se a inserção tem dois vemelhos(filho e neto) na esquerda, rotateRight
- se a inserção tem nó da esquerda e da direita vermelho, flipColors

altura total - conta tudo pra esquerda
altura negra - conta os negro pra direita