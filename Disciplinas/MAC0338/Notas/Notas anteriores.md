---
header-includes: |
    \usepackage{algorithmic}
    \usepackage{algorithm}
...
CLRS 1.1, 1.2, 2.1 e 2.2

# Algoritmos
## O *problema da ordenação*
Algoritmos podem ser descritos informalmente como uma sequência finita de passos bem definidos para se realizar uma determinada tarefa. Também podemos pensar em algoritmos como um procedimento computacional que toma um conjunto de valores como entrada e produz um outro conjunto de valores como saída.
Também podemos encarar um algoritmo como uma ferramenta para resolver um problema computacional bem especificado.


# Dando a partida
## Ordenação por Inserção{#ordenacao-por-insercao}
**Entrada:** Uma sequência de $n$ números $\langle a_1, a_2, \dots, a_n \rangle$.\
**Saída:** Uma permutação $\langle a_1', a_2', \dots, a_n' \rangle$ da sequência de entrada tal que $a_1' \leq a_2' \leq \dots \leq a_n'$.
Por exemplo: dada a sequência de entrada $\langle 31, 41, 59, 26, 41, 58 \rangle$, um algoritmo de ordenação retorna como saída a sequência $\langle 26, 31, 41, 41, 58, 59 \rangle$.
Começaremos com a ***ordenação por inserção***, um algoritmo eficiente para ordenar um pequeno número de elementos.

Pseudocódigo:

\begin{algorithm}
    \caption{Insertion-Sort}
    \begin{algorithmic}
    \PROCEDURE{InsertionSort}{$A$}
    \FOR{$j \gets 2$ \TO $A.length$}
        \STATE $key \gets A[j]$
        \STATE 
        \COMMENT{Insere $A[j]$ na sequencia ordenada $A[1 \dots j-1]$}
        \STATE $i \gets j - 1$
        \WHILE{$i > 0$ e $A[i] > key$}
            \STATE $A[i + 1] \gets A[i]$
            \STATE $i \gets i - 1$
        \ENDWHILE
        \STATE $A[i + 1] \gets key$
        \ENDFOR
    \ENDPROCEDURE
    \end{algorithmic}
\end{algorithm}

### Invariantes de laco e a corretude do insertion sort{#invariantes-de-laco}
Usamos ***invariantes de laco*** para nos ajudar por que um algoritmo eh correto. Devemos mostrar tres coisas sobre um invariante de laco:

**Inicializacao**
~ O invariante eh verdadeiro antes da primeira iteracao do laco

**Manutencao**
~ Se o invariante era verdadeiro antes de uma iteracao do laco, ele permanece verdadeiro apos sua execucao.

**Terminacao**
~ Quando o laco termina, o invariante nos da uma propriedade util para provarmos que o algoritmo eh correto.

Note a similaridade entre as duas primeiras propriedades e a inducao matematica: aqui, a parte da inicializacao corresponde ao caso base da inducao, e a manutencao corresponde ao passo indutivo.

Veremos como essas propriedades se aplicam para o insertion sort:\
O invariante que queremos mostrar eh:

::::{.centered}
Para o laco das linhas 2-11, o array $A[1, \dots, j - 1]$ esta ordenado
::::


**Inicializacao:** 
Antes da primeira iteracao do laco, temos que $j = 2$, entao $j - 1 = 1$. Portanto $A[1, \dots, j - 1]$ eh um vetor que corresponde somente a um elemento, $A[1]$, que obviamente esta ordenado.

**Manutencao:**
Suponha que $A[1, \dots, j - 1]$ esta ordenado antes de uma iteracao determinada iteracao do laco. As linhas 6-9 deslocam os elementos maiores do que o elemento $key = A[j]$ que estao em $A[1, \dots, j - 1]$ uma posicao para a frente (o que nao altera a ordem), e param quando encontram um $i$ tal que $A[i] \leq key$, o que significa que $A[1, \dots, i] \leq key$, ou $i = 0$, o que signific que $key$ eh o menor elemento do array $A[1, \dots, j - 1]$. Em ambos os casos, a instrucao da linha 10 coloca o elemento $key$ no seu lugar certo, mantendo o array ordenado. Quando termina essa iteracao do laco, entao $j$ eh incrementado, preservando o invariante.

**Terminacao:**
O laco termina quando $j > A.length = n$. Como cada iteracao do laco incrementa $j$ em $1$, temos que, ao termino da execucao do laco, $j = n + 1$, e portanto $j - 1 = n$. Entao, se o nosso invariante vale, temos que o vetor $A[1, \dots, n]$ eh ordenado, o que significa que o vetor todo esta ordenado, e entao nosso programa eh correto.

# Analisando algoritmos
**Analisar** um algoritmo significa, para nos, fazer predicoes sobre os recursos que um algoritmo requer/consome. Ocasionalmente, esses recursos se referem a memoria, hardware, largura de banda de comunicacao, mas principalmente, nossa atencao se volta para o tempo computacional requerido por um algoritmo.

## Analise do [Insertion-Sort](#ordenacao-por-insercao)
O tempo gasto pelo algoritmo insertion-sort depende da entrada: ordenar mil numeros demora mais do que ordenar tres numeros. Ainda mais: Insertion-sort pode demorar tempos diferentes para entradas diferentes, mas de mesmo tamanho, dependendo do quao ordenadas elas ja estao.\
Em geral, o tempo gasto por um algoritmo cresce em funcao do tamanho da entrada fornecida, entao eh comum descrever o tempo de execucao de um algoritmo como uma funcao do tamanho da entrada. Para faze-lo, precisamos definir bem os conceitos de "tempo de execucao" e "tamanho da entrada".

### Tamanho da entrada
A definicao mais adequada de ***tamanho da entrada*** depende do problema sendo estudado. Para muitos problemas, como ordenar vetores, ou calcular a transformada discreta de Fourier, a medida mais natural eh o *numero de itens* na entrada - por exemplo: o vetor de tamanho $n$, para ordenacao. Para muitos outros problemas, como a multiplicacao de dois inteiros, a melhor medida de tamanho da entrada eh o *numero total de bits* necessarios para representar a entrada em notacao binaria padrao. As vezes, eh mais apropriado descrever o tamanho da entrada com dois numeros, ao inves de um - por exemplo: se a entrada de um algoritmo eh um grafo, o tamanho da entrada pode ser descrito em funcao do numero de vertices e arestas do grafo. Devemos indicar qual medida de tamanho de entrada esta sendo usada em cada problema que estudarmos.

### Tempo de execucao
O ***tempo de execucao*** de um algoritmo em uma entrada particular eh o numero de instrucoes primitivas ou "passos" executados. Eh conveniente definir a nocao de passo do modo mais independente de implementacao possivel. Por hora, vamos adotar a seguinte perspectiva: uma quantidade de tempo constante eh necessaria para executar cada linha do nosso pseudocodigo. Uma linha pode levar uma quantidade de tempo diferente de outra linha, mas assumiremos que a execucao da linha $i$ leva tempo $c_i$, em que $c_i$ eh uma constante.

Comecamos por apresentar o "custo" de execucao de cada instrucao e o numero de vezes que cada instrucao eh executada.