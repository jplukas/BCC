# MAC0316 - Conceitos fundamentais de linguagens de programação
# Primeiro trabalho - Conceitos: valores, variáveis, sistemas de tipos, abstrações
## Os Conceitos da linguagem Modula-3

Professora Ana C. V. de Melo\
João Pedro Lukasavicus Silva (joao.lukasavicus.silva@usp.br) - 9276940\
Paulo Henrique Albuquerque dos Anjos de Souza - 12542251\

### Introdução
Modula-3 é uma linguagem de programação moderna e de uso geral. Ela fornece excelente suporte para aplicativos grandes, confiáveis e de fácil manutenção. Sua sintaxe e semântica limpas, juntamente com seu suporte para programação orientada a objetos e paralelismo, fazem de Modula-3 uma excelente linguagem de ensino e design. Comparado a outras linguagens com um conjunto de recursos aproximadamente equivalente (por exemplo, Ada e C++), Modula-3 é mais fácil de aprender e mais seguro contra problemas em tempo de execução. Sua facilidade de coleta automática de lixo simplifica muito a programação de aplicativos que fazem uso de memória dinâmica.

### História da linguagem
Modula-3 foi projetada como um projeto conjunto do Centro de Pesquisa de Sistemas (SRC) da Digital Equipment Corporation em Palo Alto, Califórnia, e do Centro de Pesquisa Olivetti em Menlo Park, Califórnia. Os designers foram Luca Cardelli (SRC), Jim Donahue (ORC), Mick Jordan (ORC), Bill Kalsow (SRC) e Greg Nelson (SRC). A primeira descrição da linguagem foi publicada pela Digital e Olivetti em agosto de 1988. Uma revisão baseada em experiência de implementação foi publicada em 1989, e alguns ajustes finais foram feitos em 1990. O ancestral imediato do Modula-3 é a linguagem Modula-2+, projetado na SRC no
início dos anos 1980 como uma linguagem de desenvolvimento interno. Modula-2+ é uma extensão compatível com a linguagem Modula-2 de Niklaus Wirth, que por sua vez foi sucessora do Pascal de Wirth. O próprio Wirth projetou o Oberon em 1987 como um sucessor do Modula-2, mas ele ainda forneceu sugestões úteis para os designers da Modula-3, que estavam seguindo um caminho um pouco diferente do que Wirth fez com o Oberon. sistemas no Centro de Pesquisa da Xerox Palo Alto. (Os módulos da Mesa influenciaram o design do Modula-2 de Wirth.) Outros "primos" do Modula-3 incluem Object Pascal (Apple Computer) e Euclid (PARC).

### Tipos de dados: primitivos e compostos
**Tipos primitivos**: Tipos primitivos são tipos cujos valores não podem ser decompostos em valores mais simples. Sendo assim, outros tipos são construídos a partir dos tipos primitivos. A implementação desses tipos é de "mais baixo nível" no sentido que eles não podem ser definidos utilizando os elementos da própria linguagem. Os valores precisam de uma representação no hardware e têm correspondência com objetos da memória do computador. Em geral, devido a essa natureza de "baixo nível", as operações envolvendo valores de tipos primitivos costumam ser instruções de máquina eficientes. 

**Tipos compostos**: São tipos cujos valores são constituídos de valores mais simples (primitivos). As linguagens de programação oferecem mecanismos para agrupar valores simples e construir valores compostos, às vezes inspiradas em estruturas matemáticas conhecidas, como as operações sobre conjuntos: produto cartesiano e união disjunta.

#### Tipos primitivos em Modula-3
##### Inteiros
Os tipos numéricos discretos em Modula-3 todos pertencem a uma mesma família, a dos tipos *ordinais*. Essa família pode ser subdividida em tipos *integrais*, tipos *enumerados* e tipos de *subfaixas de valores*, com uma certa sobreposição desses conjuntos, mas podemos simplesmente esquecer essa última família.\
Os tipos integrais são constituídos pelos tipos `INTEGER` e tipos de subfaixa de inteiros, do tipo $[n..m]$, (onde $n$ e $m$ são inteiros por sua vez) ou como o tipo `CARDINAL` (que é uma faixa de valores inteiros de 0 até o maior valor `INTEGER` representável para uma determinada implementação da linguagem).\
Já os tipos enumerados são compostos pelas enumerações e subfaixas de enumerações.

###### O tipo `INTEGER`
O tipo `INTEGER` serve para representar valores inteiros.\
As operações aritméticas soma (+), subtração (-), multiplicação (\*), divisão inteira (DIV) e resto da divisão inteira (MOD) estão definidas para esse tipo com a semântica usual. Além disso, a operação unária menos (-) também está definida para esse tipo, e ela resulta na inversão do sinal do operando.\
Existem seis operações relacionais definidas para esse tipo, que resultam em valores do tipo `BOOLEAN` (***true*** ou ***false***):

- `a = b` : ***true*** se `a` é igual a `b`
- `a # b` : ***true*** se `a` é diferente de `b`
- `a < b` : ***true*** se `a` é menor do que `b`
- `a > b` : ***true*** se `a` é maior do que `b`
- `a <= b` : ***true*** se `a` é menor ou igual a `b`
- `a >= b` : ***true*** se `a` é maior ou igual a `b`

Além disso, existem três funções aritméticas definidas para valores do tipo `INTEGER` embutidas na linguagem:

- `ABS(a)` : retorna `-a` caso `a < 0`. Retorna `a` caso contrário.
- `MAX(a, b)` : retorna o maior elemento entre `a` e `b`.
- `MIN(a, b)` : retorna o menor elemento entre `a` e `b`.

Além dessas funções, existe a função `FLOAT(x, T)`, que pode ser usada para transformar um valor `x` do tipo inteiro para um valor do tipo ponto flutuante (mais especificamente, `T`, onde `T` é `REAL`, `LONGREAL` ou `EXTENDED`.)

###### Enumerações, `BOOLEAN` e `CHAR`
Um tipo enumerado consiste em um conjunto de valores que são nomeados com identificadores. Por exemplo, a cor de um objeto pode ser representada por um valor do tipo enumerado `Cor`:
```modula3
TYPE Cor = {Vermelho, Verde, Azul, Branco, Preto};
VAR cor: Cor;
```
Os valores dos tipos enumerados são prefixados com o nome do seu tipo quando usados em expressões. Então, para se atribuir a cor `Azul` à variável `cor`, podemos escrever
```modula3
cor := Cor.Azul;
```
Os tipos enumerados em Modula-3 possuem uma ordem implícita, definida pela ordem na qual os valores aparecem na definição do tipo. Então, da mesma forma em que estão definidos operadores relacionais para inteiros, estes mesmos operadores estão definidos para os tipos enumerados (é claro que só se pode comparar valores do mesmo tipo). O mesmo vale para as funções `MAX` e `MIN`.\
Além disso, existem as funções `ORD(v)` e `VAL(x, T)`, onde `ORD(v)` retorna um inteiro que representa a posição do valor `v` dentro do tipo enumerado em que `v` está definido, começando por zero (p. ex.: `ORD(Cor.Vermelho)` resulta em `0` , e `ORD(Cor.Preto)` resulta em `4`), e a função `VAL(k, T)` retorna o k-ésimo valor definido na enumeração `T`.

O tipo predefinido `BOOLEAN` em Modula-3 é basicamente uma enumeração:
```modula3
TYPE BOOLEAN = {FALSE, TRUE};
```
E os identificadores predefinidos `TRUE` e `FALSE` são sinônimos para `BOOLEAN.TRUE` e  `BOOLEAN.FALSE`. Para o tipo `BOOLEAN` estão definidos os operadores binários `AND`, `OR` e o operador unário `NOT`, além dos operadores definidos para os tipos enumerados.

O tipo `CHAR` é usado para representar valores do tipo caractere, e é implementado como um tipo enumerado. Literais do tipo `CHAR` são escritos com aspas simples
```modula3
VAR letra : CHAR := 'c';
```

##### Ponto flutuante: `REAL`, `LONGREAL` e `EXTENDED`
Os tipos usados para representar valores reais em Modula-3 são `REAL`, `LONGREAL` e `EXTENDED`, que diferem apenas pela quantidade de bits utilizados para se armazenar um valor de cada tipo (ou não, dependendo do compilador utilizado).\
Os mesmos operadores aritméticos definidos para valores dos tipos inteiros são definidos para valores dos tipos ponto flutuante, com exceção da operação de divisão, que entre valores reais é feita pelo operador `/` (e não por `DIV`). Os operadores relacionais são idênticos aos definidos para os tipos inteiros (embora não se possa fazer comparações entre valores de tipos distintos, sem antes realizar uma conversão entre tipos).\
Podemos realizar conversões de valores de tipos ponto flutuante para valores do tipo `INTEGER` com as seguintes funções:

- `FLOOR(x)`: retorna o maior valor inteiro que seja menor ou igual a `x`
- `CEILING(x)`: retorna o menor valor inteiro que seja maior ou igual a `x`
- `ROUND(x)`: retorna o valor inteiro mais próximo de `x`
- `TRUNC(x)`: retorna o valor inteiro mais próximo de `x`, na direção de `0.0`.

#### Tipos compostos em Modula-3
##### Cadeias de caracteres - o tipo `TEXT`
O tipo `TEXT` em Modula-3 é usado para armazenar cadeias de caracteres (ou seja, texto). Na verdade, uma variável do tipo `TEXT` nada mais é do que uma referência a um espaço de memória que é gerenciado pela linguagem, que contém uma cadeia de caracteres (várias células de memória com valores do tipo `CHAR`).\
Literais do tipo texto são cadeias de caracteres entre aspas duplas, p. ex.: 
```modula3
VAR frase: TEXT = "Linguagens de programacao"
```
A única operação definida para valores do tipo `TEXT` é a operação binária de concatenação `&`. Os operadores de comparação `=` e `#`, quando aplicados a valores do tipo `TEXT`, realizam comparações entre os endereços de memória referenciados.

##### Conjuntos - o tipo `SET`
O tipo `SET` é utilizado para representar conjuntos, ou coleções não ordenadas de elementos (não repetidos).\
Seguindo a notação que já nos é familiar, podemos dizer que o tipo `SET` é um caso de conjunto potência de outros tipos:
$$
\texttt{SET} = \mathcal{P}(\texttt{T})
$$
Onde $\texttt{T}$ é um tipo qualquer.\
Exemplo: conjunto de cores:
```modula3
TYPE 
   CjCores = SET OF Cor;
VAR
   coresRGB: CjCores;
```
Podemos atribuir valores do tipo `SET` a variáveis usando *construtores de conjuntos*, que consistem no tipo do conjunto seguido dos seus elementos entre chaves
```modula3
coresRGB := CjCores{Cor.Vermelho, Cor.Verde, Cor.Azul}
```
Para conjuntos, estão definidos as seguintes operações:

- `s + t`: união entre conjuntos
- `s - t`: diferença entre conjuntos (retorna todos os valores de `s` que não estão em `t`)
- `s * t`: intersecção entre conjuntos
- `s / t`: diferença ***simétrica*** entre conjuntos (`(s - t) + (t - s)`)

Além disso, estão definidos os operadores relacionais:

- `s = t`: os conjuntos possuem os mesmos elementos
- `s = t`: os conjuntos não possuem os mesmos elementos
- `s <= t`: `s` está contido em `t`
- `s >= t`: `t` está contido em `s`
- `s < t`: `s <= t AND s # t`
- `s > t`: `s >= t AND s # t`

Um último operador é o operador `IN`, que é usado para determinar se um elemento pertence a um determinado conjunto
```modula3
Cor.Verde IN coresRGB (*TRUE*)
Cor.Preto IN coresRGB (*FALSE*)
1 IN coresRGB (*FALSE*)
```

##### Mapeamentos - o tipo `ARRAY`
Como os conjuntos, o tipo `ARRAY` é um tipo estruturado, composto por um conjunto ordenado de chaves, e um conjunto de valores, em que a cada chave é associado um valor. Na nossa notação costumeira, podemos escrever:
$$
\texttt{ARRAY} = \texttt{C} \mapsto \texttt{V}
$$
Isto é, um array é um mapeamento.\
Os tipos que podem ser usados para as chaves do array são subfaixas de `INTEGER` e subfaixas de tipos enumerados
```modula3
VAR
   pontos: ARRAY Cor OF INTEGER := {1, 20, 8};
   imagem: ARRAY [1..20], [1..20] OF Cor;
BEGIN
   imagem[1, 1] = Cor.Branco
   pontos[Cor.Verde] = 255 (* pontos = {1, 255, 8} *)
END
```
Para o tipo ARRAY, estão definidas as seguintes operações relacionais:

- `a = b`: retorna ***true*** caso todos os elementos de `a` e `b` sejam iguais (elementos correspondentes).
- `a # b`: `NOT a = b`

##### Produto cartesiano - o tipo `RECORD`
O tipo `RECORD` é usado para agrupar diferentes tipos de dados em uma estrutura. Diferentemente do `ARRAY`, o acesso aos componentes (ou campos) de um `RECORD` é feito usando o seu nome, e não o seu índice
```modula3
TYPE Ponto = RECORD
   x, y: REAL;
   cor: Cor;
   END;
VAR
   p: Ponto = Ponto{0.5, 2.75, Cor.Azul}
   d: REAL;
BEGIN
   d = Sqrt(p.x * p.x + p.y * p.y);
   p.cor = Cor.Preto
END
```
Na nossa notação usual, podemos dizer que o tipo `PONTO` é o produto cartesiano dos tipos dos seus componentes:
$$
\texttt{Ponto} = \texttt{REAL} \times \texttt{REAL} \times \texttt{Cor}
$$

### Variáveis - Simples e compostas
**Variáveis Simples**: Variáveis simples são utilizadas para armazenar um conteúdo atômico. Isso significa que o acesso ao conteúdo da variável só pode ser realizado sobre o valor com um todo. Valores de tipos primitivos são armazenados em variáveis simples. Um valor inteiro, por exemplo, apesar de ser implementado diferenciando sinal e módulo, não permite acesso de cada parte separadamente e, portanto, dé armezanado numa variável simples. Por outro lado, tipos compostos tem, em geral, seus valores armazenados em variáveis compostas. Ou seja, de alguma forma é possível tratar seus componentes de forma seletiva. No entanto, em alguns casos, é possível que variáveis simples armazenem valores de tipo composto.

**Variáveis Compostas**: Conforme dito acima, variáveis compostas oferecem algum mecanismo que possibilita tratar seus componentes de forma seletiva. A maioria dos tipos compostos é representada por variáveis compostas. Em algumas linguagens, o produto cartesiano de dois conjuntos, por exemplo, pode ser armazenado em uma variável composta e o conteúdo correspondente aos elementos de cada conjunto do produto pode ser acessado separadamente.

#### Variáveis simples em Modula-3
##### Tipos primitivos
Todas as variáveis que armazenam valores de tipo primitivo em Modula-3 são variáveis simples, quanto ao acesso e armazenamento de valores.

##### Variáveis do tipo `TEXT` e `SET`
As variáveis do tipo `TEXT` não oferecem acesso direto aos seus componentes (no caso, aos caracteres que a compoem). Ao invés disso, as transformações em variáveis do tipo `TEXT` são feitas atomicamente do ponto de vista do programador, seja por meio de funções, ou por meio do operador de concatenação `&`.

O caso das variáveis do tipo `SET` é análogo: somente se opera sobre o conjunto todo, nunca sobre elementos individuais.

#### Variáveis compostas em Modula-3
##### Os tipos `ARRAY` e `RECORD`
Como vimos, o tipo `ARRAY` é um mapeamento, e podemos acessar os seus itens individualmente, por meio de suas chaves. Similarmente, podemos acessar os componentes de variáveis do tipo `RECORD`, por meio dos seus nomes.

### Classificação de variáveis quanto à sua existência
**Variáveis Globais**:
Essa classificação é referente a existência quando da execução de programas. A partir do momento que uma variável global é vinculada a uma célula de memória, ou seja, é alocado memória para armazenar o conteúdo da variável, essa vínculo permanece até o final da execução do programa.

**Variáveis Locais**: Diferenetemente de variáveis globais, variáveis locais têm sua existência influenciada pelos blocos de execução nos quais estão inseridas. Isso significa que o escopo de existência dessas variáveis é escolhido pelo programador e a partir do momento que a execução deixa esse escopo, a memória associada à variável local é desalocada. No entanto, é possível que nova memória seja alocada para essa mesma variável caso a execução do programa volte para o escopo na qual ela está definida.

**Variáveis Heap**:
São variáveis que tem sua existência controlada por comandos de alocação e desalocação de memória. Essa existência temporária controlada por comandos explícitos difere esse tipo de variável das variáveis locais, que tem sua existência relacionada com blocos do programa.

**Variáveis Persistentes**:
São variáveis que armazenam conteúdo que pode ser acessado mesmo após o término da execução do programa. Geralmente, variáveis desse tipo estão relacionadas com arquivos e armazenam dados que são utilizados múltiplas vezes.

#### Tempo de vida e escopo das variáveis em Modula-3
Declarações em uma interface ou no bloco mais alto de um módulo são chamadas de declarações de nível superior e as variáveis declaradas existem ao longo da execução do programa. Os nomes declarados sempre se referem às mesmas variáveis, e essas variáveis são inicializadas uma vez, quando o programa é iniciado pela primeira vez.
Todos os outros blocos ocorrem dentro de procedimentos ou dentro do bloco de nível superior de um módulo.
Declarações nesses blocos são chamadas de declarações locais, e as variáveis declaradas existem apenas enquanto o procedimento ao redor está sendo executado. Cada vez que o procedimento é chamado, novas cópias das variáveis são criadas e inicializadas. Cada vez que o procedimento retorna, as variáveis são destruídas.

### Vinculação de tipos a variáveis
**Formas de vinculação de tipos às variáveis**: os tipos podem ser vinculados às variáveis através de declaração explícita ou implícita. Numa declaração explícita, uma instrução específica de cada linguagem permite que seja especificado um tipo associado a um nome de variável. Já numa declaração implícita, o tipo da variável é inferido. O tipo de inferimento é particular de cada linguagem de programação. É possível, por exemplo, que o tipo seja inferido checando o caractere inicial do nome de uma variável.

#### Formas de vinculação em Modula-3
A vinculação de tipos em Modula-3 pode ser feita tanto de maneira explícita como de maneira implícita, quando uma variável é inicializada logo na sua declaração, e o compilador atribui um tipo à variável analisando a expressão que foi atribuída a ela.
```modula3
VAR
   a: INTEGER; (* Declaração explícita *)
   b := a + 10; (* Declaração implícita *)
   c: REAL := FLOAT(b, REAL) (* Declaração explícita *)
```
#### Tempo de vinculação: estático e dinâmico

**Tempo de vinculação**: Há duas formas de se fazer vinculações: uma vinculação é estática se ocorre em tempo de compilação e permanence inalterada ao longo da execução do programa. Por outro lado, uma vinculação é dita dinâmica se ocorre em tempo de execução. O tempo de vinculação de tipos às variáveis pode ser estático ou dinâmico, dependendo da arquitetura da linguagem de programação.

Em Modula-3, os tipos das variáveis são vinculados estaticamente.