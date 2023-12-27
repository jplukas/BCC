# Grafos Hamiltonianos

[Caminho Hamiltoniano]{#def:caminho_hamiltoniano}
: Um ***caminho hamiltoniano*** em um grafo $G$ é um caminho que passa por todos os vértices de $G$.

[Circuito Hamiltoniano]{#def:circuito_hamiltoniano}
: Um ***circuito hamiltoniano*** em um grafo $G$ é um circuito que passa por todos os vértices de $G$.

[Grafo Hamiltoniano]{#def:grafo_hamiltoniano}
: Um grafo $G$ é dito ***hamiltoniano*** se houver um *circuito hamiltoniano* em $G$.

[Condição necessária para um grafo ser hamiltoniano]{#thm:cond_nec_hamilt}
: Dado um grafo $G$ hamiltoniano, então, para qualquer conjunto não vazio $S \subset V(G)$, temos
$$
\begin{aligned}
c(G - S) \leq |S|
\end{aligned}
$$
    ***Prova:***  
    Como $G$ é um grafo hamiltoniano, entao $G$ possui um circuito hamiltoniano. Seja $C$ esse tal circuito. Queremos provar que
    $$
    \begin{aligned}
    c(G-S) \leq c(C - S)
    \end{aligned}
    $$
    Para qualquer subconjunto $S$ não vazio dos vértices de $G$.
    Para isso, vamos mostrar que toda componente conexa de $C-S$ também está em $G - S$

    Primeiramente, note que $V(G-S) = V(C-S)$.
    Sejam $C_{1}, \ldots, C_{n}$ as componentes conexas de $C-S$. Sejam $u_{i}, v_{i} \in V(C_{i})$ dois vertices quaisquer da componente $C_{i}$.
    Se existir um caminho de $u_{i}$ a $v_{i}$ em $G-S$, entao $C_{i}$ esta em $G-S$.
    Suponha que nao exista um caminho de $u_{i}$ a $v_{i}$ em $C-S$.
    Note que, como $G$ eh hamiltoniano, entao $G$ deve ser conexo. Assim, segundo a nossa suposicao, todos os caminhos possiveis de $u_{i}$ a $v_{i}$ em $G$ devem  ter seus vertices internos em $G[S]$. Entao a unica maneira de haver um caminho de $u_{i}$ a $v_{i}$ em $C-S$ sera se $u_{i}$ for adjacente a $v_{i}$, mas isso significaria que $G-S$ teria um caminho de $u_{i}$ a $v_{i}$ (a saber, $P = (u_{i}, \alpha, v_{i})$, onde $\alpha$ eh uma aresta que eh adjacente a $u_{i}$ e $v_{i}$). Entao nossa suposicao esta errada, e quaisquer dois vertices que sejam conexos em $C-S$ devem tambem ser conexos em $G-S$.

    Dai segue que $c(G-S) \leq c(C-S)$.

    Agora vamos provar que $c(C-S) \leq |S|$

    Seja $H = C[S]$.

    Vamos escrever $C$ como $C = (w_{0}, \ldots, w_{k} = w_{k})$.

    Caso $H = C$, entao o resultado eh obvio (considerando que o numero de componentes de um grafo vazio eh zero).

    Suponha entao que $H \neq C$. Entao eh obvio que $H$ nao contem circuitos.
    Assim, sejam $H_{1}, \ldots, H_{n}$ as componentes conexas de $H$.
    Note que cada $H_{i}$ pode ser escrito como uma secao de $C$.
    Entao seja $H_{i} = (w_{i}, \ldots, w_{j})$, para algum $j,i$. Note que tanto $w_{i}$ quanto $w_{j}$ devem ser adjacentes a algum vertice de uma componente conexa de $C-S$. Da mesma maneira, cada componente conexa de $C-S$ pode ser escrita como um caminho com duas pontas adjacentes a algum vertice que eh uma componente conexa de $C[S]$. Assim, o numero de componentes conexas de $C[S]$ deve ser igual ao de $C-S$.

    Agora, so precisariamos mostrar que $c(C[S]) \leq |S|$, o que eh obvio, entao temos
    $$
    \begin{aligned}
    c(G-S) \leq c(C-S) &= c(C[S]) \leq |S|\\
    c(G-S) &\leq |S|\\
    \end{aligned}
    $$
    Como queriamos mostrar.

## Condições suficientes para um grafo hamiltoniano

[Dirac, 1952]{#thm:dirac_hamilt}
: Se $G$ é um grafo **simples** de ordem $n \geq 3$ e $\delta(G) \geq n/2$, então $G$ é hamiltoniano

    ***Prova 1:***  
    Suponha que a afirmação seja falsa. Então existe um grafo simples não-hamiltoniano maximal $G$ de ordem $n \geq 3$ tal que $\delta(G) \geq 2$. Ou seja, $G$ não é hamiltoniano, mas para qualquer par de vértices não-adjacentes $u,v$ de $G$, $G + uv$ é hamiltoniano.  
    Note que $G$ não é completo, pois qualquer grafo completo com mais do que $3$ vértices é hamiltoniano. Então deve haver no mínimo dois vértices em $G$ que não sejam adjacentes.  
    Sejam $u,v$ dois tais vértices. Como $G$ não é hamiltoniano, mas $G + uv$ é, então existe um ciclo hamiltoniano passando por $u$ e $v$ em $G + uv$, e então existe um caminho hamiltoniano $P$ com uma ponta em $u$ e outra em $v$ em $G$, a saber,
    $$
    \begin{aligned}
    P = (u = w_{1}, \ldots, w_{n} = v)
    \end{aligned}
    $$
    Note que, se $w_{i}$ é adjacente a $u$, então $w_{i-1}$ não é adjacente a $v$, pois senão
    $$
    \begin{aligned}
    C = (u = w_{1}, w_{i}, \ldots, w_{n} = u, w_{i-1}, w_{i-2}, \ldots, w_{1} = u)
    \end{aligned}
    $$
    Seria um ciclo hamiltoniano em $G$.  
    Portanto, $g(v) < n - g(u)$. Porém, temos que:
    $$
    \begin{aligned}
    g(u) &\geq n/2\\
    n - g(u) &\leq n - n/2\\
    n - g(u) &\leq n/2\\
    g(v) &< n/2
    \end{aligned}
    $$
    O que contradiz a hipótese de que $\delta(G) \geq n/2$. Portanto não pode haver tal grafo maximal.

    ***Prova 2:*** Suponha...

[Ore, 1960]{#thm:ore_hamilt}
: Se $G$ é um grafo **simples** de ordem $n \geq 3$ tal que
$$
\begin{aligned}
g(u) + g(v) \geq n \quad \text{ para todo par } u,v \text{ de vértices não-adjacentes}
\end{aligned}
$$
Então $G$ é hamiltoniano.

    ***Prova:***  
    Suponha que a afirmação seja falsa. Então existe um grafo simples não-hamiltoniano maximal $G$ de ordem $n \geq 3$ tal que, para qualquer par de vértices não-adjacentes $u,v$ em $G$, $g(u) + g(v) \geq n$. Ou seja, $G$ não é hamiltoniano, mas para qualquer par de vértices não-adjacentes $u,v$ de $G$, $G + uv$ é hamiltoniano.  
    Note que $G$ não é completo, pois qualquer grafo completo com mais do que $3$ vértices é hamiltoniano. Então deve haver no mínimo dois vértices em $G$ que não sejam adjacentes.  
    Sejam $u,v$ dois tais vértices. Como $G$ não é hamiltoniano, mas $G + uv$ é, então existe um ciclo hamiltoniano passando por $u$ e $v$ em $G + uv$, e então existe um caminho hamiltoniano $P$ com uma ponta em $u$ e outra em $v$ em $G$, a saber,
    $$
    \begin{aligned}
    P = (u = w_{1}, \ldots, w_{n} = v)
    \end{aligned}
    $$
    Note que, se $w_{i}$ é adjacente a $u$, então $w_{i-1}$ não é adjacente a $v$, pois senão
    $$
    \begin{aligned}
    C = (u = w_{1}, w_{i}, \ldots, w_{n} = u, w_{i-1}, w_{i-2}, \ldots, w_{1} = u)
    \end{aligned}
    $$
    Seria um ciclo hamiltoniano em $G$.  
    Portanto, $g(v) < n - g(u)$. Porém, temos que:
    $$
    \begin{aligned}
    g(u) + g(v) &\geq n\\
    g(v) &\geq n - g(u)
    \end{aligned}
    $$
    Que é uma contradição. Portanto não pode haver tal grafo maximal.

[Bondy e Chvátal, 1976]{#thm:bondy_chvatal_hamilt}
: Seja $G$ um grafo simples de ordem $n$ e sejam $u,v$ vértices não-adjacentes em $G$ tais que
$$
\begin{aligned}
g(u) + g(v) \geq n
\end{aligned}
$$
Então $G$ é hamiltoniano **se e só se** $G + uv$ é hamiltoniano.

    ***Prova:***  

    1. $G$ é hamiltoniano $\implies$ $G + uv$ é hamiltoniano  
    Se $G$ é hamiltoniano, então existe um circuito hamiltoniano $C$ em $G$. Note que $C$ também deve estar em $G + uv$, e $V(G) = V(G + uv)$. Portanto $C$ é um circuito hamiltoniano em $G + uv$.

    2. $G$ não é hamiltoniano $\implies$ $G + uv$ não é hamiltoniano  
    Suponha que tenhamos um grafo $G$ de ordem $n$ tal que $G$ não seja hamiltoniano, mas, para algum par de vértices não-adjacentes $u,v$ em $G$, com $g(u) + g(v) \geq n$, $G + uv$ seja hamiltoniano.  
    Caso $n < 3$, a única forma de haver dois vértices não adjacentes em $G$ seria se $G$ não tivesse nenhuma aresta. Então $g_{G}(u) = 0$ para qualquer vértice $u$ de $G$, e as hipóteses do nosso teorema não se aplicam.  
    Considere então o caso de $n \geq 3$. Sabemos que todo grafo completo de ordem $n \geq 3$ deve ser hamiltoniano. Então deve haver ao menos um par de vértices não adjacentes em $G$.  
    Sejam então $u,v$ dois vértices não adjacentes de $G$, tais que $g(u) + g(v) \geq n$. Como $G + uv$ é hamiltoniano, então deve haver um caminho hamiltoniano de $u$ a $v$ em $G$, a saber,
    $$
    \begin{aligned}
    P = (u = w_{1}, \ldots, w_{n} = v)
    \end{aligned}
    $$
    Note que, se $w_{i}$ é adjacente a $u$, então $w_{i-1}$ não é adjacente a $v$, pois senão
    $$
    \begin{aligned}
    C = (u = w_{1}, w_{i}, \ldots, w_{n} = u, w_{i-1}, w_{i-2}, \ldots, w_{1} = u)
    \end{aligned}
    $$
    Seria um ciclo hamiltoniano em $G$.  
    Portanto, $g(v) < n - g(u)$. Porém, temos que:
    $$
    \begin{aligned}
    g(u) + g(v) &\geq n\\
    g(v) &\geq n - g(u)
    \end{aligned}
    $$
    Que é uma contradição. Portanto, se $G + uv$ é hamiltoniano, $G$ também deve ser.

[Fecho de um grafo]{#def:fecho_de_um_grafo}
: O ***fecho*** de um grafo $G$, denotado por $\mathcal{F}(G)$ é o grafo que se obtém de $G$ acrescentando-se recursivamente arestas ligando pares de vértices não-adjacentes em $G$, cuja soma dos graus é pelo menos $|V(G)|$, até que não exista mais nenhum tal par.

[]{#prop:}
: O *fecho* de um grafo é único. Isto é, independe da ordem que as arestas são acrescentadas.

[Bondy e Chvátal, 1976]{#cor:fecho_hamilt}
: Um grafo $G$ é hamiltoniano **se e só se** $\mathcal{F}(G)$ é hamiltoniano.

[]{#cor:fecho_completo_hamilt}
: Se $\mathcal{F}(G)$ é completo, então $G$ é hamiltoniano.
