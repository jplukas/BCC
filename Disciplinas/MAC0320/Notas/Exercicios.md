# Exercícios

## Conceitos iniciais e resultados basicos

1. Prove que se $G$ é um grafo sem vértices isolados e $|A(G)| < |V(G)|$, então $G$ tem ao menos $2$ vértices de grau $1$.

   Vamos supor que não seja o caso, e que exista um grafo $G$ segundo a hipótese, e que tenha ao máximo $1$ vértice de grau $1$. Para o caso em que $G$ não tenha nenhum vértice de grau $1$, temos que:
   $$
   (\forall v)(v \in V(G) \implies g(v) \geq 2)
   $$
   Como $\sum_{v \in V(G)}^{}g(v) = 2|A(G)|$, resulta em
   $$
   \sum_{v \in V(G)}^{}g(v) = 2|A(G)| \geq 2|V(G)|
   $$
   O que resulta em
   $$
   |V(G)| \leq |A(G)|
   $$
   O que é uma contradição.
   Agora, para o caso que haja apenas $1$ vértice de grau $1$ no grafo, temos que
   $$
   \sum_{v \in V(G)}^{}g(v) = 2|A(G)| \geq 2|V(G)| + 1
   $$
   O que resulta em
   $$
   |V(G)| + \frac{1}{2} \leq |A(G)|
   $$
   O que também é impossível, pois para essa afirmação não contradizer a hipótese que  $|A(G)| < |V(G)|$, temos que $0 < |V(G)| - |A(G)| < \frac{1}{2}$, mas $|V(G)|, |A(G)| \in \mathbb{N}$.

2. Seja $G$ um grafo de ordem $n \geq 2$. Prove que se $G$ tem pelo menos $n+1$ arestas, então $G$ possui um vértice com grau pelo menos $3$.

   Vamos novamente supor que não seja o caso. Então $G$ é um grafo de ordem $n \geq 2$, $|A(G)| = m \geq n+1$, e $\Delta(G) \leq 2$. Disso resulta:
   $$
   \sum_{v \in V(G)}^{}g(v) = 2m \leq 2n
   $$
   E então temos que $m \leq n$, o que contradiz a nossa suposição.

3. Prove que todo grafo simples de ordem $n \geq 2$ tem pelo menos dois vértices com o mesmo grau.

   Vamos supor que exista um grafo $G$ de ordem $n \geq 2$ tal que todos os seus vértices tenham graus diferentes. Um grau de um vértice qualquer de $G$ tem que estar em $\{0, \dots, n-1\}$. Como $|\{0, \dots, n-1\}| = n$, então temos que ter, ao mesmo tempo, um vértice de grau $0$ e um vértice de grau $n-1$ no grafo, o que é impossível.

4. Liste todos os grafos simples não-isomorfos de ordem 4. Para cada um dos grafos, diga de que tipo ele é: se é completo, bipartido, bipartido completo, regular.
5. Desenhe todos os grafos simples $(V, A)$ com conjunto de vértices $V = \{u, v, w\}$. Exiba a lista desenhando lado a lado os grafos que são complementares.
6. Quantas arestas tem o grafo completo $K_n$? Quantas arestas tem o grafo bipartido completo $K_{m,n}$?

   O grafo completo $K_{n}$ tem $\binom{n}{2}$ arestas.
   O grafo $K_{n,m}$ tem $mn$ arestas.
7.
   1. Prove que um grafo simples de ordem $n$ com mais do que $n^2/4$ arestas não é bipartido.

      Seja $(X, Y)$ a partição de um grafo bipartido $G$, com $|X| = x$ e $|Y| = y$. É fácil ver que a quantidade máxima de arestas que tal grafo pode ter será $xy$, e nesse caso, o grafo será bipartido completo. Sendo $n = |V(G)|$ a ordem do grafo, podemos dizer que $y = n - x$, e então o número de arestas será $|A(G)| = x(n-x) = xn-x^2$. Podemos facilmente calcular o máximo deste valor em função de $x$, tomando $\frac{d}{dx} xn - x^2 = 0$, que resulta $n=2x$, e então o número máximo possível de arestas em um grafo bipartido será $(\frac{n}{2})^2 = \frac{n^2}{4}$.
   2. Encontre todos (diga como são) os grafos bipartidos de ordem $n$ com $\lfloor n^2/4 \rfloor$ arestas.

      Como vimos no exemplo anterior, serão grafos bipartidos completos com partições de tamanho $\left\lfloor n/2 \right\rfloor$ e $\left\lceil n/2 \right\rceil$, isto é, $K_{\left\lfloor n/2 \right\rfloor, \left\lceil n/2 \right\rceil}$.
8. Existe um grafo bipartido $G$ com $\delta (G) + \Delta (G) > |V (G)|$? Justifique sua resposta.

   Seja $|X| = x$ o tamanho do maior conjunto da bipartição de $G$, e $n = |V(G)|$ a ordem de $G$. É fácil ver que o maior valor possível para $\Delta(G)$ é $x$, enquanto o maior valor possível para $\delta (G)$ será $n-x$. Assim, temos que $\delta (G) + \Delta (G) \leq x + n-x = n$. Portanto não é possível.
9. Um grafo simples é auto-complementar se é isomorfo ao seu complemento. Mostre que se $G$ é um grafo simples auto-complementar então $|V (G)| \equiv 0 \pmod{4}$ ou $|V (G)| \equiv 1 \pmod{4}$.

   Seja $n = |V(G)|$ e $m = |A(G)|$. Temos que $m = \frac{\binom{n}{2}}{2} = \frac{n(n-1)}{4}$. Como $m$ é um número inteiro, segue que $n \equiv 0 \pmod{4}$ ou $n-1 \equiv 0 \pmod{4}$, o que resulta em $n \equiv 1 \pmod{4}$.
10. Seja $X \coloneqq {1, 2, 3, 4, 5}$. Considere o grafo $G = (V, A)$, onde $V = \{\{y, w\} : y, w \in X, y \neq w\}$ e $A := \{\{u, v\} : u,v \in V, u \cap v = \emptyset \}$. Desenhe o grafo $G$ definido. Esse grafo é chamado de grafo de Petersen. Esse grafo é regular? Quantas arestas tem?

    Primeiro, vamos considerar o número de vértices que esse grafo tem. É fácil ver que os vértices de $G$ são combinações de 2 elementos de $[5]$, então $n = |V(G)| = C^{5}_{2} = 10$.
    Quanto ao número de arestas, considere um vértice fixo $\{a,b\} \in V(G)$. Os vértices $\{x,y\}$ que serão adjacentes a esse vértice precisam ser tais que $a \neq x$ e $b \neq y$. Assim, cada vértice será adjacente a $C^{5-2}_{2} = 3$. Então temos que a soma dos graus dos vértices será $\sum_{v\in V}^{} g(v) = 10 \cdot 3 = 30$. Como sabemos que $\sum_{v \in V}^{}g(v) = 2|A(G)|$, então temos que $|A(G)| = 15$.
    Esse grafo é $3$-regular.  

11. Seja $G_{n}$ um grafo com conjunto de vértices $\{v_{1}, v_{2}, \dots v_{n}\}$ e tal que $v_{i}$ e $v_{j}$ são adjacentes se e só se $i$ e $j$ são primos entre si. Prove que se $m < n$ então $G_{m}$ é um subgrafo induzido de $G_{n}$.

    É fácil ver que $V(G_{m}) \subset V(G_{n})$. Sejam $v_{i}, v_{j} \in V(G_{m})$. Então temos que:
    $$
    \begin{aligned}
    v_{i}v_{j} \in A(G_{m}) &\iff \gcd(i, j) = 1\\
    \gcd(i, j) = 1 &\iff v_{i}v_{j} \in A(G_{n})\\
    v_{i}v_{j} \in A(G_{m}) &\iff v_{i}v_{j} \in A(G_{n})
    \end{aligned}
    $$
    Portanto $G_{m}$ é um subgrafo induzido por $G_{n}$.

12. É verdade que $\delta (H) \leq \delta (G)$ se $H$ é:
    1. Um subgrafo de $G$?

       Não. Seja, por exemplo, $G = (\{a, b, c\}, \{ab\})$ e $H = (\{a, b\}, \{ab\})$. Temos que $H \subset G$, $\delta (G) = 0$ e $\delta (H) = 1$.

    2. Um subgrafo gerador de $G$?
       Seja $H$ um subgrafo gerador de $G$, então $V(H) = V(G)$ (vamos nos referir a $V(H)$ e $V(G)$ daqui pra frente apenas como $V$, já que esses conjuntos são iguais) e $A(H) \subseteq A(G)$. Então temos que
       $$
       \begin{aligned}
       (\forall a \in A(H)) (a \in A(G))
       \end{aligned}
       $$
       Suponha que exista $w \in V$ tal que
       $$
       g_{H}(w) > g_{G}(w)
       $$
       Então temos que existe ao menos uma aresta $e$ adjacente a $w$ tal que $e \in H$, e $e \not\in G$, o que é um absurdo. Portanto, temos que:
       $$
       (\forall u \in V) (\delta (H) \leq g_{H}(u) \leq g_{G}(u))\\
       $$
       Então $\delta (H) \leq \delta (G)$.

13. É verdade que o conjunto dos vértices de qualquer grafo $G$ pode ser particionado em duas partes $X$ e $Y$ de modo que $G[X]$ e $G[Y]$ sejam ambos grafos regulares?

    Não. Considere o grafo cujas componentes conexas são $K_{1}, K_{2}, K_{4}$. Sejam $\{a\} = V(K_{1}), \{b, c\} = V(K_{2})$ e $\{d,e,f,g\} = V(K_{4})$. Vamos supor, sem perda de generalidade que $a \in X$. Então temos que $G[X]$ tem que ser $1$-regular. É fácil ver que não podemos ter em $X$ dois vértices de $K_{2}$ ou $K_{4}$ (pois teríamos em $G[X]$ vértices de grau $2$), então $Y$ deve ter vértices de grau $3$ ou $4$, que pertençam a $K_{4}$, e mais um vértice de $K_2$

    1. E se $G$ for conexo??

14. Prove que para todo grafo $G$ existe um grafo auto-complementar que tem um subgrafo induzido isomorfo a $G$.

    Vamos construir tal grafo $H$ a partir de $G$. Sejam $u, v \in V(G)$ quaisquer dois vértices de $G$. Sejam $u_{1}, u_{2}, u_{3}, u_{4}, v_{1}, v_{2}, v_{3}, v_{4},\in V(H)$ tais que:
    $$
    \begin{aligned}
    u_{1}v_{1} \in A(H) &\iff uv \in A(G)\\
    u_{2}v_{2} \in A(H) &\iff uv \not \in A(G)\\
    u_{3}v_{3} \in A(H) &\iff uv \not \in A(G)\\
    u_{4}v_{4} \in A(H) &\iff uv \in A(G)
    \end{aligned}
    $$
    $$
    \left.
    \begin{array}{ll}
    u_{1}u_{2}, u_{1} v_{2}, v_{1} u_{2}, v_{1}v_{2}\\
    u_{2}u_{3}, u_{2} v_{3}, v_{2} u_{3}, v_{2}v_{3}\\
    u_{3}u_{4}, u_{3} v_{4}, v_{3} u_{4}, v_{3}v_{4}
    \end{array}
    \right\}
    \in A(H)
    $$
    Seja também uma bijeção $\varphi : V(H) \mapsto V(H)$, tal que:
    $$
    \begin{array}{ll}
       \varphi (u_{1}) = u_{2}\\
       \varphi (u_{2}) = u_{4}\\
       \varphi (u_{3}) = u_{1}\\
       \varphi (u_{4}) = u_{3}\\
       \varphi (v_{1}) = v_{2}\\
       \varphi (v_{2}) = v_{4}\\
       \varphi (v_{3}) = v_{1}\\
       \varphi (v_{4}) = v_{3}\\
    \end{array}
    $$
    Então, temos que:
    $$
    \begin{aligned}
    u_{1}v_{1} \in A(\overline{H}) &\iff uv \not\in A(G)\\
    u_{2}v_{2} \in A(\overline{H}) &\iff uv \in A(G)\\
    u_{3}v_{3} \in A(\overline{H}) &\iff uv \in A(G)\\
    u_{4}v_{4} \in A(\overline{H}) &\iff uv \not\in A(G)
    \end{aligned}
    $$
    $$
    \left.
    \begin{array}{ll}
    u_{2}u_{4}, u_{2} v_{4}, v_{2} u_{4}, v_{2}v_{4}\\
    u_{4}u_{1}, u_{4} v_{1}, v_{4} u_{1}, v_{4}v_{1}\\
    u_{1}u_{3}, u_{1} v_{3}, v_{1} u_{3}, v_{1}v_{3}
    \end{array}
    \right\}
    \in A(\overline{H})
    $$
    Em termos de $\varphi (x)$, temos:
    $$
    \begin{aligned}
    \varphi(u_{2})\varphi(v_{2}) \in A(\overline{H}) &\iff uv \not\in A(G)\\
    \varphi(u_{4})\varphi(v_{4}) \in A(\overline{H}) &\iff uv \in A(G)\\
    \varphi(u_{1})\varphi(v_{1}) \in A(\overline{H}) &\iff uv \in A(G)\\
    \varphi(u_{3})\varphi(v_{3}) \in A(\overline{H}) &\iff uv \not\in A(G)
    \end{aligned}
    $$
    e
    $$
    \left.
    \begin{array}{ll}
    \varphi(u_{4})\varphi(u_{3}),\varphi(u_{4})\varphi(v_{3}),\varphi(v_{4})\varphi(u_{3}),\varphi(v_{4})\varphi(v_{3})\\
    \varphi(u_{3})\varphi(u_{2}),\varphi(u_{3})\varphi(v_{2}),\varphi(v_{3})\varphi(u_{2}),\varphi(v_{3})\varphi(v_{2})\\
    \varphi(u_{2})\varphi(u_{1}),\varphi(u_{2})\varphi(v_{1}),\varphi(v_{2})\varphi(u_{1}),\varphi(v_{2})\varphi(v_{1})
    \end{array}
    \right\}
    \in A(\overline{H})
    $$
    Reorganizando os termos:
    $$
    \begin{aligned}
    \varphi(u_{1})\varphi(v_{1}) \in A(\overline{H}) &\iff uv \in A(G)\\
    \varphi(u_{2})\varphi(v_{2}) \in A(\overline{H}) &\iff uv \not\in A(G)\\
    \varphi(u_{3})\varphi(v_{3}) \in A(\overline{H}) &\iff uv \not\in A(G)\\
    \varphi(u_{4})\varphi(v_{4}) \in A(\overline{H}) &\iff uv \in A(G)
    \end{aligned}
    $$
    e
    $$
    \left.
    \begin{array}{ll}
    \varphi(u_{1})\varphi(u_{2}),\varphi(v_{1})\varphi(u_{2}),\varphi(u_{1})\varphi(v_{2}),\varphi(v_{1})\varphi(v_{2})\\
    \varphi(u_{2})\varphi(u_{3}),\varphi(u_{2})\varphi(v_{3}),\varphi(v_{2})\varphi(u_{3}),\varphi(v_{2})\varphi(v_{3})\\
    \varphi(u_{3})\varphi(u_{4}),\varphi(u_{3})\varphi(v_{4}),\varphi(v_{3})\varphi(u_{4}),\varphi(v_{3})\varphi(v_{4})
    \end{array}
    \right\}
    \in A(\overline{H})
    $$
    Ou seja, para quaisquer dois vértices $p, q \in V(H)$, temos que $pq \in A(H) \iff \varphi(p)\varphi(q)\in A(\overline{H})$. Então $H$ é auto-complementar.

15. Seja $G$ um grafo, e $u, v$ vértices distintos de $G$. Prove que se $G$ contém um _passeio_ $P$ de $u$ a $v$, então $G$ contém um _caminho_ $Q$ de $u$ a $v$ tal que $V(Q) \subseteq V(P)$.

    Se $P$ não tiver vértices repetidos, então $Q = P$ é um caminho que satisfaz as condições. Suponha então que $P = (u = v_{0}, a_{1}, v_{1}, \dots, a_{k}, v_{k} = v)$ tenha $t$ vértices distintos que ocorrem mais de uma vez na sequência, e sejam $\{w_{1}, w_{2}, \dots, w_{t}\} = R$ (com $w_{i} = w_{j} \iff i = j$) esses tais vértices, onde $i$ denota o primeiro aparecimento do vértice $w_{i}$ em $P$. Portanto, $w_{1}$ é o primeiro vértice de $P$ que é repetido. Sejam então $g, h$, com $0 \leq g < h \leq k$ tais que $v_{g} \in P$ é o primeiro vértice de $P$ tal que $w_{1} = v_{g}$, e $v_{h} \in P$ é o último vértice de $P$ tal que $w_{1} = v_{h}$. Assim, podemos dizer que $P = A \cdot B \cdot C$, onde:
    $$
    \begin{cases}
      A = (v_{0}, &\dots, v_{g} = w_{1})\\
      B = (w_{1} = v_{g}, &\dots, v_{h} = w_{1})\\
      C = (w_{1} = v_{h}, &\dots, v_{k})
    \end{cases}
    $$
    Assim, temos que $P^{\prime} = A \cdot C = (v_{0}, \dots, v_{g} = w_{1} = v_{h}, \dots, v_{k})$ é um passeio de $u$ a $v$ em $G$, $V(P^{\prime}) \subset V(P)$, e $w_{1}$ só aparece uma vez em $P^{\prime}$. Seja $R^{\prime}$ o conjunto dos vértices repetidos em $P^{\prime}$. Então é fácil ver que $R^{\prime}\subsetneq R$ (pois não introduzimos nenhum vértice na sequência, e $w_{1} \not\in R^{\prime}$).
    Se $R^{\prime} = \emptyset$, então $P^{\prime}$ é um passeio de $u$ a $v$ sem vértices repetidos, o que significa que $P^{\prime}$ é um caminho de $u$ a $v$.
    Se $R^{\prime} \neq \emptyset$, então passamos a chamar $P^{\prime}$ de $P$, $R^{\prime}$ de $R$, e repetimos o processo, até que $R^{\prime} = \emptyset$. No máximo, repetiremos $t$ vezes esse processo em $P$, e então não teremos mais vértices repetidos em $P$, e $P = Q$ ainda será um passeio de $u$ a $v$.
16. Seja $G$ um grafo, e sejam $u, v, x \in V(G)$ três vértices distintos de $G$. Prove que se existe um caminho de $u$ a $v$, e um caminho de $v$ a $x$ em $G$, então existe um caminho de $u$ a $x$ em $G$.

    Seja $P$ um caminho de $u$ a $v$, e $Q$ um caminho de $v$ a $x$. Então $P \cdot Q$ é um passeio em $G$ de $u$ a $x$. Então, pelo item anterior, existe ao menos um caminho $T$ em $G$ de $u$ a $x$, com $V(T) \subseteq V(P\cdot Q)$.
17. Prove ou disprove as seguintes afirmações:
    1. Todo passeio fechado ímpar contém uma seção que é um circuito par.

       Falso. Um circuito $C$ ímpar é um passeio fechado ímpar, e somente existirá uma seção que de $C$ que será um circuito, que será o próprio $C$, que é ímpar.
    2. Todo passeio fechado par contém uma seção que é um circuito par.

       Vamos adaptar a notação de concatenação para acomodar circuitos. Sejam $C = (u_{0}, u_{1}, \dots, u_{k})$ e $D = (v_{0}, v_{1}, \dots, v_{k})$ dois circuitos distintos, com $u_{0} = v_{0}$. Então:
       $$
       C \cdot D \coloneqq (u_{0}, u_{1}, \dots, u_{k}, u_{0} =
       v_{0}, v_{1}, \dots, v_{k} = u_{0})
       $$
       e
       $$
       D \cdot C \coloneqq (v_{0}, v_{1}, \dots, v_{k}, v_{0} =
       u_{0}, u_{1}, \dots, u_{k} = v_{0})
       $$
       Assim, sejam $C$ e $D$ dois circuitos tais que $V(C) \cap V(D) = \{w\}$, e $||C|| = ||D|| = k$, com $k$ ímpar. Temos então que $C \cdot D$ é um passeio fechado, e $||C \cdot D|| = 2k$, ou seja, é par. Somente existem duas seções em $C \cdot D$ que serão circuitos, notadamente $C$ e $D$, e ambos são pares.
    3. Todo passeio fechado ímpar contém uma seção que é um circuito ímpar.

       Seja $P = (v_{0}, v_{1}, v_{2}, v_{3}, v_{4}, v_{5}, v_{2}, v_{0})$ um passeio fechado ímpar. O único circuito que é seção de $P$ é $C = (v_{2}, v_{3}, v_{4}, v_{5})$, que é par.

18. Prove que todo grafo conexo com $n \geq 1$ vértices possui pelo menos $n - 1$ arestas.

    Definição: um grafo $G$ é chamado _**árvore**_ quando $G$ é um grafo conexo sem circuitos.
    Como $G$ é conexo, então $\delta (G) \geq 1$.
    Como $G$ não tem circuitos, então temos que $\delta (G) < 2$, como vimos anteriormente. Assim, $\delta (G) = 1$.
    Seja $G$ uma árvore com $n$ vértices. Vamos provar por indução que $G$ tem $n - 1$ arestas.
    É óbvio que para $n = 1$, o grafo atende todos os requisitos.
    Suponha então que isso valha para qualquer árvore com $k < n$ vértices, em especial, $k = n - 1$, ou seja, suponha que qualquer árvore com $n - 1$ vértices tem $n - 2$ arestas.
    Assim, seja $G$ uma árvore com $n \geq 2$ vértices, e $u \in V(G)$ tal que $g(u) = 1$. Então temos que $T = G - u$ será uma árvore com $n-1$ vértices, e portanto, terá $n - 2$ arestas. Como $G = (V(T) \cup \{u\}, A(T) \cup \{v, u\})$, para algum $v \in V(T)$ (e obviamente, $\{v, u\} \not\in A(T)$), então $G$ tem $n - 2 + 1 = n - 1$ arestas.
    Seja agora $X$ um grafo conexo qualquer com $n$ vértices. Então existe um subgrafo $T \subseteq X$, com $V(T) = V(X)$ que é uma árvore com $n$ vértices. Então $T$ tem $n - 1$ arestas, e $|A(G)| \geq n - 1$.

19. Prove que se $G$ é um grafo simples com $|V(G)| \leq 2n$, e $\delta (G) \geq n$, então $G$ é conexo.

    Seja $X$ um grafo com $k$ vértices tal que $X$ não é conexo. Sejam $X_{1}, \dots, X_{t}$ as componentes conexas de $X$, e sejam $\{x_{i1}, \dots, x_{it}\} = V(X_{i})$ os vértices dessas componentes. Como $a \neq c \implies x_{ab}x_{cd} \not\in A(X)$, então $a \neq c \implies x_{ab}x_{cd} \in A(\overline{X})$. Então, com $i \neq j$, qualquer $x_{ia}x_{jb} \in A(\overline{X})$, e então $\overline{X}$ será conexo. Assim, se um grafo qualquer não é conexo, o seu complemento certamente será.
    Assim, seja $Q$ um grafo com $x$ vértices e $|A(Q)| > \frac{x^{2} -3x + 2}{2}$. Então temos que:
    $$
    \begin{aligned}
    |A(\overline{Q})| &< \frac{x^{2}-x}{2} - \frac{x^{2}-3x + 2}{2}\\
    |A(\overline{Q})| &< \frac{2x - 2}{2}\\
    |A(\overline{Q})| &< x - 1
    \end{aligned}
    $$
    Então, como vimos anteriormente, $\overline{Q}$ não é conexo, e então $Q$ é conexo.
    Voltando ao grafo $G$, temos que $|V(G)| = k$, e $\delta (G) \geq \frac{k}{2}$.
    Seja $t$ o número de componentes conexas de $G$. Seja $X$ uma dessas tais componentes. É fácil ver que o tamanho $x$ dessa componente deve ser $x \geq \frac{k}{2} + 1$, pois cada vértice de $x$ tem grau maior ou igual a $\frac{k}{2}$. Assim, temos que o número $k$ de vértices em $G$, para que $G$ tenha $t$ componentes conexas com $\delta (G) \geq \frac{k}{2}$ deve ser $k \geq t(\frac{k}{2} + 1)$. Agora suponha que $t \geq 2$. Então temos $k \geq k + 2$, o que é um absurdo. Portanto, $t = 1$, e $G$ é conexo.

20. Prove que quaisquer dois caminhos mais longos em um grafo conexo possuem um vértice em comum.

    Sejam $P_{1} = (u_{0}, \dots, u_{k})$ e $P_{2} = (v_{0}, \dots, v_{k})$ dois caminhos mais longos em $G$. Suponha $V(P_{1}) \cap V(P_{2}) = \emptyset$ (isto é, não exitem vértices em comum entre $P_{1}$ e $P_{2}$).
    Como $G$ é conexo, então há pelo menos um caminho $Q = (u_{k} = w_{0}, \dots, w_{t} = v_{0})$, com $t \leq k$. Se não houver vértices de $P_{1}$ ou $P_{2}$ nos vértices internos de $Q$, então $P_{1} \cdot Q \cdot P_{2}$ será um caminho em $G$ maior do que $P_{1}$ e $P_{2}$. Então entre os vértices internos de $Q$ deve haver ao menos um vértice de $P_{1}$ ou $P_{2}$.
    É óbvio que não pode haver um vértice interno de $Q$ que seja comum a $P_{1}$ e $P_{2}$ simultaneamente, pois esses dois caminhos são disjuntos. Portanto, vamos afirmar, sem perda de generalidade, que não há vértices em comum entre os vértices internos de $Q$ e $P_{1}$. Portanto, $P_{1} \cdot Q$ é um caminho em $G$ maior do que $P_{1}$ e $P_{2}$.
    Então nossa suposição de que $P_{1}$ e $P_{2}$ não possuem vértices em comum só pode estar errada.

## Grafos Eulerianos

1. Prove que um grafo conexo $G$ é euleriano se e só se o conjunto de suas arestas pode ser particionado em circuitos.

   Euleriano -> circuitos
   Seja $G_{i}$ um grafo tal que todos os seus vértices têm grau par. Seja $u \in V(G_{i})$ um vértice desse grafo, e $U$ a componente conexa que contém $u$. Então temos que $g_{G_{i}[U]}(u) = g_{G_{i}}(u)$. Portanto $G_{i}[U]$ é um grafo euleriano.
   Suponha que haja arestas em $G_{i}$. Então haverá ao menos uma componente conexa em $G_{i}$ tal que todos os seus vértices têm grau maior ou igual a 2, e portanto haverá circuitos em $G_{i}$. Defina $S_{i}$ um maior ciclo em $S_{i}$, e $G_{i+1} = G_{i} - A(S_{i})$.
   Seja $w \in V(S_{i})$. Note que $g_{G_{i+1}}(w) = g_{G_{i}}(w) - 2$. Portanto todos os vértices de $G_{i+1}$ também terão grau par.
   Fazendo $G_{0} = G$, a sequência $G_{0}, G_{1}, \dots, G_{k}$ eventualmente irá gerar um $G_{k}$ em que $A(G_{k}) = \emptyset$, e $S_{0}, S_{1}, \dots, S_{k-1}$ serão circuitos em $G$, dois a dois disjuntos.
   Note que: $\bigcup_{i=0}^{k-1}S \subset A(G)$, e $\emptyset = A(G_{k}) = A(G) \setminus \bigcup_{i=0}^{k-1}S$, e portanto $A(G) = \bigcup_{i=0}^{k-1}S$.

   Circuitos -> Euleriano
   Seja $G$ um grafo conexo tal que $A(G)$ pode ser particionado em circuitos.
   Sejam $S_{1}, \dots, S_{k}$ circuitos em $G$ tais que, para $1 \leq i < j \leq k$, $A(S_{i}) \cap A(S_{j}) = \emptyset$, e $\bigcup_{i=1}^{k}A(S_{i}) = A(G)$. Temos então que $\bigcup_{i=1}^{k}V(S_{i}) = V(G)$.
   Suponha que a nossa partição $S_{1}, \dots, S_{k}$ possa ser tal que $\bigcap_{i=1}^{k}V(S_{i}) = \emptyset$. Então existe $S_{k}$ tal que $V(S_{k}) \cap V(S_{i}) = \emptyset$, para todo $i \neq k$. Seja $v_{k}$ um vértice qualquer de $S_{k}$, e $u$ um vértice qualquer de $G$, que não esteja em $S_{k}$. Como $G$ é conexo, então precisa haver um caminho de $v_{k}$ a $u$, portanto deve haver uma aresta $v_{t}w$ em $S_{k}$, onde $v_{t} \in S_{k}$, e $w \in S_{l}$, para algum $l \neq k$. O que contradiz nossa hipótese que $\bigcap_{i=1}^{k}V(S_{i}) = \emptyset$. Podemos então dizer, sem perda de generalidade, que $S_{1}, \dots, S_{n}$ todos começam e terminam em um mesmo vértice $v_{i}$. Portanto, $S_{1} \cdot S_{2} \cdot \ldots \cdot S_{n}$ será uma trilha fechada euleriana em $G$.
   Seja um $x$ qualquer em $V(G)$. Note que, em todo circuito de alguma partição das arestas de $G$ em que $x$ estiver, estarão presentes exatamente duas arestas adjacentes a $x$. Então $x$ estará presente em $g(x)/2$ circuitos diferentes.
   Agora, seja $y \in V(G)$ tal que $g(y) = \Delta(G)$. Então $y$ estará presente em $\Delta(G)/2$ circuitos diferentes. Como precisa haver algum vértice de $G$ que esteja em todos os circuitos da partição, então temos que o número de circuitos em qualquer partição das arestas de $A(G)$ será igual a $\Delta(G)$.
   Note também que, se $v$ é um vértice que está em todos os circuitos de uma tal partição de $A(G)$, então $\Delta(G) = g(v)$.

2. Existe um grafo conexo euleriano simples que tem um número par de vértices e um número ímpar de arestas?

   Seja $T = (v_{1}, v_{2}, v_{3}, v_{4}, v_{5}, v_{2}, v_{6}, v_{1})$.

3. Se $G$ é um grafo euleriano com arestas $\alpha, \beta$ que têm exatamente um vértice em comum, então existe em $G$ uma trilha euleriana na qual $\alpha$ e $\beta$ aparecem consecutivamente?

   Seja $\alpha = \{u, v\}$, e $\beta = \{v, w\}$, com $u \neq w$, pois $\alpha$ e $\beta$ têm somente um vértice em comum.
   Se $G$ é um grafo euleriano, então podemos particionar as arestas de $G$ em ciclos. Seja $S_{1}, \dots, S_{n}$ uma tal partição, e $\mathcal{V}$ um ciclo qualquer dessa partição tal que $v \in V(\mathcal{V})$ (note que $\mathcal{V} = S_{t}$, para algum $1 \leq t \leq k$). Como $g(v)/2 = 1$, portanto $\mathcal{V}$ será o único circuito dessa partição em que $v$ estará. Portanto ambos $u$ e $w$ devem estar em $V(\mathcal{V})$ também.
   Seja $X = \{x \in V(G) : x \in \bigcap_{i=1}^{n}V(S_{i})\}$. Então temos que todo circuito $S_{i}$ pode ser escrito como um circuito que começa e termina em algum $x \in X$.
   Caso $v \in X$, então só poderemos particionar $G$ em apenas um ciclo, a saber $\mathcal{V}$, que podemos escrever como $\mathcal{V} = (u, \alpha, v, \beta, w, \dots, u)$.
   Suponha que $v \not\in X$. Seja então $x \in X$ um vértice qualquer de $X$ (obviamente, com $v \neq x$). Assim, podemos escrever $\mathcal{V} = (x, \dots, u, \alpha, v, \beta, w, \dots, x)$.
   Como todo circuito $S_{i}$ pode ser escrito como um circuito que começa e termina em $x$, entao podemos escrever uma trilha euleriana fechada $T$ em $G$, como $T = S_{1} \cdot S_{2} \cdot \ldots \cdot S_{t} \cdot \ldots \cdot S_{k}$, e entao $(\alpha, v, \beta)$ sera uma secao de $T$.

4. Seja $G$ um grafo conexo, sem laços, cujos vértices têm grau par, e que possui um número par de arestas. Prove que as arestas de $G$ podem ser coloridas de azuis e vermelhas, de forma que em cada vértice de $G$ incida o mesmo número de arestas azuis e vermelhas.

## Arvores

## Grafos Hamiltonianos

## Emparelhamentos

## Coberturas

## Índice cromático

1. Mostre que $\chi^{\prime}(G) \leq 2 \Delta(G) - 1$ para todo grafo $G$.

   Seja $G$ um grafo qualquer, que seja $k$-aresta-colorivel. Vamos mostrar que qualquer subgrafo de $G$ tambem eh $k$-aresta-colorivel.

   Seja $E_{1}, \ldots, E_{k}$ uma $k$-aresta-coloracao de $G$.  
   Seja $G^{\prime}$ um subgrafo de $G$, e
   $$
   \begin{aligned}
   E^{\prime}_{i} = E_{i} \cap A(G^{\prime})
   \end{aligned}
   $$
   Para todo $1 \leq i \leq k$. Entao temos que:
   $$
   \begin{aligned}
   E^{\prime}_{i} \cap E^{\prime}_{j} &= E_{i} \cap A(G^{\prime}) \cap E_{j} \cap A(G^{\prime})\\
   E^{\prime}_{i} \cap E^{\prime}_{j} &= (E_{i} \cap E_{j}) \cap A(G^{\prime})\\
   E^{\prime}_{i} \cap E^{\prime}_{j} &=
   \begin{cases}
   \emptyset, \quad &\text{para } i \neq j\\
   E_{i} \cap A(G^{\prime}) \quad &\text{para } i = j
   \end{cases}\\
   E^{\prime}_{i} \cap E^{\prime}_{j} &=
   \begin{cases}
   \emptyset, \quad &\text{para } i \neq j\\
   E^{\prime}_{i} \quad &\text{para } i = j
   \end{cases}
   \end{aligned}
   $$
   Portanto, todos os conjuntos $E^{\prime}_{i}$ sao disjuntos dois a dois.  
   Suponha que haja algum vertice $u \in V(G^{\prime})$ que seja adjacente a duas arestas de algum conjunto $E^{\prime}_{i}$. Como $E^{\prime}_{i} = E_{i} \cap A(G^{\prime})$ e $V(G^{\prime}) \subseteq V(G)$, entao $u$ deve ser adjacente a duas arestas em $E_{i}$ tambem. Porem $E_{i}$ eh um emparelhamento, entao temos uma contradicao, e nao ha nenhum vertice que seja adjacente a duas arestas diferentes em qualquer conjunto $E^{\prime}_{i}$. Entao cada $E^{\prime}_{i}$ eh um emparelhamento em $G^{\prime}$.  
   Temos tambem que:
   $$
   \begin{aligned}
   \bigcup_{i=1}^{k} E^{\prime}_{i} &= \bigcup_{i=1}^{k} E_{i} \cap A(G^{\prime})\\
   \bigcup_{i=1}^{k} E^{\prime}_{i} &= \left(\bigcup_{i=1}^{k} E_{i}\right) \cap A(G^{\prime})\\
   \bigcup_{i=1}^{k} E^{\prime}_{i} &= A(G) \cap A(G^{\prime})\\
   \bigcup_{i=1}^{k} E^{\prime}_{i} &= A(G^{\prime})
   \end{aligned}
   $$
   Entao $E^{\prime}_{1}, \ldots, E^{\prime}_{k}$ eh uma particao de $A(G^{\prime})$.  
   Entao $E^{\prime}_{1}, \ldots, E^{\prime}_{k}$ eh uma $k$-aresta-coloracao de $G^{\prime}$, e $G^{\prime}$ eh $k$-aresta-colorivel.

   Vamos provar agora que todo grafo $k$-regular eh $2k - 1$-aresta-colorivel.  
   Seja $G$ um grafo qualquer, sem loops, que seja $k$-regular. O algoritmo a seguir nos devolve então uma $2k-1$-aresta-coloração do grafo:

   \begin{algorithm}
   \caption{Max-coloracao}
   \begin{algorithmic}
   \PROCEDURE{MaxColor}{$G, k$}
   \STATE Sejam $E_{1}, \ldots, E_{2k-1} = \emptyset$
   \WHILE{$V(G) \neq \emptyset$}
   \STATE Seja $u \in V(G)$ um vértice qualquer
   \WHILE{$Adj(u) \neq \emptyset$}
   \STATE Seja $a \in Adj(u)$ uma aresta adjacente a $u$
   \STATE Seja $v$ o outro extremo de $a$
   \STATE Seja $i \gets 0$
   \REPEAT
   \STATE $i \gets i + 1$
   \STATE Seja $S$ o conjunto de todos os vértices que sejam extremos de alguma aresta em $E_{i}$
   \UNTIL{$u \not \in S \wedge v \not \in S$}
   \STATE $E_{i} \gets E_{i} \cup \{a\}$
   \STATE $Adj(u) \gets Adj(u) \setminus \{a\}$
   \ENDWHILE
   \STATE $V(G) \gets V(G) \setminus \{u\}$
   \ENDWHILE
   \RETURN $E_{1}, \ldots, E_{2k-1}$
   \ENDPROCEDURE
   \end{algorithmic}
   \end{algorithm}

   Vamos provar que $E_{1}, \ldots, E_{2k-1}$ é uma $2k-1$-aresta-coloração de $G$. Para isso, precisamos mostrar que:

   1. $E_{i}$ é um emparelhamento de $|A(G)|$;
   2. Para $i \neq j$, $E_{i} \cap E_{j} = \emptyset$;
   3. $\bigcup_{i=1}^{2k-1} E_{i} = A(G)$.

   Ao longo da execução do algoritmo, fazemos alterações no grafo $G$. Seja então $G_{n}$ o estado do grafo após a $n$-ésima iteração do laço das linhas 3-17, e $E_{i,n}$ o estado do conjunto $E_{i}$, analogamente. Além disso, seja $u_{n} \in V_{G_{n-1}}$ o vértice escolhido na linha 4 pelo algoritmo na $n$-ésima iteração desse laço, e $Adj_{G_{n-1}}(u_{n})$ as arestas adjacentes a $u_{n}$ em $G_{n-1}$.  
   Sejam $G_{0}$ e $E_{i, 0}$ os estados de $G$ e $E_{i}$ imediatamente antes da primeira iteração do laço.  
   Note que, se $i$ sempre for menor ou igual a $2k-1$, então o laço das linhas 9-12 nos garante que cada aresta adjacente a um determinado vértice estará em um conjunto $E_{i}$ diferente, isto é, que $E_{i}$ será um emparelhamento das arestas de $G$, o que prova (1). Além disso, após adicionarmos uma aresta em um determinado emparelhamento, essa aresta é removida do grafo, e portanto nenhuma aresta pode estar em mais de um emparelhamento $E_{i}$ diferente, e então $E_{i} \cap E_{j} = \emptyset$ para $i \neq j$, o que prova (2).  
   Seja $v_{j}$ o vértice escolhido pelo grafo na $i$-ésima iteração do laço das linhas 3-17, isto é, o outro extremo da aresta escolhida na linha anterior, na mesma iteração. O valor da variável $i$ só será maior do que $2k-1$ caso $E_{i, j}$ contenha uma aresta adjacente a $u_{j}$ ou $v_{j}$, para todo $1 \leq i \leq 2k-1$.
   Seja $A_{u_{j},v_{j}}(G_{j-1})$ o conjunto de arestas adjacentes a $u_{j}$ ou a $v_{j}$ em $G_{j-1}$, e seja $A_{u_{j}v_{j}}(G_{j-1})$ o conjunto de arestas adjacentes a $u_{j}$ **e** a $v_{j}$, **simultaneamente**, em $G_{j-1}$. Então, o valor da variável $i$ só será maior do que $2k-1$ caso $|A_{u_{j},v_{j}}(G_{j-1})| > 2k - 1$.  
   Temos que:
   $$
   \begin{aligned}
   |A_{u_{j},v_{j}}(G_{j-1})| &= g_{G_{j-1}}(u_{j}) + g_{G_{j-1}}(v_{j}) - |A_{u_{j}v_{j}}(G_{j-1})|
   \end{aligned}
   $$
   Como $G = G_{0}$ é $k$-regular, então $g_{G_{t}}(w) \leq g_{G}(w) = k$, para todo $w \in V(G_{t})$, para todo $1 \leq t \leq m$. Além disso, como $a_{j}$ é incidente a $u_{j}$ e $v_{j}$, então $|A_{u_{j}v_{j}}(G_{j-1})| \geq 1$.  
   Então temos:
   $$
   \begin{aligned}
   |A_{u_{j},v_{j}}(G_{j-1})| &\leq k + k - 1\\
   |A_{u_{j},v_{j}}(G_{j-1})| &\leq 2k - 1
   \end{aligned}
   $$
   Então o valor da variável $i$ nunca será maior do que $2k-1$.

   Note que:
   $$
   \begin{aligned}
   V(G_{n}) &= V(G_{n-1}) \setminus u_{n}\\
   |V(G_{n})| &= |V(G_{n - 1})| - 1\\
   |V(G_{n})| &= |V(G_{0})| - n
   \end{aligned}
   $$
   O laço das linhas 3-16 será executado até que não sobrem mais vértices no grafo. Seja $m$ o número de iterações total desse laço. Então, após $m$ iterações, temos que $V(G_{m}) = \emptyset$. Assim,
   $$
   \begin{aligned}
   |V(G_{m})| &= |V(G_{0})| - m\\
   0 &= |V(G_{0})| - m\\
   m &= |V(G_{0})|\\
   \end{aligned}
   $$
   Então o número total de iterações do laço será igual ao número de vértices que $G$ tem (antes de qualquer iteração).

   Note que $V(G_{n}) = V(G_{n-1}) \setminus \{u_{n}\}$. Além disso, temos que:
   $$
   \begin{aligned}
   A(G_{n}) &= A(G_{n-1}) \setminus Adj_{G_{n-1}}(u_{n})\\
   A(G_{n}) &= A(G_{0}) \setminus \bigcup_{j=1}^{n} Adj_{G_{j-1}}(u_{j})
   \end{aligned}
   $$
   Como o laço das linhas 5-14 é executado até que não hajam mais arestas adjacentes a $u_{n}$, então $u_{n}$ só é "excluído" do grafo, na linha 15, quando $Adj_{G_{n-1}}(u_{n}) = \emptyset$. Portanto, na $m$-ésima iteração do laço, na linha 15, já não temos mais nenhuma aresta no grafo. Então:
   $$
   \begin{aligned}
   A(G_{m}) &= A(G_{0}) \setminus \bigcup_{j=1}^{m} Adj_{G_{j-1}}(u_{j})\\
   \emptyset &= A(G_{0}) \setminus \bigcup_{j=1}^{m} Adj_{G_{j-1}}(u_{j})
   \end{aligned}
   $$
   Como $Adj_{G_{j-1}}(u_{j}) \subset A(G)$ para todo $1 \leq j \leq m$, então $A(G) = \bigcup_{j=1}^{m} Adj_{G_{j-1}}(u_{j})$.  
   Além disso, note que $\bigcup_{n=1}^{2k-1}E_{n, i} = \bigcup_{n=1}^{2k-1}E_{n, i-1} \cup Adj_{G_{n-1}}(u_{n})$.  
   Como $\bigcup_{n=1}^{2k-1}E_{n, 0} = \emptyset$, então temos que:
   $$
   \begin{aligned}
   \bigcup_{i=1}^{2k-1}E_{i, n} &= \bigcup_{j=1}^{n} Adj_{G_{j-1}}(u_{j})\\
   \bigcup_{i=1}^{2k-1}E_{i, m} &= \bigcup_{j=1}^{m} Adj_{G_{j-1}}(u_{j})\\
   \bigcup_{i=1}^{2k-1}E_{i, m} &= A(G)
   \end{aligned}
   $$
   Então, ao final da execução do algoritmo, temos que $\bigcup_{i=1}^{2k-1}E_{i} = A(G)$, e assim provamos (3).
   Então nosso algoritmo executa corretamente e nos devolve uma $2k-1$-aresta-coloração em $G$.

   Vimos então que todo grafo $k$-regular sem loops é $2k-1$-aresta-colorível, e todo subgrafo de um grafo $k$-aresta-colorível também é $k$-aresta-colorível. Portanto, todo grafo sem loops $G$ é $2 \Delta(G) - 1$-aresta-colorível.
