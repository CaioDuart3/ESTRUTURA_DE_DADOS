
---

REFERÊNCIAS:
[ROSE-fga](https://fga.rysh.com.br/eda1/aulas/11-fila_prioridades.pdf) 
[RIBAS-canal-parte1](https://www.youtube.com/watch?v=TjfFVf_H7JQ&t=634s)
[RIBAS-canal-parte2](https://www.youtube.com/watch?v=b_a8NbG1Bq8&t=2810s)
[RIBAS-canal-parte3](https://www.youtube.com/watch?v=7e-7WYsd_tM)

#### CONCEITOS RELACIONADOS:
[[Arvore]]
[[FIlas]]

---

## OQUE É?
- É um tipo abstrato de dados ([[TAD]])
## OBJETIVO:
- o objetivo ***principal*** é saber qual é o elemento mais/menos priotário.
---

## CARACTERÍSTICAS:

- são quase ordenadas;
- raiz é a chave de maior/menor prioridade;
- pai são maiores ou iguais que os filhos;
---
- não necessariamente processam todos os dados, pois conforme novos dados, ela se atualiza;
- utiliza-se de ***[[heap-binaria]]***, tendo todas as folhas em d(árvore completa) ou d-1(árvore quase completa);
---
- os nós estão/são inseridos mais a esquerda.
 ![[Pasted image 20250124001507.png]]

---
### IMPLEMENTAÇÃO:
#### teoria:
São implementados com vetores

Raiz: pq[1]
Filhos: pq[2], pq[3]
Netos: pq[4], pq[5]

---

portanto...

pai =>  pq[k/2]
filho => pq[2k] e pq[2k+1]

![[Pasted image 20250124002536.png]]

![[Pasted image 20250124002616.png]]

---

#### inserção:
![[Pasted image 20250202123954.png]]

---
![[Pasted image 20250202124018.png]]

---
![[Pasted image 20250202124037.png]]

---

![[Pasted image 20250202124100.png]]

---
![[Pasted image 20250202124113.png]]

---

![[Pasted image 20250202124132.png]]

---
![[Pasted image 20250202124142.png]]

---
![[Pasted image 20250202124152.png]]

---
![[Pasted image 20250202124203.png]]

---
![[Pasted image 20250202124222.png]]

---
![[Pasted image 20250202124231.png]]

---
![[Pasted image 20250202124239.png]]

---

#### remoção:
 - Remove o mais/menos prioritário
 - Substituir a raiz por uma folha, pois a antiga foi removida
 - Restauração/conserto: descendo na heap
 ---
![[Pasted image 20250202124806.png]]

---
![[Pasted image 20250202124815.png]]

---

![[Pasted image 20250202124829.png]]

---
![[Pasted image 20250202124838.png]]

---

![[Pasted image 20250202124910.png]]

---

![[Pasted image 20250202124923.png]]

---


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

---

inserir:
passos:
- move N
- insere
- conserta
``` C
void PQinsert(Item v){
	//adicionar item no fim do vetor
	pq[++N] = v;
	//consertar elemento em sua posição
	fixUp(N);
}
void 


```
---

conserto de vetor/arvore:
- fixUp: bottom-up(de baixo para cima) / swim (flutuar) => **O(log n)**
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
---

remover:
- consiste em pegar o elemento mais prioritário (raiz);
passos:
- swap do primeiro com o ultimo
- conserta ignorando o ultimo
- e retorna o ultimo decrementando o tamanho;
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

---

- fixDown: top-down(de cima para baixo) / sink (afundar) => **O(log n)**
	- é utilizado para consertar na remoção
	- seu objetivo no conserto é afundar o elemento menos prioritario após dar um swap.
	- o elemento menos prioritário troca com o maior entre os filhos dele da iteração.
	- a proxima iteração é no posição do antigo filho que era o maior entre os filhos.
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

---

**trocar valor** da fila com acesso direto, onde os dados estão na própria priority queue:
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
---

### trocar valor da fila **SEM** acesso direto, onde os dados não estão na própria priority queue:
- faz a priority queue ter o endereço dos dados.
- faz um vetor auxiliar com o inverso da priority queue, oque era valor vira endereço e oque era endereço na priority quee vira valor.
- e faz fixup e fixDown
---

##### declaração:
``` C

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

