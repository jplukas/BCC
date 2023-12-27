# Árvores

Suponha que numa região haja $n$ cidades. Deseja-se construir ferrovias para interligar essas cidades, de modo que sempre seja possível viajar entre quaisquer duas delas (não necessariamente com linha direta). Qual é o número mínimo de linhas diretas que deve existir interligando essas cidades?
Isto é: qual é o número mínimo de arestas que um grafo $G$ de $n$ arestas deve ter para que $G$ seja conexo?
Sabemos, do capítulo 1, que a resposta para essa pergunta é $n-1$ arestas.

Um grafo é ***acíclico*** se ele não contém circuitos.

***Proposição:*** Seja $G$ um grafo conexo com $n$ vértices. Então $G$ será acíclico se e somente se $G$ tiver $n-1$ arestas.
***Prova:***
($G$ acíclico -> $n-1$ arestas)
Seja $G$ um grafo acíclico conexo, com $n$ vértices e $k$ arestas.
Se $G$ é acíclico, então existe exatamente um único caminho entre dois vértices quaisquer de $G$. Assim, toda aresta em $G$ é uma ponte, ou aresta de corte. Então, qualquer que seja $a \in A(G)$, temos que $c(G) = c(G - a) + 1$.
Sejam $\{a_{1}, \dots, a_{k}\} = A(G)$ as arestas de $G$.
Note que
$$
\begin{aligned}
A(G) \setminus A(G) &= A(G) \setminus \bigcup_{i = 1}^{k} \{a_{i}\}\\
A(G) \setminus A(G) &= A(G) \setminus \{a_{1}\} \setminus \{a_{2}\} \setminus \ldots \setminus \{a_{k}\}
\end{aligned}
$$
Então temos que $c(G) = c(G - A(G)) + k$. Temos que $|A(G)| = k$, e como $G$ é conexo, $c(G) = 1$. Temos então que $1 = c(G - A(G)) - k$, e portanto $c(G - A(G)) = k+1$. Note que $V(G - A(G)) = V(G)$, e $A(G - A(G)) = \emptyset$. Portanto $G - A(G)$ é um grafo sem arestas, com $n$ vértices, e portanto $c(G - A(G)) = n$, assim, $n = k + 1$.

($n-1$ arestas -> $G$ acíclico)
Suponha que $G$ seja um grafo conexo, com $n-1$ arestas, tal que $G$ contenha ao menos um circuito, digamos $C$. Como $C$ é um circuito, então nehuma de suas arestas é uma aresta de corte. Seja $\alpha \in A(C)$ uma aresta qualquer desse circuito. Então $G - \alpha$ é um grafo conexo com $n$ vértices e $n - 2$ arestas, o que é um absurdo. Portanto, se um grafo $G$ conexo de $n$ vértices tem $n - 1$ arestas, $G$ é acíclico.

Uma ***Árvore*** é um grafo conexo acíclico. Temos então pela proposição acima que um grafo conexo com $n$ vértices somente será uma árvore se tiver $n-1$ arestas.
Uma ***floresta*** é um grafo sem ciclos. Note que as componentes conexas de uma floresta são árvores.
Uma ***folha*** é um vértice de uma árvore de grau 1.

***Proposição:*** Todo maior caminho em uma árvore começa e termina em folhas.
***Prova:*** Seja $G$ uma árvore, e seja $T = (u, \dots, v)$ um maior caminho em $G$. Suponha que $g(u) > 1$. Então existe algum $w \in V(G) \setminus V(T)$ tal que $w$ seja adjacente a $u$. Então $(w, wu, u) \cdot T$ será um caminho em $G$ de comprimento maior do que $T$. O mesmo vale para $v$.

***Proposição:*** Seja $T$ uma árvore não-trivial qualquer, $u \in V(T)$ um vértice qualquer de $T$ tal que $g(u) = 1$, e seja $T^{\prime} = T - u$. Então $T^{\prime}$ será uma árvore.
***Prova:*** Caso $|V(T)| = 2$, então $T^{\prime}$ será uma árvore trivial. Considere então que $|V(T)| \geq 3$.
Suponha que existam $w, v \in V(T^{\prime})$, tais que não existe um caminho de $w$ a $v$ em $T^{\prime}$.
Como $V(T^{\prime}) \subset V(T)$, então $w,v \in V(T)$. Como $T$ é conexo, então existe um único caminho $P$ de $w$ a $v$ em $T$, e $P = (w, \dots, u, \dots, v)$. Porém, isso significaria que $g(u) \geq 2$, o que é um absurdo. Então não podem haver em $T^{\prime}$ dois vértices tais que não haja caminho entre eles. Portanto $T^{\prime}$ é conexo. Além disso, como $A(T^{\prime}) \subset A(T)$, e $T$ é acíclico, então $T^{\prime}$ também deve ser. Portanto $T^{\prime}$ será uma árvore.

***Corolário:*** toda árvore não trivial tem pelo menos $2$ folhas.
***Prova:*** Seja $G$ um grafo qualquer. Sabemos que $\delta(G) \geq 2$ implica que existe ao menos um ciclo de comprimento $\delta(G) + 1$ em $G$. Então deve existir ao menos um vértice de grau 1 em qualquer árvore.
Seja $T$ a menor árvore não-trivial possivel tal que $T$ tenha apenas um vértice de grau 1, e seja $u \in V(T)$ esse vértice. Seja $v(T)$ o único vértice em $T$ adjacente a $u$. Então temos que $g(v) \geq 2$.
Considere o grafo $T^{\prime} = T - u$. Como $T$ é uma árvore, e $g(u) = 1$, então $T^{\prime}$ também deve ser uma árvore, e deve ter ao menos um vértice de grau 1. Porém, para qualquer vértice $w$ de $T$, diferente de $u$ e $v$, $g_{T}(w) = g_{T^{\prime}}(w)$. Então $u$ é o único vértice de $T^{\prime}$ de grau 1, e $T^{\prime}$ será uma árvore menor do que $T$, com apenas um vértice de grau 1, e então não pode haver $T$.

***Prova alternativa***:
Seja $T$ uma árvore nao-trivial qualquer.
Seja $P$ um maior caminho em $T$. Sabemos que $P$ deve começar e terminar vértices de grau $1$. Portanto $T$ possui ao menos $2$ folhas.

***Proposição:*** Seja $T$ uma floresta, e $T^{\prime} \subset T$ um subgrafo qualquer de $T$. Então $T^{\prime}$ será uma floresta.
***Prova:***
Suponha que $T^{\prime}$ possua ao menos um circuito, a saber, $C$. Portanto $A(C) \subset A(T^{\prime})$.
Porém, como $A(T^{\prime}) \subset A(T)$, temos que $A(C) \subset A(T)$, o que significa que $T$ possui ao menos um circuito, que é um absurdo.
Portanto $T^{\prime}$ é acíclico, e portanto, uma floresta.

***Proposição:*** Seja $T$ uma árvore. Então $T$ possui um número par de folhas.
***Prova:*** Suponha que exista ao menos uma árvore com uma quantidade ímpar de folhas. Seja então $T$ uma menor árvore com tal propriedade (contraexemplo minimal).
Note que, a menos de isomorfismos, só existe uma árvore com três vértices, e essa tal árvore tem duas folhas. Temos então que $|V(T)| \geq 4$.
Seja $u \in V(T)$ uma folha de $T$, e seja $v \in V(T)$ o único vértice adjacente a $u$ em $T$.
Seja $T^{\prime} = T - u$. Note que $T^{\prime}$ também será uma árvore.
Seja $w \in V(T^{\prime})$ um vértice qualquer de $T^{\prime}$, tal que $w \neq v$. Note que $g_{T^{\prime}}(w) = g_{T}(w)$, e $g_{T^{\prime}}(v) = g_{T}(v) - 1$.
Note que
$$
\begin{aligned}
\sum_{w \in V(T)}^{}g_{T}(w) &= 2|A(T)|\\
\sum_{w \in V(T^{\prime})}^{}g_{T^{\prime}}(w) &= 2|A(T)| - 2\\
\sum_{w \in V(T)}^{}g_{T}(w) - \sum_{w \in V(T^{\prime})}^{}g_{T^{\prime}}(w) &=
2\\
g_{T}(v) - g_{T^{\prime}}(v) &= 2\\
g_{T}(v) + g_{T^{\prime}}(v) + 1 &= 2\\
g_{T^{\prime}}(v)&= 1\\
\end{aligned}
$$
Então $T^{\prime}$ terá a mesma quantidade de folhas que $T$, ou seja, $T^{\prime}$ será uma árvore menor que $T$ com uma quantidade ímpar de folhas, e não pode haver uma árvore $T$ de tamanho mínimo com essa propriedade.

***Prova alternativa:*** Seja $T_{k}$ uma floresta qualquer, e seja $P_{k}$ um maior caminho em $T_{k}$. Note que $A(P_{k}) \subset A(T_{k})$, e $A(P_{k}) = \emptyset \implies A(T_{k}) = \emptyset$.
Caso $A(P_{k}) \neq \emptyset$, seja então $T_{k+1} = T_{k} - A(P_{k})$.
Suponha que $A(P_{k}) \neq \emptyset$.
Então existem $u_{k}, v_{k} \in V(T_{k})$, com $u_{k} \neq v_{k}$ tais que $P_{k} = (u_{k}, \dots, v_{k})$.
Note então que todos os vértices de $V(P_{k})$ devem pertencer a uma mesma componente conexa. Como $T_{k}$ é uma floresta, e $P_{k}$ é um subgrafo conexo de $T_{k}$, então $P_{k}$ é um maior caminho em uma árvore. Portanto $g_{T_{k}}(u_{k}) = g_{T_{k}}(v_{k}) = 1$. Note também que $g_{T_{k+1}}(u_{k}) = g_{T_{k+1}}(v_{k}) = 0$.
Suponha que exista $w_{k} \in V(P_{k})$ tal que $w_{k} \neq u_{k}$ e $w_{k} \neq v_{k}$ (isto é, $w_{k}$) é um vértice interno de $P_{k}$. Temos que $w_{k}$ deve aparecer exatamente uma vez em $P_{k}$, e exatamente duas de suas arestas devem estar em $P_{k}$. Então temos que $g_{T_{k+1}}(w_{k}) = g_{T_{k}}(w_{k}) - 2$. Note que $g_{T_{k}}(w_{k}) \geq 2$.
Seja $n_{k}$ o número de vértices de grau $1$ em $T_{k}$.
Então $n_{k+1} = n_{k} - 2$.
Note que $A(P_{k}) \neq \emptyset \implies n_{k} \geq 2$.
Como $A(P_{k}) = \emptyset \implies A(T_{k}) = \emptyset$, então temos que $A(P_{k}) = \emptyset \implies n_{k} = 0$. Então $A(P_{k}) \neq \emptyset \iff n_{k} \geq 2$.
Seja $T_{0} = T$. Note que $n_{k} = n_{0} - 2k$. Seja $n = n_{0}$ o número de vértices de grau $1$ em $T$.
Note que $A(T_{k}) = A(T) \setminus \bigcup_{i=0}^{k - 1}A(P_{i})$, $A(P_{i}) \subset A(T)$ para todo $i$ tal que $1 \leq i \leq k - 1$, e $A(P_{i}) \cap A(P_{j}) = \emptyset$, para todos $i, j$ tais que $1 \leq i < j \leq k - 1$.
Seja $k$ tal que $n_{k} = 0$. Então $k = \frac{n}{2}$.
Então, temos que $A(T_{k}) = \emptyset \iff k = \frac{n}{2}$.
Note que $k = \frac{n}{2} \iff \emptyset = A(T) \setminus \bigcup_{i=0}^{n/2 - 1}A(P_{i})$, e então $A(T) = \bigcup_{i=0}^{n/2 - 1}A(P_{i})$.
Caso $n \geq 2$, então poderemos gerar uma sequência de $k$ caminhos de $T$, $P_{0}, \dots, P_{k - 1}$, disjuntos nas arestas, e tais que $\bigcup_{i=0}^{k-1} A(P_{k}) = A(T)$, e $n = 2k$.

***Teorema:*** As seguintes afirmações a respeito de um grafo $G$ são equivalentes:

1. $G$ é uma árvore
2. Entre dois vértices de $G$ existe exatamente um caminho.
3. $G$ é um grafo acíclico maximal (isto é, dados dois vértices $u,v \in G$ não adjacentes, $G + uv$ contém exatamente um circuito).
4. $G$ é conexo, e toda aresta de $G$ é uma ponte.

***Prova:***
1 -> 2
Seja $G$ uma árvore, e sejam $u, v \in V(G)$ dois vértices quaisquer de $G$. Como $G$ é conexa, existe ao menos um caminho $P$ de $u$ a $v$ em $G$. Suponha que exista outro caminho, que chamaremos de $P^{\prime}$.
Seja $Q = P \cdot P^{\prime} = (u = w_{0}, \dots, w_{k} = u)$ um passeio fechado em $G$.
Seja $T = (w_{0}, \dots, w_{t})$ uma maior seção de $Q$, começando em $w_{0}$ tal que $T$ seja um caminho (note que $P$ é uma seção de $Q$, começando em $w_{0}$, e $P$ é um caminho, portanto tal seção $T$ deve existir). Então $w_{t+1}$ será igual a exatamente um vértice em $V(T)$. Seja $w_{i}$ tal vértice. Então $(w_{i}, \dots, w_{t + 1})$ será um circuito em $G$, o que é um absurdo, pois $G$ é uma árvore.

2 -> 3
Sejam $u,v$ dois vértices não adjacentes quaisquer de $G$. Temos que existe exatamente um caminho de $v$ a $u$ em $G$. Seja $P = (v = w_{0}, \dots, w_{k} = u)$ esse caminho.
Note que $A(G) \subset A(G + uv)$, e $A(G + uv) \setminus A(G) = \{uv\}$, e $V(G) = V(G + uv)$.
Portanto $P$ também é um caminho de $v$ a $u$ em $G + uv$.
Note que, como $A(P) \subset A(G)$, então $uv \not\in A(P)$.
Então $S = P \cdot (u, uv, v)$ será um circuito em $G + uv$.
Suponha que exista outro circuito $C$ em $G + uv$, tal que $A(C) \neq A(S)$. Note que $uv \in A(C)$, caso contrário $G$ teria um circuito. Então podemos escrever $C = (v, \dots, u) \cdot (u, uv, v) = T \cdot (u, uv, v)$. Então $T$ é um caminho em $G$ de $v$ a $u$, diferente de $P$, o que é um absurdo. Portanto $G + uv$ terá exatamente um circuito, que conterá $uv$.

3 -> 4
Seja $G$ um grafo acíclico. Sabemos que para dois vértices $u,v$ de $G$ não adjacentes, $G + uv$ terá exatamente um circuito, passando por $uv$. Seja $(v, \dots, u) \cdot (u, uv, v) = S \cdot (u, uv, v)$ esse tal circuito. Então $S$ será um caminho de $v$ a $u$ em $G$. Portanto $G$ será conexo.
Seja $e = rs$ uma aresta qualquer de $G$.
Suponha que $G - e$ seja conexo. Então existe um caminho $P$ de $s$ a $r$ em $G - e$. Como $A(P) \subset A(G - e) \subset G$, temos que $e \not\in A(P)$, e $P$ é um caminho de $s$ a $r$ em $G$. Então $P \cdot (r, rs, s)$ será um ciclo em $G$, o que é um absurdo.

4 -> 1
Seja $G$ um grafo conexo tal que todas as suas arestas sejam pontes.
Suponha que $G$ tenha um circuito, a saber, $C = (u, \dots, v)$.
Então considere a aresta $e = vu$ (note que $vu \in A(C)$). Então $(u, \dots, v)$ é um caminho de $u$ a $v$ em $G$, então $e$ não é uma ponte, o que é um absurdo.
Assim, $G$ não tem circuitos.

***Proposição:*** Toda trilha fechada em um grafo simples contém uma seção que é um circuito.
***Prova:*** Seja $T = (v_{0}, v_{1}, \dots, v_{k} = v_{0})$ uma trilha fechada em um grafo $G$ qualquer, de comprimento $k + 1 \geq 3$.
Note que deve existir ao menos uma seção de $T$ que seja um caminho, pois qualquer seção $(v_{i}, v_{i+1})$ de $T$, com $0 \leq i \leq k-1$ será um caminho.
Seja então $Q = (v_{0}, \dots, v_{i})$ uma maior seção de $T$ que seja um maior caminho começando em $v_{0}$.
Note que $v_{i + 1} \in V(Q)$ (caso contrário $(v_{0}, \dots, v_{i+1})$ seria uma seção de $T$ que é um caminho começando em $v_{0}$ maior do que $Q$). Então temos que existe um único vértice em $V(Q)$ que é igual a $v_{i+1}$. Seja $v_{t} \in V(Q)$ esse vértice. Então $(v_{t}, \dots, v_{i+1})$ é um circuito em $T$.

Uma ***árvore geradora*** de um grafo $G$ é um subgrafo gerador de $G$ que é uma árvore.
