# Sequências

Uma sequência é uma função de inteiros positivos (Naturais) a valores reais. Se a cada número natural $n$ é associado um número $a_n$, diz-se que os valores $a_n$ formam uma sequência infinita. Ordenam-se os números segundo seus índices: $a_1, a_2, \dots, a_n, \dots$
Notação para sequência: $\{a_1, a_2, \dots, a_n \dots\} = \{a_n\}_{n \in \mathbb{N}} = \{a_n\}_{n=1}^\infty = \{a_n\}$
Todos esses símbolos denotam a mesma sequência, e o termo $a_n$ é chamado de o n-ésimo termo da sequência.

Exemplos:

(@) Se $a_n = 2^n$, então a sequência é $\{2, 4, 8, \dots\}$
(@) Se $a_n = n$, então a sequência é $\{1, 2, 3, \dots\}$
(@) Dada a sequência $\{0, \frac{1}{2}, \frac{2}{3}, \frac{3}{4}, \frac{4}{5}, \dots\}$, qual seria o n-ésimo termo? $a_n = \frac{n-1}{n}$, com $n \geq 1$.
(@) Dada a sequência $\{\frac{1}{2}, -\frac{1}{2}, \frac{1}{4}, -\frac{3}{4}, \frac{1}{8}, -\frac{7}{8}, \dots\}$, qual seria o n-ésimo termo? $a_{2n - 1} = \frac{1}{2^n}$, e $a_{2n} = -\frac{2n + 1}{2^n}$, para $n \geq 1$.
(@) Outra forma de se escrever uma sequência é por meio de uma relação de recorrência: $a_1 = 2$, $a_{n+1} = \sqrt{2 + a_n}$. Assim, a sequência é: $\{\sqrt{2}, \sqrt{2 + \sqrt{2}}, \sqrt{2 + \sqrt{2 + \sqrt{2}}}\}$.
Um outro exemplo importante é a sequência de Fibonacci dada por: $a_1 = 1$, $a_2 = 1$, e $a_n = a_{n - 1} + a_{n - 2}, \ n \geq 3$. Assim, a sequência de Fibonacci é $\{1, 1, 2, 3, 5, 8, 13, 21, 34, \dots\}$.

Definição: A sequência $\{a_n\}$ tem limite $L$ finito, e escrevemos $\lim_{n \to \infty} a_n = L$, se $a_n$ se aproxima de $L$ ao passo quando $n$ fica maior. Mais formalmente,
$$
\lim_{n \to \infty} a_n = L
\iff
\forall \epsilon(\epsilon > 0 \implies \exists n_0(\forall n(n \geq n_0 \implies |L - a_n| \leq \epsilon)))
$$
Se o limite $L$ existe, dizemos que a sequência é convergente (mais ainda, dizemos que $a_n$ é convergente a $L$). Caso contrário, dizemos que a sequência é divergente.

Se uma sequência $a_n$ provém de uma função $f:[0, +\infty[ \to \mathbb{R}$, isto é, $a_n = f(n)$ e é verdade que $\lim_{x \to + \infty} f(x) = L$, então $a_n$ também converge a $L$. Portanto, podemos aplicar a teoria sobre limites de funções quando falamos de sequências também.
Prova: TODO

Exemplos:

(@) $\lim_{n \to + \infty} e^{-n} = 0$

(@) $\lim_{n \to + \infty} \dfrac{\ln n}{n^a}$

$$
\lim_{n \to + \infty} \dfrac{\ln n}{n^a} \overset{\text{L'hopital}}{=}
\lim_{n \to + \infty} \dfrac{1}{n \cdot an^{a-1}} = \lim_{n \to + \infty} \dfrac{1}{an^a} = 0
$$

(@) $\lim_{n \to + \infty} \sqrt[n]{a}$

$$
\lim_{n \to + \infty} \sqrt[n]{a} = \lim_{n \to + \infty} a ^{\frac{1}{n}} \overset{\text{cont. da exp.}}{=} a ^ {\lim_{n \to + \infty} \frac{1}{n}} = a^0 = 1 \ (\text{para } a > 0)
$$

(@) $\lim_{n \to + \infty} \left(\dfrac{n-1}{n}\right)^n$

$$
\lim_{n \to \infty} \left(\dfrac{n-1}{n}\right)^n = \ ?
$$
Seja $f(x) = \left(\dfrac{x-1}{x}\right)^x$. Entao vamos calcular o limite $\lim_{x \to \infty} f(x)$.
$$
\begin{aligned}
\ln\left(\left(\dfrac{x-1}{x}\right)^x\right) &=
x(\ln(x-1) - \ln(x))\\
x(\ln(x-1) - \ln(x)) &=
\dfrac{\ln(x-1) - \ln(x)}{\dfrac{1}{x}}
\end{aligned}
$$
Entao, temos
$$
\begin{aligned}
\lim_{x \to \infty} \dfrac{\ln(x-1) - \ln(x)}{\dfrac{1}{x}}
&\overset{\text{L'Hopital}}{=}
\lim_{x \to \infty}
\dfrac{\dfrac{1}{x - 1} - \dfrac{1}{x}}{-x^{-2}}\\
\lim_{x \to \infty}
\dfrac{\dfrac{1}{x - 1} - \dfrac{1}{x}}{-x^{-2}} &=
\lim_{x \to \infty}
x - \dfrac{x^2}{x-1}\\
\lim_{x \to \infty}
x - \dfrac{x^2}{x-1} &=
\lim_{x \to \infty}
\dfrac{x^2 - x - x^2}{x-1}\\
\lim_{x \to \infty}
\dfrac{x^2 - x - x^2}{x-1} &=
\lim_{x \to \infty}
\dfrac{- x}{x-1} = -1
\end{aligned}
$$
Entao, como $\lim_{x \to \infty} \ln (f(x)) = -1$, temos que $\lim_{x \to \infty} f(x) = e^{-1}$.

(@) Calcule
$\lim_{n \to \infty} \left(\dfrac{n+a}{n}\right)^n$.
$$
\ln \left(\dfrac{n+a}{n}\right)^n =
\dfrac{(\ln (n + a) - \ln n)}{n^{-1}}
$$
$$
\begin{aligned}
\lim_{x \to \infty}
\dfrac{(\ln (x + a) - \ln x)}{x^{-1}}
&\overset{\text{L'Hopital}}{=}
\lim_{x \to \infty}
\dfrac{(x+a)^{-1} - x^{-1}}{-x^{-2}} \\
\lim_{x \to \infty}
\dfrac{(x+a)^{-1} - x^{-1}}{-x^{-2}} &=
\lim_{x \to \infty}
x - \dfrac{x^2}{x+a}\\
\lim_{x \to \infty}
\dfrac{x^2 + ax - x^2}{x+a}\\
\lim_{x \to \infty}
\dfrac{x^2 + ax - x^2}{x+a} &=
\lim_{x \to \infty}
\dfrac{ax}{x+a} \\
\lim_{x \to \infty}
\dfrac{ax}{x+a} &=
a \lim_{x \to \infty}
\dfrac{x}{x+a} &= a \cdot 1 = a
\end{aligned}
$$
Como $\lim_{x \to \infty} \ln (f(x)) = a$, temos que $\lim_{x \to \infty} f(x) = e^a$.

## Sequências monotônicas

Definição: uma sequência $\{a_n\}$ é dita crescente se (e somente se) $a_n < a_{n + 1}$, para todo $n \geq 1$.
Uma sequência $\{a_n\}$ é dita decrescente se (e somente se) $a_n > a_{n + 1}$, para todo $n \geq 1$.
Uma sequência é dita monotônica se for crescente ou decrescente.

Exemplo:

(@) Seja $f:[1, \infty) \to \mathbb{R}$ uma função crescente $f^\prime(x) > 0$, então $a_n = f(n)$ será uma sequência crescente. A situação é a análoga para funções decrescentes.
Prova: Pelo TVM, temos
$$
f(n + 1) = f^\prime(c) \cdot (n + 1 - n) + f(n)\\
f(n + 1) = f^\prime(c) + f(n)
$$
Onde $n < c < n + 1$. Porém, como $f^\prime(x) > 0$ para todo $x$ no domínio, em especial $x = c$, temos que $f^\prime(c) > 0$, e então
$$
f(n + 1) = f^\prime(c) + f(n) > 0 + f(n) \\
f(n + 1) > f(n)
$$
(@) Mostre que a sequência $\left\{\dfrac{e^{-n}}{n}\right\}$ é decrescente:
$$
f(x) = \dfrac{e^{-x}}{x}\\
f^\prime(x) = \dfrac{-xe^{-x} -e^{-x}}{x^2}\\
f^\prime(x) = -e^{-x} \dfrac{(x + 1)}{x^2}\\
f^\prime(x) \leq 0 \iff
\dfrac{(x + 1)}{x^2} \geq 0\\
f^\prime(x) \leq 0 \iff
x \geq -1
$$
Portanto, para $x \geq 0$, a função é decrescente. Logo, a sequência também é.

## Sequências limitadas

Uma sequência é dita limitada superiormente se existe $M \in \mathbb{R}$ tal que $\forall n(a_n \leq M)$. Analogamente, uma sequência é dita limitada inferiormente se existe $m \in \mathbb{R}$ tal que $\forall n(a_n \geq m)$.

Teorema das sequências monotônicas: Toda sequência crescente e limitada superiormente é convergente.
Prova: Seja $a_n$ uma sequência crescente e limitada superiormente (mais especificamente, por $M \in \mathbb{R}$). Pela completude dos números reais, como o conjunto $\{a_n\}$ é limitado superiormente, deve ter um supremo, isto é, um número $L \in \mathbb{R}$ tal que $\forall x(x \in \{a_n\} \implies x \leq L)$. É fácil ver que no nosso caso, a nossa sequência $a_n$ converge a $L$. Vamos supor então que não seja esse o caso, isto é:
$$
\begin{aligned}
\not \forall \epsilon(
    \epsilon > 0 \implies
    \exists n_0(
        \forall n(
            n \geq n_0 \implies
            |L - a_n| < \epsilon
        )
    )
)\\
\exists \epsilon(
    \epsilon > 0 \wedge
    \not \exists n_0(
        \forall n(
            n \geq n_0 \implies
            |L - a_n| < \epsilon
        )
    )
)\\
\exists \epsilon(
    \epsilon > 0 \wedge
    \forall n_0(
        \not \forall n(
            n \geq n_0 \implies
            |L - a_n| < \epsilon
        )
    )
)\\
\exists \epsilon(
    \epsilon > 0 \wedge
    \forall n_0(
        \exists n(
            n \geq n_0 \wedge
            |L - a_n| \geq \epsilon
        )
    )
)\\
\exists \epsilon(
    \epsilon > 0 \wedge
    \forall n_0(
        \exists n(
            n \geq n_0 \wedge
            L - a_n \geq \epsilon
        )
    )
)\\
\exists \epsilon(
    \epsilon > 0 \wedge
    \forall n_0(
        \exists n(
            n \geq n_0 \wedge
            a_n \leq L - \epsilon
        )
    )
)
\end{aligned}
$$
Como $a_n$ é crescente, para qualquer $i < n$, temos que $a_i < a_n$. Em especial, escolhendo $i \leq n_0$, temos que
$$
\exists \epsilon(
    \epsilon > 0 \wedge
    \forall i(
        a_i \leq L - \epsilon
    )
)
$$
O que contradiz a nossa afirmação que $L$ é o supremo de $a_n$. Portanto, nossa hipótese que $a_n$ não converge a $L$ está errada, e $\lim_{n \to \infty} a_n = L$.

Exemplo:

(@) Determine se a sequência $\{a_n\}$ é convergente, onde $a_i = 2$ e $a_{n+1} = \frac{1}{2} (a_n + 6), \ \text{para } n \geq 1$.

Vamos provar que a sequência é crescente e limitada superiormente. Primeiramente, temos que, para qualquer $n \geq 1$,
$$
\begin{aligned}
a_{n+1} - a_n &= \frac{1}{2} (a_n + 6) - a_n\\
a_{n+1} - a_n &= \frac{a_n}{2} + 3\\
a_{n+1} - a_n > 0 &\iff
\frac{a_n}{2} + 3 > 0\\
a_{n+1} - a_n > 0 &\iff
\frac{a_n}{2} > -3\\
a_{n+1} - a_n > 0 &\iff
a_n > -6
\end{aligned}
$$
Isto é, $\{a_n\}$ é crescente se e somente se $a_n > -6$ para todo $n \in \mathbb{N}$. A seguir provamos isso por indução.
Suponha que $a_n > -6$. Então:
$$
\begin{aligned}
a_{n + 1} = \frac{1}{2} (a_n + 6) &>
\dfrac{1}{2} (-6 + 6)\\
a_{n + 1} &> \dfrac{1}{2} \cdot 0\\
a_{n + 1} &> 0\\
a_{n + 1} &> -6
\end{aligned}
$$
Então temos que $a_n > -6 \implies a_{n+1} > -6$. Para completar a indução, basta observar que $a_1 = 2 > -6$. Provamos então que $\{a_n\}$ é crescente.
Vamos provar agora então que $a_n$ é limitada superiormente, vamos supor, por $6$:
$$
\begin{aligned}
a_n < 6 &\implies
a_{n+1} = \frac{1}{2} (a_n + 6) <
\dfrac{1}{2} (6 + 6)\\
a_n < 6 &\implies
a_{n+1} <
\dfrac{1}{2} \cdot 12\\
a_n < 6 &\implies
a_{n+1} < 6
\end{aligned}
$$
Para completar nossa prova por indução, basta observar que $a_1 = 2 < 6$.
Provamos então que a sequência $\{a_n\}$ é crescente e limitada. Portanto, pelo teorema das sequências monotônicas, ela também é convergente. Vamos agora descobrir para qual valor ela converge.
Podemos dizer que $\lim_{n \to \infty} a_n = L$. Porém, também é verdade que $\lim_{n \to \infty} a_{n + 1} = L$, então, temos:
$$
\begin{aligned}
L &= \lim_{n \to \infty} a_{n + 1} =
\lim_{n \to \infty} \dfrac{1}{2}(a_n + 6)\\
L &=  
3 + \dfrac{1}{2} \lim_{n \to \infty} a_n\\
L &=  
3 + \dfrac{1}{2} L\\  
3 &= \dfrac{1}{2} L\\
L &= 6
\end{aligned}
$$

(@) $\lim_{n \to \infty}\dfrac{\sin(\frac{1}{2^n})}{\frac{1}{2^n}}$

Como $\lim_{n \to \infty} \frac{1}{2^n} = 0$, então
$$
\begin{aligned}
\lim_{n \to \infty}
\dfrac{\sin(\frac{1}{2^n})}
{\frac{1}{2^n}} &=
\lim_{x \to 0} \dfrac{\sin{x}}{x}\\
\lim_{n \to \infty}
\dfrac{\sin(\frac{1}{2^n})}
{\frac{1}{2^n}} &= 1
\end{aligned}
$$

(@) $\lim_{n \to \infty}\arctan{\left(\dfrac{1}{n}\right)}$

Como $\lim_{n \to \infty} \frac{1}{n} = 0$, então
$$
\begin{aligned}
\lim_{n \to \infty}
\arctan{
\left(\dfrac{1}{n}\right)
}
&=
\lim_{x \to 0} \arctan{(x)}\\
\lim_{n \to \infty}
\arctan{
\left(\dfrac{1}{n}\right)
}
&=0
\end{aligned}
$$

(@) $\lim_{n \to \infty}\ln{n}$

Vamos supor que o limite exista, e $\lim_{n \to \infty}\ln{n} = L$.
Isso significaria que
$$
\forall \epsilon(\epsilon > 0 \implies \exists n_0(\forall n(n \geq n_0 \implies |L - \ln n| < \epsilon)))
$$

Porém, temos que $\ln n$ é crescente, e então $n > e^L \implies \ln n > L$. Então a sequência $\ln n$ não converge.
$$
\frac{d}{dx} \sin \frac{1}{x} = -\frac{\cos(\frac{1}{x})}{x²}
$$
$$
x > 1 \implies 0 < 1/x < 1 < \frac{\pi}{2} \implies
\cos (1/x) > 0
$$

## Subsequências

[Subsequência]{#def:subsequencia}
: Uma ***subsequência*** de $\{a_{n}\}$ é uma restrição da aplicação $n \to a_{n}$ a um subconjunto finito da forma
$$
N^{\prime} = \{n_{1} < n_{2} < \ldots < n_{k} < \ldots\}
$$
A subsequência é denotada pela notação $\{a_{n}\}_{n \in N^{\prime}}$

Exemplo: A sequência $2^{n}$ possui a subsequência $4^{k}$.

[]{#thm:subseq}
: Se $\lim_{n \to \infty} a_{n} = L$, então toda subsequência de $\{a_{n}\}$ converge para $L$.

[]{#cor:subseq}
: Se uma sequência possui subsequências que convergem para valores diferentes, então a sequência original diverge.
