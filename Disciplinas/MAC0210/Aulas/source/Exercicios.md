# Exercícios

## Aproximações

1. Use o método das diferenças finitas para fazer uma aproximação da derivada da função $f(x) = e^{-2x}$ avaliada em $x_{0} = 0.5$.

   Sabemos que a função $f(x) = e^{-2x}$ tem derivada igual a $-2e^{-2x}$. Em $x = 0.5$ o valor dessa derivada é $\frac{-2}{e}$. No nosso código, avaliamos a derivada utilizando o método das diferenças finitas, ou seja: $f^{\prime }(x) \approx \frac{f(x + h) - f(x)}{h}$. Avaliamos essa expressão para diferentes valores de $h$.

    ```python {.cb-nb show=code+rich_output:png+stdout:raw name=ex1}
    import math
    import matplotlib.pyplot as plt

    def f(x):
        return math.exp((-2) * x)

    x_0 = 0.5
    f_x = f(x_0)
    actual = -2.0 * f(x_0)
    start = 1
    end = 18
    x = []
    y = []
    for i in range(start, end):
        h = 10.0 ** (-i)
        d_dx = (f(x_0 + h) - f_x) / h
        abs_diff = abs(d_dx - actual)
        rel_diff = abs_diff / abs(actual)
        x.append(h)
        y.append(rel_diff)
        print(f"\(10^{{-{i:02d}}} \quad {d_dx:+.20f} \quad{abs_diff:.10f} \quad {rel_diff:.10f}\)")
        
    plt.plot(x, y)
    plt.yscale('log')
    plt.xscale('log')
    ```

2. Use o método das diferenças finitas para fazer uma aproximação da derivada da função $f(x) = \sin x$ avaliada em $x_{0} = \frac{\pi }{2}$. Mostre que o erro desta aproximação é $\mathcal{O}(n²)$.

   Sabemos que a função $f(x) = \sin x$ tem derivada igual a $\cos x$. Em $x = \frac{\pi }{2}$ o valor dessa derivada é $0$. No nosso código, avaliamos a derivada utilizando o método das diferenças finitas, ou seja: $f^{\prime }(x) \approx \frac{f(x + h) - f(x - h)}{2h}$. Avaliamos essa expressão para diferentes valores de $h$.

    ```python {.cb-nb}
    import math
    import matplotlib.pyplot as plt

    x_0 = math.pi / 3.0
    actual = math.cos(x_0)
    start = 1
    end = 18
    x = []
    y = []
    for i in range(start, end):
        h = 10.0 ** (-i)
        d_dx = (math.sin(x_0 + h) - math.sin(x_0 - h)) / (2 * h)
        abs_diff = abs(d_dx - actual)
        rel_diff = abs_diff / abs(actual)
        x.append(h)
        y.append(rel_diff)
        print(f"\(10^{{-{i:02d}}} \quad {d_dx:+.20f} \quad{abs_diff:.10f} \quad {rel_diff:.10f}\)")
        
    plt.plot(x, y)
    plt.yscale('log')
    plt.xscale('log')
    ```

## Soluções de equações não-lineares

1. Utilize o método da bisecção para encontrar a raiz da função $f(x) = \sqrt[]{x} - 1.1$ começando do intervalo $[0,2]$, com $\text{atol} = 10^{-8}$.

    1. Quantas iterações são necessárias? A quantidade real de iterações é compatível com a nossa análise de convergência?

        Seguindo o modelo da nossa análise, temos que:
        $$
        \begin{align*}
            n &=  \left\lceil
                    \log_{2}
                    \dfrac{2}{2 \cdot 10 ^{-8}}
                \right\rceil \\
                n &= \left\lceil
                    \log_{2}
                    10 ^{8}
                \right\rceil \\
                n &= \left\lceil
                    8 \log_{2} 10
                \right\rceil \\
                n &= \lceil 26.5754247591 \rceil \\
                n &= 27
        \end{align*}
        $$

        ```python {.cb-nb}
        import math

        def f(x):
            return math.sqrt(x) - 1.1

        actual = 1.1 ** 2
        a = 0
        b = 2
        atol = 10 ** (-8)
        n = math.ceil(math.log2((b-a)/(2 * atol)))
        print(f"Quantidade de iterações: {n}")
        for i in range(n):
            p = (a + b) / (2.0)
            f_p = f(p)
            print(f"\(p= {p:+.10f}; \quad f(p)= {f_p:+.10f}\)")
            if f_p * f(a) < 0:
                b = p
            else:
                a = p
        
        abs_error = abs(actual - p)
        print(f"\(p= {p:+.10f}\)")
        print(f"\(\\text{{abs error}}= {abs_error:.2E}\)")
        ```

    2. Qual é o erro absoluto? Esse erro poderia ser predito pela nossa análise de convergência?

        A nossa análise de convergência nos garante que, após $27$ iterações, o erro absoluto deve ser menor do que $10^{-8}$, e de fato, o erro absoluto obtido foi de $|1.2099999934 - 10^{-8}| \approx 6.56E−09$.

## Iteração de ponto fixo

1. Considere a iteração de ponto fixo $x_{k+1} = g(x_{k})$, e deixe que todas as hipóteses do teorema do ponto fixo sejam verdadeiras. Use uma expansão da série de Taylor para mostrar que a ordem de convergência do método depende da quantidade de derivadas que desaparecem em $x = x^{*}$. Use esse resultado para mostrar o quão rápido esse método deve convergir para $g^{\prime }(x^{*}) = \dots = g^{(r)}(x^{*}) = 0$, onde o inteiro $r \geq 1$ é dado.

    Se as hipóteses do Teorema do Ponto Fixo são válidas, então temos que $g \in C^{r}[a,b]$, e $a \leq g(x) \leq b$, e além disso, existe $\rho < 1$ tal que $|g^{\prime }(x)| \leq \rho$.
    Temos que, segundo a expansão da série de taylor para a função $g(x)$ que:
    $$
    \begin{aligned}
    g(x_k) &= \sum_{n=0}^{r} \dfrac{g^{(n)}(x)}{n!} (x_k - x)^{n} + \dfrac{g^{(r + 1)}(\xi_{k})}{(r + 1)!} (x_k - x)^{r + 1}\\
    g(x_k) &= \dfrac{g^{(r + 1)}(\xi_k)}{(r + 1)!} (x_k - x^{*})^{r + 1}\\
    \end{aligned}
    $$
    Vamos definir $\varepsilon_{k}$ como o erro $x_{k} - x^{*}$. Como $g(x_{k}) = x_{k+1}$, temos
    $$
    \varepsilon_{k + 1} = \dfrac{g^{(r + 1)}(\xi_{k})}{(r + 1)!} \varepsilon_{k}^{r + 1} - x^{*}
    $$
    Vamos definir $C = \left|\dfrac{g^{(r + 1)}(\xi_{k})}{(r + 1)!}\right|$ então, temos que:
$$
\begin{aligned}
\varepsilon_{k+1} &= |C \varepsilon_{k}^{r+1} - x^{*}|\\
|C \varepsilon_{k}^{r+1} - x^{*}| &\leq |C \varepsilon_{k}^{r+1}| + |-x^{*}|\\
\varepsilon_{k+1} &\leq C \varepsilon_{k}^{r+1} + |x^{*}|\\
\end{aligned}
$$

2. Considere a função $g(x) = x^{2} + \frac{3}{16}$.

    1. Essa função tem dois pontos fixos. Quais são?

        Os pontos fixos dessa função são os pontos $x^{*}$ tais que $g(x^{*}) = x^{*}$, ou seja, ${x^*}^{2} + \frac{3}{16} = x^{*}$, isto é, as raízes da equação ${x^{*}}^{2} - x^{*} + \frac{3}{16} = 0$, que são os valores $\{\frac{1}{4}, \frac{3}{4}\}$.

    2. Considere a iteração de ponto fixo $x_{k+1} = g(x_{k})$. Para quais dos pontos fixos podemos ter certeza que a nossa iteração irá convergir?

        Segundo o teorema do ponto fixo, somente podemos ter certeza da convergência da iteração para um ponto fixo em uma vizinhança do ponto onde a primeira derivada da função for menor (em valor absoluto) do que $1$, isto é:
        $$
        |g^{\prime }(x)| < 1
        $$
        No nosso caso, então:
        $$
        |2x| < 1 \iff -\frac{1}{2} < x < \frac{1}{2}
        $$
        Assim, como dos pontos fixos que encontramos em (1), apenas $\frac{1}{4}$ atende esse requisito, a função somente irá convergir para esse ponto (claro, quando $-\frac{1}{2} < x < \frac{1}{2}$).

    3. Para o ponto ou pontos encontrados em (2), quantas iterações serão necessárias para reduzir o erro de convergência por um fator de 10?

        Temos que, segundo o teorema do valor intermediário, que $|x_{k} - \frac{1}{4}| \approx \rho^{k} |x_{0} - \frac{1}{4}|$, onde $\rho = |g^{\prime }(\frac{1}{4})| = |2 \cdot \frac{1}{4}| = \frac{1}{2}$. Então temos que
        $$
        \begin{aligned}
        \frac{|x_{k} - \frac{1}{4}|}{|x_{0} - \frac{1}{4}|} =
        10^{-1} &\implies \left( \frac{1}{2}\right)
        ^{k} = 10^{-1}\\
        \frac{|x_{k} - \frac{1}{4}|}{|x_{0} - \frac{1}{4}|} =
        10^{-1} &\implies
        2^{-k} = 10^{-1}\\
        \frac{|x_{k} - \frac{1}{4}|}{|x_{0} - \frac{1}{4}|} =
        10^{-1} &\implies
        -k \log_{10} 2 = -1\\
        \frac{|x_{k} - \frac{1}{4}|}{|x_{0} - \frac{1}{4}|} =
        10^{-1} &\implies
        k = \left\lceil \log_{2} 10 \right\rceil \\
        \end{aligned}
        $$

3. NADA

4. Derive um método semelhante ao método de Newton para encontrar raízes de $f(x) = 0$, utilizando a função $f$, bem como sua primeira e segunda derivadas $f^{\prime}, f^{\prime \prime}$.

5. Considere o método de *Steffensen*:

    $$
    x_{k+1} = x_{k} - \frac{f(x_{k})}{g(x_{k})}
    $$
    Onde
    $$
    g(x) = \frac{f(x + f(x)) - f(x)}{f(x)}
    $$

    1. Mostre que em geral, o método converge quadraticamente para uma raiz de $f(x)$.

        Vamos definir o erro $E_{k}$ da $k$-ésima iteração do método como:
        $$
        \begin{aligned}
        E_{k} = |x_{k} - x^{*}|
        \end{aligned}
        $$
        Onde $x^{*}$ é uma raiz de $f(x)$.

        $$
        \begin{aligned}
        \frac{f(x + h) - f(x)}{h} &= f^{\prime}(x)\\
        f(x + h) - f(x) &= hf^{\prime}(x)\\
        f(x + h) &= f(x) + hf^{\prime}(x)\\
        f(x + f(x)) &= f(x) + f(x)f^{\prime}(x) + f(x)^{2}\frac{f^{\prime \prime}(x)}{2} +
        \sum_{i=3}^{\infty} f(x)^{i} \frac{f^{(i)}(x)}{i!}\\
        g(x) &= f^{\prime}(x) + f(x)\frac{f^{\prime \prime}(x)}{2} +
        \sum_{i=3}^{\infty} f(x)^{i - 1} \frac{f^{(i)}(x)}{i!}\\
        g^{\prime}(x) &= f^{\prime \prime}(x) +
        \sum_{i=3}^{\infty} f(x)^{i - 1} \frac{f^{(i)}(x)}{i!}\\
        g(x^{*}) &= f^{\prime}(x^{*}) + f(x^{*})\frac{f^{\prime \prime}(x^{*})}{2} +
        \sum_{i=3}^{\infty} f(x^{*})^{i - 1} \frac{f^{(i)}(x^{*})}{i!}\\
        g(x^{*}) &= f^{\prime}(x^{*})
        \end{aligned}
        $$

        $$
        \begin{aligned}
        h(x) = x - \frac{f^{2}(x)}{\sum_{i=0}^{\infty} f(x)^{i} \frac{f^{(i)}(x)}{i!} - f(x)}\\
        \varepsilon_{k} = \frac{f^{2}(x_{k})}{\sum_{i=0}^{\infty} f(x_{k})^{i} \frac{f^{(i)}(x_{k})}{i!} - f(x_{k})}\\
        \end{aligned}
        $$

    2. Compare a eficiência desse método com a eficiência do método da secante.

## Interpolação polinomial

1. asd

    $$
    \ln u(x) = \ln (\gamma *{0}e^{\gamma*{1}x+\gamma *{2}x^{2}}) =
    \ln \gamma*{0} + \gamma_{1}x+\gamma *{2}x^{2}
    $$
    $$
    \begin{align*}
    \ln \gamma *{0} + \gamma*{1}x*{0}+\gamma*{2}x*{0}^{2} = z*{0}\\
    \ln \gamma *{0} + \gamma*{1}x*{1}+\gamma*{2}x*{1}^{2} = z*{1}\\
    \ln \gamma *{0} + \gamma*{1}x*{2}+\gamma*{2}x*{2}^{2} = z*{2}\\  
    \end{align*}
    $$
    $$
    \begin{bmatrix}
        \ln \gamma_0 & \gamma_1 & \gamma_2\\
        \ln \gamma_0 & \gamma_1 & \gamma_2\\
        \ln \gamma_0 & \gamma_1 & \gamma_2
    \end{bmatrix}
    \begin{bmatrix}
        1 \\ x \\ x^2
    \end{bmatrix}=
    \begin{bmatrix}
        z*{0} \\ z*{1} \\ z*{2}
    \end{bmatrix}
    $$

2. Use os valores da função $\sin(x)$ em $x = 0, \pi /6, \pi /4, \pi /3, \pi /2$ para derivar um polinômio interpolante $p(x)$. Qual é o grau desse polinômio?

    Como temos $5$ pontos, temos que o grau desse polinômio será $5-1 = 4$. Os pontos que devem ser interpolados são: $(0, 0), (\pi /6, 1/2), (\pi /4, \sqrt[]{2}/2), (\pi /3, \sqrt[]{3}/2), (\pi /2, 1)$.
    Nosso polinômio será da forma: $c*{0} + c*{1}x + c*{2}x² + c*{3}x³+c_{4}x⁴$. Assim, temos que:
    $$
    p(0) = c_{0} = 0
    $$
    $$
    \sin(x_{i} + a) = \sin (x_{i})
    + \cos(x_{i})(a) -
    \frac{\sin (\xi *{i})}{2}(a)^{2}
    $$
    $$
    |p(1.2) - \sin (1.2)| =
    \left|
        p(1.2) - \sin (\pi /3)
    + \cos(\pi /3)a +
    \frac{\sin (\pi /3)}{2}a^{2} +
    \frac{\cos (\pi /3)}{6}a^{3} -
    \frac{\sin (\xi*{i})}{24}a^{4}
    \right|
    $$
    Onde $a = 1.2 - \pi /3$
    Mas também temos que:
    $$
    p(1.2) = p(\pi /3) + p^{\prime }(\pi /3)a + \frac{p^{\prime \prime }(\pi /3)}{2}a^{2} + \frac{p^{\prime \prime \prime }(\pi /3)}{6}a^{3} +
    $$

3. Dados $n+1$ pontos $(x_{0}, y_{0}), \ldots, (x_{n}, y_{n})$, defina para $j = 0_{}, \ldots, n_{}$ as funções $\rho_{j} = \prod_{i \neq j}^{} (x_{j} - x_{i})$, e $\psi(x) = \prod_{i=0}^{n}(x - x_{i})$.

    1. Mostre que $\rho_{j} = \psi^{\prime}(x_{j})$

        Seja $\psi_{t}(x) = \prod_{i \neq t} (x - x_{i})$. Então temos que:
        $$
        \begin{aligned}
        \psi^{\prime}(x) &= \psi_{t}(x) + x \psi_{t}^{\prime}(x) - x_{t}\psi_{t}^{\prime}(x)\\
        \psi^{\prime}(x) &= \psi_{t}(x) + (x - x_{t})\psi_{t}^{\prime}(x)\\
        \psi^{\prime}(x) &= \psi_{j}(x) + (x - x_{j})\psi_{j}^{\prime}(x)\\
        \psi^{\prime}(x_{j}) &= \psi_{j}(x_{j}) + (x_{j} - x_{j})\psi_{j}^{\prime}(x_{j})\\
        \psi^{\prime}(x_{j}) &= \psi_{j}(x_{j})\\
        \psi^{\prime}(x_{j}) &= \prod_{i \neq j} (x_{j} - x_{i})\\
        \psi^{\prime}(x_{j}) &= \rho_{j}\\
        \end{aligned}
        $$

    2. Mostre que o polinômio interpolante de grau no máximo $n$ é dado por:
    $$
    \begin{aligned}
    p_{n}(x) = \psi(x) \sum_{j=0}^{n} \frac{y_{j}}{(x - x_{j})\psi^{\prime}(x_{j})}
    \end{aligned}
    $$

        $$
        \begin{aligned}
        p_{n}(x) &= \psi(x) \sum_{j=0}^{n} \frac{y_{j}}{(x - x_{j})\psi^{\prime}(x_{j})}\\
        p_{n}(x) &=
        \psi(x) \sum_{j=0}^{n} \frac{y_{j}}{(x - x_{j})\prod_{i \neq j}(x_{j} - x_{i})}\\
        p_{n}(x) &= \sum_{j=0}^{n} \frac{y_{j} \psi(x)}
        {(x - x_{j})\psi^{\prime}(x_{j})}\\
        p_{n}(x) &= \sum_{j=0}^{n} \frac{y_{j} \prod_{i=0}^{n} (x - x_{i})}
        {(x - x_{j})\psi^{\prime}(x_{j})}\\
        p_{n}(x) &= \sum_{j=0}^{n} y_{j} \frac{\prod_{i \neq j} (x - x_{i})}
        {\psi^{\prime}(x_{j})}\\
        p_{n}(x_{t}) &= \sum_{j=0}^{n} y_{j} \frac{\prod_{i \neq j} (x_{t} - x_{i})}
        {\psi^{\prime}(x_{j})}\\
        p_{n}(x_{t}) &=
        \sum_{j=0}^{t-1} y_{j} \frac{\prod_{i \neq j} (x_{t} - x_{i})}
        {\psi^{\prime}(x_{j})} +
        y_{t} \frac{\prod_{i \neq t} (x_{t} - x_{i})}
        {\psi^{\prime}(x_{t})} +
        \sum_{j=t+1}^{n} y_{j} \frac{\prod_{i \neq j} (x_{t} - x_{i})}
        {\psi^{\prime}(x_{j})}\\
        p_{n}(x_{t}) &= y_{t} \frac{\prod_{i \neq t} (x_{t} - x_{i})}
        {\psi^{\prime}(x_{t})}\\
        p_{n}(x_{t}) &= y_{t} \frac{\prod_{i \neq t} (x_{t} - x_{i})}
        {\prod_{i \neq t} (x_{t} - x_{i})}\\
        p_{n}(x_{t}) &= y_{t}
        \end{aligned}
        $$

4. Construa um polinômio $p_{3}$ de grau no máximo 3, na forma de Lagrange, que interpole os seguintes pontos:
$$
\begin{array}{|r|r|}
t & -1.1 & 1.1 & 2.2 & 0.0\\
\hline
y & 0.0 & 6.75 & 0.0 & 0.0
\end{array}
$$

    Vamos calcular os valores de $w_{j}$:
    $$
    \begin{aligned}
    w_{0} &= \frac{1}{(-1.1 - 1.1) \cdot (-1.1 - 2.2) \cdot (-1.1 - 0.0)}\\
    w_{0} &= \frac{1}{(-2.2) \cdot (-3.3) \cdot (-1.1)}\\
    w_{0} &= -\frac{1000}{7986}\\
    w_{1} &= \frac{1}{(1.1 + 1.1) \cdot (1.1 - 2.2) \cdot (1.1 - 0.0)}\\
    w_{1} &= \frac{1}{(2.2) \cdot (- 1.1) \cdot (1.1)}\\
    w_{1} &= -\frac{1000}{2662}\\
    w_{2} &= \frac{1}{(2.2 + 1.1) \cdot (2.2 - 1.1) \cdot (2.2 - 0.0)}\\
    w_{2} &= \frac{1}{(3.3) \cdot (1.1) \cdot (2.2)}\\
    w_{2} &= \frac{1000}{7986}\\
    w_{3} &= \frac{1}{(0.0 + 1.1) \cdot (0.0 - 1.1) \cdot (0.0 - 2.2)}\\
    w_{3} &= \frac{1}{(1.1) \cdot (- 1.1) \cdot (- 2.2)}\\
    w_{3} &= \frac{1000}{2662}\\
    \end{aligned}
    $$
    Agora, para calcular o valor do polinômio em algum ponto $x$, basta fazer:
    $$
    \begin{aligned}
    p_{3}(x) = \frac{\sum_{i=0}^{n} \frac{w_{i} y_{i}}{(x - x_{i})}}{\sum_{i=0}^{n} \frac{w_{i}}{(x - x_{i})}}
    \end{aligned}
    $$

5. Dados os pontos $(-1, 1), (0, 1), (1, 2), (2, 0)$, determine o polinômio interpolador de grau 3:

    1. Usando a base monomial:

        Usando a base monomial, temos que:
$$
\begin{aligned}
p_{3}(x) &= c_{0} + c_{1} x + c_{2} x^{2} + c_{3} x^{3}\\
p_{3}(0) &= c_{0} + c_{1} 0 + c_{2} 0^{2} + c_{3} 0^{3}\\
p_{3}(0) &= c_{0}\\
p_{3}(0) &= 1\\
c_{0} &= 1\\
p_{3}(-1) &= c_{0} + c_{1} (-1) + c_{2} (-1)^{2} + c_{3} (-1)^{3}\\
p_{3}(-1) &= 1 - c_{1} + c_{2} - c_{3}\\
p_{3}(-1) &= 1\\
1 &= 1 - c_{1} + c_{2} - c_{3}\\
p_{3}(1) &= c_{0} + c_{1} (1) + c_{2} (1)^{2} + c_{3} (1)^{3}\\
p_{3}(1) &= 1 + c_{1} + c_{2} + c_{3}\\
p_{3}(1) &= 2\\
2 &= 1 + c_{1} + c_{2} + c_{3}\\
2 + 1 &= 1 + c_{1} + c_{2} + c_{3} + 1 - c_{1} + c_{2} - c_{3}\\
1 &= 2 c_{2}\\
c_{2} &= \frac{1}{2}\\
p_{3}(2) &= c_{0} + c_{1} (2) + c_{2} (2)^{2} + c_{3} (2)^{3}\\
p_{3}(2) &= 1 + 2 c_{1} + 4 \frac{1}{2} + 8 c_{3}\\
p_{3}(2) &= 0\\
0 &= 1 + 2 c_{1} + 4 \frac{1}{2} + 8 c_{3}\\
-3 &= 2 c_{1} + 8 c_{3}\\
1 &= 1 - c_{1} + \frac{1}{2} - c_{3}\\
-1 &= - 2c_{1} - 2c_{3}\\
-3 + -1 &= 2 c_{1} + 8 c_{3} - 2c_{1} - 2c_{3}\\
-4 &= 6 c_{3}\\
c_{3} &= -\frac{2}{3}\\
-1 &= - 2c_{1} + \frac{4}{3}\\
c_{1} &= \frac{1 + \frac{4}{3}}{2}\\
c_{1} &= \frac{7}{6}\\
\end{aligned}
$$
Então, usando a base monomial, nosso polinômio fica:
$$
\begin{aligned}
p_{3}(x) = 1 + \frac{7}{6} x + \frac{1}{2} x^{2} - \frac{2}{3} x^{3}
\end{aligned}
$$

    2. Usando a base de Lagrange:

        $$
        \begin{aligned}
        L_{0}(x) &= c_{0}(x - 0)(x - 1)(x - 2)\\
        L_{0}(x) &= c_{0}(x)(x - 1)(x - 2)\\
        1 &= c_{0}(-1)(-1 - 1)(-1 - 2)\\
        1 &= c_{0}(-1)(-2)(-3)\\
        1 &= -6c_{0}\\
        c_{0} &= -\frac{1}{6}\\
        L_{0}(x) &= -\frac{1}{6}(x)(x - 1)(x - 2)\\
        L_{1}(x) &= c_{1}(x + 1)(x - 1)(x - 2)\\
        1 &= c_{1}(0 + 1)(0 - 1)(0 - 2)\\
        1 &= c_{1}(1)(- 1)(- 2)\\
        1 &= 2c_{1}\\
        c_{1} &= \frac{1}{2}\\
        L_{1}(x) &= \frac{1}{2}(x + 1)(x - 1)(x - 2)\\
        L_{2}(x) &= c_{2}(x + 1)(x - 0)(x - 2)\\
        L_{2}(x) &= c_{2}(x + 1)(x)(x - 2)\\
        2 &= c_{2}(1 + 1)(1)(1 - 2)\\
        2 &= c_{2}(2)(1)(-1)\\
        2 &= -2 c_{2}\\
        c_{2} &= -1\\
        L_{2}(x) &= -(x + 1)(x)(x - 2)\\
        L_{3}(x) &= c_{3}(x + 1)(x - 0)(x - 1)\\
        L_{3}(x) &= c_{3}(x + 1)(x)(x - 1)\\
        0 &= c_{3}(2 + 1)(2)(2 - 1)\\
        0 &= c_{3}(3)(2)(1)\\
        0 &= 6 c_{3}\\
        c_{3} &= 0\\
        L_{3}(x) &= 0(x + 1)(x)(x - 1)\\
        L_{3}(x) &= 0\\
        \end{aligned}
        $$
        Então, o polinômio $p_{3}(x)$ é dado por:
        $$
        \begin{aligned}
        \sum_{i=0}^{2} L_{i}(x)
        \end{aligned}
        $$

    3. Usando a base de Newton:

        Vamos calcular as diferenças divididas:
        $$
        \begin{array}{|c|c|}
        \hline
        i & x_{i} & y_{i} & f[x_{i}] & f[x_{i-1}, x_{i}] & f[x_{i-2}, x_{i-1}, x_{i}] &
        f[x_{i-3}, x_{i-2}, x_{i-1}, x_{i}]\\
        \hline
        0 & -1 & 1 & 1\\
        \hline
        1 & 0 & 1 & 1 & \frac{1 - 1}{0 + 1} = 0\\
        \hline
        2 & 1 & 2 & 2 & \frac{2 - 1}{1 - 0} = 1 & \frac{1 - 0}{1 + 1} = \frac{1}{2}\\
        \hline
        3 & 2 & 0 & 0 & \frac{0 - 2}{2 - 1} = -2 & \frac{-2 - 1}{2 - 0} = -\frac{3}{2}
        & \frac{- \frac{3}{2} - \frac{1}{2}}{2 + 1} = -\frac{2}{3}\\
        \hline
        \end{array}
        $$
        O polinômio interpolante $p_{3}(x)$ é dado por:
        $$
        \begin{aligned}
        p_{3}(x) &= 1 + 0(x + 1) + \frac{1}{2}(x + 1)(x) - \frac{2}{3}(x + 1)(x)(x - 1)\\
        p_{3}(x) &= 1 + \frac{1}{2}(x + 1)(x) -
        \frac{2}{3}(x + 1)(x)(x - 1)
        \end{aligned}
        $$

    4. Mostre que todas as representações são equivalentes:

        Primeiramente, vamos mostrar que a representação para o polinômio de lagrange é equivalente à da base monomial:
        $$
        \begin{aligned}
        {p_{3}}_{L}(x) &= \sum_{i=0}^{2}L_{i}(x)\\
        {p_{3}}_{L}(x) &= -\frac{1}{6}(x)(x - 1)(x - 2) +
        \frac{1}{2}(x + 1)(x - 1)(x - 2) -
        (x + 1)(x)(x - 2)\\
        {p_{3}}_{L}(x) &= -\frac{1}{6}(x^{3} -3x^{2} + 2x) +
        \frac{1}{2}(x^{3} - 2x^{2} - x + 2) -
        (x^{3} - x^{2} - 2x)\\
        {p_{3}}_{L}(x) &=
        x^{3} \left(-\frac{1}{6} + \frac{1}{2} - 1\right) +
        x^{2} \left(\frac{3}{6} - \frac{2}{2} + 1\right) +
        x \left(-\frac{2}{6} - \frac{1}{2} + 2\right) +\\
        1 \left(\frac{2}{2}\right)\\
        {p_{3}}_{L}(x) &=
        -\frac{2}{3} x^{3} +
        \frac{1}{2} x^{2} +
        \frac{7}{6} x + 1
        \end{aligned}
        $$
        Como queríamos mostrar.  
        Agora, vamos mostrar que a forma de Newton é igual a representação monomial:
        $$
        \begin{aligned}
        {p_{3}}_{N}(x) &= 1 + \frac{1}{2}(x + 1)(x) - \frac{2}{3}(x + 1)(x)(x - 1)\\
        {p_{3}}_{N}(x) &= 1 + \frac{1}{2}(x^{2} + x) - \frac{2}{3}(x^{3} - x)\\
        {p_{3}}_{N}(x) &=
        x^{3} \left(-\frac{2}{3}\right) +
        x^{2} \left(\frac{1}{2}\right)+
        x \left(\frac{1}{2} + \frac{2}{3}\right)+
        1\\
        {p_{3}}_{N}(x) &=
        -\frac{2}{3} x^{3} +
        \frac{1}{2} x^{2} +
        \frac{7}{6} x +
        1\\
        \end{aligned}
        $$
        Então as três representações são equivalentes.

6. Para a base de Newton, prove que $c_{j} = f[x_{0}, \ldots, x_{j}]$ satisfaz a recursão dada por:
$$
\begin{aligned}
f[x_{0}, \ldots, x_{j}] =
\frac{f[x_{1}, \ldots, x_{j}] - f[x_{0}, \ldots, x_{j - 1}]}{x_{j} - x_{0}}
\end{aligned}
$$

7. asdasd

    Sejam $x_{i}, x_{i + 1}, x_{i + 2}$ três pontos consecutivos quaisquer. Então, temos que
$$
\begin{aligned}
f[x_{i}, x_{i + 1}, x_{i + 2}] &= \frac{f^{(2)}(x)}{2}\\
1 &= \frac{f^{(2)}(x)}{2}\\
f^{(2)}(x) &= 2\\
f^{\prime}(x) &= 2x + c_{1}\\
f(x) &= x^{2} + c_{1} x + c_{2}\\
f(0) &= 0^{2} + c_{1} 0 + c_{2}\\
f(0) &= c_{2}\\
c_{2} &= 0\\
f(x) &= x^{2} + c_{1} x\\
f(1) &= 1^{2} + c_{1} 1\\
f(1) &= 1 + c_{1}\\
2 &= 1 + c_{1}\\
c_{1} &= 1\\
f(x) &= x^{2} + x\\
\end{aligned}
$$

8. Seja $p_{k}(x)$ o polinômio de grau no máximo $k$, na forma de Newton. Caracterize $p_{k}^{(t)}(x)$, onde $t = \{0, \ldots, k\}$, e $p_{k}^{(k)}(x)$.

    Temos que $p_{k}(x) = \sum_{n=0}^{k} f[0, \ldots, n] \prod_{i=0}^{n-1} (x - x_{i})$. Então:
    $$
    \begin{aligned}
    p_{k}(x) = \sum_{n=0}^{k} f[0, \ldots, n] \sum_{i=0}^{n} \alpha_{i} x^{i}
    \end{aligned}
    $$
    Onde $\sum_{i=0}^{n} \alpha_{i} x^{i} = \prod_{i=0}^{n-1} (x - x_{i})$. Então:
    $$
    \begin{aligned}
    p_{k}^{(t)}(x) &= \sum_{n=0}^{k} f[0, \ldots, n]
    \sum_{i=t}^{n} \alpha_{i} \frac{i!}{(i-t)!} x^{i - t}\\
    p_{k}^{(k)}(x) &= \sum_{n=0}^{k} f[0, \ldots, n]
    \sum_{i=k}^{n} \alpha_{i} \frac{i!}{(i-k)!} x^{i - k}\\
    p_{k}^{(k)}(x) &= f[0, \ldots, k]
    \alpha_{k} \frac{k!}{(k-k)!} x^{k - k}\\
    p_{k}^{(k)}(x) &= f[0, \ldots, k] k!
    \alpha_{k}\\
    \end{aligned}
    $$
    Note que $\alpha_{k}$ é o coeficiente de $x^{k}$ em $p_{k}(x)$. Note que $\alpha_{k} = 1$. Portanto $p_{k}^{(k)}(x) = f[0, \ldots, k] k!$.

9. Suponha que queremos aproximar a função $e^{x}$ no intervalo $[0,1]$ usando interpolação polinomial usando os pontos $x_{0} = 0, x_{1} = \frac{1}{2}, x_{2} = 1$. Seja $p_{2}(x)$ esse polinômio.

    1. Encontre um limite superior para a magnitude do erro
    $$
    \begin{aligned}
    \max_{0 \leq x \leq 1} |e_{x} - p_{2}(x)|
    \end{aligned}
    $$

        Sabemos que
        $$
        \begin{aligned}
        \max_{0 \leq x \leq 1} |e_{x} - p_{2}(x)| &\leq  \frac{1}{(2 + 1)!}
        \max_{0 \leq t \leq 1}|e^{x}| \max_{0 \leq s \leq 1} \prod_{i=0}^{2} |s - x_{i}|\\
        \max_{0 \leq x \leq 1} |e_{x} - p_{2}(x)| &\leq \frac{e}{6}
        \max_{0 \leq s \leq 1} |s - 0| \cdot \left|s - \frac{1}{2}\right| \cdot |s - 1|\\
        \max_{0 \leq x \leq 1} |e_{x} - p_{2}(x)| &\leq \frac{e}{6}
        \max_{0 \leq s \leq 1} s(1 - s) \cdot \left|s - \frac{1}{2}\right|\\
        \max_{0 \leq x \leq 1} |e_{x} - p_{2}(x)| &\leq \frac{e}{6}
        \max_{0 \leq s \leq 1} (s - s^{2}) \cdot \left|s - \frac{1}{2}\right|\\
        \end{aligned}
        $$
        Seja $f(s) = (s - s^{2}) \cdot \left|s - \frac{1}{2}\right|$. Então
        $$
        \begin{aligned}
        f(s) &= \begin{cases}
        (s - s^{2}) (s - 1/2) & \text{caso } s \geq \frac{1}{2}\\
        (s - s^{2}) (1/2 - s) & \text{caso } s \leq \frac{1}{2}
        \end{cases}\\
        f(s) &= \begin{cases}
        s^{2} - s^{3} - \frac{1}{2}s + \frac{1}{2}s^{2} & \text{caso } s \geq \frac{1}{2}\\
        \frac{1}{2}s - \frac{1}{2}s^{2} - s^{2} + s^{3} & \text{caso } s \leq \frac{1}{2}
        \end{cases}\\
        f(s) &= \begin{cases}
        -s^{3} + \frac{3}{2} s^{2} -\frac{1}{2}s & \text{caso } s \geq \frac{1}{2}\\
        s^{3} - \frac{3}{2} s^{2} + \frac{1}{2}s & \text{caso } s < \frac{1}{2}
        \end{cases}\\
        \end{aligned}
        $$
        Temos então que, para $s \leq 1/2$
        $$
        \begin{aligned}
        f^{\prime}(s) &= 3s^{2} - 3s + \frac{1}{2}\\
        f^{\prime}(s) = 0 &\implies 3s^{2} - 3s + \frac{1}{2} = 0\\
        f^{\prime}(s) = 0 &\implies 6s^{2} - 6s + 1 = 0\\
        \Delta &= (-6)^{2} - 4 \cdot 6 \cdot 1\\
        \Delta &= 12\\
        \sqrt[]{\Delta} &= 2 \sqrt[]{3}\\
        s &= \frac{6 \pm 2 \sqrt[]{3}}{12}\\
        s &= \frac{3 \pm \sqrt[]{3}}{6}\\
        \end{aligned}
        $$
        Como $s = \frac{3 - \sqrt[]{3}}{6}$ é o único ponto em $[0,1/2)$ em que $f^{\prime}(s) = 0$, então, para $s \in [0,\frac{3 - \sqrt[]{3}}{6})$, $f(s)$ é crescente, e para $s \in (\frac{3 - \sqrt[]{3}}{6}, 1/2)$, $f(s)$ é decrescente. Portanto, o maior valor de $f(s)$ para $s \in [0, 1/2)$ é:
        $$
        \begin{aligned}
        f\left(\frac{3 - \sqrt[]{3}}{6}\right) &=
        \left(\frac{3 - \sqrt[]{3}}{6}\right)^{3} -
        \frac{3}{2} \left(\frac{3 - \sqrt[]{3}}{6}\right)^{2} +
        \frac{1}{2}\left(\frac{3 - \sqrt[]{3}}{6}\right)\\
        \end{aligned}
        $$

10. Sejam $x_{0}, \ldots, x_{4} = 0, \pi/6, \pi/4, \pi/3, \pi/2$, e $y_{i} = \sin(x_{i})$. Construa o polinômio interpolante de grau no máximo $4$ para os pontos $(x_{i}, y_{i})$, e então calcule um limite superior para o erro da interpolação em $[0, \pi/2]$.

    Vamos construir o polinômio interpolante na forma de Newton para esses pontos:

$$
\begin{array}{|c|c|}
\hline
i & x_{i} & y_{i} & f[x_{i}] & f[x_{i-1}, x_{i}] & f[x_{i-2}, x_{i-1}, x_{i}] &
f[x_{i-3}, x_{i-2}, x_{i-1}, x_{i}] & f[x_{i-4}, x_{i-3}, x_{i-2}, x_{i-1}, x_{i}]\\
\hline
0 & 0 & 0 & 0\\
\hline
1 & \pi/6 & \frac{1}{2} & \frac{1}{2} &
\frac{\frac{1}{2} - 0}{\pi/6 - 0} = \frac{\pi}{3}\\
\hline
2 & \pi/4 & \frac{\sqrt[]{2}}{2} & \frac{\sqrt[]{2}}{2}&
\frac{\frac{\sqrt[]{2}}{2} - \frac{1}{2}}{\pi/4 - \pi/6}=
\frac{\frac{\sqrt[]{2}}{2}}{\frac{(3 - 2)\pi}{12}}=
\frac{\sqrt[]{2} \pi}{6}\\
\hline
3 & \pi/3 & \frac{\sqrt[]{3}}{2} & \frac{\sqrt[]{3}}{2}&
\frac{\frac{\sqrt[]{3}}{2} - \frac{\sqrt[]{2}}{2}}{\pi/3 - \pi/4}=
\frac{\frac{\sqrt[]{3} - \sqrt[]{2}}{2}}{\frac{(4 - 3)\pi}{12}}=
\frac{12(\sqrt[]{3} - \sqrt[]{2}) \pi}{6}\\
\hline
4 & \pi/2 & 1 & 1&
\frac{\frac{\sqrt[]{3}}{2} - \frac{\sqrt[]{2}}{2}}{\pi/3 - \pi/4}=
\\
\hline
\end{array}
$$
