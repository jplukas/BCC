# Introdução

## Alfabetos

Um ***alfabeto*** é um conjunto finito não-vazio qualquer. Aos elementos do alfabeto damos o nome de ***símbolos***.
Comumente usamos uma letra grega maíscula para denotar um alfabeto, como $\Sigma$, e algum símbolo de alguma fonte de máquina de escrever para denotar os seus símbolos.
Exemplos:
$$
\begin{aligned}
\Sigma &= \{\text{0, 1}\}\\
\Gamma &= \{\text{0, 1, x, y, z}\}
\end{aligned}
$$

## Strings

Uma ***string sobre um alfabeto*** é uma sequência *finita* de símbolos de algum alfabeto (podemos também dizer que é uma tupla), usualmente escritas com um símbolo após o outro, e não separados por vírgula. Seja $\Sigma = \{\text{0, 1}\}$ um alfabeto qualquer. Então $w = \text{01011010100}$ é uma string sobre $\Sigma$. Geralmente usamos letras minúsculas para nos referir a strings.

Se $w$ é uma string sobre $\Sigma$, o ***comprimento*** de $w$ denota-se por $|w|$, e é a quantidade de elementos na sequência $w$ (ou também a aridade da tupla $w$).
Uma string pode não conter nenhum símbolo. Nesse caso, dizemos que a string é a ***string vazia***. Denotamos tal string por $\epsilon$ e convencionamos que o seu comprimento é 0.

Sejam $a = a_{1}, \ldots, a_{n}$ uma string sobre $\Sigma_{1}$ e $b = b_{1}, \ldots, b_{m}$ uma string sobre $\Sigma_{2}$. A ***concatenação*** de $a$ e $b$, denotada por $ab$ é a string $a_{1}, \ldots, a_{n} b_{1}, \ldots, b_{m}$, que é uma string sobre $\Sigma_{1} \cup \Sigma_{2}$.

Dizemos que uma string $x$ é uma ***substring*** de uma string $z$ quando existirem strings (possivelmente vazias) $a, b$ tais que $z = axb$. Se $a$ ou $b$ não forem vazias, dizemos que $x$ é uma ***substring própria*** de $z$. Caso $a$ seja vazia, dizemos que $x$ é um ***prefixo*** de $z$. O mesmo vale para ***prefixos próprios***, ***sufixos*** e ***sufixos próprios***.

Uma ***linguagem*** é um conjunto de strings sobre algum alfabeto. Geralmente usamos letras maísculas para denotar linguagens.
Quando uma linguagem qualquer $A$ é tal que nenhuma de suas palavras é um prefixo (próprio) de qualquer outra, dizemos que $A$ é uma linguagem ***livre de prefixos***.

# Autômatos

## Autômatos finitos determinísticos

Um ***autômato finito determinístico***, ou AFD é uma 5-upla $(Q, \Sigma, \delta, q_{0}, F)$, onde:

1. $Q$ é um conjunto finito de ***estados***
2. $\Sigma$ é um alfabeto
3. $\delta : Q \times \Sigma \to Q$ é uma ***função de transição***
4. $q_{0} \in Q$ é um ***estado inicial***
5. $F \subseteq Q$ é um conjunto de ***estados de aceitação***

Podemos representar um AFD por um grafo direcionado $G$, onde:

1. Cada vértice do grafo corresponde a um estado
2. Cada aresta $\alpha$ corresponde à uma transição possível de um estado a outro. Cada vértice deve estar associada a um símbolo do alfabeto.

Usamos grafos direcionados para desenhar o ***diagrama de estados*** de um AFD.

## Linguagens regulares

Seja $M$ um AFD, e seja $\Sigma$ o alfabeto da sua definição. Uma string $w = w_{1}, \ldots, w_{n}$ sobre $\Sigma$ é dita ***aceita*** por $M$ se existe uma sequência finita de estados $r_{0}, \ldots, r_{n}$, onde $r_{0} = q_{0}$ é o estado inicial de $M$, $r_{n} \in F$ é um dos estados de aceitação de $M$, e $r_{k + 1} = \delta(r_{k}, w_{k + 1})$, para $0 \leq k \leq n - 1$, e $\delta$ é a função de transição de $M$.
Uma linguagem $A$ é dita ***reconhecida*** por um autômato $M$ quando todas as suas strings são aceitas por $M$.
Uma linguagem é dita ***regular*** quando existe algum autômato que a reconhece.
Se $B$ for o conjunto de todas as strings reconhecidas por $M$, então dizemos que $B$ é a ***linguagem da máquina*** $M$, e escrevemos $L(M) = B$. Podemos também escrever $L(M)$ na linguagem de construção de conjuntos, como
$$
\begin{aligned}
L(M) = \{x | M \text{ aceita } x\}
\end{aligned}
$$


## Operações regulares

Vamos definir algumas operações (em outras palavras, funções) sobre linguagens. Sejam $A$ e $B$ duas linguagens sobre $\Sigma_{1}$ e $\Sigma_{2}$, respectivamente. Definimos então as seguintes operações:

### União

A operação de ***união*** é análoga a operação de conjuntos. É definida por:
$$
\begin{aligned}
A \cup B = \{x | x \in A \vee x \in B\}
\end{aligned}
$$

Note que a linguagem "resultante" é uma linguagem sobre $\Sigma_{1} \cup \Sigma_{2}$.

### Concatenação

A operação de ***concatenação*** é definida por:
$$
\begin{aligned}
A \circ B = \{xy | x \in A \wedge y \in B\}
\end{aligned}
$$

Note que a linguagem "resultante" também é uma linguagem sobre $\Sigma_{1} \cup \Sigma_{2}$.

### Estrela

A operação ***estrela***, diferentemente das outras duas operações, é uma operação *unária*, e é definida por:
$$
\begin{aligned}
A^{*} = \{x_{1}...x_{k} | x_{i} \in A \text{ para } 1 \leq i \leq k \wedge k \geq 0\}
\end{aligned}
$$

Isto é, cada string em $A^{*}$ é a concatenação de 0 ou mais strings em $A$.