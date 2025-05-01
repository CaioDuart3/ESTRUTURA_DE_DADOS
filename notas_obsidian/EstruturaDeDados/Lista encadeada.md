## definição:
Sequência de células/nós, alocação conforme necessidade
#### complexidade:
- **Remoção de um nó específico**:
	- **Simples:** tempo linear;
	- **Dupla:** tempo constante;
- **Inserção antes/após um nó específico:**
	- **Simples:** tempo linear(antes), tempo constante(após);
	- **Dupla:** tempo constante;

Busca sequencial, sem acesso direto a uma posição.

##### Implementações:
- Sem cabeça, com cabeça, com cauda, com cabeça e cauda;
- Cabeça do mesmo tipo dos elementos do corpo;
- Cabeça com elementos diferentes do corpo;

##### Tipos: 
- **lista simplesmente encadeada**:
![[Pasted image 20241224182351.png]]
ultimo nó aponta para NULL
com/sem cabeça;
com/sem cauda;
com/sem cabeça com metadados;

- **lista duplamente encadeada:**
além de apontar para o próximo, aponta para o anterior
anterior do primeiro nó aponta para NULL e proximo do ultimo nó aponta para NULL
![[Pasted image 20241224183518.png]]

- **lista circular:**
**Simplesmente Encadeada Circular:**
Cada nó possui um único ponteiro que aponta para o próximo elemento.
O último nó aponta para o primeiro nó, fechando o ciclo.

![[Pasted image 20241224184336.png]]

**Duplamente Encadeada Circular:**
Cada nó possui dois ponteiros:
Um para o próximo nó.
Outro para o nó anterior.
O primeiro nó aponta para o último no campo "anterior".
O último nó aponta para o primeiro no campo "próximo".
![[Pasted image 20241224184400.png]]
- **multilista:**
apontamentos (tanto anterior quanto posterior) não seguem uma ordem/padrão estabelecido de apontamento.
![[Pasted image 20241224184432.png]]