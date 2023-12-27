# Equações não-lineares em uma variável

## Método da bissecção

O método da bisecção é simples. Imagine que, dada uma função contínua $f(x)$ temos um intervalo $[a, b] \in \mathbb{R}$ tal que sabemos que $f$ muda de sinal, isto é, $f(a)\cdot f(b) < 0$. Pelo Teorema do Valor Intermediário, temos que deve existir $c \in [a, b]$ tal que $f(c) = 0$. Então avaliamos $f(p)$, onde $p = \frac{a+b}{2}$ é a média entre $a$ e $b$, e checamos o valor de $f(a) \cdot f(b)$. Se esse valor for $0$, então $p$ é uma raiz. Se esse valor for negativo, então fazemos $b \leftarrow p$ e recomeçamos. Senão, fazemos $a \leftarrow p$ e recomeçamos, até que estejamos a uma distância aceitável da raiz.

### Convergência do método da bissecção

A cada iteração do método, o intervalo $[a,b]$ onde a raiz $x^{*}$ está "presa" diminui pela metade. Então, após um total de $n$ iterações, temos que $|x^{*} - x_{n}| \leq \frac{b-a}{2}2^{-n}$. Então, o algoritmo garantidamente converge. Para que o algoritmo satisfaça $|x^{*} - x_{n}| \leq \text{atol}$, para uma tolerância absoluta $\text{atol}$, em $n$ iterações, podemos fazer $\frac{b-a}{2}2^{-n} \leq \text{atol}$, e então $n = \left\lceil \log_{2} \left( \frac{b-a}{2 \text{atol}} \right) \right\rceil $.

## Iteração de ponto fixo

Considere nosso problema de encontrar $x$ tal que $f(x) = 0$. Podemos reescrever esse problema como encontrar $x$ tal que $g(x) = x \iff f(x) = 0$. Isto significa que passamos então a procurar um ponto fixo $x^{*}$ tal que $g(x^{*}) = x^{*}$. No método do ponto fixo, definimos uma sequência de iterandos $x_{1}, x_{2}, \dots, x_{k}, \dots$ por $x_{k+1} = x_{k}$, começando por um iterando inicial $x_{0}$.

### Teorema do ponto fixo

### Convergência do método do ponto fixo

### Taxa de convergência

### Método de Newton e variantes

#### Método da secante
