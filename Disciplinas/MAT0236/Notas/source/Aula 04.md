# Funções diferenciáveis

## Noções de topologia

[Bola aberta]{#def:bola_aberta}
: Dado um conjunto $S$ e um ponto $p_{0} \in S$, a ***bola aberta de centro $p_{0}$ e raio $r$*** é o conjunto $\{p | r > |p - p_{0}|\}$. Note que $r$ deve ser maior do que $0$.  
Denotamos esse conjunto por $B(p_{0}, r)$.

[Ponto interior]{#def:ponto_interior}
: Um ponto $p$ é dito ***interior*** a um conjunto $S$ se existe alguma bola aberta $B(p, r)$ tal que $B(p, r) \subseteq S$.  
Um *conjunto* $A$ é dito ***interior a $S$*** se todos os pontos de $A$ são interiores a $S$.  
O ***interior de $S$*** é o conjunto de todos os pontos interiores a $S$. Podemos também dizer que o interior de $S$ é o maior conjunto que é interior a $S$.

[Conjunto aberto]{#def:conjunto_aberto}
: Um conjunto $S$ é dito ***aberto*** se todo ponto de $S$ é interior a $S$. Nesse caso, o interior de $S$ coincide com $S$.

[Ponto exterior]{#def:ponto_exterior}
: Um ponto $p_{0}$ é dito ***exterior*** a um conjunto $S$ se $p \not\in S$ e existe uma bola aberta $B(p_{0}, r)$ tal que $B(p_{0}, r) \cap S = \emptyset$. Um conjunto $A$ é dito ***exterior a $S$*** se todos os seus pontos são exteriores a $S$.

[Conjunto fechado]{#def:conjunto_fechado}
: Um conjunto $S$ é dito ***fechado*** se todos os pontos que não pertencem a $S$ são exteriores a $S$. Podemos também dizer que um conjunto é dito fechado se seu *complemento* é aberto.

[Ponto fronteira]{#def:ponto_fronteira}
: Um ponto $p$ é dito ***fronteira*** de um conjunto $S$ se $p$ não é nem interior nem exterior a $S$. Podemos também dizer que $p$ é um ponto fronteira de $S$ se toda bola aberta de centro $p$ contém tanto pontos interiores e exteriores a $S$.  
A ***fronteira de $S$*** é o conjunto de todos os pontos fronteira de $S$. Podemos então dizer que um conjunto $S$ será fechado se e somente se sua fronteira for um subconjunto de $S$.

[Fecho de um conjunto]{#def:fecho_de_um_conjunto}
: O ***fecho*** de um conjunto $S$ é a união de $S$ com a sua fronteira. Podemos então dizer que um conjunto $S$ será fechado se e somente se for igual ao seu fecho.  
Podemos dizer também que o fecho de $S$ é o menor conjunto fechado que contém $S$.

[Vizinhança]{#def:vizinhanca}
: Um conjunto $S$ é dito ***vizinhança*** de $p_{0}$ se $p_{0}$ for um ponto interior a $S$.  
Note que toda bola aberta de centro $p_{0}$ é uma vizinhança de $p_{0}$, mas nem toda vizinhança de $p_{0}$ precisa ser uma bola aberta.

[Ponto de acumulação]{#def:ponto_de_acumulacao}
: Um ponto $p \in S$ é dito ***ponto de acumulação*** de $S$ se toda vizinhança de $p$ contiver infinitos pontos de $S$. Caso contrário $p$ é chamado de ***ponto isolado***.

## Limite

[Limite]{#def:limite}
: Seja $f : S \to \mathbb{R}^{m}$ um campo vetorial. Se $\mathbf{a} \in S$ e $\mathbf{b} \in \mathbb{R}^{m}$, escrevemos
$$
\begin{aligned}
\lim_{\mathbf{x} \to \mathbf{a}} f(\mathbf{x}) = \mathbf{b}
\end{aligned}
$$
Para indicar que
$$
\begin{aligned}
\lim_{||\mathbf{x} - \mathbf{a}|| \to 0} ||f(\mathbf{x}) - \mathbf{b}|| = 0
\end{aligned}
$$
Se escrevermos $\mathbf{x} - \mathbf{a}$ como $\mathbf{h}$, então a equação acima fica
$$
\begin{aligned}
\lim_{||h|| \to 0} ||f(\mathbf{a} + \mathbf{h}) - \mathbf{b}|| = 0
\end{aligned}
$$

## Continuidade

[Continuidade]{#def:continuidade}
: Seja $f : D \to R$ uma função e $p_{0} \in D$ um ponto de acumulação de $D$. A função $f$ é dita ***contínua em $p_{0}$*** se, dado qualquer número real $\varepsilon > 0$, existe uma vizinhança $U$ de $p_{0}$ tal que $|f(p) - f(p_{0})| < \varepsilon$ para todo $p \in U$.  
A função é dita ***contínua em $D$*** se for contínua para cada ponto de $D$.

Podemos escrever essa definição acima também como:  
Seja $f : S \to \mathbf{R}^{m}$ um campo vetorial, e $\textbf{a} \in S$ um ponto em que $f$ está definida. Então temos que f é ***contínua em $\mathbf{a}$*** se e somente se
$$
\begin{aligned}
\lim_{\textbf{x} \to \textbf{a}} f(\textbf{x}) = f(\textbf{a})
\end{aligned}
$$

## Derivada

[Derivada de um campo escalar em relacao a um vetor]{#def:derivada_de_um_campo_escalar_em_relacao_a_um_vetor}
: Dado um campo escalar $f : S \subseteq \mathbb{R}^{n} \to \mathbb{R}$, e $\textbf{a}$ um ponto interior de $S$, e $\textbf{y} \in R^{n}$ um ponto qualquer, denotamos a ***derivada de $f$ em relação a $\textbf{y}$ no ponto $\textbf{a}$*** pelo símbolo $f^{\prime}(\textbf{a};\textbf{y})$, e a definimos como:
$$
\begin{aligned}
f^{\prime}(\textbf{a};\textbf{y}) =
\lim_{h \to 0} \frac{f(\textbf{a} + h \textbf{y}) - f(\textbf{a})}{h}
\end{aligned}
$$
Quando o limite existe.

[]{#prop:deriv1}
: Seja $g(t) = f(\textbf{a} + t \textbf{y})$. Então temos que:
$$
\begin{aligned}
g^{\prime}(t) = f^{\prime}(\textbf{a} + t \textbf{y};\textbf{y})
\end{aligned}
$$
E, em particular,
$$
\begin{aligned}
g^{\prime}(0) = f^{\prime}(\textbf{a};\textbf{y})
\end{aligned}
$$

### Derivadas direcionais e derivadas parciais

[Derivada direcional]{#def:derivada_direcional}
: Seja $f : S \to \mathbb{R}$ um campo escalar, $\textbf{a} \in S$ um ponto qualquer para o qual $f$ esteja definida, e $\textbf{y} \in \mathbb{R}^{n}$ tal que $||\textbf{y}|| = 1$. Então $f^{\prime}(\textbf{a};\textbf{y})$ é chamada de ***derivada de $f$ em direção a $\textbf{y}$ em $\textbf{a}$***.

[Derivada parcial]{#def:derivada_parcial}
: Seja $f : S \to \mathbb{R}^{m}$ um campo escalar, e $\textbf{a} \in S$ um ponto para a qual $f$ está definida. Então a ***derivada parcial de $f$ em relação a $\textbf{e}_{k}$ em $\textbf{a}$***, denotada por $\frac{\partial{f}}{\partial{x_k}}$ é definida como:
$$
\begin{aligned}
\frac{\partial{f(\textbf{a})}}{\partial{x_{k}}} = f^{\prime}(\textbf{a};\textbf{e}_k)
\end{aligned}
$$

Exemplo: Seja $f(x,y) = x^{2} + 2xy$. Então temos que:
$$
\begin{aligned}
\frac{\partial{f}}{\partial{x}} &= f^{\prime}((x,y);(1,0))\\
\frac{\partial{f}}{\partial{x}} &=
\lim_{h \to 0} \frac{f((x,y) + h(1,0)) - f(x,y)}{h}\\
\frac{\partial{f}}{\partial{x}} &=
\lim_{h \to 0} \frac{f(x + h,y) - f(x,y)}{h}\\
\frac{\partial{f}}{\partial{x}} &=
\lim_{h \to 0} \frac{
(x + h)^{2} + 2(x + h)y - x^{2} - 2xy
}{h}\\
\frac{\partial{f}}{\partial{x}} &=
\lim_{h \to 0} \frac{
x^{2} + h^{2} + 2xh + 2xy + 2hy - x^{2} - 2xy
}{h}\\
\frac{\partial{f}}{\partial{x}} &=
\lim_{h \to 0} \frac{h^{2} + 2xh + 2hy}{h}\\
\frac{\partial{f}}{\partial{x}} &=
\lim_{h \to 0} h + 2x + 2y\\
\frac{\partial{f}}{\partial{x}} &= 2(x + y)
\end{aligned}
$$

### Derivada total e gradiente

[Derivada total]{#def:derivada_total}
: Seja $f : S \to \mathbb{R}$ um campo escalar, e $\textbf{a} \in S$ um ponto interior de $S$. Dizemos que ***$f$ é diferenciável em $\textbf{a}$*** se existe uma transformação linear $T_{\textbf{a}} : S \to R$, e uma função escalar $E(\textbf{a}, \textbf{v})$ tais que
$$
\begin{aligned}
f(\textbf{a} + \textbf{v}) =
f(\textbf{a}) + T_{\textbf{a}}(\textbf{v}) +
||\textbf{v}|| E(\textbf{a}, \textbf{v})
\end{aligned}
$$
e
$$
\begin{aligned}
\lim_{||\textbf{v}|| \to 0} E(\textbf{a}, \textbf{v}) = 0
\end{aligned}
$$
Além disso, chamamos $T_{\textbf{a}}$ de ***derivada total de $f$ em $\textbf{a}$***.

[Gradiente]{#def:gradiente}
: Seja $f : S \subseteq \mathbb{R}^{n} \to \mathbb{R}$ um campo escalar, tal que $f(\textbf{x}) = f(x_{1}, \ldots, x_{n})$. Então o ***gradiente*** de $f$ em $\textbf{a} = (a_{2}, \ldots, a_{n}) \in S$, denotado por $\nabla f(\textbf{a})$ é definido como:
$$
\begin{aligned}
\nabla f(\textbf{a}) =
\left(
    \frac{\partial{f}(\textbf{a})}{\partial{x_{1}}}, \ldots,
    \frac{\partial{f}(\textbf{a})}{\partial{x_{n}}}
\right)
\end{aligned}
$$
