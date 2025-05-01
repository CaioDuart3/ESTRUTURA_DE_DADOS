## Complexidade
depende muita da implementação, mas no melhor caso sempre será 
O(1)

## Propriedades
- tem uma função de espalhamento, função hash
- colisões: chaves duplicadas (retornos da função hash)


## Função hashing
A função hashing respodee a pergunta: "Em qual posição da tabela hash devo colocar esta chave?", ela é responsável por espalhar as chaves pela tabela hash, associando um valor de 0 a M-1

- Queremos uma função de hashing que
    - possa ser calculada eficientemente e
    - espalhe bem as chaves pelo intervalo 0 . . M−1.
### tipos de função hashing
- #### função hash modular
	hash (v, m ) (v % m) // m sendo primo
- #### função hash universal
		hash
## tipos de tabela hash
- encadeamento separado
- endereçamento aberto
	- sondagem linear
	- double hash

## Recomendações
tabela hash em geral é indicado melhor quando você sabe quantos valores serão lidos, pois assim você pode escolher o primo ideal, o tamanho da tabela ideal.
