#### Referências:

[FILAS-PauloFeofiloff](https://www.ime.usp.br/~pf/algoritmos/aulas/fila.html) 
[FILAS-Rose](https://fga.rysh.com.br/eda1/aulas/9-tad.pdf) 
## OQUE É?
Uma fila é um **tipo abstrado dados** ([[TAD]]) que admite [remoção](https://www.ime.usp.br/~pf/algoritmos/aulas/array.html#remocao) de elementos e [inserção](https://www.ime.usp.br/~pf/algoritmos/aulas/array.html#insercao) de novos elementos.  Mais especificamente, uma  fila  (= _queue_)  é uma estrutura sujeita à seguinte regra de operação:  cada remoção remove o elemento _mais antigo_ da fila, isto é, o elemento que está na estrutura há _mais_ tempo.
![[fila_exemplo.png]]

## Processamento/atendimento de uma FILA?
Os dados que estão na frente são processados primeiro.

## FIFO (First-in First-out) - Largura
* **primeiro** a entrar, **primeiro** a sair
- inserir no fim, remover no início
## Formas de implementação
#### [[Lista estática]]

##### complexidade constante:
enfileirar e desenfileirar
##### implementações com vetores, fila circular:
- criar_fila
``` C
#define N 7
int fila[N];
int p,u;
void criar_fila (){
	p=u=0;
}
```
- vazia 
``` C
int vazia (){
	return p ==u ;
}
```
- fila_cheia
``` C
int fila_cheia(){
	// se a proxima posição for p && p = 0
	return (u+1 == p) || (u+1==N && p == 0);
	//ou
	//return  (u+1) % N == p;
}
```
- enfileira - insere no fim 
``` C
void enfileira(int y){
	fila[u++] = y;
	if(u == N) u = 0; //se u chegar no fim, reinicia
}
```
- desenfileira - remove no inicio
``` C
int desenfileira(){
	int x = fila[p++];
	if(p == N) p = 0; //se p chegar no fim, reinicia
	return x;
}
```
- redimensiona (realocando espaço da fila):
``` C
void redimensiona (void){
	N*=2; //dobrar tamanho da lista
	fila = realloc (fila, N * sizeof (int));
}
```
- redimensiona (reposicionando p e u):
``` C
void redimensiona (){
	 N*=2;
	 int *novo = malloc(N*sizeof (int));
	 int j = 0;
	 for(int i = p; i < u; i++, j++){
		 novo[j] = fila[i];
	 }
	 free(fila);
	 fila = novo
}
```

- tamanho 
- primeiro - busca inicio
- ultimo - busca fim

##### possibilidade de ter várias filas estáticas:
os códigos a seguir não se tratam de uma fila circular, mas é adaptável.
* declaração:
``` C
//estrutura que ja armazena
typedef int Item;
typedef struct{
	Item *item. //Fila[i] = item
	int primeiro, ultimo; // p, u
} Fila;
```
- criar_filas:
``` C
Fila *criar_filas(int maxN){
	Fila *p = malloc(sizeof(Fila));
	p->item = malloc(maxN*sizeof(Item));
	p->primeiro = p->ultimo = 0;
	return p;
}
```
- vazia:
``` C
int vazia(Fila *f){
	return f->primeiro == f->ultimo;
}
```
- desenfileira: 
``` C
int desenfileira(Fila *f){
	return f->item[f->primeiro++];
}
```
- enfileira:
``` C
void enfileira (Fila *f, int y){
	f->item[f->ultimo++] = y;
}
```
- imprime: 
``` C
void imprime(Fila *f){
	printf("\nFILA p=%d e u=%d", f->primeiro, f->ultimo);
	for(int i = f->primeiro; i < f->ultimo; i++){
		printf(" F[%d] |", i);	
	}
	printf("\n");
	for(int i = f->primeiro; i <f->ultimo; i++){
		printf(" %3d  |", f->item[i]);
	}
	printf("\n");
}
```
#### [[Lista encadeada]]
##### complexidade constante:
enfileirar e desenfileirar
##### implementações:

- enfileirar:
```C
//cria e enfileira
void enfileirar(cabeca *lista, Item x){
	no *novo = criar_no(x);
	if(novo){
		if(vazia(lista)) lista->prox = novo;
		else lista->ultimo->prox = novo;

		lista->ultimp = novo;
		novo->prox = NULL;

		lista->tam++;
	}
}
```
- desenfileira:
```C
//desenfileira e devolve o item
Item desenfileira(cabeca *lista){
	no *lixo = lista->prox;
	lista->prox = lixo->prox;
	if(vazia(lista)) lista->prox = NULL;
	lista->tam--;

	Item x = lixo->info;
	free(lixo);
	return x;
}
```