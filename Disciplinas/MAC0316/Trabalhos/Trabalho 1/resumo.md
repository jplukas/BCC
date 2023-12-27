**Tipos primitivos**: Tipos primitivos são tipos cujos valores não podem ser decompostos em valores mais simples. Sendo assim, outros tipos são construídos a partir dos tipos primitivos. A implementação desses tipos é de "mais baixo nível" no sentido que eles não podem ser definidos utilizando os elementos da própria linguagem. Os valores precisam de uma representação no hardware e têm correspondência com objetos da memória do computador. Em geral, devido a essa natureza de "baixo nível", as operações envolvendo valores de tipos primitivos costumam ser instruções de máquina eficientes. 

**Tipos compostos**: São tipos cujos valores são constituídos de valores mais simples (primitivos). As linguagens de programação oferecem mecanismos para agrupar valores simples e construir valores compostos, às vezes inspiradas em estruturas matemáticas conhecidas, como as operações sobre conjuntos: produto cartesiano e união disjunta.

**Variáveis Simples**: Variáveis simples são utilizadas para armazenar um conteúdo atômico. Isso significa que o acesso ao conteúdo da variável só pode ser realizado sobre o valor com um todo. Valores de tipos primitivos são armazenados em variáveis simples. Um valor inteiro, por exemplo, apesar de ser implementado diferenciando sinal e módulo, não permite acesso de cada parte separadamente e, portanto, dé armezanado numa variável simples. Por outro lado, tipos compostos tem, em geral, seus valores armazenados em variáveis compostas. Ou seja, de alguma forma é possível tratar seus componentes de forma seletiva. No entanto, em alguns casos, é possível que variáveis simples armazenem valores de tipo composto.

**Variáveis Compostas**: Conforme dito acima, variáveis compostas oferecem algum mecanismo que possibilita tratar seus componentes de forma seletiva. A maioria dos tipos compostos é representada por variáveis compostas. Em algumas linguagens, o produto cartesiano de dois conjuntos, por exemplo, pode ser armazenado em uma variável composta e o conteúdo correspondente aos elementos de cada conjunto do produto pode ser acessado separadamente.

**Variáveis Globais**:
Essa classificação é referente a existência quando da execução de programas. A partir do momento que uma variável global é vinculada a uma célula de memória, ou seja, é alocado memória para armazenar o conteúdo da variável, essa vínculo permanece até o final da execução do programa.

**Variáveis Locais**: Diferenetemente de variáveis globais, variáveis locais têm sua existência influenciada pelos blocos de execução nos quais estão inseridas. Isso significa que o escopo de existência dessas variáveis é escolhido pelo programador e a partir do momento que a execução deixa esse escopo, a memória associada à variável local é desalocada. No entanto, é possível que nova memória seja alocada para essa mesma variável caso a execução do programa volte para o escopo na qual ela está definida.

**Variáveis Heap**:
São variáveis que tem sua existência controlada por comandos de alocação e desalocação de memória. Essa existência temporária controlada por comandos explícitos difere esse tipo de variável das variáveis locais, que tem sua existência relacionada com blocos do programa.

**Variáveis Persistentes**:
São variáveis que armazenam conteúdo que pode ser acessado mesmo após o término da execução do programa. Geralmente, variáveis desse tipo estão relacionadas com arquivos e armazenam dados que são utilizados múltiplas vezes.

**Formas de vinculação de tipos às variáveis**: os tipos podem ser vinculados às variáveis através de declaração explícita ou implícita. Numa declaração explícita, uma instrução específica de cada linguagem permite que seja especificado um tipo associado a um nome de variável. Já numa declaração implícita, o tipo da variável é inferido. O tipo de inferimento é particular de cada linguagem de programação. É possível, por exemplo, que o tipo seja inferido checando o caractere inicial do nome de uma variável.

**Tempo de vinculação**: Há duas formas de se fazer vinculações: uma vinculação é estática se ocorre em tempo de compilação e permanence inalterada ao longo da execução do programa. Por outro lado, uma vinculação é dita dinâmica se ocorre em tempo de execução. O tempo de vinculação de tipos às variáveis pode ser estático ou dinâmico, dependendo da arquitetura da linguagem de programação.
