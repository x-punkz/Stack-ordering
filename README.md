*Este projeto foi criado como parte do currículo 42 por daniviei.*

# push_swap

## Descrição

**push_swap** é um projeto do currículo 42 cujo objetivo é ordenar uma pilha de inteiros usando um conjunto limitado de operações, minimizando o número total de movimentações.

O programa recebe uma lista de inteiros como argumentos, armazena-os na **pilha A** e deve ordená-los em ordem crescente usando a **pilha B** como armazenamento auxiliar.

O principal desafio do projeto não é apenas ordenar corretamente, mas fazê-lo de forma eficiente, já que o desempenho é avaliado com base no número de operações.

Neste projeto, o algoritmo turco foi implementado usando uma estratégia baseada em blocos, onde os elementos são inseridos na pilha A e transferidos para a pilha B:
- A lista de entrada é primeiro enviada para um vetor auxiliar.
- Depois os valores sao enviados para a pilha A lá convertidos em inteiros.
- Os valores são demarcados pelos seus indices finais e enviados em 2 blocos (intervalos).
- A primeira metade da lista ordenada é inserida na pilha B de forma controlada.
- A segunda metade é inserida de forma mais livre, priorizando a velocidade em detrimento da ordenação estrita.
- Finalmente, todos os elementos são inseridos de volta da pilha B para a pilha A na ordem correta.

Essa abordagem oferece um bom equilíbrio entre simplicidade e eficiência, especialmente para entradas grandes.

## Instruções

### Compilação

Compile o projeto usando:

make

Isso gerará o executável `push_swap`.

### Execução

Execute o programa passando os números como argumentos:

./push_swap 4 67 3 87 23

O programa exibe na saída padrão a lista de operações necessárias para ordenar os números.

### Exemplo

./push_swap 3 2 1

Saída possível:
sa
rra

### Verificador (opcional)

./push_swap 3 2 1 | ./checker 3 2 1

Se tudo estiver correto, o verificador exibirá:
OK

## Algoritmo e Escolhas Técnicas

### Algoritmo Turco

O algoritmo turco concentra-se em determinar a posição ideal de cada elemento na pilha B antes de inseri-lo, reduzindo rotações e movimentações desnecessárias.

### Estratégia de Fragmentação

- A entrada é toda demarcada com indices indicando suas posições devidamente ordenadas.
- Os elementos pertencentes a pilha A são movidos para a pilha B.
- Para a primeira metade da lista, os elementos sao enviados com base em seus indices.
- Para a segunda metade, os elementos são movidos com mais liberdade.
- A pilha B é então processada para mover todos os elementos de volta para a pilha A em ordem crescente.

Essa estratégia reduz significativamente o número total de operações para entradas de 100 e 500 números.

## Recursos
### Referências

- Disciplina oficial push_swap (42)
- Documentação da disciplina 42 e informações sobre algoritmos de ordenação
- Artigos sobre algoritmos de ordenação baseados em pilha
- Estratégias de ordenação por blocos
- Algoritmo turco usado no push_swap
- Repositórios da comunidade e explicações de alunos da disciplina 42 no medium

### Uso de IA

- Ferramentas de IA foram utilizadas como suporte durante o desenvolvimento deste projeto,
    apenas para formular este readme de forma mais eficiente e acertiva.

## Considerações Finais

Este projeto foi desenvolvido em conformidade com 42 regras, incluindo:
- Uso apenas de funções permitidas
- Gerenciamento adequado de memória
- Tratamento de erros (entrada inválida, duplicados, estouro de inteiro)

O foco principal foi alcançar um bom desempenho (o que deu trabalho :/ ), mantendo o código claro e bem estruturado.