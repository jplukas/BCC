# Emparelhamentos

Todos os grafos nesta seção são grafos **simples**, isto é, sem laços ou arestas múltiplas.

[Emparelhamento]{#def:emparelhamento}
: Um ***emparelhamento*** em um grafo é um conjunto de arestas duas a duas não-adjacentes. Isto é, um emparelhamento é um conjunto $E$ de arestas tal que todo vértice do grafo é extremo de no máximo um elemento de $E$.

    - Seja $G$ um grafo e $X \subseteq V(G)$. Dizemos que um emparelhamento $E$ ***cobre*** (ou satura) $X$ se em cada vértice de $X$ incide uma aresta de $E$. Neste caso, dizemos que $X$ é ***coberto*** (ou saturado) por $E$. Se $X = \{v\}$, então dizemos simplesmente que $E$ ***cobre*** (ou satura) $v$.

    - Um emparelhamento é ***perfeito*** se cobre todos os vértices de um grafo.

    - Se um vértice $v$ não é coberto por um emparelhamento $E$, então dizemos que $v$ é ***livre em relação a $E$*** (ou simplesmente ***livre***, se $E$ estiver claro pelo contexto).

## Emparelhamentos máximos

[Emparelhamento maximal]{#def:emparelhamento_maximal}
: Um emparelhamento $E$ em um grafo $G$ é dito ***maximal*** se não existe nesse grafo um emparelhamento $E^{\prime}$ que contenha $E$ propriamente (isto é, não existe emparelhamento $E^{\prime}$ em $G$ tal que $E \subsetneq E^{\prime}$).

[Emparelhamento máximo]{#def:emparelhamento_maximo}
: Um emparelhamento $E$ de um grafo $G$ é dito ***máximo*** se não existe, em $G$, nenhum outro emparelhamento com cardinalidade *maior* do que $|E|$.

Note que:

1. Nem todo emparelhamento maximal é máximo
2. Todo emparelhamento máximo é maximal
3. Pode haver mais de um emparelhamento maximal ou máximo em um mesmo grafo

[Caminho alternante]{#def:caminho_alternante}
: Seja $E$ um emparelhamento num grafo $G$. Um ***caminho $E$-alternante*** é um caminho em $G$ cujas arestas estão alternadamente em $E$ ou em $A(G) \setminus E$. Isto é, seja $P = (v_{1}, \ldots, v_{n})$ um caminho $E$-alternante. Então
$$
\begin{aligned}
v_{i}v_{i+1} \in E \iff v_{i-1}v_{i} \in A(G) \setminus E \quad \text{ para } 1 < i \leq n
\end{aligned}
$$
Um tal caminho com ambas extremidades livres (em $E$) é chamado de ***caminho aumentador*** (*augmenting path*).

### Caracterização de emparelhamentos máximos

[Berge, 1957]{#thm:berge_emp_max}
: Seja $G$ um grafo e $E$ um emparelhamento em $G$. Temos que $E$ é um emparelhamento máximo se e somente se não houver um caminho $E$-alternante que seja aumentador.

    ***Prova:***

    Seja $E$ um emparelhamento em um grafo $G$, e $P$ um caminho $E$-alternante qualquer.  
    Vamos provar que $X = A(P) \setminus E$ também é um emparelhamento.  
    Suponha que exista um vértice $v \in V(G)$ que seja adjacente a mais de uma aresta em $X$. Sejam então $\alpha$ e $\beta$ duas arestas em $X$ que tenham $v$ como um de seus extremos.  
    Como $\alpha, \beta \in X$, então temos que
    $$
    \begin{aligned}
    \alpha \in A(P) &\wedge \alpha \not\in E\\
    \beta \in A(P) &\wedge \beta \not\in E
    \end{aligned}
    $$
    Como ambos $\alpha$ e $\beta$ estão em $P$, essas arestas não podem aparecer consecutivamente, pois nenhuma das duas está em $E$. Porém, como $v$ é incidente às duas, a única maneira que isso seria possível seria se $\alpha = v_{1}v_{2}$ e $\beta = v_{n-1}v_{n}$. Porém, nesse caso, $v$ apareceria duas vezes em $P$, e $P$ não seria um caminho.  
    Portanto todas as arestas de $X$ têm de ser duas a duas não-adjacentes, e $X = A(P) \setminus E$ é um emparelhamento em $G$.  
    Note também que $E \setminus A(P) \subset E$, portanto $E \setminus A(P)$ também é um emparelhamento.  
    Como ambos $A(P) \setminus E$ e $E \setminus A(P)$ são emparelhamentos, então $E \triangle A(P)$ também é, e $|E \triangle A(P)| = |E| + |A(P) \setminus E| - |E \cap A(P)|$.

    Além disso, sejam
    $$
    \begin{aligned}
    \mathcal{P} &= \{v_{i}v_{i+1} : i \quad \text{é par}\}\\
    \mathcal{I} &= \{v_{i}v_{i+1} : i \quad \text{é ímpar}\}
    \end{aligned}
    $$
    dois subconjuntos de $A(P)$. Note que
    $$
    \begin{aligned}
    v_{1}v_{2} \in E &\iff E \cap A(P) = \mathcal{I}\\
    v_{1}v_{2} \not\in E &\iff A(P) \setminus E = \mathcal{I}\\
    v_{1}v_{2} \in E &\iff A(P) \setminus E = \mathcal{P}
    \end{aligned}
    $$
    Além disso, como $\mathcal{P} \cap \mathcal{I} = \emptyset$, e $A(P) = \mathcal{P} \cup \mathcal{I}$, então $n - 1 = |A(P)| = |\mathcal{P}| + |\mathcal{I}| = |E \cap A(P)| + |A(P) \setminus E|$.  
    Então considere os seguintes casos:

    1. $n$ é **ímpar**:

        Se $n$ é ímpar, então $n-1$ é par, e $|E \cap A(P)| = |A(P) \setminus E|$.  
        Neste caso, $v_{1}v_{2} \in E \iff v_{n-1}v_{n} \in A(P) \setminus E$, e então $P$ não é um caminho aumentador.

    2. $n$ é **par**:

        Se $n$ é par, então $n-1$ é ímpar, e $|E \cap A(P)| = |A(P) \setminus E| \pm 1$.  
        Neste caso, $v_{1}v_{2} \in E \iff v_{n-1}v_{n} \in E$. Daí temos dois sub-casos:

        1. $v_{1}v_{2}, v_{n-1}v_{n} \in E$:

           $P$ não é um caminho aumentador, e $|E \cap A(P)| = |A(P) \setminus E| + 1$.

        2. $v_{1}v_{2}, v_{n-1}v_{n} \in A(P) \setminus E$

           $P$ é um caminho aumentador, e $|E \cap A(P)| = |A(P) \setminus E| - 1$.

    Portanto, se houver um caminho $P$, $E$-alternante que seja aumentador, temos que:
    $$
    \begin{aligned}
    |E \triangle A(P)| &= |E| + |A(P) \setminus E| - |E \cap A(P)|\\
    |E \triangle A(P)| &= |E| + |A(P) \setminus E| - (|A(P) \setminus E| - 1)\\
    |E \triangle A(P)| &= |E| + 1\\
    |E \triangle A(P)| &> |E|
    \end{aligned}
    $$
    E então $E$ não será máximo.

## Emparelhamentos em grafos bipartidos

[Hall, 1935]{#thm:hall_bip}
: Seja $G$ um grafo $(X,Y)$-bipartido. Então $G$ tem um emparelhamento que cobre $X$ se e somente se $|Adj(S)| \geq |S|$ para todo $S \subseteq X$.

[]{#cor:hall_1}
: Seja $G$ um grafo $(X,Y)$-bipartido. Se $|Adj(S)| \geq |S| - k$ para todo $S \subseteq X$ e algum inteiro fixo $k$, então $G$ tem um emparelhamento de cardinalidade maior ou igual a $|X| - k$.

[]{#cor:hall_2}
: Todo grafo bipartido $k$-regular, com $k \geq 1$ tem (ao menos) um emparelhamento perfeito.

[]{#cor:hall_3}
: Todo grafo bipartido $k$-regular, com $k \geq 2$ tem $k$ emparelhamentos perfeitos dois a dois disjuntos.

    ***Prova:***

    Seja $G$ um grafo bipartido $1$-regular. É fácil ver então que $A(G)$ é o único emparelhamento perfeito de $G$.

    Suponha então que todo grafo bipartido $k-1$-regular tenha $k-1$ emparelhamentos perfeitos, dois a dois disjuntos. Sejam $E_{1}, \ldots, E_{k-1}$ esses tais emparelhamentos.  
    Seja $G$ um grafo $(X,Y)$-bipartido $k$-regular. Note que podemos obter $G$ a partir de algum grafo $(X,Y)$-bipartido $k-1$-regular $G^{\prime}$, ao acrescentar (em $G^{\prime}$) uma aresta a cada vértice de $X$, que seja incidente a algum vértice de $Y$.  
    Como $V(G) = V(G^{\prime})$, e $A(G^{\prime}) \subset A(G)$, qualquer emparelhamento perfeito de $G^{\prime}$ também será um emparelhamento perfeito de $G$.  
    Considere então o conjunto de arestas $R = G \setminus G^{\prime}$. Note que cada aresta de $R$ incide sobre um único vértice de $X$ e $Y$, e nenhum par de arestas distintas incide sobre o mesmo vértice. Portanto $R$ é um emparelhamento perfeito de $G$. Note também que $R \cap E_{i} = \emptyset$, pois nenhum elemento de $R$ pertence a $A(G^{\prime})$. Então temos que
    $$
    \begin{aligned}
    \left|\bigcup_{i=1}^{k-1} E_{i} \cup R\right| &= \sum_{i=1}^{k-1} |E_{i}| + |R|\\
    \left|\bigcup_{i=1}^{k-1} E_{i} \cup R\right| &= (k-1) \cdot |X| + |X|\\
    \left|\bigcup_{i=1}^{k-1} E_{i} \cup R\right| &= k |X|\\
    \left|\bigcup_{i=1}^{k-1} E_{i} \cup R\right| &= |A(G)|\\
    \end{aligned}
    $$
    Como $(\bigcup_{i=1}^{k-1} E_{i} \cup R) \subseteq A(G)$, então só pode ser que $\bigcup_{i=1}^{k-1} E_{i} \cup R = A(G)$, o que significa que $G$ tem $k$ emparelhamentos perfeitos dois a dois disjuntos.

    Assim completamos nossa prova por indução em $k$.

[k-fator]{#def:k-fator}
: Seja $k$ um inteiro positivo. Um subgrafo gerador $k$-regular de um grafo $G$ é chamado de ***$k$-fator*** de $G$.

[]{#cor:2-fator}
: Todo grafo bipartido $k$-regular tem pelo menos $\binom{k}{2}$ $2$-fatores distintos.

[Teorema do 2-fator, Petersen, 1891]{#thm:2-fator}
: Se $G$ é um grafo conexo $2k$-regular, com $k \geq 1$, então o conjunto das arestas de $G$ pode ser particionado em $k$ $2$-fatores disjuntos nas arestas (também dizemos que $G$ admite uma decomposição em $k$ $2$-fatores).

# Coberturas

[Cobertura]{#def:cobertura}
: Uma ***cobertura*** de um grafo $G$ é um subconjunto $S \subseteq V(G)$ dos vértices de $G$, tal que toda aresta de $G$ tem pelo menos um dos extremos em $S$.

## Relação entre emparelhamentos e coberturas de um grafo

Seja $K$ uma cobertura, e $E$ um emparelhamento de um grafo $G$. Então temos que $|E| \leq |K|$, pois cada aresta de $E$ deve ser incidente de ao menos um vértice de $K$.

## Problema da cobertura mínima

[Cobertura mínima]{#def:cobertura_minima}
: Dado um grafo $G$, uma ***cobertura mínima*** de $G$ é uma cobertura de menor cardinalidade de $G$.

Assim, nos deparamos com o seguinte problema: Dado um grafo $G$, encontre uma cobertura mínima em $G$.

Esse problema é um problema NP-difícil para grafos quaisquer, mas é polinomial para grafos bipartidos.
