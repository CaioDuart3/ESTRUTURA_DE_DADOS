## Árvore de busca binária
- Combina a flexibilidade das listas encadeadas com a eficiência da busca binária
## Estrutura das árvores binárias
- Todo nó não-terminal(folha) tem no máximo 2 filhos
- Nó folha apontam para NULL(nós externos)
## Estrutura de busca na ABB
- Cada nó tem a chave **maior** que as chaves da sua subárvore a esquerda.
- Cada nó tem a chave **menor** que as chaves da sua subárvore a direita.
- Permite a busca binária de um nó a partir da raiz
- Em uma **árvore de busca binária**, os elementos comparados e ordenados são geralmente as **chaves** dos nós, e essas chaves precisam ser **únicas**
- 
![[Pasted image 20250114134556.png]]
## código
- declaração:
``` C

#define info (A )(A . info )
#define key (A ) (A. chave )
#define less (A , B)(( A) < (B))
#define eq (A , B)(( A) == ( B))
#define exch (A , B) { Item t=A; A=B; B=t; }
#define compexch (A , B) if( less (B , A)) exch (A , B )

//cada item de um nó é representado como struct, contendo uma chave única e info 
typedef int Key;
typedef struct data Item;
struct data{
	Key chave;
	char info[100];
};
//subarvore representada como struct
typedef struct node STnode;
struct node{
	Item item;
	STnode *esq, *dir;
};

```
- criação:
```C
	STnode *new(Item x, STnode *e, STnode *d){
		STnode *no = malloc(sizeof(STnode));
		no->item = x;
		no->esq = e;
		no->dir = d;
		return no;
	}
```
- buscar_elemento:
```C
	STnode *STsearch(STnode *no, Key v){
		//se o elemento for nulo, retorna nulo, se o elemento for a raiz da subarvore, retorna o elemento
	
		if(no == NULL || eq(v, key(no->item))){
			return no;
		}
		// se ele a chave for menor que a chave da raiz, vai para esquerda, se não, direita
		if(less(v, key(no->item))){
			return STsearch(no->esq, v);
		} else{
			return STsearch(no->dir,v);
		}
	}
```
- inserir_elemento: 
``` C
//              arvore       novo nó
STnode *STinsert(STnode *no, Item item){
//  se não tiver elementos ela cria uma árvore para inserir.
	if(no == NULL) 
		return new(item, NULL, NULL);
	//armazena a chave do novo
	Key novo = key(item);
	//armazena a chave da atual nó da árvore
	Key atual = key(no->item);
	
	if(less(novo, atual))
		no->esq = STinsert(no->esq, item);
	else
		no->dir = STinsert(no->dir, item);
	return no;
}
``` 
-  menor elemento de uma ABB:
``` C
STnode *minimo(STnode *no){
	if(no->esq == NULL) return no;
	return minimo(no->esq);
}
``` 
- maior elemento de uma ABB:
``` C
STnode *maximo(STnode *no){
	if(no->dir == NULL) return no;
	return maximo(no->dir);
}
``` 
- sucessor de um nó:
	- caso tenha subarvore a direita é o seu menor elemento
	- caso **não** tenha, é o ancestral a direita
	``` C
	STnode *sucessor(STnode *no){
		//se tem subarvore a direita pega o menor elemento.
		if(no->dir != NULL) return minimo(no->dir);
		//se não tem subarvore, pega o ancestral a direita
		return ancestral_a_direita(STnode*no);
	}
	STnode *ancestral_a_direita(){
	
		if(no == NULL) return NULL;
		// se não tiver pai, por tanto não há sucessor, se ele for o filho da esquerda o sucessor é o pai
		if(no->pai == NULL || no->pai->esq == no) return no->pai; 
		
		return ancestral_a_direita(no->pai);
	}
	``` 
- remover nó:
	- caso 1: remover folha - resolve-se com ligação direta;
	- caso 2: um filho - resolve-se ligando o filho ao avô; 
	- caso 3: 2 filhos - resolve-se colocando o sucessor no lugar do pai.
``` C
STnode *STdelete(STnode *no, Key remove){
// não encontrou o elemento para remover
	if(no == NULL) return NULL;
	Key atual = key(no->item);


	// percorrer 
	//procurar a esquerda o elemento a ser removido
	if(less(remove, atual)){
		no->esq = STdelete(no->esq, remove);
	}
	//procurar a direita o elemento a ser removio
	else if (less(atual, remove)){
		no->dir = STdelete(no->dir,remove);
	}
	
	// CASO 1 e 2:
	else if(no->dir == NULL){
			STnode *filho =no->esq;
			free(no);
			return filho;
	}
	else if(no->esq == NULL){
		STnode *filho = no->dir;
		free(no);
		return filho;	
	}
	else{
		remover_sucessor(no);
	}
	return no;
}
```
# CONTINUAR SLIDE 235
### Complexidade:
![[Pasted image 20250114215049.png]]
solução: árvores red-blacks.