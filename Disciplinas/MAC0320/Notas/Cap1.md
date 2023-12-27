# Conceitos e resultados básicos

## Grafos

[]{#prop:1}
: Para todo grafo $G$ temos que $\sum_{v \in V(G)}^{}g(v) = 2|A(G)|$

Colorário 1.2: Todo grafo tem um número par de vértices de grau ímpar.

## Tipos especiais de grafos

- Grafo simples: Um grafo simples é um grafo onde qualquer aresta é adjacente a dois vértices diferentes. Em um grafo simples, não existem arestas paralelas ou laços.
- Grafo vazio: um (ou O) grafo vazio é um grafo $G$ tal que $V(G) = A(G) = \emptyset$
- Grafo trivial: Um (ou O) grafo trivial é um grafo com apenas um vértice e sem arestas.
- Grafo regular: é um grafo onde todos os vértices têm o mesmo grau. Seja $k$ o grau dos vértices de um tal grafo, então chamamos esse grafo de $k$-regular.
- Grafo completo: é um grafo (simples) onde quaisquer dois vértices diferentes são adjacentes. Um grafo completo com $n$ vértices tem $\binom{n}{2}$ arestas e é denotado por $K_{n}$.
- Grafo bipartido: um grafo $G = (V, A)$ é bipartido se existem $X, Y \subset V$, com $X \cup Y = V, X \cap Y = \emptyset$ tais que qualquer aresta $\{u, v\} \in V$ tem uma ponta em $X$ e outra em $Y$ (isto é, $u \in X$ e $v \in Y$, ou vice-versa).
  - Bipartido completo: um grafo bipartido é dito bipartido completo se quaisquer dois vértices $u, v$, com $u \in X$ e $v \in Y$ são adjacentes. Se $|X| = m$ e $|Y| = n$, tal grafo é denotado por $K_{m, n}$.
- Complemento de um grafo: o complemento de um grafo $G = (V, A)$ é um grafo $G^{\prime} = (V, A^{\prime})$ tal que $\{u, v\} \in A^{\prime} \iff u, v \in V \wedge \{u, v\} \notin A$.

## Isomorfismo de grafos

## Subgrafos

Um grafo $H$ é dito *subgrafo* de $G$ se $V(H) \subseteq V(G)$ e $A(H) \subseteq A(G)$. Quando isso acontece, escrevemos $H \subseteq G$.

### Subgrafo gerador

Um subgrafo $H \subseteq G$ é um *subgrafo gerador* de $G$ quando $V(H) = V(G)$.

### Subgrafo induzido

Se $G$ é um grafo e $\emptyset \neq X \subseteq V(G)$, então o *subgrafo induzido* (ou gerado) por $X$ é o subgrafo $H \subseteq G$ tal que $V(H) = X$, e $\{u, v\} \in A(H) \iff u,v \in X \wedge \{u,v\} \in A(G)$. Denotamos esse subgrafo por $G[X] = H$.
Se $\emptyset \neq F \subseteq A(G)$, então o grafo induzido por $F$, $G[F]$ é o grafo tal que $A(G[F]) = F$ e $u \in V(G[F]) \iff (\exists v \in V(G)) \{u,v\} \in F$
Denotamos por $G-X$ o subgrafo $G[V(G)\setminus X]$, e $G-F$ o subgrafo $G[A(G)\setminus F]$.
Denotamos por $G-a$ o subgrafo $G - \{a\}$, onde $a$ é um vértice ou aresta de $G$.

***Proposição:*** Se $G$ é um grafo simples com $6$ vértices, então $G$ ou $\overline{G}$ contém um triângulo.
Seja $u \in V(G)$ um vértice qualquer de $G$. Como $g_{G}(u) + g_{\overline{G}}(u) = 5$, então $g_{G}(u) \geq 3$ ou $g_{\overline{G}}(u) \geq 3$. Vamos supor, sem perda de generalidade, que $g_{G}(u) \geq 3$. Então sejam $\{v_{1}, v_{2}, v_{3}\} \in V(G)$ vértices adjacentes a $u$. Se quaisquer dois $v_{i}, v_{j}$ entre esses vértices forem adjacentes entre si, então $\{v_{i}v_{j}v_{u}v_{i}\}$ será um triângulo em $G$. Caso $\{v_{1}, v_{2}, v_{3}\}$ seja um conjunto independente em $G$, então será um triângulo em $\overline{G}$.

## Passeios, caminhos, trilhas e circuitos

Um ***passeio*** em um grafo $G$ é uma sequência finita e não-vazia $P = (v_{0}, a_{1}, v_{1}, a_{2}, \dots, a_{k}, v_{k})$, onde $v_{i} \in V(G)$, $a_{i} \in A(G)$, e $a_{i}$ é adjacente a $v_{i-1}$ e $v_{i}$. Dizemos que $P$ é um passeio ***de*** $v_{0}$ a $v_{k}$, e $P$ ***passa*** pelos vértices $v_{0}, \dots, v_{k}$ e pelas arestas $a_{1}, \dots, a_{k}$. Os vértices $v_{0}$ e $v_{k}$ são chamados de ***origem*** e ***término*** de $P$, e $v_{1}, \dots, v_{k-1}$ são chamados de ***vértices internos*** de $P$. O conjunto de vértices e o conjunto de arestas de $P$ são denotados por $V(P)$ e $A(P)$, respectivamente. O ***comprimento*** de $P$ é denotado por $||P||$ e é o número de arestas em $P$.
Note que se $G$ é um grafo simples, então podemos omitir as arestas na definição do passeio (uma vez que um par de vértices define univocamente uma aresta).

Uma ***trilha*** é um passeio sem *arestas* repetidas. Um ***caminho*** é um passeio sem *vértices* repetidos (note que todo caminho então é necessariamente uma trilha). Um passeio é ***fechado*** se seu começo e término coincidem. Uma trilha fechada cujos vértices internos e origem são todos distintos é um ***circuito***. Um circuito de comprimento $n$ é denotado por $C_{n}$. Dizemos que um circuito é ***par*** se o seu comprimento é par, e ***ímpar*** caso contrário.

Uma ***seção*** $Q$ de um passeio $P = (v_{0}, a_{1}, v_{2}, \dots, a_{n}, v_{n})$ é uma subsequência $Q = (v_{i}, a_{i+1}, v_{i+1}, \dots, a_{j}, v_{j})$ de $P$, com $0 \leq i < j \leq n$.
A ***concatenação*** de dois passeios $P = (v_{0}, \dots, v_{k})$ e $Q = (v_{k} = u_{0}, \dots, u_{n})$ é o passeio $(v_{0}, \dots, v_{k} = u_{0}, \dots, u_{n})$, que é denotado por $P \cdot Q$ (note que $P \subset P \cdot Q$ e $Q \subset P \cdot Q$).
**Proposição**: $||P\cdot Q|| = ||P|| + ||Q||$
O ***reverso*** de $P = (v_{0}, a_{1}, v_{1}, \dots, v_{k-1}, a_{k}, v_{k})$ é o passeio $(v_{k}, a_{k}, v_{k-1}, \dots, v_{1}, a_{1}, v_{0})$, e é denotado por $P^{-1}$.
**Convenção:** O termo passeio (respectivamente caminho, circuito, trilha) também será usado para denotar um grafo ou subgrafo cujos vértices e arestas formam um passeio (ou caminho, circuito, trilha). Quando é óbvio que estamos falando de um circuito, não precisamos repetir a origem e o destino (que coincidem). Assim, $C = (v_{0}, v_{1}, \dots, v_{k})$ denota um circuito com origem e destino $v_{0}$ e vértices internos $v_{1}, \dots, v_{k}$.

**Proposição:** Seja $G$ um grafo simples tal que $\delta (G) \geq 2$. Então $G$ contém um caminho de comprimento $\delta (G)$, e um circuito de comprimento ao menos $\delta (G) + 1$.
Seja $P = (v_{0}, \dots, v_{k})$ um caminho mais longo em $G$. Seja $\Gamma (v_{k}) = \{u_{1}, \dots, u_{n}\}$ os vizinhos de $v_{k}$, com $n \geq \delta (G)$. Se existir $u \in \Gamma (v_{k})$ tal que $u \not\in V(P)$, então existirá um caminho $P\cdot \{u\}$ em $G$, com comprimento igual a $||P|| + 1$, e portanto $P$ não será um caminho mais longo em $G$. Então, dado um caminho mais longo $P = (v_{0},\dots, v_{k})$ deve conter todos os vértices de $\Gamma (v_{k})$, portanto $||P|| \geq \delta (G)$.
Além disso, dado um caminho mais longo $P$ com destino $v_{k}$, como sabemos que todos os vértices de $\Gamma (v_{k})$ estão em $P$, seja $v_{i}$ o vizinho de $v_{k}$ que aparece primeiro em $P$. Então o valor máximo de $i$ será $||P|| - g(v_{k})$, então
$$
\begin{aligned}
i &\leq ||P|| - g(v_{k})\\
i &\leq k - \delta (G)
\end{aligned}
$$
Como $(v_{i}, \dots, v_{k})$ é um caminho (pois é uma seção de $P$, que é um caminho), e $v_{i}v_{k} \in A(G)$, então $C = (v_{i}, \dots, v_{k})$ é um ciclo.
É fácil ver que $||C|| = 1 + k - i$, portanto temos:
$$
\begin{aligned}
   ||C|| = 1 + k - i &\geq 1 + k - (k - \delta (G))\\
   ||C|| &\geq 1 + \delta (G)
\end{aligned}
$$

## Conexidade

Um grafo $G$ é dito ***conexo*** se para todo par de vértices distintos $u$ e $v$ de $G$ existe um caminho de $u$ a $v$ em $G$. Caso contrário o grafo é dito ***desconexo***
Os subgrafos conexos maximais de um grafo são chamados de ***componentes*** (ou ***componentes conexas***) do grafo.
Obs.: Um grafo $G$ é dito ***maximal*** (ou ***minimal***, respectivamente) em relação a alguma propriedade $\mathcal{P}$, se nenhum supergrafo (ou subgrafo, respectivamente) próprio de $G$ possuir essa propriedade.

***Proposição:*** Suponha que exista $G$ seja um grafo conexo com $n$ vértices e $n - 1$ arestas, $n \geq 3$. Então $G$ contém um circuito.
Seja $u \in G$ tal que $g(u) = \Delta (G)$.

## Distância, diâmetro, cintura e circunferência

A ***distância*** entre dois vértices $u, v$ quaisquer de $G$, denotada $d_{G}(u,v)$, ou simplesmente $d(u,v)$ é o comprimento de *um* caminho mais curto entre $u$ e $v$. Quando não existe nenhum caminho de $u$ a $v$, definimos $d(u,v) = \infty$.
A maior das distâncias entre dois vértices quaisquer de um grafo $G$ é chamada de ***diâmetro*** do grafo, e denotada por $\textbf{diam}(G)$. A ***cintura*** de um grafo é o comprimento de um menor circuito do grafo, e é denominada $\mathbf{cint}(G)$. A ***circunferência*** de um grafo é o comprimento de um maior circuito de um grafo. Quando um grafo não possui circuitos, definimos sua cintura como infinita, e sua circunferência como sendo zero.

***Proposição:*** Se $G$ é um grafo que contém pelo menos um ciclo, então $\mathbf{cint}(G) \leq 2 \mathbf{diam}(G) + 1$.

Caso $G$ não seja conexo, temos que $diam(G) = \infty$, e então o resultado é imediato. Caso $|V(G)| < 3$, é impossível que $G$ possua ciclos. Seja $G$ então um grafo conexo qualquer, com $|V(G)| \geq 3$.
Seja $C_{k} = (v_{0}, \dots, v_{k - 1})$ um menor circuito em $G$, então $\mathbf{cint}(G) = k$.
Temos que, para quaisquer $u, v \in  V(G)$, $d(u,v) \leq \mathbf{diam}(G)$.
Seja $w \in C_{k}$ tal que $C_{k} = (v_{0}, \dots, v_{\lfloor k/ 2\rfloor} = w, \dots, v_{k - 1})$, então $P = (v_{0}, \dots, v_{\lfloor k/ 2\rfloor} = w)$ é um caminho de $v_{0}$ a $w$ de comprimento $\left\lfloor \frac{k}{2} \right\rfloor$, e $Q = (w = v_{\lfloor k/ 2\rfloor}, \dots, v_{k - 1}, v_{0})^{-1}$ é um caminho de $v_{0}$ a $w$ de comprimento $\left\lceil \frac{k}{2} \right\rceil$. Suponha que exista outro caminho $T$ de $v_{0}$ a $w$, com $||T|| < \left\lceil \frac{k}{2} \right\rceil$. Então é fácil ver que $P \cdot T^{-1}$ será um ciclo de comprimento menor que $k$. Como $k = \mathbf{cint}(G)$, tal caminho não pode existir, e então $d(v_{0}, w) = \left\lfloor \frac{k}{2} \right\rfloor$.
Vamos supor que $k = \mathbf{cint}(G) > 2 \mathbf{diam}(G) + 1$. Portanto, temos que:
$$
\begin{aligned}
d(v_{0}, w) &> \left\lfloor \frac{2\mathbf{diam}(G) + 1}{2} \right\rfloor\\
d(v_{0}, w) &> \left\lfloor \mathbf{diam}(G) + \frac{1}{2} \right\rfloor\\
d(v_{0}, w) &> \mathbf{diam}(G)
\end{aligned}
$$
O que é um absurdo. Portanto temos que nossa suposição que $\mathbf{cint}(G) > 2 \mathbf{diam}(G) + 1$ só pode estar errada, e $\mathbf{cint}(G) \leq 2 \mathbf{diam}(G) + 1$.

**Proposição:** Sejam $C_{t}$, com $||C_{t}|| = t$ um circuito qualquer. Então $(\forall a,b \in V(C_{t})) (d(a,b) \leq \frac{t +1}{2})$.
**Prova:** Suponha que existam $a, b \in V(C_{t})$ tais que $d(a,b) > \frac{t}{2}$. Então existe um menor caminho $P = (a = v_{0}, \dots, v_{k} = b)$ de comprimento $k > \frac{t}{2}$ em $C_{t}$. Porém, como $C_{t}$ é um circuito, temos que existe um caminho $Q = (b = w_{0}, \dots, w_{r} = a)$ de comprimento $r$ em $C_{t}$, pois $C_{t}$ é alguma permutação da concatenação desses dois caminhos, e então temos que $t = r + k$. Porém, como $k > \frac{t}{2}$, temos:
$$
\begin{aligned}
k &> \frac{t}{2}\\
2k &> t\\
2k &> r + k\\
k &> r
\end{aligned}
$$
Então temos que $Q^{-1}$ é um caminho de $a$ a $b$ menor do que $P$, portanto $P$ não pode ser um menor caminho de $a$ a $b$. Então nossa suposição que existem $a, b \in V(C_{t})$ tais que $d(a,b) > \frac{t}{2}$ está errada, e quaisquer dois vértices em $C_{t}$ terão distância menor ou igual a $\frac{t}{2}$

***Proposição:*** Um grafo $G$ será bipartido se e somente se $G$ não tiver circuitos ímpares.
Primeiramente, seja $G$ um grafo qualquer que tenha um circuito ímpar, digamos, $C_{k} = (v_{0}, \dots, v_{k-1})$. Vamos supor que exista uma partição $(X, Y)$ de $G$, tal que toda aresta de $G$ tem uma ponta em $X$ e outra em $Y$. Assim, seja $v_{i}$ um vértice qualquer de $C_{k}$, com $0 \leq i < k - 1$. Assim, $v_{i} \in X \iff v_{i + 1} \in Y$. Então, todo $v_{i}$ em $C_{k} = (v_{0}, \dots, v_{k-1})$ tal que $i$ é par deve estar no mesmo conjunto da partição, e o mesmo para todo $v_{j}$ tal que $j$ é ímpar. Como $k - 1$ é par, então $v_{0}$ e $v_{k-1}$ devem estar na mesma partição. Porém, como $C_{k}$ é um circuito, temos que $v_{k-1}v_{0} \in A(C_{k}) \subseteq A(G)$, então $G$ não pode ser bipartido.

Seja $G$ um grafo que não tenha circuitos ímpares. Queremos provar então que $G$ é bipartido.

Sejam então $G_{1}, \dots, G_{n}$ as componentes conexas de $G$, com $V(G_{i}) = \{u_{i1}, \dots, u_{ik}\}$.
Seja então $u_{i1}$ um vértice qualquer de $G_{i}$. Como $G_{i}$ é conexo, então existe pelo menos um menor caminho de $u_{i1}$ a $u_{ij}$ (com $1 < j \leq k$) em $G$, que chamaremos de $P_{u_{i1}u_{ij}}$.
Sejam então $X, Y$, com $X \cup Y = V(G)$, $X \cap Y = \emptyset$, tais que:
$u_{ij} \in X \iff j = 1 \vee ||P_{u_{i1}u_{ij}}|| \text{ é par}$
$u_{ik} \in Y \iff ||P_{u_{i1}u_{ik}}|| \text{ é ímpar}$
É claro que, para $i \neq j$, $u_{ix}, u_{jy}$ não serão adjacentes, pois $u_{ix} \in G_{i}$, e $u_{jy} \in G_{j}$. Sejam $u_{ix}, u_{iy} \in X$, com $x \neq y$, tais que $0 < ||P_{u_{i1}u_{ix}}|| \leq ||P_{u_{i1}u_{iy}}||$. Suponha que $u_{ix}, u_{iy}$ sejam adjacentes. Então temos que $0 < ||P_{u_{i1}u_{ix}}|| \leq ||P_{u_{i1}u_{iy}}|| \leq ||P_{u_{i1}u_{ix}}|| + 1$, que implica em $0 \leq ||P_{u_{i1}u_{iy}}|| - ||P_{u_{i1}u_{ix}}|| \leq 1$.
Porém, como $||P_{u_{i1}u_{ix}}||$ e $||P_{u_{i1}u_{iy}}||$ são ambos pares, então $||P_{u_{i1}u_{iy}}|| - ||P_{u_{i1}u_{ix}}||$ também deve ser par, e assim temos que $||P_{u_{i1}u_{iy}}|| = ||P_{u_{i1}u_{ix}}||$
Sejam então $P_{u_{i1}u_{ix}} = (u_{i1} = v_{0}, \dots, v_{t} = u_{ix})$ e $P_{u_{i1}u_{iy}} = (u_{i1} = w_{0}, \dots, w_{t} = u_{iy})$ dois menores caminhos quaisquer de $u_{i1}$ a $u_{ix}$ e a $u_{i1}$ a $u_{iy}$, respectivamente. Seja $e$ o vértice que, dentre os vértices de $P_{u_{i1}u_{ix}}$, seja o último que apareça também em $P_{u_{i1}u_{iy}}$. É óbvio que $e$ não aparecerá mais de uma vez em um mesmo caminho.
Então, temos que:
$$
P_{u_{i1}u_{ix}} = (u_{i1} = v_{0}, \dots, v_{a} = e, \dots, v_{t} = u_{ix})\\
P_{u_{i1}u_{iy}} = (u_{i1} = w_{0}, \dots, w_{b} = e, \dots, w_{t} = u_{iy})
$$
Assim, temos que $P_{1} = (u_{i1}, \dots, v_{a} = e = w_{b}, \dots, u_{i1})$ é um ciclo de comprimento $a + b$, e $P_{2} = (e = v_{t}, \dots, v_{t} = u_{ix}, u_{iy} = w_{t}, \dots, w_{b} = e)$ é um ciclo de comprimento $t - a + t - b = 2t - (a + b) + 1$. Assim, $P_{1} \text{ é par } \iff P_{2} \text{ é ímpar}$. Então teremos ciclos ímpares em $G$, o que é um absurdo. Então nossa suposição de que existe $u, v \in X$ tais que $u,v$ são adjacentes está errada, e $G$ é bipartido.
