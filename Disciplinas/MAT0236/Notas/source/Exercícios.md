# Exercícios

## Sequências

1. Decida se cada uma das sequências é convergente ou divergente, calculando o limite no caso convergente:

    1. $0, \frac{1}{2}, \frac{2}{3}, \frac{3}{4}, \frac{4}{5}, \frac{5}{6}, \frac{6}{7}, \ldots$

        $$
        \begin{aligned}
        a_n &= \dfrac{n-1}{n}\\
        \lim_{n \to \infty} a_{n} &= \lim_{n \to \infty} \frac{n-1}{n}\\
        \lim_{n \to \infty} a_{n} &=1
        \end{aligned}
        $$
        A sequência **converge para $1$**.

    2. $\frac{1}{2}, -\frac{1}{2}, \frac{1}{4}, -\frac{3}{4}, \frac{1}{8}, -\frac{7}{8}, \ldots$

        $$
        \begin{aligned}
        a_{2n - 1} &= \dfrac{1}{2^n}\\
        a_{2n} &= \dfrac{1}{2^{n-1}} -1
        \end{aligned}
        $$
        Temos então, dentro da mesma sequência $a_n$, duas subsequências distintas, e
        $$
        \begin{aligned}
        \lim_{n \to \infty}a_{2n - 1} &= 0\\
        \lim_{n \to \infty}a_{2n} &= -1
        \end{aligned}
        $$
        Como as subseqências convergem para valores diferentes, então a sequência original é **divergente**.

    3. $a_n = \left(4 + \frac{1}{n}\right)^{\frac{1}{2}}$

        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \left(4 + \frac{1}{n}\right)^{\frac{1}{2}}\\
        \lim_{n \to \infty} a_{n} &=
        \left(4 + \left(
            \lim_{n \to \infty} \frac{1}{n}
            \right)\right)^{\frac{1}{2}}\\
        \lim_{n \to \infty} a_{n} &=
        \left(4 + 0\right)^{\frac{1}{2}}\\
        \lim_{n \to \infty} a_{n} &= 2
        \end{aligned}
        $$
        A sequência **converge para $2$**.

    4. $a_{n} = \frac{\sqrt[]{n}+1}{n-1},\  n \geq 2$

        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \frac{\sqrt[]{n}+1}{n-1}\\
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \frac{\sqrt[]{n}}{n-1} +
        \lim_{n \to \infty} \frac{1}{n-1}\\
        \lim_{n \to \infty} a_{n} &= 0 + 0\\
        \lim_{n \to \infty} a_{n} &= 0
        \end{aligned}
        $$
        A sequência **converge para $0$**.

    5. $a_{n} = \frac{n³+3n+1}{4n³+2}$

        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \frac{n³+3n+1}{4n³+2}\\
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \frac{n³}{4n³+2} +
        \lim_{n \to \infty} \frac{3n}{4n³+2} +
        \lim_{n \to \infty} \frac{1}{4n³+2}\\
        \lim_{n \to \infty} a_{n} &=
        \frac{1}{4} + 0 + 0\\
        \lim_{n \to \infty} a_{n} &= \frac{1}{4}
        \end{aligned}
        $$
        A sequência **converge para $\frac{1}{4}$**.

    6. $a_{n} = \sqrt[]{n+1} - \sqrt[]{n}$

        Como $a_{n} = \sqrt[]{n+1} - \sqrt[]{n} = \frac{n + 1 - n}{\sqrt[]{n+1} + \sqrt[]{n}} = \frac{1}{\sqrt[]{n+1} + \sqrt[]{n}}$, então temos
        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \sqrt[]{n+1} + \sqrt[]{n}\\
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \frac{1}{\sqrt[]{n+1} + \sqrt[]{n}}\\
        \lim_{n \to \infty} a_{n} &= 0
        \end{aligned}
        $$
        A sequência **converge para $0$**.

    7. $a_{n} = \frac{n+(-1)^n}{n-(-1)^n}$

        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \frac{n+(-1)^n}{n-(-1)^n} \\
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty}
        \frac{1+(-1)^n/n}{1-(-1)^n/n}\\
        \lim_{n \to \infty} a_{n} &=
        \frac{1 + 0}{1 - 0}\\
        \lim_{n \to \infty} a_{n} &=1
        \end{aligned}
        $$
        A sequência **converge para $1$**.

    8. $a_{n} = \frac{2n}{n+1} - \frac{n+1}{2n}$

        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \frac{2n}{n+1} - \frac{n+1}{2n} \\
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \frac{2n}{n+1} - \lim_{n \to \infty} \frac{n+1}{2n}\\
        \lim_{n \to \infty} a_{n} &= 2 - \frac{1}{2}\\
        \lim_{n \to \infty} a_{n} &= \frac{3}{2}
        \end{aligned}
        $$
        A sequência **converge para $\frac{3}{2}$**.

    9. $a_{n} = \frac{\sin n}{n}$

        Como $|\sin n| \leq 1$ e $\lim_{n \to \infty} \frac{1}{n} = 0$, temos, pelo teorema do confronto, que $\lim_{n \to \infty} \frac{\sin n}{n} = 0$.
        A sequência **converge para $0$**.

    10. $a_{n} = \left( \frac{3n+5}{5n+11} \right)^n$

        $\ln (\left( \frac{3n+5}{5n+11} \right)^n) = n \ln (\frac{3n + 5}{5n+11})$
        Como $\lim_{n \to \infty} n = \infty$, e $\lim_{n \to \infty} \ln (\frac{3n+5}{5n+11}) = ln(3/5) < 0$, então $\lim_{n \to \infty} n \ln (\frac{3n + 5}{5n+11}) = -\infty$.
        Então $\lim_{n \to \infty} \left(\frac{3n+5}{5n+11}\right)^n = \lim_{u \to -\infty} e^u = 0$.
        A sequência **converge para $0$**.

    11. $a_{n} = \frac{(n+3)!-n!}{(n+4)!}$

        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \left(\frac{(n+3)!}{(n+4)!} - \frac{n!}{(n+4)!}\right)\\
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \left(\frac{1}{(n+4)} - \frac{1}{(n+4)(n+3)(n+2)(n+1)}\right)\\
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \frac{1}{(n+4)} -
        \lim_{n \to \infty} \frac{1}{(n+4)(n+3)(n+2)(n+1)}\\
        \lim_{n \to \infty} a_{n} &= 0 - 0\\
        \lim_{n \to \infty} a_{n} &=0
        \end{aligned}
        $$

        A sequência **converge para $0$**.

    12. $a_{n} = \frac{n\sin(n!)}{n^{2}+1}$

        $$
        a_{n} = \frac{n}{n^{2} + 1} \sin(n!)
        $$

        Temos que $|\sin(n!)| \leq 1$. Além disso:

        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{n}{n^{2} + 1} = 0
        \end{aligned}
        $$

        Portanto, $\lim_{n \to \infty} a_{n} = 0$.

        A sequência **converge para $0$**.

    13. $a_{n} = \left(\frac{n+1}{n+2}\right)^n$

        Seja $u=n+2$, (e $n=u-2$). Então $a_{n} = \left(\frac{u-1}{u}\right)^{u-2}$.
        Então temos:
        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{u \to \infty} \left(\frac{u-1}{u}\right)^{u-2}\\
        \lim_{n \to \infty} a_{n} &=
        \lim_{u \to \infty} \left(\frac{u-1}{u}\right)^{u} \cdot
        \lim_{u \to \infty} \left(\frac{u}{u-1} \right)^{2}\\
        \lim_{n \to \infty} a_{n} &= e^{-1} \cdot 1^2 = e^{-1}
        \end{aligned}
        $$
        A sequência **converge para $e^{-1}$**.

    14. $a_{n} = \sqrt[n]{n}$

        Temos que $\ln \sqrt[n]{n} = \frac{\ln n}{n}$, e
        $\lim_{n \to \infty} \frac{\ln n}{n} = 0$.
        Então, $\lim_{n \to \infty} a_n = e^0 = 1$.
        A sequência **converge para $1$**.

    15. $a_{n} = \left(\frac{n+1}{n}\right)^{\sqrt[]{n}}$

        Como $\sqrt[]{n} = n^{\frac{1}{2}}$.
        Seja $u = \sqrt{n}$. Então $a_{n} = \left(\frac{u^{2}+1}{u^{2}}\right)^{u}$
        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{u \to \infty} \left(\frac{u^{2}+1}{u^{2}}\right)^{u}\\
        \lim_{n \to \infty} a_{n} &=
        e^{\lim_{u \to \infty} \ln\left(\frac{u^{2}+1}{u^{2}}\right)^{u}}\\
        \lim_{n \to \infty} a_{n} &=
        e^{\lim_{u \to \infty} \frac{\ln\left(\frac{u^{2}+1}{u^{2}}\right)}{\frac{1}{u}}}\\
        \lim_{n \to \infty} a_{n} &=
        e^{\lim_{u \to \infty}
        \frac{
            \frac{u^{2}}{u^{2} + 1}
            \left(
                \frac{2u(u^2) - 2u(u^2 + 1)}{u^{4}}
            \right)
        }
        {-\frac{1}{u^{2}}}}\\
        \lim_{n \to \infty} a_{n} &=
        e^{\lim_{u \to \infty}
        \frac{2u(u^2 + 1) - 2u(u^2)}{u^{2} + 1}
        }\\
        \lim_{n \to \infty} a_{n} &=
        e^{\lim_{u \to \infty}
        \frac{2u}{u^{2} + 1}
        }\\
        \lim_{n \to \infty} a_{n} &=
        e^0\\
        \lim_{n \to \infty} a_{n} &= 1
        \end{aligned}
        $$
        A sequencia converge para $1$.

    16. $a_{n} = \frac{2n + \sin (n)}{5n+1}$.

        $$
        \begin{aligned}
        \lim_{n \to \infty} a_n &=
        \lim_{n \to \infty} \frac{2n}{5n+1} +
        \lim_{n \to \infty} \frac{\sin n}{5n+1}\\
        \lim_{n \to \infty} a_n &= \frac{2}{5} + 0\\
        \lim_{n \to \infty} a_n &= \frac{2}{5}
        \end{aligned}
        $$
        A sequência **converge para $\frac{2}{5}$**.

    17. $a_{n} = (1 + \frac{1}{n²})^n$.

        Seja $u = n^2$. Então $a_{n} = (1 + \frac{1}{u})^{\sqrt[]{u}}$.
        Então, segundo o exercicio 15, $\lim_{n \to \infty} a_n = 1$.
        A sequência **converge para $1$**.

    18. $a_{n} = -n-n^3$.

        É fácil ver que $\lim_{n \to \infty} a_{n} = -\infty$.

2. Verifique que as sequências a seguir são sequências monotônicas e calcule seus limites.

    1. $a_{n + 1} = \sqrt[]{2 a_{n}}$, com $a_{1} = \sqrt[]{2}$.

        I. $a_{n}$ é crescente:

        $$
        \begin{aligned}
        a_{n+1} - a_{n} \geq 0 &\iff
        \sqrt[]{2 a_{n}} - a_{n} \geq 0\\
        a_{n+1} - a_{n} \geq 0 &\iff
        \sqrt[]{2 a_{n}} \geq a_{n}\\
        a_{n+1} - a_{n} \geq 0 &\iff
        2 a_{n} \geq a_{n}²
        \end{aligned}
        $$
        Supondo que $a_{n} > 0$, temos
        $$
        \begin{aligned}
        a_{n+1} - a_{n} \geq 0 &\iff
        2 \geq a_{n}
        \end{aligned}
        $$

        Suponha que $a_{n} > 0$, entao
        $$
        \begin{aligned}
        \sqrt[]{2a_{n}} &> \sqrt[]{2 \cdot 0}\\
        \sqrt[]{2a_{n}} &> 0\\
        a_{n+1} &> 0
        \end{aligned}
        $$
        Como $a_{1} = \sqrt[]{2} > 0$, esta provado por inducao que $a_{n} > 0$.

        Temos então que provar II:

        II. $a_{n} \leq 2$.

        $$
        \begin{aligned}
        a_{n} \leq 2 &\implies 2 a_{n} \leq 4\\
        a_{n} \leq 2 &\implies \sqrt[]{2 a_{n}} \leq \sqrt[]{4}\\
        a_{n} \leq 2 &\implies a_{n+1} \leq 2
        \end{aligned}
        $$
        Como $a_{1} = \sqrt[]{2} \leq 2$, então está provado que $a_{n}$ é crescente e limitada.
        Podemos então escrever:
        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n+1} &=
        \lim_{n \to \infty} a_{n} = L\\
        L &= \sqrt[]{2L}\\
        L^2 &= 2L\\
        L &= 2
        \end{aligned}
        $$
        Portanto, $\lim_{n \to \infty} a_{n} = 2$.

    2. $a_{n+1} = \sqrt[]{2 + a_{n}}$, e $a_{1} = \sqrt[]{2}$.

       I. $a_{n}$ é crescente:

        $$
        \begin{aligned}
        a_{n+1} \geq a_{n} &\iff
        \sqrt[]{2 + a_{n}} \geq a_{n}
        \end{aligned}
        $$
        Supondo que $a_{n} \geq 0$, temos
        $$
        \begin{aligned}
        a_{n+1} \geq a_{n} &\iff
        2 + a_{n} \geq a_{n}²\\
        a_{n+1} \geq a_{n} &\iff
        2 \geq a_{n}² - a_{n}
        \end{aligned}
        $$
        Provaremos isso mais tarde.

        Suponha que $a_{n} \geq 0$, entao temos
        $$
        \begin{aligned}
        \sqrt[]{2 + a_{n}} &\geq \sqrt[]{2 + 0}\\
        \sqrt[]{2 + a_{n}} &\geq \sqrt[]{2}\\
        \sqrt[]{2 + a_{n}} &\geq 0\\
        a_{n+1} &\geq 0
        \end{aligned}
        $$
        Como $a_{1} = \sqrt[]{2} \geq 0$, está provado por indução que $a_{n} \geq 0$.

       II. $a_{n}$ é limitada superiormente por $2$.

       $$
        \begin{aligned}
        a_{n} \leq 2 &\implies
        a_{n}² - a_{n} \leq 2² - 2\\
        a_{n} \leq 2 &\implies
        a_{n}² - a_{n} \leq 2\\
        a_{n} \leq 2 &\implies
        2 + a_{n} \leq 2 + 2\\
        a_{n} \leq 2 &\implies
        2 + a_{n} \leq 4\\
        a_{n} \leq 2 &\implies
        \sqrt[]{2 + a_{n}} \leq 2\\
        a_{n} \leq 2 &\implies
        a_{n+1} \leq 2\\
        \end{aligned}
       $$
       Como $a_1 = \sqrt[]{2} \leq 2$, então está completa a prova de que $a_{n}$ é limitada superiormente por $2$. Como $a_{n} \leq 2 \implies a_{n}² - a_{n} \leq 2 \iff a_{n+1} \geq a_{n}$, então também está provado que $a_{n}$ é crescente.
        Então podemos escrever:
        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} a_{n+1} = L\\
        L &= \sqrt[]{2 + L}\\
        L² &= 2 + L\\
        L² - L &= 2\\
        L &= 2
        \end{aligned}
        $$
        Assim, $\lim_{n \to \infty} a_{n} = 2$.

    3. $a_{n+1} = \sqrt[]{2}^{a_{n}}$, e $a_{1} = \sqrt[]{2}$.

        I. $a_{n}$ é crescente:

        $$
        \begin{aligned}
        a_{n+1} \geq a_{n} &\iff \sqrt[]{2}^{a_{n}} \geq a_{n}\\
        a_{n+1} \geq a_{n} &\iff \sqrt[]{2} \geq 2 \log_{2} a_{n}\\
        a_{n+1} \geq a_{n} &\iff \log_{2} a_{n}\leq \sqrt[]{\frac{1}{2}}
        \end{aligned}
        $$
        Como $\log_{2} a_{1}= \log_{2} \sqrt[]{2} = \frac{1}{2}$, e $\frac{1}{2} \leq \sqrt[]{\frac{1}{2}} \iff \frac{1}{4} \leq \frac{1}{2}$, então está provado que $a_{n}$ é crescente.

        II. $a_{n}$ é limitada superiormente por $2$.

        Vamos encontrar as condições necessárias para que $a^{x}$ (com $a$ fixo, e $x \geq 0$) seja uma função crescente. Para isso, a primeira derivada de $f(x) = a^{x}$ precisa ser maior do que zero:
        $$
        \begin{aligned}
        f^{\prime}(x) &> 0\\
        \ln a \cdot a^{x} &> 0\\
        \ln a &> 0\\
        e^{\ln a} &> e^{\ln 0}\\
        a &> 1
        \end{aligned}
        $$

        Vamos supor que $a_{n} \geq 0$. Suponha que $a_{n+1} < 0$. Então temos:
        $$
        \begin{aligned}
        a_{n+1} &< 0\\
        \sqrt[]{2}^{a_{n}} &< 0\\
        \sqrt[]{2}^{a_{n}} &< 1\\
        2\log_{2}\left(\sqrt[]{2}^{a_{n}}\right) &< 2 \log_{2}(1)\\
        2 a_{n} &< 0\\
        a_{n} &< 0
        \end{aligned}
        $$
        O que é uma contradição. Temos então que $a_{n} \geq 0 \implies a_{n+1} \geq 0$. Como $a_{1} = \sqrt[]{2} \geq 0$, então está provado, por indução, que $a_{n} \geq 0$.

        Assim, podemos escrever:

        $$
        \begin{aligned}
        a_{n} \leq 2 &\implies
        \sqrt[]{2}^{a_{n}} \leq \sqrt[]{2}^{2}\\
        a_{n} \leq 2 &\implies
        a_{n+1} \leq 2
        \end{aligned}
        $$
        Como $a_{1} = \sqrt[]{2} \leq 2$, então está provado que $a_{n}$ é limitada superiormente por $2$.
        Então, podemos escrever que $L = \lim_{n \to \infty} a_{n+1} = \lim_{n \to \infty} a_{n}$, e $\sqrt[]{2}^{L} = L$
        $$
        \begin{aligned}
        \sqrt[]{2}^{L} &= L\\
        L &= 2 \log_{2} L\\
        2^L &= L^2\\
        L &= 2
        \end{aligned}
        $$

    4. Seja $\alpha > 0$, e $x_{1} > \sqrt[]{\alpha}$, e
        $$
        x_{n+1} = \frac{1}{2}
        \left(
        x_{n} + \frac{\alpha}{x_{n}}
        \right)
        $$
        Para $n > 1$

        I. $x_{n}$ é decrescente:

        $$
        \begin{aligned}
        x_{n+1} \leq x_{n} &\iff
        \frac{1}{2}\left(
        x_{n} + \frac{\alpha}{x_{n}}
        \right) \leq x_{n}\\
        x_{n+1} \leq x_{n} &\iff
        x_{n} + \frac{\alpha}{x_{n}}
        \leq 2 x_{n}\\
        x_{n+1} \leq x_{n} &\iff
        x_{n}^{2} + \alpha
        \leq 2 x_{n}^{2}\\
        x_{n+1} \leq x_{n} &\iff
        \alpha \leq x_{n}^{2}\\
        x_{n+1} \leq x_{n} &\iff
        \sqrt[]{\alpha} \leq x_{n}
        \end{aligned}
        $$
        Vamos terminar de provar isso assim que provarmos que:

        II. $x_{n}$ é limitada inferiormente por $\sqrt[]{\alpha}$:

        Vamos supor que $x_{n} \geq \sqrt[]{\alpha}$, mas $x_{n+1} < \sqrt[]{\alpha}$.
        Então temos:

        $$
        \begin{aligned}
        x_{n+1} &< \sqrt[]{\alpha}\\
        \frac{1}{2}
        \left(
        x_{n} + \frac{\alpha}{x_{n}}
        \right) &< \sqrt[]{\alpha}\\
        x_{n} + \frac{\alpha}{x_{n}} &< 2 \sqrt[]{\alpha}\\
        \end{aligned}
        $$ {#eq:1}

        Porém, temos

        $$
        \begin{aligned}
        x_{n} &\geq \sqrt[]{\alpha}\\
        x_{n}^{2} &\geq \alpha\\
        x_{n} &\geq \frac{\alpha}{x_{n}}
        \end{aligned}
        $$

        Então, voltando a +@eq:1,
        $$
        \begin{aligned}
        2 x_{n} &< 2 \sqrt[]{\alpha}\\
        x_{n} &< \sqrt[]{\alpha}
        \end{aligned}
        $$

        O que é uma contradição. Portanto, se $x_{n} \geq \sqrt[]{\alpha}$, temos que $x_{n+1} \geq \sqrt[]{\alpha}$ também.

        Assim, como $x_{1} > \sqrt[]{\alpha}$, então está provado que $x_{n}$ é decrescente e limitada inferiormente por $\sqrt[]{\alpha}$.
        Então podemos escrever que $L = \lim_{n \to \infty} x_{n+1} = \lim_{n \to \infty} x_{n}$, e então:
        $$
        \begin{aligned}
        \frac{1}{2}\left( L + \frac{\alpha}{L} \right) &= L\\
        L^2 + \alpha &= 2L²\\
        L^2 &= \alpha\\
        L &= \sqrt[]{\alpha}
        \end{aligned}
        $$

    5. Como $f$ é contínua em $A$, então temos que $f(a) = \lim_{x \to a} f(x)$.
    Temos que provar então que $\lim_{x \to a} f(x) = a$, isto é:
    $$
    \forall \epsilon > 0 (\exists \delta > 0 (
    |x - a| < \delta \implies |f(x) - a| < \epsilon
    ))
    $$

## Séries

### Cálculo do valor de séries

1. Calcule a soma da série dada.

    1. $\sum_{k=0}^{\infty}\left(\frac{1}{2}\right)^{k}$

        Essa série é a série geométrica com razão $r = \frac{1}{2}$.
        Sabemos então que essa série converge para $\frac{1}{1-r} = 2$.

    2. $\sum_{k=2}^{\infty}\left(\frac{1}{3}\right)^{k}$

        Note que:
        $$
        \begin{aligned}
        \sum_{k=2}^{\infty}\left(\frac{1}{3}\right)^{k} &=
        \sum_{k=0}^{\infty}\left(\frac{1}{3}\right)^{k} -
        \left(1 + \frac{1}{3} + \frac{1}{3^{2}}\right)\\
        \sum_{k=2}^{\infty}\left(\frac{1}{3}\right)^{k} &=
        \sum_{k=0}^{\infty}\left(\frac{1}{3}\right)^{k} -
        \frac{13}{9}\\
        \end{aligned}
        $$

        Como $\sum_{k=0}^{\infty}\left(\frac{1}{3}\right)^{k}$ é uma série geométrica com razão $r = \frac{1}{3}$, então
        $$
        \begin{aligned}
        \sum_{k=2}^{\infty}\left(\frac{1}{3}\right)^{k} &=
        \frac{1}{1-\frac{1}{3}} - \frac{13}{9}\\
        \sum_{k=2}^{\infty}\left(\frac{1}{3}\right)^{k} &=
        \frac{3}{2} - \frac{13}{9}\\
        \sum_{k=2}^{\infty}\left(\frac{1}{3}\right)^{k} &=
        \frac{27 - 26}{18}\\
        \sum_{k=2}^{\infty}\left(\frac{1}{3}\right)^{k} &=
        \frac{1}{18}
        \end{aligned}
        $$

    3. $\sum_{k=0}^{\infty}e^{-k}$

        Essa série também é uma série geométrica. Dessa vez, com $r = \frac{1}{e}$. Então:
        $$
        \begin{aligned}
        \sum_{k=0}^{\infty}e^{-k} &= \frac{1}{1 - \frac{1}{e}}\\
        \sum_{k=0}^{\infty}e^{-k} &= \frac{e}{e - 1}
        \end{aligned}
        $$

    4. $\sum_{k=1}^{\infty}[1 + (-1)^{k}]$

        Esta série é **divergente**. Para ver isso, basta ver que $\lim_{n \to \infty} [1 + (-1)^{n}]$ não existe.

    5. $\sum_{k=0}^{\infty} \frac{1}{(4k+1)(4k+5)}$

        Temos que:
        $$
        \begin{aligned}
        \frac{1}{(4k+1)(4k+5)} &= \frac{1}{4(k + \frac{1}{4})4(k + \frac{5}{4})}\\
        \frac{1}{(4k+1)(4k+5)} &= \frac{1}{16} \frac{1}{(k + \frac{1}{4})(k + \frac{5}{4})}\\
        \frac{1}{(4k+1)(4k+5)} &= \frac{1}{16}
        \frac{k + \frac{5}{4} - k - \frac{1}{4}}{(k + \frac{1}{4})(k + \frac{5}{4})}\\
        \frac{1}{(4k+1)(4k+5)} &= \frac{1}{16} \left(
        \frac{k + \frac{5}{4}}{(k + \frac{1}{4})(k + \frac{5}{4})} -
        \frac{k + \frac{1}{4}}{(k + \frac{1}{4})(k + \frac{5}{4})}
        \right)\\
        \frac{1}{(4k+1)(4k+5)} &= \frac{1}{16} \left(
        \frac{1}{k + \frac{1}{4}} -
        \frac{1}{k + \frac{5}{4}}
        \right)\\
        \frac{1}{(4k+1)(4k+5)} &= \frac{1}{16} \left(
        \frac{1}{k + \frac{1}{4}} -
        \frac{1}{(k + 1) + \frac{1}{4}}
        \right)\\
        \end{aligned}
        $$

        Então, podemos escrever $\sum_{k=0}^{\infty} \frac{1}{(4k+1)(4k+5)}$ como uma série telescópica:
        $$
        \begin{aligned}
        \frac{1}{(4k+1)(4k+5)} = \frac{1}{16} (b_{k} - b_{k+1})
        \end{aligned}
        $$
        Onde $b_{k} = \frac{1}{k + \frac{1}{4}}$.
        Então, pela propriedade das séries telescópicas, temos que
        $$
        \begin{aligned}
        \sum_{k=0}^{\infty} \frac{1}{(4k+1)(4k+5)} &=
        \frac{1}{16} \left(b_{0} - \lim_{k \to \infty} \frac{1}{k + \frac{1}{4}}\right)\\
        \sum_{k=0}^{\infty} \frac{1}{(4k+1)(4k+5)} &=
        \frac{1}{16}(b_{0} - 0)\\
        \sum_{k=0}^{\infty} \frac{1}{(4k+1)(4k+5)} &= \frac{b_{0}}{16}
        \end{aligned}
        $$

        Como $b_{0} = \frac{1}{0 + \frac{1}{4}} = 4$, então $\sum_{k=0}^{\infty} \frac{1}{(4k+1)(4k+5)} = \frac{4}{16} = \frac{1}{4}$.

    6. $\sum_{k=1}^{\infty} \frac{1}{k (k+1)(k+2)(k+3)}$

        Note que:
        $$
        \begin{aligned}
        \frac{1}{k (k+1)(k+2)(k+3)} &=
        \frac{1}{3} \frac{k + 3 - k}{k (k+1)(k+2)(k+3)}\\
        \frac{1}{k (k+1)(k+2)(k+3)} &=
        \frac{1}{3} \left(
        \frac{k + 3}{k (k+1)(k+2)(k+3)} -
        \frac{k}{k (k+1)(k+2)(k+3)}
        \right)\\
        \frac{1}{k (k+1)(k+2)(k+3)} &=
        \frac{1}{3} \left(
        \frac{1}{k (k+1)(k+2)} -
        \frac{1}{(k+1)(k+2)(k+3)}
        \right)\\
        \end{aligned}
        $$

        Então podemos escrever a série $\sum_{k=1}^{\infty} \frac{1}{k (k+1)(k+2)(k+3)}$ como uma série telescópica, com $\frac{1}{k(k+1)(k+2)(k+3)} = \frac{1}{3}(b_{k} - b_{k + 1})$, onde $b_{k} = \frac{1}{k(k+1)(k+2)}$.
        Então, pela propriedade das séries telescópicas, temos:
        $$
        \begin{aligned}
        \sum_{k=1}^{\infty} \frac{1}{k (k+1)(k+2)} &=
        \frac{1}{3}\left(b_{1} - \lim_{k \to \infty} \frac{1}{k (k+1)(k+2)}\right)\\
        \sum_{k=1}^{\infty} \frac{1}{k (k+1)(k+2)(k+3)} &=
        \frac{1}{3}(b_{1} - 0)\\
        \sum_{k=1}^{\infty} \frac{1}{k (k+1)(k+2)(k+3)} &=
        \frac{b_{1}}{3}\\
        \end{aligned}
        $$
        Como $b_{1} = \frac{1}{1(1+1)(1+2)} = \frac{1}{6}$, entao $\sum_{k=1}^{\infty} \frac{1}{k (k+1)(k+2)(k+3)} = \frac{1}{18}$

    7. $\sum_{k=1}^{\infty} \frac{2k+1}{k^{2}(k+1)^{2}}$.

        Note que:
        $$
        \begin{aligned}
        \frac{2k+1}{k^{2}(k+1)^{2}} &=
        \frac{(k+1)^{2} - k^{2}}{k^{2}(k+1)^{2}}\\
        \frac{2k+1}{k^{2}(k+1)^{2}} &=
        \frac{(k+1)^{2}}{k^{2}(k+1)^{2}} -
        \frac{k^{2}}{k^{2}(k+1)^{2}}\\
        \frac{2k+1}{k^{2}(k+1)^{2}} &=
        \frac{1}{k^{2}} -
        \frac{1}{(k+1)^{2}}\\
        \end{aligned}
        $$

        Então podemos escrever a série $\sum_{k=1}^{\infty} \frac{2k+1}{k^{2}(k+1)^{2}}$ como uma série telescópica, com $\frac{1}{k(k+1)(k+2)(k+3)} = b_{k} - b_{k+1}$, onde $b_{k} = \frac{1}{k^{2}}$.
        Então, pela propriedade das séries telescópicas, temos:
        $$
        \begin{aligned}
        \sum_{k=1}^{\infty} \frac{2k+1}{k^{2}(k+1)^{2}} &=
        b_{1} - \lim_{k \to \infty} \frac{1}{k^{2}}\\
        \sum_{k=1}^{\infty} \frac{2k+1}{k^{2}(k+1)^{2}} &= b_{1} - 0\\
        \sum_{k=1}^{\infty} \frac{2k+1}{k^{2}(k+1)^{2}} &= b_{1}
        \end{aligned}
        $$

        Assim, como $b_{1} = \frac{1}{1^{2}} = 1$, temos que $\sum_{k=1}^{\infty} \frac{2k+1}{k^{2}(k+1)^{2}} = 1$.

    8. $\sum_{k=1}^{\infty}n \alpha^{n}$, com $0 < \alpha < 1$.

    9. $\sum_{k=1}^{\infty} \prod_{i=0}^{p} \frac{1}{k + i}$, onde $p \geq 1$ eh um natural dado

        $$
        \begin{aligned}
        \prod_{i=0}^{p} \frac{1}{k + i} &=
        \frac{1}{p} \left(\frac{k + p - k}{\prod_{i=0}^{p}(k + i)}\right)\\
        \prod_{i=0}^{p} \frac{1}{k + i} &=
        \frac{1}{p} \left(
            \frac{k + p}{\prod_{i=0}^{p}(k + i)} -
            \frac{k}{\prod_{i=0}^{p}(k + i)}
        \right)\\
        \prod_{i=0}^{p} \frac{1}{k + i} &=
        \frac{1}{p} \left(
            \frac{1}{\prod_{i=0}^{p - 1}(k + i)} -
            \frac{1}{\prod_{i=1}^{p}(k + i)}
        \right)\\
        \end{aligned}
        $$
        Note que $\prod_{k=1}^{p}(k+i) = \prod_{k=0}^{p-1}((k+1)+i)$.
        Entao podemos escrever $\sum_{k=1}^{\infty} \prod_{i=0}^{p} \frac{1}{k + i}$ como uma serie telescopica $\sum_{k=1}^{\infty} \prod_{i=0}^{p} \frac{1}{k + i} = \frac{1}{p}(b_{k} - b_{k+1})$, onde $b_{k} = \frac{1}{\prod_{i=0}^{p - 1}(k + i)}$.

        Assim, segundo as propriedades das series telescopicas, temos que
        $$
        \begin{aligned}
        \sum_{k=1}^{\infty} \prod_{i=0}^{p} \frac{1}{k + i} &=
        \frac{1}{p}\left(b_{1} - \lim_{k \to \infty} \frac{1}{\prod_{i=0}^{p - 1}(k + i)}\right)\\
        \sum_{k=1}^{\infty} \prod_{i=0}^{p} \frac{1}{k + i} &=
        \frac{1}{p}(b_{1} - 0)\\
        \sum_{k=1}^{\infty} \prod_{i=0}^{p} \frac{1}{k + i} &=
        \frac{b_{1}}{p}\\
        \end{aligned}
        $$

        Como $b_{1} = \prod_{i=0}^{p-1} \frac{1}{1 + i}$, temos que
        $$
        \begin{aligned}
        \sum_{k=1}^{\infty} \prod_{i=0}^{p} \frac{1}{k + i} &=
        \frac{1}{p} \prod_{i=0}^{p-1} \frac{1}{1 + i}
        \end{aligned}
        $$

    10. $\sum_{k=0}^{\infty}\frac{1}{(4k+1)(4k+3)}$

    11. $\sum_{k=1}^{\infty} \frac{1}{k^{2}(k+1)(k+2)^{2}}$

### Critérios de convergência

1. Estude a série dada em relação a convergência ou divergência:

    a. $\sum_{k=0}^{\infty}\frac{1}{k^{2} + 1}$

    Note que $\frac{1}{k^{2} + 1}$ é sempre positiva. Além disso $\frac{1}{k^{2} + 1}$ é decrescente, pois sua derivada,
    $$
    \begin{aligned}
    \frac{d}{dk} \frac{1}{k^{2} + 1} = \frac{-2k}{k^{4} + 2k^{2} + 1}
    \end{aligned}
    $$
    claramente é negativa, para $k > 0$.

    Podemos então aplicar o teste da integral:
    $$
    \begin{aligned}
    \int_{1}^{\infty} \frac{1}{x^{2} + 1} dx &=
    \lim_{k \to \infty} \arctan k - \arctan 1\\
    \int_{1}^{\infty} \frac{1}{x^{2} + 1} dx &=
    \frac{\pi}{2} - \frac{\pi}{4}\\
    \int_{1}^{\infty} \frac{1}{x^{2} + 1} dx &=
    \frac{\pi}{4}\\
    \end{aligned}
    $$
    Assim, concluímos que a série é convergente.

    b. $\sum_{k=2}^{\infty} \frac{1}{k^{2} \ln{k}}$

    Podemos usar o critério da comparação no limite para comparar essa série com a do item anterior:

    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{\frac{1}{k^{2}+1}}{\frac{1}{k^{2}+\ln{k}}} &=
    \lim_{k \to \infty} \frac{k^{2}+\ln{k}}{k^{2}+1}\\
    \lim_{k \to \infty} \frac{\frac{1}{k^{2}+1}}{\frac{1}{k^{2}+\ln{k}}} &= 1
    \end{aligned}
    $$

    Como o limite é $1$, e a série do item anterior converge, então essa série também converge.

    c. $\sum_{k=2}^{\infty} \frac{1}{k^{\alpha} \ln{k}}$, com $\alpha > 0$.
    Vamos definir $a_{k} = \frac{1}{k^{\alpha} \ln{k}}$.

    Vamos tentar usar o critério da razão:
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{a_{k+1}}{a_{k}} &=
    \lim_{k \to \infty} \frac{k^{\alpha} \ln{k}}{(k+1)^{\alpha} \ln{k+1}}\\
    \end{aligned}
    $$

    Aplicando a regra de L'Hôpital, temos:
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{a_{k+1}}{a_{k}} &=
    \lim_{k \to \infty}
    \frac{\ln{k} \alpha k^{\alpha-1} + \frac{k^{\alpha}}{k}}
    {\ln{(k + 1)} \alpha (k + 1)^{\alpha-1} + \frac{(k+1)^{\alpha}}{k+1}}\\
    \end{aligned}
    $$

    O que não parece nos ajudar muito...

    Vamos então tentar usar o critério da raiz:
    $$
    \begin{aligned}
    \lim_{k \to \infty} \sqrt[k]{\frac{1}{k^{\alpha}\ln{k}}} =
    e^{(-1) \lim_{k \to \infty} \frac{\alpha \ln{k} + \ln{\ln{k}}}{k}}
    \end{aligned}
    $$
    Note que
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{\alpha \ln{k} + \ln{\ln{k}}}{k} = \frac{\infty}{\infty}
    \end{aligned}
    $$
    Então, aplicando a regra de L'Hôpital, temos:
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{\alpha \ln{k} + \ln{\ln{k}}}{k} &=
    \lim_{k \to \infty} \alpha \frac{1}{k} + \frac{1}{\ln{k}} \frac{1}{k}\\
    \lim_{k \to \infty} \frac{\alpha \ln{k} + \ln{\ln{k}}}{k} &= 0
    \end{aligned}
    $$
    Então
    $$
    \begin{aligned}
    \lim_{k \to \infty} \sqrt[k]{\frac{1}{k^{\alpha}\ln{k}}} &= e^{0}\\
    \lim_{k \to \infty} \sqrt[k]{\frac{1}{k^{\alpha}\ln{k}}} &= 1
    \end{aligned}
    $$
    E o critério da raiz nada revela.

    Vamos usar então o críterio de comparação no limite com a série harmônica generalizada, isto é: $b_{k} = \frac{1}{k^{\alpha}}$.
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &=
    \lim_{k \to \infty} \frac{k^{\alpha}}{k^{\alpha} \ln{k}}\\
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &=
    \lim_{k \to \infty} \frac{1}{\ln{k}}\\
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &= 0
    \end{aligned}
    $$
    Então, pelo [Critério da comparação no limite](#thm:crit_comp_lim), temos que, se $\sum_{k=0}^{\infty}b_{k}$ for convergente, então $\sum_{k=0}^{\infty}a_{k}$ também será. Sabemos que isso acontece para $\alpha > 1$.

    Seja agora $c_{k} = \frac{1}{k^{\beta}}$ com $\beta > \alpha$, então temos:
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &=
    \lim_{k \to \infty} \frac{k^{\beta}}{k^{\alpha} \ln{k}}\\
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &=
    \lim_{k \to \infty} \frac{k^{\beta - \alpha}}{\ln{k}}\\
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &= \frac{\infty}{\infty}\\
    \text{(Por L'Hôpital, temos)}
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &=
    \lim_{k \to \infty} \frac{(\beta - \alpha)k^{\beta - \alpha - 1}}{\frac{1}{k}}\\
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &=
    \lim_{k \to \infty} (\beta - \alpha)k^{\beta - \alpha}\\
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &= \infty
    \end{aligned}
    $$
    Então, pelo mesmo critério, se $\sum_{k=0}^{\infty}c_{k}$ for divergente, então $\sum_{k=0}^{\infty}a_{k}$ também será. Sabemos que $\sum_{k=0}^{\infty}c_{k}$ será divergente se e somente se $\beta \leq 1$. Então, como $\alpha < \beta$, se $\alpha < 1$, $\sum_{k=0}^{\infty}a_{k}$ será divergente.

    Caso $\alpha = 1$, então $a_{k} = \frac{1}{k \ln{k}}$.

    Note que $k \ln{k}$ é crescente em todo o seu domínio, e então $\sum_{k=2}^{\infty} a_{k}$ é uma série de termo geral decrescente e positivo. Podemos então utilizar o teste da integral.
    $$
    \begin{aligned}
    \int_{2}^{\infty} \frac{1}{x \ln{x}} &=
    \lim_{k \to \infty} (\ln{(\ln{k})}) - \ln{(\ln{2})}\\
    \int_{2}^{\infty} \frac{1}{x \ln{x}} &= \infty
    \end{aligned}
    $$
    Portanto, para $\alpha = 1$, a série diverge.

    Assim, a série $\sum_{k=2}^{\infty} \frac{1}{k^{\alpha} \ln{k}}$, com $\alpha > 0$ converge para $\alpha > 1$, e diverge caso contrário.

    d. $\sum_{k=0}^{\infty} \frac{k}{1 + k^{4}}$

    Seja $a_{k} = \frac{k}{1 + k^{4}}$ e $b_{k} = \frac{1}{k^{2} + 1}$. Sabemos, pelo item (a), que $\sum_{k=0}^{\infty}b_{k}$ é convergente. Vamos aplicar o critério da comparação no limite.
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &=
    \lim_{k \to \infty} \frac{k (k^{2} + 1)}{1 + k^{4}}\\
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &=
    \lim_{k \to \infty} \frac{k^{3} + k}{1 + k^{4}}\\
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &= 0
    \end{aligned}
    $$
    Então, pelo critério da comparação no limite, temos que $\sum_{k=0}^{\infty} \frac{k}{1 + k^{4}}$ será convergente.

    e. $\sum_{k=2}^{\infty} \frac{1}{k \ln{k}\ \ln{(\ln{k})}}$

    Note que, a partir de $k \geq k_{0}$ para algum $k_{0} \in \mathbb{N}$, essa é uma série de termo geral decrescente e positivo. Então podemos aplicar o teste da integral:
    $$
    \begin{aligned}
    \int_{e^{2}}^{\infty} \frac{1}{k \ln{k}\ \ln{(\ln{k})}} &=
    \lim_{k \to \infty}\ln{(\ln{(\ln{k})})} - \ln{(\ln{(\ln{e^{2}})})}\\
    \int_{e^{2}}^{\infty} \frac{1}{k \ln{k}\ \ln{(\ln{k})}} &= \infty
    \end{aligned}
    $$
    Então, pelo critério da integral, a série $\sum_{k=2}^{\infty} \frac{1}{k \ln{k}\ \ln{(\ln{k})}}$ diverge.

    f. $\sum_{k=2}^{\infty} \frac{1}{k \ln{k}\ [\ln{(\ln{k})}]^{\alpha}}$, com $\alpha > 1$

    Vamos fazer $a_{k} = \frac{1}{k \ln{k}\ [\ln{(\ln{k})}]^{\alpha}}$, e $b_{k} = \frac{1}{k \ln{k}\ \ln{(\ln{k})}}$, e aplicar o critério da comparação no limite.
    Sabemos que $\sum_{k=2}^{\infty} b_{k}$ é divergente. Então temos:
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &=
    \lim_{k \to \infty} \frac{k \ln{k}\ \ln{(\ln{k})}}{k \ln{k}\ [\ln{(\ln{k})}]^{\alpha}}\\
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &=
    \lim_{k \to \infty} \frac{1}{[\ln{(\ln{k})}]^{\alpha - 1}}\\
    \end{aligned}
    $$
    Note que, caso $0 < \alpha < 1$, $\lim_{k \to \infty} \frac{a_{k}}{b_{k}} = \infty$, e caso $\alpha = 1$, $\lim_{k \to \infty} \frac{a_{k}}{b_{k}} = 1$, e então, para $0 < \alpha \leq 1$, $\sum_{k=2}^{\infty} \frac{1}{k \ln{k}\ [\ln{(\ln{k})}]^{\alpha}}$ será divergente.

    Vamos agora considerar o caso em que $\alpha > 1$.

    Vamos tentar usar o critério da raiz:
    $$
    \begin{aligned}
    \lim_{k \to \infty} \sqrt[k]{\frac{1}{k \ln{k}\ (\ln{(\ln{k})})^{\alpha}}} &=
    \lim_{k \to \infty}(k \ln{k}\ (\ln{(\ln{k})})^{\alpha})^{\frac{-1}{k}}\\
    \lim_{k \to \infty} \sqrt[k]{\frac{1}{k \ln{k}\ (\ln{(\ln{k})})^{\alpha}}} &=
    e^{-\lim_{k \to \infty}\frac{\ln{(k \ln{k}\ (\ln{(\ln{k})})^{\alpha})}}{k}}\\
    \lim_{k \to \infty}\frac{\ln{(k \ln{k}\ (\ln{(\ln{k})})^{\alpha})}}{k} &=
    \lim_{k \to \infty}\frac{\ln{k} + \ln{(\ln{k})} + \alpha \ln{(\ln{(\ln{k})})}}{k}\\
    \lim_{k \to \infty}\frac{\ln{(k \ln{k}\ (\ln{(\ln{k})})^{\alpha})}}{k} &=
    \frac{\infty}{\infty}
    \end{aligned}
    $$
    Então, por Lhopital, temos:
    $$
    \begin{aligned}
    \lim_{k \to \infty}\frac{\ln{(k \ln{k}\ (\ln{(\ln{k})})^{\alpha})}}{k} &=
    \frac{1}{k} + \frac{1}{k \ln{k}} + \frac{\alpha}{k \ln{k}\ \ln{(\ln{k})}}\\
    \lim_{k \to \infty}\frac{\ln{(k \ln{k}\ (\ln{(\ln{k})})^{\alpha})}}{k} &=0
    \end{aligned}
    $$

    Então $\lim_{k \to \infty} \sqrt[k]{a_{k}} = e^{0} = 1$, e o critério da raiz nada revela.

    Vamos decidir sobre a convergência da série $\sum_{e^{2}}^{\infty} c_{k}$, onde $c_{k} = \frac{1}{(\ln{(\ln{k})})^{\beta}}$.
    Para isso, vamos utilizar $d_{k} = \frac{1}{k^{\alpha}}$, a série harmônica generalizada,e o critério de comparação no limite. Seja $0 < \beta < \alpha$. Então temos:
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{c_{k}}{d_{k}} &=
    \lim_{k \to \infty} \frac{(\ln{(\ln{k})})^{\beta}}{k^{\alpha}}\\
    \lim_{k \to \infty} \frac{c_{k}}{d_{k}} &=
    \lim_{k \to \infty} \left(\frac{\ln{(\ln{k})}}{k}\right)^{\beta}
    \frac{1}{k^{\alpha - \beta}}
    \\
    \lim_{k \to \infty} \frac{c_{k}}{d_{k}} &=
    \left(\lim_{k \to \infty} \left(\frac{\ln{(\ln{k})}}{k}\right)^{\beta}\right)
    \left(\lim_{k \to \infty} \frac{1}{k^{\alpha - \beta}}\right)
    \\
    \lim_{k \to \infty} \frac{c_{k}}{d_{k}} &= 0 \cdot 0\\
    \lim_{k \to \infty} \frac{c_{k}}{d_{k}} &= 0
    \end{aligned}
    $$

    Entao $\sum_{k=e^{2}}^{\infty} c_{k}$ será convergente se $\sum_{k=1}^{\infty} d_{k}$ for convergente. Sabemos que isso acontece sempre quando $\alpha > 1$. Então, para todo $\beta > 1$, a série $\sum_{k=e^{2}}^{\infty} \frac{1}{(\ln{(\ln{k})})^{\beta}}$ é convergente.

    Vamos utilizar essa série, com o critério da comparação no limite para decidir sobre a convergência de $\sum_{k=2}^{\infty} a_{k}$. Seja $\alpha > \beta > 1$, então a série $\sum_{k=e^{2}}^{\infty} c_{k}$ é convergente. Temos que:
    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &=
    \lim_{k \to \infty} \frac{(\ln{(\ln{k})})^{\beta}}{k \ln{k}\ [\ln{(\ln{k})}]^{\alpha}}\\
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &=
    \lim_{k \to \infty} \frac{(\ln{(\ln{k})})^{\beta-\alpha}}{k \ln{k}}\\
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &=
    \lim_{k \to \infty} \frac{1}
    {k \ln{k} (\ln{(\ln{k})})^{\alpha-\beta}}\\
    \lim_{k \to \infty} \frac{a_{k}}{c_{k}} &=0
    \end{aligned}
    $$

    Assim, pelo critério da comparação no limite, para $\alpha > 1$, a série é convergente.

    g. $\sum_{k=2}^{\infty} \frac{1}{k \ln{k}\ [\ln{(\ln{k})}]^{\alpha}}$, com $0 < \alpha < 1$

    Vimos pelo item anterior que, para $0 < \alpha < 1$, a série é divergente.

    h. $\sum_{k=0}^{\infty} \frac{k}{k^{2} + 1}$

    Seja $a_{k} = \frac{k}{k^{2} + 1}$, e $b_{k} = \frac{1}{k}$, a série harmônica. Sabemos que a série harmônica diverge. Vamos usar o critério de comparação no limite.

    $$
    \begin{aligned}
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &=
    \lim_{k \to \infty} \frac{k^{2}}{k^{2} + 1}\\
    \lim_{k \to \infty} \frac{a_{k}}{b_{k}} &= 1
    \end{aligned}
    $$
    Assim, pelo critério da comparação no limite, a série é divergente.

2. Decida se cada uma das séries a seguir é convergente ou divergente:

    1. $\sum_{n=3}^{\infty} \frac{1}{\sqrt[]{n^{2} - 4}}$

        Seja $a_{n} = \frac{1}{\sqrt[]{n^{2} - 4}}$, e $b_{n} = \frac{1}{n}$, o termo geral da série harmônica. Sabemos que a série harmônica diverge. Vamos então usar o critério da comparação no limite:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{\sqrt[]{n^{2} - 4}}{n}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{\sqrt[]{n^{2} - 4}}{\sqrt[]{n^{2}}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \sqrt[]{\lim_{n \to \infty} \frac{n^{2} - 4}{n^{2}}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= \sqrt[]{1}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= 1\\
        \end{aligned}
        $$
        Assim, pelo critério da comparação no limite, a série diverge.

    2. $\sum_{n=2}^{\infty}\frac{\arctan n}{n^{2}}$

        Seja $a_{n} = \frac{\arctan n}{n^{2}}$ e $b_{n} = \frac{1}{n^{2}}$, ou seja, a série harmônica generalizada com $\alpha = 2$. Sabemos que $\sum_{n=1}^{\infty} b_{n}$ converge. Vamos então usar o critério de comparação no limite:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{n^{2} \arctan n}{n^{2}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \arctan n\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= 0
        \end{aligned}
        $$
        Então, pelo critério de comparação no limite, a série converge.

    3. $\sum_{n=1}^{\infty} \frac{e^{\frac{1}{n}}}{n^{2}}$

        Seja $a_{n} = \frac{e^{\frac{1}{n}}}{n^{2}}$, e $b_{n} = \frac{1}{n^{2}}$, a série harmônica generalizada com $\alpha = 2$. Sabemos que $\sum_{n=1}^{\infty} b_{n}$ converge. Vamos então aplicar o critério de comparação no limite:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{n^{2} e^{\frac{1}{n}}}{n^{2}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} e^{\frac{1}{n}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} e^{0}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= 1
        \end{aligned}
        $$
        Assim, pelo critério da comparação no limite, a série converge.

    4. $\sum_{n=1}^{\infty} \frac{2^{n}}{n!}$

        Seja $a_{n} = \frac{2^{n}}{n!}$. Vamos tentar então usar o critério da razão:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        \lim_{n \to \infty} \frac{2^{n + 1}}{(n + 1)!} \frac{n!}{2^{n}}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        \lim_{n \to \infty} \frac{2}{n + 1}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &= 0
        \end{aligned}
        $$
        Então, pelo critério da razão, a série converge.

    5. $\sum_{n=1}^{\infty} \frac{(2n)!}{(n!)^{2}}$

        Seja $a_{n} = \frac{(2n)!}{(n!)^{2}}$. Vamos tentar usar o critério da razão:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        \lim_{n \to \infty} \frac{(2(n + 1))!}{((n + 1)!)^{2}} \frac{(n!)^{2}}{(2n)!}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        \lim_{n \to \infty} \frac{(2n + 2)!}{(2n)! (n + 1)^{2}}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        \lim_{n \to \infty} \frac{(2n + 2)(2n + 1)}{(n + 1)^{2}}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        \lim_{n \to \infty} \frac{4n^{2} + 6n + 2}{n^{2} + 2n + 1}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &= 4
        \end{aligned}
        $$
        Então, pelo critério da razão, a série diverge.

    6. $\sum_{n=2}^{\infty} \frac{\ln{n}}{n}$

        Sabemos que $\sum_{n=1}^{\infty} \frac{1}{n}$ é divergente.
        Como $\frac{\ln{n}}{n} > \frac{1}{n}$, para $n \geq 1$, então a série dada só pode ser divergente também.

    7. $\sum_{n=1}^{\infty} \frac{\sqrt[3]{n+2}}{\sqrt[4]{n^{3}+3} \sqrt[5]{n^{3}+5}}$

        Seja $a_{n} = \frac{\sqrt[3]{n+2}}{\sqrt[4]{n^{3}+3} \sqrt[5]{n^{3}+5}}$, e $b_{n} = \frac{\sqrt[3]{n}}{\sqrt[4]{n^{3}} \sqrt[5]{n^{3}}}$. Note que:
        $$
        \begin{aligned}
        \sqrt[3]{n} &= n^{\frac{1}{3}}\\
        \sqrt[4]{n^{3}} &= n^{\frac{3}{4}}\\
        \sqrt[5]{n^{3}} &= n^{\frac{3}{5}}
        \end{aligned}
        $$
        Portanto,
        $$
        \begin{aligned}
        b_{n} &= \frac{n^{\frac{1}{3}}}{n^{\frac{3}{4}} n^{\frac{3}{5}}}\\
        b_{n} &= n^{\frac{1}{3} - \frac{3}{4} - \frac{3}{5}}\\
        b_{n} &= n^{\frac{20 - 45 - 36}{60}}\\
        b_{n} &= n^{- \frac{61}{60}}\\
        b_{n} &= \frac{1}{n^{\frac{61}{60}}}
        \end{aligned}
        $$
        Assim, $\sum_{n=1}^{\infty} b_{n}$ é igual à série harmônica generalizada, com $\alpha > 1$, e portanto $\sum_{n=1}^{\infty} b_{n}$ converge. Vamos então aplicar o critério da comparação no limite:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty}
        \frac{\sqrt[3]{n+2}}{\sqrt[4]{n^{3}+3} \sqrt[5]{n^{3}+5}}
        \frac{\sqrt[4]{n^{3}} \sqrt[5]{n^{3}}}{\sqrt[3]{n}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \left(\lim_{n \to \infty} \frac{\sqrt[3]{n+2}}{\sqrt[3]{n}}\right)
        \left(\lim_{n \to \infty} \frac{\sqrt[4]{n^{3}}}{\sqrt[4]{n^{3}+3}}\right)
        \left(\lim_{n \to \infty} \frac{\sqrt[5]{n^{3}}}{\sqrt[5]{n^{3}+5}}\right)\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= 1 \cdot 1 \cdot 1\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= 1
        \end{aligned}
        $$
        Então, pelo critério da comparação no limite, a série converge.

    8. $\sum_{n=1}^{\infty} \left(1 - \cos \frac{1}{n}\right)$

        Seja $a_{n} = \left(1 - \cos \frac{1}{n}\right)$. Note que $a_{n} > 0$, para todo $n$.

        Seja $b_{n} = \frac{1}{n^{2}}$, o termo geral da série harmônica generalizada com $\alpha = 2$. Sabemos que essa série é convergente.
        Vamos então utilizar o critério de comparação no limite:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{1 - \cos \frac{1}{n}}{\frac{1}{n^{2}}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{1 - \cos \frac{1}{n}}{\frac{1}{n^{2}}}
        \frac{1 + \cos \frac{1}{n}}{1 + \cos \frac{1}{n}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{\sin^{2} \frac{1}{n}}
        {\frac{1 + \cos \frac{1}{n}}{n^{2}}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \left(\frac{\sin \frac{1}{n}}{\frac{1}{n}}\right)^{2}
        \frac{1}{1 + \cos \frac{1}{n}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \left(\lim_{n \to \infty} \frac{\sin \frac{1}{n}}{\frac{1}{n}}\right)^{2}
        \left(\lim_{n \to \infty}\frac{1}{1 + \cos \frac{1}{n}}\right)\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= 1^{2} \cdot \frac{1}{2}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= \frac{1}{2}
        \end{aligned}
        $$
        Então, pelo critério da comparação no limite, a série converge.

    9. $\sum_{n=2}^{\infty} \frac{1}{(\ln{n})^{n}}$

        É fácil ver que os termos dessa série são estritamente positivos. Seja $a_{n}=\frac{1}{(\ln{n})^{n}}$. Vamos então aplicar o critério da raiz:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \sqrt[n]{a_{n}} &=
        \lim_{n \to \infty} \sqrt[n]{\frac{1}{(\ln{n})^{n}}}\\
        \lim_{n \to \infty} \sqrt[n]{a_{n}} &=
        \lim_{n \to \infty} \frac{1}{\ln{n}}\\
        \lim_{n \to \infty} \sqrt[n]{a_{n}} &= 0
        \end{aligned}
        $$
        Então, pelo critério da raiz, a série converge.

    10. $\sum_{n=2}^{\infty} \frac{\ln{n}}{n^{2}}$

        Seja $a_{n}=\frac{\ln{n}}{n^{2}}$, e $b_{n} = \frac{1}{n^{\frac{3}{2}}}$, isto é, a série harmônica generalizada com $\alpha = \frac{3}{2}$. Sabemos que $\sum_{n=1}^{\infty} b_{n}$ converge. Vamos então utilizar o critério da comparação no limite:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{\ln{n}}{n^{\frac{1}{2}}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \frac{\infty}{\infty}
        \end{aligned}
        $$
        Por Lhopital, temos:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{1}{n} \cdot 2 \cdot \frac{1}{n^{-\frac{1}{2}}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{2}{n^{\frac{1}{2}}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= 0
        \end{aligned}
        $$
        Então, pelo critério da comparação no limite, a série converge.

    11. $\sum_{n=1}^{\infty} \frac{n! 3^{n}}{n^{n}}$

        É facil ver que todos os termos da série são positivos. Seja então $a_{n}$ o termo geral da série. Vamos aplicar o critério da razão:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        \lim_{n \to \infty} \frac{(n + 1)! 3^{n + 1}}{(n + 1)^{n + 1}} \frac{n^{n}}{n! 3^{n}}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        \lim_{n \to \infty} \frac{n^{n} 3(n + 1)}{(n + 1)^{n} (n+1)}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        3 \lim_{n \to \infty} \left(\frac{n}{n + 1}\right)^{n}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=
        3 e^{\lim_{n \to \infty}n\ln{\left(\frac{n}{n + 1}\right)}}\\
        \end{aligned}
        $$
        Temos que:
        $$
        \begin{aligned}
        \lim_{n \to \infty} n \ln{\left(\frac{n}{n + 1}\right)} &=
        \lim_{n \to \infty} \frac{\ln{\left(\frac{n}{n + 1}\right)}}{\frac{1}{n}}\\
        \lim_{n \to \infty} n \ln{\left(\frac{n}{n + 1}\right)} &=
        \frac{0}{0}
        \end{aligned}
        $$
        Então, por Lhopital, temos:
        $$
        \begin{aligned}
        \lim_{n \to \infty} n \ln{\left(\frac{n}{n + 1}\right)} &=
        \lim_{n \to \infty} \frac{\frac{n+1}{n}\frac{n+1 - n}{(n+1)^{2}}}
        {(-1)n^{-2}}\\
        \lim_{n \to \infty} n \ln{\left(\frac{n}{n + 1}\right)} &=
        \lim_{n \to \infty} \frac{\frac{1}{n}\frac{1}{n+1}}
        {(-1)n^{-2}}\\
        \lim_{n \to \infty} n \ln{\left(\frac{n}{n + 1}\right)} &=
        \lim_{n \to \infty} (-1) n^{2} \frac{1}{n(n+1)}\\
        \lim_{n \to \infty} n \ln{\left(\frac{n}{n + 1}\right)} &=
        \lim_{n \to \infty} -\frac{n}{n+1}\\
        \lim_{n \to \infty} n \ln{\left(\frac{n}{n + 1}\right)} &= -1
        \end{aligned}
        $$
        Então
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &=3 e^{-1}\\
        \lim_{n \to \infty} \frac{a_{n+1}}{a_{n}} &= \frac{3}{e}\\
        \end{aligned}
        $$
        Como $e<3$, então o limite é maior do que $1$, e portanto, pelo critério da razão, a série diverge.

    12. $\sum_{n=1}^{\infty} \frac{e^{\frac{1}{n}}}{n^{n}}$

        É facil ver que todos os termos da série são positivos. Seja então $a_{n}$ o termo geral da série. Vamos aplicar o critério da raiz:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \sqrt[n]{a_{n}} &=
        \lim_{n \to \infty} \sqrt[n]{\frac{e^{\frac{1}{n}}}{n^{n}}}\\
        \lim_{n \to \infty} \sqrt[n]{a_{n}} &=
        \lim_{n \to \infty} \frac{e^{\frac{1}{n^{2}}}}{n}\\
        \lim_{n \to \infty} \sqrt[n]{a_{n}} &= 0
        \end{aligned}
        $$
        Então, pelo critério da raiz, a série é convergente.

3. Expresse as seguintes representaçoes decimais como quociente de 2 inteiros:

    1. $1,\overline{29}$

        Temos que:
        $$
        \begin{aligned}
        1,\overline{29} &= 1 + \sum_{n=1}^{\infty} \frac{29}{100^{n}}\\
        1,\overline{29} &= 1 + 29 \sum_{n=1}^{\infty} \frac{1}{100^{n}}\\
        \end{aligned}
        $$
        Seja $a_{n} = \frac{1}{100^{n}}$. Então $\sum_{n=1}^{\infty} a_{n}$ é uma série geométrica de razão $r = \frac{1}{100}$.

        Então,
        $$
        \begin{aligned}
        1,\overline{29} &= 1 + 29 \left(\frac{1}{1 - \frac{1}{100}} - 1\right)\\
        1,\overline{29} &= 1 + 29 \left(\frac{1}{\frac{99}{100}} - 1\right)\\
        1,\overline{29} &= 1 + 29 \left(\frac{100}{99} - 1\right)\\
        1,\overline{29} &= 1 + 29 \frac{1}{99}\\
        1,\overline{29} &= \frac{99 + 29}{99}\\
        1,\overline{29} &= \frac{128}{99}\\
        \end{aligned}
        $$

    2. $0,3\overline{117}$

        Temos que:
        $$
        \begin{aligned}
        0,3\overline{117} &= \frac{3}{10} + \sum_{n=1}^{\infty} \frac{117}{1000^{n+2}}\\
        0,3\overline{117} &= \frac{3}{10} + \frac{117}{10} \sum_{n=1}^{\infty} \frac{1}{1000^{n}}\\
        \end{aligned}
        $$
        Seja $a_{n} = \frac{1}{1000^{n}}$. Então $\sum_{n=1}^{\infty} a_{n}$ é uma série geométrica de razão $r = \frac{1}{1000}$.

        Então,
        $$
        \begin{aligned}
        0,3\overline{117} &= \frac{3}{10} + \frac{117}{10}
        \left(\frac{1}{1 - \frac{1}{1000}} - 1\right)\\
        0,3\overline{117} &= \frac{3}{10} + \frac{117}{10}
        \frac{1}{999}\\
        0,3\overline{117} &= \frac{3}{10} + \frac{13}{1110}\\
        0,3\overline{117} &= \frac{333 + 13}{1110}\\
        0,3\overline{117} &= \frac{346}{1110}\\
        0,3\overline{117} &= \frac{173}{555}
        \end{aligned}
        $$

4. Seja $(a_{n})$ uma sequência qualquer dos dígitos $0, 1, 2, \ldots, 9$. Mostre que é convergente a série
    $$
    \begin{aligned}
    \frac{a_{1}}{10} + \frac{a_{2}}{100} + \ldots + \frac{a_{n}}{10^{n}} + \ldots
    \end{aligned}
    $$

    Podemos representar a série como:
    $$
    \begin{aligned}
    \sum_{n=1}^{\infty} \frac{a_{n}}{10^{n}}
    \end{aligned}
    $$
    Note que essa série sé tem termos positivos.

    Seja $b_{n} = \frac{9}{10^{n}}$. Então note que $a_{n} \leq b_{n}$. Sabemos que $\sum_{n=1}^{\infty} b_{n}$ converge, pois trata-se de uma série geométrica de razão $r = \frac{1}{10}$.
    Então, como $a_{n} \leq b_{n}$ e $\sum_{n=1}^{\infty} b_{n}$ converge, $\sum_{n=1}^{\infty} a_{n}$ também deve convergir, pelo critério da comparação.

5. Decida se cada uma das séries abaixo é convergente. Se possível, calcule sua soma.

    1. $\sum_{n=0}^{\infty} \left(\frac{1}{10^{n}} + 2^{n}\right)$

        Seja $a_{n} = \frac{1}{10^{n}} + 2^{n}$. Então temos
        $$
        \begin{aligned}
        \lim_{n \to \infty} a_{n} &=
        \lim_{n \to \infty} \left(\frac{1}{10^{n}} + 2^{n}\right)\\
        \lim_{n \to \infty} a_{n} &= \infty
        \end{aligned}
        $$
        Então a série é divergente.

    2. $\sum_{k=0}^{\infty} (-1)^{k} t^{\frac{k}{2}}$, para $0 < t < 1$

        Podemos escrever a série como:
        $$
        \begin{aligned}
        \sum_{k=0}^{\infty} (-1)^{k} b_{k}
        \end{aligned}
        $$
        Onde
        $$
        \begin{aligned}
        b_{k} = \left(\frac{1}{t}\right)^{-\frac{k}{2}}
        \end{aligned}
        $$
        Note que $b_{k}$ é uma sequência de termos positivos e decrescente, pois $\frac{1}{t} > 1$.

        Então a série converge.

        Essa série é uma série geométrica com $r = -\sqrt[]{t}$. Então temos que:
        $$
        \begin{aligned}
        \sum_{k=0}^{\infty} (-1)^{k} t^{\frac{k}{2}} &=
        \frac{1}{1 + \sqrt[]{t}}\\
        \sum_{k=0}^{\infty} (-1)^{k} t^{\frac{k}{2}} &=
        \frac{1 - \sqrt[]{t}}{1 - t}
        \end{aligned}
        $$

    3. $\sum_{n=0}^{\infty} \sin^{2n}x$ para $|x| < \frac{\pi}{2}$

        Se $|x| < \frac{\pi}{2}$, então $-1 < \sin x < 1$, então $\sin^{2} x < 1$, e $\sin^{2n} x = (\sin^{2}x)^{n}$ é uma progressão geométrica de razão $\sin^{2} x < 1$. Logo, a série converge.

        Então, temos:
        $$
        \begin{aligned}
        \sum_{n=0}^{\infty} \sin^{2n}x &=
        \frac{1}{1 - \sin^{2}x}\\
        \sum_{n=0}^{\infty} \sin^{2n}x &=
        \frac{1}{\cos^{2}x}\\
        \sum_{n=0}^{\infty} \sin^{2n}x &=
        \sec^{2} x
        \end{aligned}
        $$

    4. $\sum_{n=1}^{\infty} \cos \left(\frac{n \pi}{2}\right)$

        Note que
        $$
        \begin{aligned}
        \cos \left(\frac{n \pi}{2}\right) = \cos \left(n \frac{\pi}{2}\right)
        \end{aligned}
        $$
        E
        $$
        \begin{aligned}
        \cos \left(n \frac{\pi}{2}\right) =
        \begin{cases}
        0, \ &\text{para } n \text{ ímpar}\\
        1, \ &\text{para } n \equiv 0 \pmod{4}\\
        -1, \ &\text{para } n \equiv 2 \pmod{4}
        \end{cases}
        \end{aligned}
        $$
        Portanto, não existe $\lim_{n \to \infty} \cos \left(\frac{n \pi}{2}\right)$, e então a série é divergente.

    5. $\sum_{n=1}^{\infty} \frac{1}{\sqrt[]{n+1} + \sqrt[]{n}}$

        Seja $a_{n} = \frac{1}{\sqrt[]{n+1} + \sqrt[]{n}}$, e $b_{n} = \frac{1}{n}$, o termo geral da série harmônica. Sabemos que a série harmônica diverge. Vamos então aplicar o critério da comparação no limite.
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &=
        \lim_{n \to \infty} \frac{n}{\sqrt[]{n+1} + \sqrt[]{n}}\\
        \lim_{n \to \infty} \frac{a_{n}}{b_{n}} &= \infty
        \end{aligned}
        $$
        Assim, pelo critério da comparação no limite, a série diverge.

    6. $\sum_{n=1}^{\infty} \frac{n}{\sin n}$

        Note que $\lim_{n \to \infty} \sin n$ não existe, portanto $\lim_{n \to \infty} \frac{n}{\sin n}$ também não existe, e então a série é divergente.

6. Decida se a série converge absolutamente, condicionalmente, ou diverge:

    1. $\sum_{n=1}^{\infty} (-1)^{n} \frac{1}{\sqrt[]{n}}$

        Temos que:
        $$
        \begin{aligned}
        |(-1)^{n} \frac{1}{\sqrt[]{n}}| = \frac{1}{\sqrt[]{n}}
        \end{aligned}
        $$
        Sabemos que essa série deve divergir, pois $\frac{1}{n} \leq \frac{1}{\sqrt[]{n}}$ para todo $n \geq 1$, e a série $\sum_{n=1}^{\infty} \frac{1}{n}$ diverge. Então a série não e absolutamente convergente. Note que a série em questao é uma série alternada, então vamos aplicar o teste para séries alternadas.

        Note que $\sqrt[]{n}$ é crescente e positiva, logo, $\frac{1}{\sqrt[]{n}}$ é decrescente e positiva.
        Veja que $\lim_{n \to \infty} \frac{1}{\sqrt[]{n}} = 0$, então, pelo critério das séries alternadas, a série converge.

        Como a série converge, mas não converge absolutamente, então a série é condicionalmente convergente.

    2. $\sum_{n=1}^{\infty} \frac{(-1)^{n+1}}{n^{\frac{3}{2}}}$

        Seja $a_{n} = |\frac{(-1)^{n+1}}{n^{\frac{3}{2}}}| = \frac{1}{n^{\frac{3}{2}}}$. Trata-se então da série harmônica generalizada com $\alpha = \frac{3}{2}$. Então $\sum_{n=1}^{\infty} a_{n}$ deve convergir. Assim, a série dada converge absolutamente.

7. Determine os valores de $x \in \mathbb{R}$ para os quais as séries convergem.

    1. $\sum_{n=1}^{\infty} x^{n}(1 + x^{n})$

        Primeiramente, vamos analizar o caso em que $x = 0$.
        Então a nossa série fica $\sum_{n=1}^{\infty} 0(1 + 0)$ e a série é convergente.

        Vamos então analisar o caso em que $x \neq 0$. Para isso, vamos aplicar o critério da razão para séries de termos quaisquer. Seja $a_{n} = x^{n}(1 + x^{n})$, então temos:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        \lim_{n \to \infty} \left|\frac{x^{n + 1}(1 + x^{n + 1})}{x^{n}(1 + x^{n})}\right| \\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        \lim_{n \to \infty}
        \left|\frac{x^{n + 1} + x^{2n + 2}}
        {x^{n}(1 + x^{n})}\right| \\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        \lim_{n \to \infty}
        \left|\frac{x^{n}(x + x^{n + 2})}
        {x^{n}(1 + x^{n})}\right| \\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        \lim_{n \to \infty}
        \left|\frac{x + x^{n + 2}}
        {1 + x^{n}}\right| \\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        |x| \lim_{n \to \infty}
        \left|\frac{1 + x^{n + 1}}
        {1 + x^{n}}\right| \\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        |x| \lim_{n \to \infty}\left|
        x \cdot \frac{x^{n}}{1 + x^{n}} +
        \frac{1}{1 + x^{n}}\right|
        \end{aligned}
        $$
        Caso $|x| < 1$, então $\lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| = |x| \cdot 1 < 1$, e a série será convergente.

        Caso $x > 1$, então temos:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        x \lim_{n \to \infty}\left(
        x \cdot \frac{x^{n}}{1 + x^{n}} +
        \frac{1}{1 + x^{n}}\right)\\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        x \left(\left(\lim_{n \to \infty}
        x \cdot \frac{x^{n}}{1 + x^{n}}\right) +
        \left(\lim_{n \to \infty} \frac{1}{1 + x^{n}}\right)\right)\\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        x \left(x \left(\lim_{n \to \infty}
        \cdot \frac{x^{n}}{1 + x^{n}}\right) +
        0\right)\\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        x(x \cdot 1)\\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &= x^{2}
        \end{aligned}
        $$
        Como $x > 1$, então $\lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| = x^{2} > 1$, portanto a série será divergente.

        Para $x < -1$, note que $\lim_{n \to \infty} \left|\frac{1}{1+x^{n}}\right| = 0$, portanto $\lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| = \lim_{n \to \infty} \left|x \cdot \frac{x^{n}}{1 + x^{n}}\right|$. Então:
        $$
        \begin{aligned}
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        \lim_{n \to \infty} \left|x \cdot \frac{x^{n}}{1 + x^{n}}\right|\\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        |x| \lim_{n \to \infty} \left|\frac{x^{n}}{1 + x^{n}}\right|\\
        \end{aligned}
        $$
        Note que
        $$
        \begin{aligned}
        1+x^{n} < 0 \implies x^{n} < 0
        \end{aligned}
        $$
        Portanto,
        $$
        \begin{aligned}
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &=
        |x| \lim_{n \to \infty}\frac{x^{n}}{1 + x^{n}}\\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right| &= |x|
        \end{aligned}
        $$
        Então $\lim_{n \to \infty}\left|\frac{a_{n+1}}{a_{n}}\right| = |x| > 1$, e a série diverge.

        Para $x = 1$, temos que $\lim_{n \to \infty} x^{n}(1 + x^{n}) = 2 \neq 0$, portanto a série diverge.

        Para $x = -1$, temos que $\lim_{n \to \infty} x^{n}(1 + x^{n})$ não existe, portanto a série diverge.

        Concluímos assim que a série é convergente se e somente se $|x| < 1$.

    2. $\sum_{n=1}^{\infty} x^{n} \cos \left(\frac{n \pi}{2}\right)$

        Para $x = 0$, temos que $x^{n} \cos \left(\frac{n \pi}{2}\right) = 0$, portanto a série converge, e tem soma infinita igual a 0.

        Para $|x| > 1$, $\lim_{n \to \infty} x^{n} \cos\left(\frac{n \pi}{2}\right)$ não existe, portanto a série diverge.

        Para $x = 1$, $\lim_{n \to \infty} x^{n} \cos\left(\frac{n \pi}{2}\right)$ não existe, portanto a série diverge.

        Para $x = -1$, $\lim_{n \to \infty} x^{n} \cos\left(\frac{n \pi}{2}\right)$ não existe.

        Para $|x| < 1$, vamos analisar a convergência de $\sum_{n=1}^{\infty} |x^{n} \cos \left(\frac{n \pi}{2}\right)|$. Temos que $|x^{n} \cos \left(\frac{n \pi}{2}\right)| = |x^{n}| \cdot |\cos \left(\frac{n \pi}{2}\right)|$, e $|\cos \left(\frac{n \pi}{2}\right)| \leq 1$. Portanto, $|x^{n} \cos \left(\frac{n \pi}{2}\right)| \leq |x^{n}|$.

        Para $|x| < 1$, a série $\sum_{n=1}^{\infty} |x^{n}|$ é uma série geométrica com razão $r = |x| < 1$, portanto $\sum_{n=1}^{\infty} |x^{n}|$ converge, e então $|x^{n} \cos \left(\frac{n \pi}{2}\right)|$ converge também. Então, para $|x| < 1$, a série converge absolutamente.

    3. $\sum_{n=1}^{\infty} n!x^{n}$

        Para $x = 0$, temos que $n!x^{n} = 0$, então a série converge.

        Para $x \neq 0$, vamos aplicar o critério da razão para séries de termos quaisquer. Seja $a_{n} = n!x^{n}$
        $$
        \begin{aligned}
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right|&=
        \lim_{n \to \infty} \left|\frac{(n+1)!x^{n+1}}{n!x^{n}}\right|\\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right|&=
        \lim_{n \to \infty} \left|(n+1) x\right|\\
        \lim_{n \to \infty} \left|\frac{a_{n+1}}{a_{n}}\right|&= \infty
        \end{aligned}
        $$
        Então a série converge se e somente se $x = 0$.

## Convergência Pontual e Uniforme

1. Determine o domínio da função dada por:

    $$
    \begin{aligned}
    f(x) = \lim_{n \to \infty} f_{n}(x)
    \end{aligned}
    $$

    1. $f_n(x) = e^{nx}$

        Temos que:
        $$
        \begin{aligned}
        \lim_{n \to \infty} e^{nx} &= e^{x (\lim_{n \to \infty} n)}\\
        \lim_{n \to \infty} e^{nx} &= e^{x \infty}\\
        \end{aligned}
        $$
        Entao a funcao vai convergir se e somente se $x \leq 0$. Assim, o dominio de $f(x)$ eh $x \in ]-\infty, 0]$.

    2. $f_{n}(x) = \frac{nx}{1 + nx^{2}}$

        Note que, para $x = 0$,
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{nx}{1 + nx^{2}} &=
        \lim_{n \to \infty} \frac{0}{1+0}\\
        \lim_{n \to \infty} \frac{nx}{1 + nx^{2}} &=0
        \end{aligned}
        $$
        Entao a sequencia converge para $f(x) = 0$.

        Temos que, para $x \neq 0$,
        $$
        \begin{aligned}
        \lim_{n \to \infty} \frac{nx}{1 + nx^{2}} &=
        \lim_{n \to \infty} \frac{x}{\frac{1}{n} + x^{2}}\\
        \lim_{n \to \infty} \frac{nx}{1 + nx^{2}} &= \frac{1}{x}
        \end{aligned}
        $$
        Entao, para $x \neq 0$, $f(x) = \frac{1}{x}$.

        Entao, temos que:
        $$
        \begin{aligned}
        f(x) =
        \begin{cases}
        0, &\text{para } x=0\\
        \frac{1}{x}, &\text{para } x \neq 0
        \end{cases}
        \end{aligned}
        $$
        E o dominio de $f(x)$ eh $x \in \mathbb{R}$.

    3. $f_{n}(x) = nxe^{-nx^{2}}$

        Caso $x = 0$, temos que $nxe^{-nx^{2}} = 0 \cdot 1 = 0$, portanto a sequencia converge para $0$.

        Caso $x \neq 0$, temos que:
        $$
        \begin{aligned}
        \lim_{n \to \infty} nxe^{-nx^{2}} &=
        x \lim_{n \to \infty} ne^{-nx^{2}}\\
        \lim_{n \to \infty} nxe^{-nx^{2}} &=
        x \lim_{n \to \infty} e^{\ln{n} -nx^{2}}\\
        \lim_{n \to \infty} nxe^{-nx^{2}} &=
        x e^{\lim_{n \to \infty} \ln{n} -nx^{2}}\\
        \lim_{n \to \infty} \ln{n} -nx^{2} &= -\infty\\
        \lim_{n \to \infty} nxe^{-nx^{2}} &= x \cdot 0\\
        \lim_{n \to \infty} nxe^{-nx^{2}} &= 0
        \end{aligned}
        $$
        Entao a sequencia converge para todo $x \in \mathbb{R}$, a saber, para $f(x) = 0$.

## Funcoes diferenciaveis

1. Seja $z = f(x,y) = x^{2} + y^{2}$. Encontre a equacao do plano tangente a funcao no ponto $(1, 2, 5)$.

Seja $F(x, y, z) = x^{2} + y^{2} - z$ temos entao que $F(x, y, z) = 0$ define $z$ como uma funcao implicita de $x,y$, mais especificamente, $z = x^{2} + y^{2}$. Temos entao que $\nabla F(x, y, z)$ eh um vetor normal ao plano tangente a superficie de nivel $(x, y, f(x, y))$.  
Temos que:
$$
\begin{aligned}
\nabla F(x, y, z) &= (2x, 2y, -1)\\
(2(1), 2(2), -1) \cdot (x - 1, y - 2, z - 5) &= 0\\
(2, 4, -1) \cdot (x - 1, y - 2, z - 5) &= 0\\
2 (x - 1) + 4 (y - 2) - (z - 5) &= 0\\
2 x - 2 + 4 y - 8 + 5 - z &= 0\\
2x + 4y - z &= 5\\
\end{aligned}
$$
