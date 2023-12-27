# Grafos Eulerianos

Uma ***trilha euleriana*** é uma trilha que passa por todas as arestas de um grafo. Um grafo é dito ***euleriano*** se possui uma trilha euleriana fechada.

**Proposição:** Um grafo $G$ conexo é euleriano se e somente se o grau de todos os seus vértices for par.
(Euleriano -> grau par)
Seja $G$ um grafo euleriano, e seja $P = (v_{0}, a_{1}, v_{1}, a_{2}, \dots, a_{k}, v_{k}, a_{k+1}, v_{0})$ uma trilha euleriana qualquer em $G$. É óbvio que qualquer vértice de $G$ precisa aparecer em $P$ ao menos uma vez, e toda aresta de $G$ aparece em $P$ exatamente uma vez.
Note também que para qualquer $i$ com $1 \leq i \leq k + 1$, $T = (v_{i-1}, a_{i}, v_{i}, \dots, a_{k}, v_{k}, a_{k+1}, v_{0}, a_{1}, \dots, v_{0})$ também será uma trilha euleriana, isto é, existe uma trilha euleriana que começa e termina em qualquer vértice do grafo. Seja então $Q = (u = w_{0}, e_{1}, w_{1}, \dots, e_{k}, w_{k}, e_{k+1}, w_{0} = u)$ uma trilha euleriana que comece e termine em $u$.
Sejam $P = \{p_{1}, \dots, p_{t}\}$ as arestas adjacentes a $u$, na ordem em que essas arestas aparecem em $Q$. Seja $P_{i} = (u, p_{2i - 1}, \dots, p_{2i}, u)$, para $1 \leq i \leq \lfloor \frac{k}{2}\rfloor$ uma seção de $P$. Então note que $P = P_{1} \cdot P_{2} \cdot \ldots \cdot P_{\left\lfloor \frac{k}{2} \right\rfloor }$. Note que uma aresta adjacente a $u$ está presente em exatamente uma seção $P_{i}$, e em cada $P_{i}$ temos 2 arestas adjacentes a $u$. Portanto, $|P| = 2 \left\lfloor \frac{k}{2} \right\rfloor$, que é um número par.

(grau par -> Euleriano)

Suponha que exista um grafo conexo, cujos vértices têm todos grau par e não seja euleriano. Seja $G$ um tal grafo com o menor número possível de arestas (um contraexemplo minimal), com $|V(G)| \geq 2$. Como $G$ é conexo, então $\delta (G) \geq 2$. Portanto $G$ possui ao menos um circuito, e portanto possui pelo menos uma trilha fechada. Seja $T$ uma trilha fechada de comprimento máximo em $G$. Note que $T$ não é euleriana, portanto $G^{\prime} = G - T$ deve ter arestas. Como $T$ é uma trilha fechada, então todo vértice de $G^{\prime}$ também tem grau par. Seja $G^{*}$ uma componente conexa de $G^{\prime}$. Como $G^{*}$ é conexa e todos os seus vértices têm grau par, então $G^{*}$ precisa ser euleriana, pois caso contrário seria um contraexemplo menor do que $G$. Seja então $T^{*}$ uma trilha euleriana em $G^{*}$.
Como $G$ é conexo, existe um vértice $v$ tal que $v \in V(T) \cap V(T^{*})$. Sem perda de generalidade, suponha que $v$ é a origem e término de $T$ e $T^{*}$. Assim, $T \cdot T^{*}$ é uma trilha fechada em $G$ de comprimento maior do que $T$, o que contradiz a escolha de $T$ como trilha fechada de maior comprimento. Portanto não pode haver contraexemplo minimal, e então todo grafo conexo onde todos os seus vértices têm grau par deve ser euleriano.

**Corolário:** Um grafo conexo tem uma trilha euleriana se e somente se tem no máximo 2 vértices de grau ímpar.

trilha euleriana -> 2v
Seja $G$ um grafo conexo que possua uma trilha euleriana. Se $G$ for euleriano, então sabemos que o número de vértices de grau ímpar em $G$ será 0. Caso $G$ não seja euleriano, seja $T = (v_{0}, \dots, v_{k})$ uma trilha euleriana em $G$. Temos que $v_{k}v_{0} \not\in A(G)$. Portanto, $G^{\prime}(V(G), A(G) \cup \{v_{k}v_{0}\})$ é um grafo euleriano, e todos os seus vértices têm grau par, em especial, $g_{G^{\prime}}(v_{k})$ e $g_{G^{\prime}}(v_{0})$ são pares. Porém, temos que $g_G(v_{k}) = g_{G^{\prime}}(v_{k}) - 1$, e $g_G(v_{0}) = g_{G^{\prime}}(v_{0}) - 1$ (mas $g_G(u) = g_{G^{\prime}}(u)$ para todos os outros vértices), e portanto $v_{0}$ e $v_{k}$ são os únicos vértices de $G$ de grau ímpar.

2v -> trilha euleriana
Agora, seja $G$ um grafo conexo. Se $G$ não tiver nenhum vértice de grau ímpar, já sabemos que $G$ possui uma trilha euleriana fechada. Suponha que $G$ possui exatamente $2$ vértices de grau ímpar, a saber, $u$ e $v$.
Suponha que $uv \in A(G)$. Seja então $G^{\prime} = G - uv$. Temos que $g_{G^{\prime}}(u) = g_{G}(u) - 1$, e $g_{G^{\prime}}(v) = g_{G}(v) - 1$. Se $G^{\prime}$ for conexo, então $G^{\prime}$ será euleriano. Seja então $T = (u = w_{0}, \dots, w_{0} = u)$ uma trilha euleriana fechada em $G^{\prime}$. Então $T \cdot (u, uv, v)$ será uma trilha euleriana em $G$.
Se $G^{\prime}$ não for conexo, então $G^{\prime}$ será formado por 2 componentes conexas. Sejam elas $U^{\prime}, V^{\prime}$, tais que $u \in U^{\prime}$ e $v \in V^{\prime}$. Então temos que $G^{\prime}[U^{\prime}]$ e $G^{\prime}[V^{\prime}]$ serão ambos grafos eulerianos. Assim, sejam $T_{u}$ uma trilha euleriana fechada em $G^{\prime}[U^{\prime}]$ que começa e termina em $u$, e $T_{v}$ uma trilha euleriana fechada em $G^{\prime}[V^{\prime}]$ qve começa e termina em $v$. Assim, $T_{u} \cdot (u, uv, v) \cdot T_{v}$ será uma trilha euleriana em $G$.

**Proposição:** Em um grafo conexo não-euleriano, uma maior trilha aberta começa e termina em vértices com graus ímpares.
Suponha que exista uma maior trilha em um grafo não-euleriano que comece (ou termine) em um vértice de grau par. Seja $T = (v_{0}, \dots, v_{k})$ tal trilha. Note que existe uma quantidade ímpar de arestas adjacentes a $v_{0}$ em $T$. Assim, existe ao menos uma aresta adjacente a $v_{0}$ que não está em $T$. Suponha que $v_{0}$ não seja adjacente a $v_{k}$. Então, vai existir algum vértice $u \neq v_{k}$, tal que $(u, uv_{0}, v_{0}) \cdot T$ é uma trilha aberta de comprimento maior do que $T$, o que contraria nossa escolha de $T$ como trilha de comprimento máximo.
Suponha que $v_{k}v_{0} \in A(G)$. Então $Q = T \cdot (v_{k}, v_{k}v_{0}, v_{0})$ será uma trilha fechada, porém não será euleriana. Como $G$ é conexo, porém, existirá algum $u \in G$, tal que $wu \in A(G)$, e $wu \not\in A(Q)$, para algum vértice $w \in Q$. Assim, seja $Q_{w}$ a trilha fechada que começa e termina em $w$. Temos que $Q_{w} \cdot (w, wu, u)$ será uma trilha aberta de comprimento maior do que $T$ em $G$, o que contraria a nossa escolha de $T$ como uma trilha de comprimento máximo em $G$. Assim, toda trilha aberta de comprimento máximo em um grafo conexo não-euleriano tem de começar e terminar em vértices de grau ímpar.

***Proposição (para grafos sem loops):*** Seja $w$ um vértice interno (que não seja igual à origem, nem ao destino) de uma trilha aberta $T$. Então o número de arestas adjacentes a $w$ que aparecem em $T$ será par.
Seja $T = (v_{0}, \dots, v_{i0} = w_{0} = w, \dots, v_{i1} = w_{1} = w, \dots, v_{ik} = w_{k} = w, \dots, v_{n})$. Podemos escrever $T = T_{0} \cdot T_{1} \cdot \ldots \cdot T_{k + 1}$, onde $T_{0} = (v_{0}, \dots, v_{i0} = w_{0})$, $T_{k + 1} = (w_{k} = v_{ik}, \dots, v_{n})$, e $T_{j} = (w_{j-1} = v_{ij-1}, \dots, v_{ij} = w_{j})$, para $1 \leq j \leq k$. Assim, cada aresta adjacente a $w$ pertence a algum $T_{j}$, com $1 \leq j \leq k$, e cada $T_{j}$ contém $2$ arestas adjacentes a $w$. Então o número de arestas adjacentes a $w$ em $T$ será $2k$ (ou duas vezes o número de vezes que $w$ aparece em $T$), que é um número par.

***Corolário:*** Seja $G$ um grafo conexo com $2k \geq 2$ vértices de grau ímpar. Então $G$ tem $k$ trilhas (abertas) $T_{1}, \ldots, T_{k}$ duas a duas disjuntas nas arestas e tais que $A(G) = A(T_{1}) \cup A(T_{2}) \cup, \ldots, \cup A(T_{k})$

Seja $G_{0} = G$, e defina:
$T_{i}$ é uma maior trilha aberta em $G_{i-1}$, e $G_{i} = G_{i-1} - T_{i}$, para $1 \leq i \leq k$.
Vamos supor que $G_{i-1}$ seja não-euleriano.
Seja $G_{i - 1}^{\prime}$ a componente conexa que contém $T_{i}$. Então $T_{i}$ é uma maior trilha aberta em $G_{i-1}[G_{i - 1}^{\prime}]$, que é um grafo conexo não euleriano. Portanto $T_{i}$ deve começar e terminar em vértices de grau ímpar.
Seja $T_{i} = (u_{i}, \dots, v_{i})$. Temos que, com exceção de $u_{i}$ e $v_{i}$, para todo vértice $w \in V(T_{i})$, temos que $g_{G_{i}}(w) \textbf{ é par } \iff g_{G}(w) \textbf{ é par }$, e $g_{G_{i}}(u_{i}) \textbf{ é par } \iff g_{G}(u_{i}) \textbf{ é ímpar }$, e $g_{G_{i}}(v_{i}) \textbf{ é par } \iff g_{G}(v_{i}) \textbf{ é ímpar }$.
Como $T_{i}$ é uma maior trilha aberta em $G_{i - 1}$, e $G_{i - 1}$ é um grafo conexo não-euleriano, temos que $g_{G_{i}}(u_{i})$, e $g_{G_{i}}(v_{i})$ são ambos pares. Assim, seja $x_{i}$ o número de vértices de grau ímpar em $G_{i}$, então temos que $x_{i} = x_{i-1} - 2$.
Ainda sob a suposição de que $G_{i-1}$ não seja euleriano, vamos supor que $G_{i}$ seja. Então temos que $x_{i} = 0$, e portanto $x_{i-1} = 2$. Assim, se $G_{i}$ é euleriano, então $G_{i-1}$ tem uma trilha euleriana aberta, portanto $A(G_{i}) = \emptyset$.
Assim, se $G_{i-1}$ não é euleriano, então $G_{i}$ ou também não é euleriano, ou $A(G_{i}) = 0$.
Seja então $x_{0} = 2k \geq 2$. Temos que, para $x_{i}$, com $1 \leq i \leq k$, $x_{i} = 2(k - i)$. Portanto podemos repetir esse processo $k$ vezes, obtendo uma trilha aberta $T_{i}$ em cada iteração. É fácil ver que, para $1 \leq i < j \leq k$, $A(T_{i}) \cap A(T_{j}) = \emptyset$. É fácil ver que $\bigcup_{i=1}^{k}A(T_{i}) \subset A(G)$. Agora note que $\emptyset = A(G_{k}) = A(G) \setminus \bigcup_{i=1}^{k}A(T_{i})$. Portanto $A(G) \subset \bigcup_{i=1}^{k}A(T_{i})$, e então $A(G) = \bigcup_{i=1}^{k}A(T_{i})$.

***Prova alternativa:*** Sejam $v_{1}, \dots, v_{2k} \in V(G)$ os vértices de $G$ de grau ímpar.
Seja $G^{\prime}$ um supergrafo de $G$, tal que $V(G^{\prime}) \setminus V(G) = \{u\}$, e $A(G^{\prime}) \setminus A(G) = \{uv_{1}, \dots, uv_{2k}\}$. Então temos que $G^{\prime}$ é um grafo conexo sem vértices de grau ímpar, portanto é euleriano.
Seja $T = (u, uv_{1}, v_{1}, \dots, v_{2}, v_{2}u, u, \dots, v_{2k}u, u)$ uma trilha euleriana em $G^{\prime}$. Podemos então escrever:
$$
T = R_{0} \cdot T_{1} \cdot R_{1} \cdot T_{2} \cdot R_{2} \cdot \ldots \cdot T_{k} \cdot R_{k}
$$
Onde $T_{i} = (v_{2i - 1}, \dots, v_{2i})$ para $1 \leq i \leq k$, $R_{0} = (u, uv_{1}, v_{1})$, $R_{k} = (v_{k}, v_{k}u, u)$, e $R_{j} = (v_{2j}, v_{2j}u, u, uv_{2j + 1}, v_{2j + 1})$, para $1 \leq j \leq k - 1$.
Note que, como $T$ é uma trilha, então temos que, para $1 \leq i < j \leq k$, $T_{i} \cap T_{k} = \emptyset$.
Temos que
$$
\begin{aligned}
\bigcup_{i=1}^{k}A(T_{i}) &= A(G^{\prime}) \setminus \bigcup_{j = 0}^{k}R_{k}\\
\bigcup_{i=1}^{k}A(T_{i}) &= A(G^{\prime}) \setminus \{uv_{1}, uv_{2}, \dots, uv_{2k}\}\\
\bigcup_{i=1}^{k}A(T_{i}) &= A(G)
\end{aligned}
$$

## Aresta de corte ou Ponte

Denotamos por $c(G)$ o número de componentes conexas de um grafo $G$. Dizemos que $\alpha$ é uma ***aresta de corte*** ou uma ***ponte*** se $c(G - a) > c(G)$.

## Algoritmo de Fleury

Entrada: grafo conexo $G$ com no máximo dois vértices de grau ímpar.
Saída: Trilha euleriana em $G$.

1. Se $G$ possui vertices de grau impar, seja $v_{0}$ um tal vertice. Senao, seja $v_{0}$ um vertice qualquer. Faca $T_{0} = (v_{0})$.
2. Tendo escolhido a trilha $T_{k} = (v_{0}, a_{1}, v_{1}, \dots, a_{k}, v_{k})$, faca $G_{k + 1} = G_{k} - A(T_{k})$. Caso $A(G_{k+1}) = \emptyset$ entao devolva a trilha $T_{k}$. Caso contrario, escolha em $G_{k+1}$ uma aresta $a_{k+1}$ incidente a $v_{k}$, de preferencia que $a_{k+1}$ nao seja ponte. Caso nao seja possivel, escolha $a_{k+1}$ uma ponte em $G_{k+1}$. De qualquer modo, seja $a_{k+1} = \{v_{k}, v_{k+1}\}$, entao faca $T_{k+1} = T_{k} \cdot (v_{k}, a_{k+1}, v_{k+1})$. Repita esse passo enquanto for possivel.

Vamos provar que esse algoritmo sempre produz trilhas eulerianas, se $G$ for um grafo conexo com no maximo dois vertices de grau impar.

***Proposição:*** Seja $G$ um grafo com uma trilha euleriana aberta, e seja $u$ um vértice de $G$ de grau ímpar. Portanto $u$ só pode ter no máximo uma aresta adjacente a si que seja uma ponte.
***Prova:***
Seja $T$ uma trilha euleriana de $G$. Podemos dizer, sem perda de generalidade, que $T$ começa em $u$.
Suponha que $\alpha, \beta$ sejam pontes adjacentes a $u$. Suponha que $\alpha$ apareça primeiro em $T$. Então existe uma trilha fechada em $T$, começando e terminando em $u$, que contém $\alpha$, pois $\beta$ deve aparecer em algum ponto de $T$, e vice versa. Tal afirmação é contraditória, pois $\alpha$ e $\beta$ são ambas pontes em $G$. Então temos que o máximo de pontes que podem ser adjacentes a $u$ será $1$.  

Seja $a_{k+1} = \{v_{k-1}, v_{k}\}$ a aresta escolhida pelo algoritmo na $k$-esima iteracao. Note que $a_{k+1} \in G_{k - 1}$, mas $a_{k+1} \not\in G_{k}$ Entao $g_{G_{k}}(v_{k - 1}) = g_{G_{k - 1}}(v_{k - 1}) - 1$, e $g_{G_{k}}(v_{k}) = g_{G_{k - 1}}(v_{k}) - 1$.

Suponha que $G_{k} \subset G$ seja um grafo que tenha $2$ vertices de grau impar. É fácil ver que toda aresta de $G_{k}$ pertence a uma mesma componente conexa. Sejam $u$ e $v$ os vértices de $G_{k}$ de grau ímpar, e suponha também que $T_{k}$ seja uma trilha em $G$ que termine em $u$, e $u$ seja um vértice de $G$ que pertence à componente conexa de $G_{k}$ (então $g_{G_{k}}(u) \geq 1$). Entao temos que $a_{k+1} = \{u, w\}$, para algum $w \in G_{k}$. Então temos que $g_{G_{k+1}}(u)$ é par.

Suponha que $a_{k+1}$ seja uma ponte. Sabemos que $a_{k+1}$ é a única ponte adjacente a $v_{k}$, pois $g_{G_{k}}(v_{k})$ é ímpar, e a componente conexa de $G_{k}$ que contém $v_{k}$ tem 2 vértices de grau ímpar. Então $a_{k+1}$ é a única aresta de $G_{k}$ adjacente a $v_{k}$ (pois todas as que não são ponte foram escolhidas). Suponha então que exista $e = \{x, y\} \in A(G_{k+1})$ tal que $x$ não esteja na componente conexa de $w$ em $G_{k+1}$. Como $A(G_{k + 1}) \subset A(G_{k})$, então temos que $e \in A(G_{k})$, e então $x$ e $w$ pertencem à mesma componente conexa em $G_{k}$. Portanto o caminho (em $G_{k}$) de $x$ a $w$ deve passar por $u$. Como $a_{k+1} = \{u,w\}$ é a única aresta de $G_{k}$ incidente em $u$, temos que não pode existir caminho entre $x$ e $u$ em $G_{k}$.
. Portanto não pode haver tal aresta $e$, e concluímos que todas as arestas em $G_{k+1}$ também devem estar na mesma componente conexa, que deve conter $w$.

Caso $a_{k+1}$ não seja uma ponte, então novamente, todas as arestas de $G_{k+1}$ estarão na mesma componente conexa. Temos também que, caso $a_{k+1}$ não seja uma ponte, então $g_{G_{k}}(w) \geq 2$, portanto $g_{G_{k+1}}(w) \geq 1$. Então $w$ terá arestas adjacentes a si em $G_{k+1}$, e $w$ estará na componente conexa das arestas de $G_{k+1}$.

Suponha agora que $w = v$.
Entao temos que $g_{G_{k + 1}}(w)$ sera par, e $G_{k+1}$ sera um grafo em que todos os seus vertices tem grau par.

Suponha agora que $w \neq v$. Portanto $g_{G_{k+1}}(w)$ será ímpar, e então teremos que $G_{k+1}$ será um grafo em que apenas dois de seus vértices terão grau ímpar, e $T_{k+1} = T_{k} \cdot (u, uw, w)$, vai acabar em um vértice de grau ímpar.

Conseguimos mostrar então que, dado um grafo $G_{k} \subset G$ que tenha $2$ vertices de grau ímpar, e $T_{k}$ uma trilha em $G$ que termine em $u$, e $u$ seja um vértice de $G$ que pertence à componente conexa de $G_{k}$, com $g_{G_{k}}(u)$ ímpar, então $T_{k+1}$ será uma trilha em $G$ terminando em $w$, e $G_{k+1}$ será um grafo com exatamente 2 vértices de grau ímpar, sendo $w$ um deles, ou $G_{k+1}$ será um grafo onde todos os vértices terão grau par. De qualquer jeito, todas as arestas de $G_{k+1}$ devem pertencer à componente conexa de $w$ em $G_{k+1}$.

Suponha agora que $T_{k}$ seja uma trilha em $G$ terminando em $w$, e $G_{k} \subset G$ seja um grafo em que todos os seus vértices têm grau par, e todas as suas arestas estão na componente conexa de $G_{k}$ que contém $w$. Se $A(G_{k}) \neq \emptyset$, então $g_{G_{k}}(w) \geq 2$ (e também $g_{G_{k}}(u) \geq 2 \implies g_{G_{k + 1}}(u) \geq 1$).
Novamente, seja $a_{k+1} = \{w, u\}$ a aresta de $G_{k}$ escolhida pelo algoritmo na $k$-ésima iteração. Então temos que $w$ e $u$ serão os únicos vértices de $G_{k+1}$ com grau ímpar, e $T_{k+1} = T_{k} \cdot (w, wu, u)$. Como sabemos, todas as arestas de $G_{k+1}$ devem estar na mesma componente conexa. Como $g_{G_{k+1}}(u) \geq 1$, então $u$ tem arestas em $G_{k+1}$, portanto $u$ pertence a essa componente conexa.

Então, dado um grafo $G_{k} \subset G$, e uma trilha $T_{k}$ em $G$ que termina em $w_{k} \in G_{k}$, tais que $A(G_{k}) \neq \emptyset$, $G_{k}$ é um grafo em que no máximo dois de seus vértices têm grau ímpar, e todas as arestas de $G_{k}$ pertencem à componente conexa de $w_{k}$, sempre podemos gerar $T_{k+1}$ e $G_{k+1}$, os quais atendem os mesmos requisitos, só não necessariamente o de $G_{k+1}$ não ser vazio.
Note que $|A(G_{k})| = |A(G_{k-1})| - 1$, e então $|A(G_{k})| = |A(G_{0})| - k$.
Defina $G_{0} = G$, e seja $n$ tal que $|A(G_{n})| = 0$. Então temos que $n = |A(G)|$.
Note que $A(T_{k}) \subset A(G)$, e $A(G_{k}) = A(G_{k-1}) \setminus A(T_{k})$, $A(G_{k}) = A(G) \setminus \bigcup_{i=1}^{k} A(T_{i})$.
Note também que $A(T_{i}) \subset A(T_{i+1})$, para todo $0 \leq i \leq n$. Então $\bigcup_{i=1}^{n}A(T_{i}) = A(T_{n})$
Então temos que $A(G_{n}) = A(G) \setminus A(T_{n})$. Como $|A(G_{n})| = 0$, temos que $A(G_{n}) = \emptyset$, portanto $A(G) = A(T_{n})$, e então $T_{n}$ é uma trilha euleriana em $G$.
