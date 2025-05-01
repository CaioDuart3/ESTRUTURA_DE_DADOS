
REFERÊNCIAS:
https://fga.rysh.com.br/eda1/aulas/12-ordenacao_eficiente.pdf

#### CONCEITOS RELACIONADOS:
[[Arvore]]
[[FIlas]]
[[Filas de prioridades]]
## OQUE É?
- É uma das ordenações eficientes (junto com merge sort e quick sort).
- utiliza-se fila de prioridade para ordenar elementos.
- constroe e destroe a heap da fila de prioridades.

## PASSOS:
- Fase 1: 
- Fase 2:
## CARACTERÍSTICAS:

## IMPLEMENTAÇÃO:
#### teoria:
São implementados com vetores

Raiz: pq[1]
Filhos: pq[2], pq[3]
Netos: pq[4], pq[5]

portanto...

pai =>  pq[k/2]
filho => pq[2k] e pq[2k+1]

![[Pasted image 20250124002536.png]]

![[Pasted image 20250124002616.png]]

#### prática:
##### vetor (com acesso direto):
declaração:
``` C
#define less(A,B) (A < B)
#define exch(A,B) {Item t=A; A=B; B=t; }

static Item *pq;
static int N;

//inicializa a árvore
void PQinit(int maxN){
	//                por desconsideramos 0, somamos 1
	pq = malloc(sizeof(Item)*(maxN+1))
	N =0;
}
//verifica se está vázia, zero é utilizado apenas para descrever se está vazia
int PQempty(){
	return N == 0;
}

```

inserir:
``` C
void PQinsert(Item v){
	//adicionar item no fim do vetor
	pq[++N] = v;
	//consertar elemento em sua posição
	fixUp(N);
}
void 


```
conserto de vetor/arvore:
- fixUp: bottom-up(de baixo para cima) / swim (flutuar) => O(log n)
	- fixUp é utilizado para consertar na inserção.
	- seu objetivo no conserto é pegar o elemento da posicao N e posicionar na sua prioridade correta.
``` C
// posicao do elemento no vetor
void fixUp(int k){
// enquanto não chegar na raiz e o filho for maior que o pai
	while(k>1 && less(pq[k/2], pq[k])){
		//swap
		exch(pq[k], pq[k/2]);
		//sobe pro pai
		k = k/2;
	}
}
```

remover:
- consiste em pegar o elemento mais prioritário (raiz);
``` C
Item PQdelMax(){
	//troca raiz com o ultimo elemento
	exch(pq[1], pq[N]);
	//conserta do primeiro ao penultimo elemento, pois o ultimo é um elemento removido (não acessível)
	fixDown(1, N-1);	
	//retorna o removido e diminui N, para o elemento não ser mais acessível;
	return pq[N--];
}
``` 
- fixDown: top-down(de cima para baixo) / sink (afundar) => O(log n)
	- é utilizado para consertar na remoção
	- seu objetivo no conserto é afundar o elemento menos prioritario.
``` C
void fixDown(int k, int N){
	//enquanto tiver filhos dentro do vetor
	while(2*k <= N){
		int j = 2*k;
		// se tiver filho a direita E filho da esquerda for menor que o da direita, pegamos a posição do filho da direita. 
		if(j<N && less(p[j], p[j+1])) j++;
		// se pai maior igual que os filhos, encerra;
		if(! less(pq[k], pq[j]) ) break;
		// se não, (pai menor que os filhos), swap;
		exch(pq[k], pq[j]);
		// filho maior vira pai pra proxima interação com os netos sendo os novos filhos;
		k =j;
	}
}

```
trocar valor da fila, consequentemente trocando prioridade:
``` C
//posição a se receber , valor a ser atribuido
void PQchange(int k, int valor){
	//aplica troca
	v[k] = valor;
	//aplica correção bottom-up
	fixUp(k);
	//aplica correção top-down
	fixDown(k, N);
}

```
##### para ter várias filas, utilizamos struct (sem acesso direto):
- por não ter acesso direto, a dificuldade é maior pra implementação
- porém há o beneficio de se poder criar várias filas.

declaração:
```C
typedef int Item;

typedef struct{
	Item *pq;
	int N;
} PQueue;
//prototipos
PQueue *PQinit(int);
int PQempty(PQueue *);
void PQinsert(PQueue*, Item);
Item PQdelMax(PQueue*);

// ponteiro do inicio da subarvore, "recursoes" a se fazer
void fixUp(PQueue*, int);
void fixDown(PQueue*, int);


```

