1.
    $$
        \begin{align*}
            a_n &= \dfrac{n-1}{n}\\
            \lim_{n \to \infty} \frac{n-1}{n} &=
            1
        \end{align*}
    $$
2.
    $$
        \begin{align*}
            a_{2n - 1} &= \dfrac{1}{2^n}\\
            a_{2n} &= \dfrac{1}{2^{n-1}} -1
        \end{align*}
    $$
    Temos então, dentro da mesma sequência $a_n$, duas subsequências distintas, e
    $$
        \begin{align*}
            \lim_{n \to \infty}a_{2n - 1} &= 0\\
            \lim_{n \to \infty}a_{2n} &= -1
        \end{align*}
    $$
    Como as subseqências convergem para valores diferentes, então a sequência original não pode ser convergente.
    $$
        \begin{align*}
            \lim_{n \to \infty}\left(
                4 + \dfrac{1}{n}
            \right)^{\frac{1}{2}} &=
            \left(
                4 + \lim_{n \to \infty} \dfrac{1}{n}
            \right)^{\frac{1}{2}}\\
            \lim_{n \to \infty}\left(
                4 + \dfrac{1}{n}
            \right)^{\frac{1}{2}} &=
                (4 + 0)
            ^{\frac{1}{2}}\\
            \lim_{n \to \infty}\left(
                4 + \dfrac{1}{n}
            \right)^{\frac{1}{2}} &= 2
        \end{align*}
    $$
3. $a_n = \left( 4 + \frac{1}{n} \right)^{\frac{1}{n}}$

    $$
        \lim_{n \to \infty} \left( 4 + \frac{1}{n} \right)^{\frac{1}{n}} \overset{x = \frac{1}{n}}{=}
        \lim_{x \to 0^+} (4 + x)^x
    $$
    Como $\ln (4 + x)^x = x \ln (4 + x)$, temos que
    $$
        \begin{align*}
           \lim_{x \to 0⁺} x \ln (4 + x) &=
           \lim_{x \to 0⁺} x  \cdot \lim_{x \to 0^+} \ln (4 + x)\\
           \lim_{x \to 0⁺} x \ln (4 + x) &= 0 \cdot \ln 4 = 0
        \end{align*}
    $$
    Então temos que
    $$
        \lim_{n \to \infty} \left( 4 + \frac{1}{n} \right)^{\frac{1}{n}} = e^0 = 1
    $$
4. $a_{n} = \frac{\sqrt[]{n}+1}{n-1},\  n \geq 2$
    $$
        \begin{align*}
           \lim_{n \to \infty} \frac{\sqrt[]{n}+1}{n-1} &=
           \lim_{n \to \infty} \frac{\sqrt[]{n}}{n-1} +
           \lim_{n \to \infty} \frac{1}{n-1}\\
           \lim_{n \to \infty} \frac{\sqrt[]{n}+1}{n-1} &= 0 + 0 = 0
        \end{align*}
    $$
5. $a_{n} = \frac{n³+3n+1}{4n³+2}$
    $$
        \begin{align*}
           \lim_{n \to \infty} \frac{n³+3n+1}{4n³+2} &=
           \lim_{n \to \infty} \frac{1+3n^{-2}+n^{-3}}{4+2n^{-3}}\\
           \lim_{n \to \infty} \frac{n³+3n+1}{4n³+2} &=
            \lim_{n \to \infty} \frac{1}{4+2n^{-3}} +
            \lim_{n \to \infty} \frac{3n^{-2}}{4+2n^{-3}} +
            \lim_{n \to \infty} \frac{n^{-3}}{4+2n^{-3}}\\
            \lim_{n \to \infty} \frac{n³+3n+1}{4n³+2} &=
            \frac{1}{4} + 0 + 0 = \frac{1}{4}
        \end{align*}
    $$
6. $a_{n} = \sqrt[]{n+1} - \sqrt[]{n}$
    Como $a_{n} = \sqrt[]{n+1} - \sqrt[]{n} = \frac{n + 1 - n}{\sqrt[]{n+1} + \sqrt[]{n}} = \frac{1}{\sqrt[]{n+1} + \sqrt[]{n}}$, então temos
    $$
        \begin{align*}
           \lim_{n \to \infty} \sqrt[]{n+1} + \sqrt[]{n} &= \lim_{n \to \infty} \frac{1}{\sqrt[]{n+1} + \sqrt[]{n}}\\
           \lim_{n \to \infty} \sqrt[]{n+1} + \sqrt[]{n} &= 0
        \end{align*}
    $$
7. $a_{n} = \frac{n+(-1)^n}{n-(-1)^n}$
    $$
        \begin{align*}
           \lim_{n \to \infty} \frac{n+(-1)^n}{n-(-1)^n} &=
           \lim_{n \to \infty}
           \frac{1+(-1)^n/n}{1-(-1)^n/n}\\
           \lim_{n \to \infty} \frac{n+(-1)^n}{n-(-1)^n} &=
           \frac{1 + 0}{1 - 0} = 1
        \end{align*}
    $$
8. $a_{n} = \frac{2n}{n+1} - \frac{n+1}{2n}$
    $$
        \begin{align*}
           \lim_{n \to \infty} \frac{2n}{n+1} - \frac{n+1}{2n} &=
           \lim_{n \to \infty} \frac{2n}{n+1} - \lim_{n \to \infty} \frac{n+1}{2n}\\
           \lim_{n \to \infty} \frac{2n}{n+1} - \frac{n+1}{2n} &= 2 - \frac{1}{2} = \frac{3}{2}
        \end{align*}
    $$
9. $a_{n} = \frac{\sin n}{n}$
    Como $\sin n \leq 1$ e $\lim_{n \to \infty} \frac{1}{n} = 0$, temos que $\lim_{n \to \infty} \frac{\sin n}{n} = 0$
10. $a_{n} = \left( \frac{3n+5}{5n+11} \right)^n$
    $\ln (\left( \frac{3n+5}{5n+11} \right)^n) = n \ln (\frac{3n + 5}{5n+11})$
    Como $\lim_{n \to \infty} n = \infty$, e $\lim_{n \to \infty} \ln (\frac{3n+5}{5n+11}) = ln(3/5) < 0$, então $\lim_{n \to \infty} n \ln (\frac{3n + 5}{5n+11}) = -\infty$. Então $\lim_{n \to \infty} \left( \frac{3n+5}{5n+11} \right)^n = e^{-\infty} = 0$.
11. $a_{n} = \frac{(n+3)!-n!}{(n+4)!}$
    $a_{n} = \frac{(n+3)!}{(n+4)!} - \frac{n!}{(n+4)!} = \frac{1}{(n+4)} - \frac{1}{(n+4)(n+3)(n+2)(n+1)}$
    Então, $\lim_{n \to \infty} a_{n} = 0 - 0 = 0$
12. $a_{n} = \frac{n\sin (n!)}{n²+1}$
    $a_{n} = \frac{n}{n²+1} \frac{\sin (n!)}{n²+1}$
    Então, $\lim_{n \to \infty} a_{n} = \lim_{n \to \infty} \frac{n}{n²+1} \cdot \lim_{n \to \infty} \frac{\sin (n!)}{n²+1} = 0 \cdot 0 = 0$
13. $a_{n} = \left( \frac{n+1}{n+2} \right)^n$
    Seja $u=n+2$, (e $n=u-2$). Então $a_{n} = \left( \frac{u-1}{u} \right)^{u-2}$.
    Então temos:
    $$
        \begin{align*}
            \lim_{n \to \infty} a_{n} &= \lim_{u \to \infty} \left( \frac{u-1}{u} \right)^{u-2}\\
            \lim_{n \to \infty} a_{n} &= \lim_{u \to \infty} \left( \frac{u-1}{u} \right)^{u} \cdot \lim_{u \to \infty} \left( \frac{u}{u-1} \right)²\\
            \lim_{n \to \infty} a_{n} &= e^{-1} \cdot 1^2 = e^{-1}
        \end{align*}
    $$
14. $a_{n} = \sqrt[n]{n}$
    $\ln \sqrt[n]{n} = \frac{\ln n}{n}$
    $\lim_{n \to \infty} \frac{\ln n}{n} = 0$
    Então, $\lim_{n \to \infty} a_n = e^0 = 1$.
15. $a_{n} = \left( \frac{n+1}{n} \right)^{\sqrt[]{n}}$
    Como $\sqrt[]{n} = n^{\frac{1}{2}}$, temos que:
    $$
        \lim_{n \to \infty} a_{n} = \lim_{n \to \infty} \left( \frac{n+1}{n} \right)^{n ^{\frac{1}{2}}} = \sqrt[]{e}
    $$
16. $a_{n} = \frac{2n + \sin (n)}{5n+1}$.
    $$
        \lim_{n \to \infty} a_n = \lim_{n \to \infty} \frac{2n}{5n+1} + \lim_{n \to \infty} \frac{\sin n}{5n+1} = \frac{2}{5} + 0 = \frac{2}{5}
    $$
17. $a_{n} = (1 + \frac{1}{n²})^n$.
    Seja $u = n^2$. Então $a_{n} = (1 + \frac{1}{u})^{\sqrt[]{u}}$. Então $\lim_{n \to \infty} a_n = \sqrt[]{e}$.
18. $a_{n} = -n-n^3$.
    É fácil ver que $\lim_{n \to \infty} a_{n} = -\infty $.
19.
    1. $a_{n + 1} = \sqrt[]{2 a_{n}}$, com $a_{1} = \sqrt[]{2}$.
       I. $a_{n}$ é crescente:
       $$
            \begin{align*}
                a_{n+1} - a_{n} \geq 0 &\iff
                \sqrt[]{2 a_{n}} - a_{n} \geq 0\\
                a_{n+1} - a_{n} \geq 0 &\iff
                \sqrt[]{2 a_{n}} \geq a_{n}\\
                a_{n+1} - a_{n} \geq 0 &\iff
                2 a_{n} \geq a_{n}²\\
                a_{n+1} - a_{n} \geq 0 &\iff
                2 \geq a_{n}
            \end{align*}
       $$
       Temos então que provar II:
       II. $a_{n} \leq 2$.
       $$
            \begin{align*}
               a_{n} \leq 2 &\implies 2 a_{n} \leq 4\\
               a_{n} \leq 2 &\implies \sqrt[]{2 a_{n}} \leq \sqrt[]{4}\\
               a_{n} \leq 2 &\implies a_{n+1} \leq 2\\
            \end{align*}
       $$
       Como $a_{1} = \sqrt[]{2} \leq 2$, então está provado que $a_{n}$ é crescente e limitada.
       Podemos então escrever:
       $$
            \begin{align*}
               \lim_{n \to \infty} a_{n+1} &=
               \lim_{n \to \infty} a_{n} = L\\
               L &= \sqrt[]{2L}\\
               L^2 &= 2L\\
               L &= 2
            \end{align*}
       $$
       Portanto, $\lim_{n \to \infty} a_{n} = 2$.
    2. $a_{n+1} = \sqrt[]{2 + a_{n}}$, e $a_{1} = \sqrt[]{2}$.
       I. $a_{n}$ é crescente:
       $$
            \begin{align*}
                a_{n+1} \geq a_{n} &\iff
                \sqrt[]{2 + a_{n}} \geq a_{n}\\
                a_{n+1} \geq a_{n} &\iff
                2 + a_{n} \geq a_{n}²\\
                a_{n+1} \geq a_{n} &\iff
                2 \geq a_{n}² - a_{n}\\
            \end{align*}
       $$
       Provaremos isso mais tarde.
       II. $a_{n}$ é limitada superiormente por $2$.
       $$
            \begin{align*}
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
            \end{align*}
       $$
       Como $a_1 = \sqrt[]{2} \leq 2$, então está completa a prova de que $a_{n}$ é limitada superiormente por $2$. Como $a_{n} \leq 2 \implies a_{n}² - a_{n} \leq 2 \iff a_{n+1} \geq a_{n}$, então também está provado que $a_{n}$ é crescente.
        Então podemos escrever:
        $$
            \begin{align*}
               \lim_{n \to \infty} a_{n} &=
               \lim_{n \to \infty} a_{n+1} = L\\
               L &= \sqrt[]{2 + L}\\
               L² &= 2 + L\\
               L² - L &= 2\\
               L &= 2
            \end{align*}
        $$
        Assim, $\lim_{n \to \infty} a_{n} = 2$.
    3. $a_{n+1} = \sqrt[]{2}^{a_{n}}$, e $a_{1} = \sqrt[]{2}$.
        I. $a_{n}$ é crescente:
        $$
            \begin{align*}
                a_{n+1} \geq a_{n} &\iff \sqrt[]{2}^{a_{n}} \geq a_{n}\\
                a_{n+1} \geq a_{n} &\iff \sqrt[]{2} \geq 2 \log_{2} a_{n}\\
                a_{n+1} \geq a_{n} &\iff 2 \geq 4 (\log_{2} a_{n})²\\
                a_{n+1} \geq a_{n} &\iff \log_{2} a_{n}\leq \sqrt[]{\frac{1}{2}}\\
            \end{align*}
        $$
        Como $\log_{2} a_{1}= \log_{2} \sqrt[]{2} = \frac{1}{2}$, e $\frac{1}{2} \leq \sqrt[]{\frac{1}{2}} \iff \frac{1}{4} \leq \frac{1}{2}$, então está provado que $a_{n}$ é crescente.
        II. $a_{n}$ é limitada superiormente por $2$.
        $$
            \begin{align*}
                a_{n} \leq 2 &\implies
                \sqrt[]{2}^{a_{n}} \leq \sqrt[]{2}^{2}\\
                a_{n} \leq 2 &\implies
                a_{n+1} \leq 2\\
            \end{align*}
        $$
        Como $a_{1} = \sqrt[]{2} \leq 2$, então está provado que $a_{n}$ é limitada superiormente por $2$.
        Então, podemos escrever que $L = \lim_{n \to \infty} a_{n+1} = \lim_{n \to \infty} a_{n}$, e $\sqrt[]{2}^{L} = L$
        $$
            \begin{align*}
                \sqrt[]{2}^{L} &= L\\
                L &= 2 \log_{2} L\\
                2^L &= L^2\\
                L &= 2
            \end{align*}
        $$
    4. Seja $\alpha > 0$, e $x_{1} > \sqrt[]{\alpha}$, e
        $$
            x_{n+1} = \frac{1}{2}\left(
                x _{n} + \frac{\alpha}{x_{n}}
             \right)
        $$
        Para $n > 1$
        I. $x_{n}$ é decrescente:
        $$
            \begin{align*}
                x_{n+1} \leq x_{n} &\iff
                \frac{1}{2}\left(
x_{n} + \frac{\alpha}{x _{n}}
                \right) \leq x_{n}\\
                x_{n+1} \leq x_{n} &\iff
                x _{n} + \frac{\alpha}{x_{n}}
                \leq 2 x_{n}\\
                x_{n+1} \leq x_{n} &\iff
x_{n}^{2} + \alpha
                \leq 2 x_{n}^{2}\\
                x_{n+1} \leq x_{n} &\iff
                \alpha \leq x_{n}^{2}\\
                x_{n+1} \leq x_{n} &\iff
                \sqrt[]{\alpha} \leq x_{n}
            \end{align*}
        $$
        Vamos terminar de provar isso assim que provarmos que:
        II. $x_{n}$ é limitada inferiormente por $\sqrt[]{\alpha}$:
        $$
            \begin{align*}
                x_{n} \geq \sqrt[]{\alpha} &\implies
                x_{n} + \frac{\alpha}{x_{n}} \geq
                \sqrt[]{\alpha} + \frac{\alpha}{\sqrt[]{\alpha}}\\
                x_{n} \geq \sqrt[]{\alpha} &\implies
                x_{n} + \frac{\alpha}{x_{n}} \geq
                2\  \sqrt[]{\alpha}\\
                x_{n} \geq \sqrt[]{\alpha}&\implies
                \frac{1}{2}\left( x_{n} + \frac{\alpha}{x_{n}} \right) \geq
                \frac{1}{2} 2\  \sqrt[]{\alpha}\\
                x_{n} \geq \sqrt[]{\alpha}&\implies
                x_{n+1} \geq
                \sqrt[]{\alpha}\\
            \end{align*}
        $$
        Assim, como $x_{1} > \sqrt[]{\alpha}$, então está provado que $x_{n}$ é decrescente e limitada inferiormente por $\sqrt[]{\alpha}$. Então podemos escrever que $L = \lim_{n \to \infty} x_{n+1} = \lim_{n \to \infty} x_{n}$, e então:
        $$
            \begin{align*}
               \frac{1}{2}\left( L + \frac{\alpha}{L} \right) &= L\\
               L^2 + \alpha &= 2L²\\
               L^2 &= \alpha\\
               L &= \sqrt[]{\alpha}
            \end{align*}
        $$
    5. Como $f$ é contínua em $A$, então temos que $f(a) = \lim_{x \to a} f(x)$.
    Temos que provar então que $\lim_{x \to a} f(x) = a$, isto é:
    $$
        \forall \epsilon > 0 (\exists \delta > 0 (
              |x - a| < \delta \implies |f(x) - a| < \epsilon
        ))
    $$
20.
    1. $a_{n} = a_{n-1} \frac{2n}{2n-1}$, com $a_{1} = 2$.
    I. $a_{n}$ é crescente:
    $$
        \begin{align*}
           a_{n} > a_{n - 1} &\iff
           \frac{2n}{2n-1} a_{n-1} > a_{n-1}\\
           a_{n} > a_{n - 1} &\iff
           \frac{2n}{2n-1} > 1\\
           a_{n} > a_{n - 1} &\iff
           2n > 2n - 1\\
        \end{align*}
    $$
    Portanto, contanto que $a_{n}$ seja positiva, ela é crescente.
    II. $a_{n}$ é limitada superiormente por $M$ (?)
    $$

    $$
