#### REFERÊNCIAS:
[Pilha_Feofiloff](https://www.ime.usp.br/~pf/algoritmos/aulas/pilha.html)
[Pilha_ROSE](https://fga.rysh.com.br/eda1/aulas/9-tad.pdf)
## OQUE É?
Uma pilha é uma estrutura de dados que admite remoção de elementos e inserção de novos elementos. Mais especificamente, uma pilha ( = stack) é uma estrutura sujeita à seguinte regra de operação: sempre que houver uma remoção, **o elemento removido é o que está na estrutura há *menos tempo***
![[pilha.png]]

## PROCESSAMENTO/ATENDIMENTO DA PILHA

## LIFO (Last-in First-out) - Profundidade
- remoção no topo da pilha
- inserção no topo  da pilha

## Formas de implementação

#### [[Lista estática]]
##### implemntação básica vetor:
- criar: ```
``` C
int *pilha; //declaradas globalmente
int t;N  //t = topo, N = tamanho
void criar(int N){
	pilha = malloc(N*sizeof(int))
	t =0;
}
```
- empilhar:
``` C
void empilha(int x){
	pilha[t++] = x;
}
```
- desempilhar:
``` C
Item desempilha(){
	return pilha[--t]; 
}
```
- espia:
``` C
Item espia(){
	return pilha[t-1];
}
```
- vazio:
``` C
int vazia(){
	return t == 0;
}
```
##### implementação básica de vetor usando struct:
- declaração:
``` C
typedef char Item;
typedef struct {
	Item *item;
	int topo;
}Pilha;
``` 
- criar pilha:
``` C
Pilha *criar( int maxN){
	Pilha *p = malloc(sizeof(Pilha));
	p->item = malloc(maxN*sizeof(Item));
	p->topo =0;
	return p;
}
```
- vazia:
``` C
int vazia(Pilha *p){
	return p->topo == 0;
}
```
* empilhar:
``` C
void empilhar(Pilha *p, Item item){
	p->item[p->topo++] = item;
}
```
* espiar:
``` C
Item espiar(Pilha *p){
	return p->item[p->topo-1];
}
```
#### [[Lista encadeada]]

- declaração cabeça:
``` C
typedef struct head{
	
}
```
- empilha: 
empilhar um item, implica em dizer que está criando um nó
``` C
void empilha(head *lista, Item x){
	node *novo = criar_no(x);
	if(novo){
		if(vazia(lista)) lista-> ultimo = novo;
		novo->prox = lista->prox; //aponta para quem a cabeça aponta.
		lista->prox = novo; //faz com que a cabeça aponte para o recem nó criado
		lista->num_itens++; //aumenta a quantidade de itens na pilha
	} 
}
```
- desempilha:
``` C
Item desempilha(head *lista){
	node *topo = lista->prox; //pega o topo, que é o primeiro elemento.
	lista->prox = topo->prox;  //faz com que a cabeça aponte para quem o primeiro elemento aponta.
	if(topo == lista->ultimo) lista->ultimo = NULL; //se sobrar um elemento, aponta para NULL
	lista->num_itens--;
	Item x = topo->info;//armazena o elemento removido para retornar;
	free(topo);
	return x; //retorna o elemento removido
}
```
- espia:
```C
Item espia(head *p){
	return (p->prox->info); //retorna a informação do elemento do topo.
}
```
