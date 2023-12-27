# MAC0316 - Conceitos fundamentais de linguagens de programação
# Segundo trabalho - Sistemas de tipos e abstrações
## Os Conceitos da linguagem Modula-3

Professora Ana C. V. de Melo\
João Pedro Lukasavicus Silva (joao.lukasavicus.silva@usp.br) - 9276940\
Paulo Henrique Albuquerque dos Anjos de Souza - 12542251\

### Sistemas de tipos
#### Tipos monomórficos
As variáveis, a menos do caso do uso de *Genéricos*, são do tipo monomórfico em modula-3, uma vez que seus tipos são todos vinculados estaticamente por meio de declarações explícitas ou implícitas

#### Sobrecarga
Em modula-3 somente existe sobrecarga sobre alguns operadores predefinidos, como `ABS`, que pode ser usado com números inteiros e reais, o que caracteriza, nesse caso, uma sobrecarga independente de contexto. Não existe sobrecarga de procedimentos ou de operadores em modula-3.

#### Polimorfismo
Em modula-3, um tipo de polimorfismo presente na linguagem se dá pelos tipos parametrizados, que são chamados de *generics*, no nosso caso.

### Equivalência de tipos
#### Equivalência estrutural
Em modula-3, o tipo de equivalência de tipos adotado é o de equivalência estrutural.

### Estilo de tipagem
Modula-3 é uma linguagem fortemente tipada, com vinculação estática de tipos. Isso significa que inconsistências entre tipos podem ser verificadas em tempo de compilação. 


## Abstrações
## Abstrações de processos: Procedimentos e funções
Em Modula-3, procedimentos são apenas funções que não retornam nenhum valor. *Procedures* são declaradas usando-se a keyword `PROCEDURE`, seguida do seu nome, sua assinatura e seu corpo. A sua assinatura lista os parâmetros formais, tipo do resultado (se houver) e o conjunto de exceções lançadas pelo procedimento.   

### Parâmetros
#### Parâmetros formais
Parâmetros formais são um canal pelo qual os dados são passados para um procedimento. Durante a chamada de uma função, os parâmetros formais são associados aos parâmetros atuais, que são os dados passados para o procedimento. Esses parâmetros são associados de duas maneiras distintas, por valor e por referência, dependendo do "modo" que são declarados na assinatura do procedimento. 

##### Tipos e modos de parâmetros
Todo parâmetro formal tem um tipo e um modo. Os tipos de dados já foram discutidos, então nos atentamos aos modos:

 - ***VALUE***: No modo *value*, o parâmetro formal é tratado como uma variável local ao escopo do procedimento, e o valor do parâmetro atual é copiado para o parâmetro formal. Assim não há uma vinculação entre o parâmetro formal e o atual, e quaisquer modificações no valor do parâmetro formal não terão consequências no estado do programa, fora do escopo do procedimento.
 - ***VAR***: No modo *var*, o parâmetro formal é associado ao atual por meio de um mecanismo chamado passagem por referência, no qual o parâmetro formal se torna uma espécie de *alias* para o parâmetro atual, isto é, apenas um outro nome para a mesma variável, e então, qualquer mudança no valor do parâmetro formal também acarretará uma mudança no valor do parâmetro atual. Note que nesse caso, não é possível passar um valor constante, ou literal na chamada da função.
 - ***READONLY***: um parâmetro no modo *readonly* difere de parâmetros nos outros modos pois não pode ser modificado, e o compilador se encarrega de decidir se o mecanismo utilizado será o de passagem por valor ou por referência, de modo a deixar o código mais otimizado possível.

