## REFERÊNCIAS:
[ÁRVORES na Computação I Programação dinâmica | youtube](https://www.youtube.com/watch?v=NpJVZtgSY4U)
[Arvore-Rose](https://fga.rysh.com.br/eda1/aulas/10-arvores.pdf)
[Método-de-leitura-percurso-arvores](https://www.youtube.com/watch?v=T4okc8dDlek)
## O QUE É?
- Estrutura não-linear com relacionamentos hierárquicos entre os elementos(nós, vértices)
- É um [[Grafo]] conexo acíclico.
- enraizada
## Utilidade:
- Amplamente utilizadas na computação para modelagem de problemas reais: representação computacional.
- Representação hierárquica:
	-  Estrutura de organização que favorece consultas eficientes.
	-  Cada ramificação possui um conjunto de informações específicas.
	
![[arvore_genealogica.png]]

## Aplicações:
- aprendizado de máquina
- enginnes como o Super Cocos
- sistemas de arquivos
- comprimir arquivos, (código de Huffman)

## Definições:
![[arvore_conceito.png]]
#### legenda
- raiz- primeiro elemento da árvore.
- não terminais- nós que possuem filhos não nulos.
- folhas/terminais- nós que todos os filhos são nulos.
- nós externos- elementos nulos(nada, zero, nill), não tem filhos.
	- nós externos = nós internos + 1
- nós internos- elementos não-nulos, podem ter filhos.
## Genealogia:
![[arvore_genealogia2.png]]

![[arvore_genealogia.png]]

![[Pasted image 20250103145228.png]]
-Subárvore enraizada em x é a árvore composta pelos nós descendentes de x

![[Pasted image 20250103145311.png]]

#### observações:
Grau: número de filhos/ramificações (subárvores), em uma binária o grau é 2.
nó folha possui grau 0.
Árvores n-árias: quando **todos os nós** possuem grau máximo "n" (binária. ternária)

### Profundidade
![[Pasted image 20250103145610.png]]
- Nível inidica a profundidade dos nós
- Profundidade de um nó:
	- Número de ancestrais: caminho entre o nó até a raiz.
	- A raiz tem profundidade 0
- Um conjunto de nós com  a mesma profundidade estão em um mesmo nível.
### Altura
maior profundidade de um nó externo (NULL),
Altura = profundidade + 1
![[Pasted image 20250103151340.png]]
- Se a altura é h, então a árvore:
	- tem no mínimo h nós internos.
		![[Pasted image 20250103161129.png]]
	- tem no máximo nʰ - 1 nós internos (árvore n-ária completa)
		- exemplo na binária:
			- 2⁰ + 2¹ + 2³ + ... + 2ʰ⁻¹
			- soma de uma PG (a0 * (qʰ-1)) / (q-1)
			- n = 1* (2ʰ-1) / (2-1)
			- n = 2ʰ-1
			![[Pasted image 20250103161513.png]]
- Se a árvore tem n >= 1 nós, então a altura:
	- é no mínimo lg(n+1):
		- quando a árvore é completa
		- incompletaa
	- é no máximo n:
		- quando cada nó não-terminal tem apenas um filho
### Tipos
#### binária:
###### classificação:
- Árvore estritamente binária:
	- os nós tem 0 ou 2 filhos.
	![[Pasted image 20250103153056.png]]
- Árvore Binária quase completa
	- Todas as folhas estão no nível "d" ou "d-1", ou seja, o ultimo nível ou o penúltimo nível está cheio.
	![[Pasted image 20250103155712.png]]
- Árvore Binária completa
	- Todos os nós folhas estão em um mesmo nível
	![[Pasted image 20250103160339.png]]
- Árvore binária cheia
	- consiste em um árvore estritamente binária e completa;
	![[Pasted image 20250103160549.png]]

##### implementação
- Lista de adjacências ou matriz de adjacências (aulas anteriores)
- Lista estática ou encadeada
	- ![[Pasted image 20250103193653.png]]
	- ![[Pasted image 20250103193724.png]]
	- ![[Pasted image 20250103194237.png]]
		- pai: v[k]= k/2
		- filho: v[k]= 2*k e 2*k+1

- declaração:
``` C
typedef int Item;
typedef struct node no;
struct node{
	Item item;
	no *pai;
	no *esq, *dir;
};
```
- criar árvore:
``` C
//               elem    pai     esq    dir
no *criar_arvore(Item x, no *p, no *e, no *d){
	no *raiz = malloc(sizeof(no));
	raiz->pai = p;
	raiz->esq = e;
	raiz->dir = d;
	raiz->item = x;
	return raiz;
}
```
- pegar avô:
```C
no *avo(no *elemento){
		//se o elemento e o pai dele existem, portanto ele tem um avô
	if((elemento != NULL)&&(elemento->pai!=NULL)){
		return elemento->pai->pai;
	}
	return NULL;
}
```
- pegar tio:
```C
//      elemento
no *tio(no *elemento){
	//pega o avô do elemento
	no *vo = avo(elemento);
	//confere se existe um avô para que haja um tio
	if(vo == NULL) return NULL;
	//se ele existe, confere se o tio está na esq ou dir
	if (elemento->pai == vo->esquerda) return vo->direita;
	return vo->esquerda;
}
```
- pegar irmão:
``` C
no *irmao(no *elemento){
	if((elemento != NULL) && (elemento->pai != NULL)){
		if(elemento == elemento->pai->esquerda){
			return pai->direita;
		}
		return pai->esquerda;
	}
}
``` 
- busca linear:
``` C
no *busca_linear(no *elemento, Item v){
	//se o elemento é nulo ou raiz da subarvore, retorna-o
	if(elemento == NULL || elemento->item == v){
		return elemento;.
	}
	no *e = busca_linear(elemento->esq, v);
	if(e != NULL) return e;
	return (buscal_linear(elemento->dir, v));
}
```
- numero de nós internos:
```C
int numero_nos(no *raiz){
	if(raiz == NULL) return 0;
	return 1 + numero_nos(raiz->esq) + numero_nos(raiz-dir);
}
```
- altura:
```C
int altura(no *raiz){
	if(raiz == NULL) return 0;
	int h_esq = altura(raiz->esq);
	int h_dir = altura(raiz->dir);
	return 1 + (h_esq > h_dir ? h_esq:h_dir);
}
```
#### Algoritimos de percurso:
- Diferentes percursos, geram diferentes sequências de nós (informações).
- ##### Percurso em largura
	- utiliza-se de [[FIlas]]
	- percurso por nível: os nós são visitados na ordem dos níveis em que se encontram
	- inicialmente são visitados todos os nós do nível 0 (raiz), depois os nós do nível 1, depois do nível 2 e assim por diante.
	![[Pasted image 20250114164718.png]]
- ##### Percurso em profundidade
	- utiliza-se de [[Pilhas]]
	- Em-Ordem: esquerda pai direta (ex:notação normal)
	- Pré-Ordem: pai esquerda direita (ex: notação polonesa)
	- Pós-Ordem esquerda direita pai (e: notação polonesa inversa)
- ##### Códigos do percurso:
- pré-ordem:
``` C
void preOrdem(no *raiz){
	if(raiz != NULL){
		printf("%d", raiz->dado);
		preordem(raiz->esq);
		preordem(raiz->dir);
	}
}
```
- em-ordem:
```C
void emOrdem(no *raiz){
	if(raiz != NULL){
	emOrdem(raiz->esq);
	printf("%d", raiz->dado);
	emOrdem(raiz->dir);
	}
}

```
- pós-ordem:
```C
void posOrdem(no *raiz){
	if(raiz != NULL){
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf("%d", raiz->dado);
	}
}
```
- porNivel:
```C
void porNivel(no *raiz){
	

}
```
