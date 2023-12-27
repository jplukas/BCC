# Variáveis - Nomes, vincolações e escopos
Capítulo 5 de *Concepts of programming languages*

Linguagens do paradigma imperativo são, em vários graus, abstrações da arquitetura de computadores de Von Neumann subjacente. Os dois componentes principais da arquitetura são a memória, que armazena tanto instruções de programas de computador quanto dados, e o processador, que provê meios de executar essas instruções para modificar o conteúdo da memória. As abstrações das células de memória em uma linguagem são as variáveis. Em alguns casos, essas representações abstratas podem ser bem próximas da realidade de sua implementação, como uma variável do tipo inteiro. Outras vezes, essa representação pode estar totalmente removida de sua realização, como um vetor multidimensional, que requer um software de mapeamento para dar suporte a essa abstração.

Uma variável pode ser caracterizada por uma sextupla de atributos: Nome, endereço, valor, tipo, tempo de vida e escopo.

## Nome
O nome que se dá a uma variável é o modo como o programador se refere a ela.

## Endereço
O endereço de uma variável se refere à região de memória associada a ela. Essa associação por vezes é complexa. Por exemplo, tome uma variável declarada no escopo de uma função, ou subprograma, que é alocada na pilha de execução durante uma chamada a esse subprograma. Diferentes chamadas podem resultar em diferentes endereços de alocação para essa mesma variável, em contextos de chamadas diferentes.\
O endereço de uma variável é por vezes chamado de ***l-value***, pois é o que é requerido quando o nome de uma variável aparece do lado esquerdo de uma expressão de atribuição.

É possível que várias variáveis possuam o mesmo endereço. Quando isso acontece, essas variáveis são chamadas de ***aliases***. Esse processo, chamado de *aliasing*, é um obstáculo para a legibilidade do código, pois permite que uma variável tenha o seu valor alterado por uma instrução de atribuição de outra variável. Então o programador precisa estar ciente de todos os aliases de uma determinada variável. Aliasing também dificulta o processo de manutenção do código.

Aliasing pode ser feito de diversas formas. Um exemplo são os tipos union, em C e C++. Outra forma é por meio de ponteiros, que são variáveis que armazenam endereços, ou referências a outras variáveis. Quando um ponteiro que aponta para uma variável nomeada é desreferenciado, ele e a variável para qual ele aponta são aliases.

## Tipo
O tipo de uma variável determina o conjunto de valores que ela pode armazenar, e as operações que estão definidas para aquela variável.

## Valor
O valor de uma variavel é o conteúdo da célula (ou células) de memória associadas a ela. Aqui, é conveniente pensarmos em células *abstratas* de memória, não físicas, como são implementadas pelo hardware. Células físicas de memória têm um tamanho fixo, dependendo da arquitetura do computador.\
O valor de uma variável é também chamado de ***r-value***, pois é o que queremos da variável, quando ela aparece do lado direito de uma operação de atribuição. Para acessar o r-value, o l-value (ou seja, o endereco) deve ser determinado primeiro.

## O conceito de vinculação
