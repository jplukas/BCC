# Séries

[Série]{#def:serie}
: Considere uma sequência $a_{n}$. Então a somatória
$$
\sum_{i=1}^{\infty} a_{i}
$$
É chamada de ***série*** associada a $a_{n}$.
Seja $S_{n} = \sum_{i=1}^{n} a_{i}$, a soma dos $n$ primeiros termos da sequência. Chamamos então $S_{n}$ de ***soma parcial dos $n$ primeiros termos de $a_{n}$***.
Dizemos que a série $\sum_{i=1}^{\infty} a_{i}$ tem uma soma ***finita*** quando existe o limite $\lim_{n \to \infty} S_{n}$. Quando esse limite existe e é um número real, digamos, $L$, dizemos que a série ***converge*** a $L$, e escrevemos
$$
\sum_{i=1}^{\infty} a_{i} = L
$$

Veremos que às vezes é possível encontrar uma fórmula fechada para $S_{n}$, mas às vezes não.
Exemplos:

(@) $a_{n} = n$
Note que $S_{n} = \frac{n(n+1)}{2}$, e $\lim_{n \to \infty} \sum_{i=1}^{n}a_{i} = \infty$. Ou seja, a série *diverge*.

(@) Seja $a \neq 0$ real, e considere a série $\sum_{n=1}^{\infty}ar^{n-1}$, onde $r$ é chamada ***razão*** da série. Tal série é denominada ***série geométrica de razão $r$***.
Note que:
$$
S_{n} = \frac{a(r^{n - 1} - 1)}{r - 1}
$$
Assim, para um mesmo valor de $a$, temos $3$ situações possíveis:

    1. Para $|r| < 1$, temos que:
    $$
    \begin{aligned}
    \lim_{n \to \infty} S_{n} &= \frac{a(-1)}{r-1}\\
    \sum_{n=1}^{\infty}a_{n} &= \frac{a}{1-r}
    \end{aligned}
    $$

    2. Para $r > 1$, temos:
    $$
    \begin{aligned}
    \lim_{n \to \infty} S_{n} = \infty
    \end{aligned}
    $$
    Portanto $\sum_{n=1}^{\infty} a_{n}$ *diverge* para $\infty$.

    3. Para $r=1$, $\sum_{n=1}^{\infty} a_{n}$ *diverge*.

(@harm_s) Considere a série $\sum_{n=1}^{\infty} \frac{1}{n}$. Essa série é denominada ***série harmônica***.
Note que
$$
\begin{aligned}
\int_{1}^{n} \frac{1}{x} &\leq S_{n}\\
\ln n &\leq S_{n}
\end{aligned}
$$
E como $\lim_{n \to \infty} \ln n = \infty$, logo, $\lim_{n \to \infty} \sum_{i=1}^{\infty} \frac{1}{n} = \infty$, e a série harmônica *diverge*. Note que nesse caso, não precisamos encontrar uma fórmula fechada para $S_{n}$, mas mesmo assim conseguimos decidir sobre a convergência da série.

(@harm_g) Considere agora a série $\sum_{n=1}^{\infty} \frac{1}{n^{\alpha}}$. Essa série é denominada ***série harmônica generalizada***.
Note que:
$$
\begin{aligned}
\int_{1}^{n} \frac{1}{x^{\alpha}} \leq S_{n} \leq 1 + \int_{1}^{n} \frac{1}{x^{\alpha}}
\end{aligned}
$$
Já vimos que, no caso de $\alpha = 1$, a série é *divergente*.
É facil ver, pelo [Critério da comparação](#thm:crit_comp) que, para $\alpha < 1$, a série também diverge.
Para $\alpha > 1$, por outro lado, note que:
$$
\begin{aligned}
\int_{}^{}\frac{1}{x^{\alpha}}  dx = \frac{x^{1-\alpha}}{1-\alpha} + C
\end{aligned}
$$
E então,
$$
\begin{aligned}
\int_{1}^{n} \frac{1}{x^{\alpha}}  dx &=
\frac{n^{1-\alpha}}{1-\alpha} - \frac{1^{1-\alpha}}{1-\alpha}\\
\int_{1}^{n} \frac{1}{x^{\alpha}}  dx &=
\frac{n^{1-\alpha}}{1-\alpha} - \frac{1}{1-\alpha}\\
\end{aligned}
$$
Assim, temos que:
$$
    \begin{aligned}
    \int_{1}^{\infty} \frac{1}{x^{\alpha}}  dx &=
    \lim_{n \to \infty}\frac{n^{1-\alpha}}{1-\alpha} - \frac{1}{1-\alpha}\\
    \int_{1}^{\infty} \frac{1}{x^{\alpha}}  dx &=
    - \frac{1}{1-\alpha}\\
    \int_{1}^{\infty} \frac{1}{x^{\alpha}}  dx &=
    \frac{1}{\alpha - 1}\\
    \end{aligned}
$$
Então, para $\alpha > 1$, temos que $\sum_{n=1}^{\infty} \frac{1}{n^{\alpha}}$ será convergente, e
$$
\begin{aligned}
\frac{1}{\alpha - 1} \leq \sum_{n=1}^{\infty} \frac{1}{n^{\alpha}} \leq 1 + \frac{1}{\alpha - 1}
\end{aligned}
$$

## Propriedades de séries convergentes

[]{#thm:comb_conv}
: Se $\sum_{n=1}^{\infty}a_{n}$ e $\sum_{n=1}^{\infty}b_{n}$ forem séries convergentes, com $\sum_{n=1}^{\infty}a_{n} = A$, e $\sum_{n=1}^{\infty}b_{n} = B$, então:

    1. $\sum_{n=1}^{\infty}ca_{n} = cA$, onde $c \in \mathbb{R}$ é uma constante.
    2. $\sum_{n=1}^{\infty}(a_{n} \pm b_{n}) = (A \pm B)$.

[]{#thm:comb_div}
: Se $\sum_{n=1}^{\infty} a_{n}$ é convergente, e $\sum_{n=1}^{\infty} b_{n}$ é divergente, então $\sum_{n=1}^{\infty} (a_{n} + b_{n})$ é divergente.

## Séries telescópicas

[Série telescópica]{#def:serie_telescopica}
: Considere a série $\sum_{n=1}^{\infty} a_{n}$ tal que $a_{k} = b_{k} - b_{k + 1}$, para alguma sequência $b_{k}$, com $k \geq 1$. Uma tal série é denominada ***série telescópica***.
Seja $S_{n}$ a soma parcial de ordem $n$ da série. Então temos que:
$$
\begin{aligned}
S_{n} &= \sum_{i=1}^{n}a_{i}\\
S_{n} &= \sum_{i=1}^{n}(b_{i} - b_{i+1})\\
S_{n} &= \sum_{i=1}^{n} b_{i} - \sum_{i=2}^{n + 1} b_{i}\\
S_{n} &= b_{1} - b_{n+1}
\end{aligned}
$$
Assuma que o limite $\lim_{n \to \infty} b_{n} = b$ exista, então temos:
$$
\begin{aligned}
\sum_{n=1}^{\infty} a_{n} = b_{1} - b
\end{aligned}
$$

## Critérios de convergência para séries

### Critério do termo geral

[]{#thm:termo_geral}
: Seja $\sum_{n=1}^{\infty} a_{n}$ uma série convergente. Então $\lim_{n \to \infty} a_{n} = 0$.

### Critérios para séries alternadas

Uma série cujos termos são alternadamente positivos e negativos é denominada uma ***série alternada***.
Seja $\sum_{n=1}^{\infty} a_{n}$ uma tal série. Podemos então escrever essa série como $\sum_{n=1}^{\infty}(-1)^{n}b_{n}$, onde $b_{n}$ é uma sequência de termos **estritamente** positivos (no caso, $n$ pode ser substituído por $n + 1$, caso a série comece com um termo positivo).

[Critério para séries alternadas]{#thm:crit_series_alt}
: Seja $\sum_{n=1}^{\infty}(-1)^{n}a_{n}$ uma série alternada. Se a sequência $a_{n}$ for decrescente (a partir de algum índice $n_{0}$), e $\lim_{n \to \infty} a_{n} = 0$, então a série será convergente.

### Critérios para séries de termos positivos

$\sum_{n=1}^{\infty} a_{n}$ é uma ***série de termos positivos*** se, para todo $n$, $a_{n} \geq 0$.

[Critério da integral]{#thm:crit_integ}
: Seja $f : [1, \infty) \to (0, \infty)$ contínua e decrescente. Defina $a_{n} = f(n)$. Então temos que $\sum_{n=1}^{\infty} a_{n}$ é convergente se e somente se $\int_{1}^{\infty}f(x) dx$ também for.

[Critério da comparação]{#thm:crit_comp}
: Sejam $a_{n}$ e $b_{n}$ duas sequências de termos positivos, tais que existe algum $n_{0} \in \mathbb{N}$ tal que para todo $n \geq n_{0}$, $a_{n} \leq b_{n}$. Então, se $\sum_{n=1}^{\infty} b_{n}$ for convergente, $\sum_{n=1}^{\infty} a_{n}$ também será (e se $\sum_{n=1}^{\infty} a_{n}$ for divergente, $\sum_{n=1}^{\infty} b_{n}$ também será).

[Critério da comparação no limite]{#thm:crit_comp_lim}
: Sejam $a_{n}$ e $b_{n}$ duas sequências de termos **estritamente** positivos. Considere o limite $\lim_{n \to \infty} \frac{a_{n}}{b_{n}}$.

    1. Caso o limite exista e seja um número real positivo, então $\sum_{n=1}^{\infty}a_{n}$ será convergente se e somente $\sum_{n=1}^{\infty}b_{n}$ também for.
    2. Caso o limite exista e seja zero, então se $\sum_{n=1}^{\infty}b_{n}$ for convergente, $\sum_{n=1}^{\infty}a_{n}$ também será.
    3. Caso o limite exista e seja infinito, então se $\sum_{n=1}^{\infty}b_{n}$ for divergente, $\sum_{n=1}^{\infty}a_{n}$ também será

[Critério da razão]{#thm:crit_razao}
: Seja a série $\sum_{n=1}^{\infty} a_{n}$ uma série de termos **estritamente** positivos (após algum índice $n_{0}$ qualquer). Suponha que o limite $\lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} = L$ exista, seja ele finito ou infinito. Então temos:

    1. Se $L < 1$, a série é convergente
    2. Se $L > 1$ ou $L = \infty$, a série é divergente
    3. Se $L = 1$, o critério nada revela

[Critério da raiz]{#thm:crit_raiz}
: Seja a série $\sum_{n=1}^{\infty} a_{n}$ uma série de termos **estritamente** positivos (após algum índice $n_{0}$ qualquer). Suponha que o limite $\lim_{n \to \infty} \sqrt[n]{a_{n}} = L$ exista, seja ele finito ou infinito. Então temos:

    1. Se $L < 1$, a série é convergente
    2. Se $L > 1$ ou $L = \infty$, a série é divergente
    3. Se $L = 1$, o critério nada revela
