---
title: |
       | MAC 0210 - Laboratório de Métodos Numéricos
       | Exercício Programa 3

author: |
        | Joao Pedro Lukasavicus Silva
        | <joao.lukasavicus.silva@usp.br>
        | 9276940
codebraid:
    jupyter: true
...

# Primeira parte: computando trabalho

## Interpolação polinomial

Vamos investigar algumas propriedades de alguns polinômios interpoladores. Para isso, vamos construir interpoladores usando a forma de Newton e a forma de Lagrange.  
Os dois interpoladores serão construídos em `C`.

### Forma de Newton

Código do cabeçalho:

```c {.cb-code include_file="./newton.h"}
```

Implementação:

```c {.cb-code include_file="./newton.c"}
```

### Forma de Lagrange

Código do cabeçalho:

```c {.cb-code include_file="./lagrange.h"}
```

Implementação:

```c {.cb-code include_file="./lagrange.c"}
```

### Interpolando funções

A seguir apresentamos o código usado para testar os polinômios interpoladores.

O programa `driver.c` recebe três argumentos: um inteiro positivo `<n>`, e duas cadeias de caracteres, `<method>` e `<filename>`.  
O primeiro argumento determina a quantidade de valores que o programa irá calcular.  
O segundo argumento determina qual a forma do polinômio interpolador a ser utilizado, entre `"newton"` ou `"lagrange"`.  
O terceiro argumento é o nome de um arquivo .csv do qual o programa irá ler os pontos $(x, f(x))$, para usar na construção do interpolante e depois da avaliação do seu valor em algum ponto.

Aqui está o código-fonte do programa `driver`

```c {.cb-code include_file="./driver.c"}
```

Após ler os pontos do arquivo determinado por `<filename>`, o programa constrói um polinômio interpolante e o armazena na memória. Em seguida, o programa define uma faixa de `<n>` valores igualmente espaçados, desde o menor valor de $x$ dos pontos lidos, até o maior valor, e avalia o valor do polinômio interpolador para cada um dos pontos da faixa. O resultado é então escrito na saída padrão na forma $x_{i}, p_{n}(x_{i})$ para cada um dos pontos da faixa.

Para gerar os pontos para testar o programa, usamos o programa `sample_points.py`.

O programa recebe dois argumentos: `<inputfile>` e `<maxpoints>`.  
O primeiro argumento é uma cadeia de caracteres que deve ser o nome do arquivo .csv de onde as funções serão lidas. Para isso, utilizamos o módulo [SimPy](https://www.sympy.org/en/index.html), que manipulação de símbolos matemáticos.
Cada registro do arquivo `<inputfile>.csv` contém uma função matemática, um limite inferior e um limite superior para a avaliação da função.  
O segundo argumento é um inteiro, que determina o número máximo de pontos a ser gerado para a avaliação de cada função.  

```python {.cb-code include_file="./sample_points.py"}
```

O programa lê o arquivo com as funções, e, para cada função, computa o valor da função para cada valor em uma faixa com `i` pontos, com `i` variando de $2$ até `<maxpoints>`. Então o programa salva o resultado dessa avaliação para cada função, e para cada valor de `i`, em um arquivo .csv de nome `"{funcao}_{i}_in.csv"`.

Por fim, para gerar os dados que vamos usar na nossa análise (e outras coisas, como construir os binários dos programas utilizados, a partir do código-fonte), utilizamos um arquivo `Makefile`, usado pelo [GNU Make](https://www.gnu.org/software/make/).

#### Resultados

Vamos utilizar algumas bibliotecas, como o [Pandas](https://pandas.pydata.org/), [NumPy](https://numpy.org/), e [MatPlotLib](https://matplotlib.org/), para analisar nossos resultados.

Importando bibliotecas e realizando configurações iniciais

```python {.cb-nb show=code}
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sympy as sp
from IPython import display
import warnings
warnings.filterwarnings('ignore')
import csv
```

Lendo o arquivo com as funções  
Essa etapa é importante para determinar quais funções foram avaliadas, e comparar os valores da função com os obtidos por cada polinômio interpolador.

```python {.cb-nb}
lst = [];
max_diff = {};
x = sp.var('x');
with open("functions.csv", 'r') as file:
    reader = csv.reader(file);
    for row in reader:
        func, _, _ = row;
        expr = sp.sympify(func);
        lst.append(expr);
```

Carregando os dados com os resultados dos experimentos

```python {.cb-nb}
dfs = {}
for func in lst:
    f = sp.lambdify(x, func, "numpy");

    df_curr = pd.DataFrame();

    for i in range(2, 11):
        df_n = pd.read_csv(f"{str(func)}_{i}_newton.out.csv",
        names=['x', f"p_{i}_x_newton"]);
        df_l = pd.read_csv(f"{str(func)}_{i}_lagrange.out.csv",
        names=['x', f"p_{i}_x_lagrange"]);
        df_curr['x'] = df_n['x'];
        df_curr[f"p_{i}_x_newton"] = df_n[f"p_{i}_x_newton"];
        df_curr[f"p_{i}_x_lagrange"] = df_l[f"p_{i}_x_lagrange"];
        df_curr[f"abs_diff_{i}"] = \
        np.absolute(df_curr[f"p_{i}_x_lagrange"] \
        - df_curr[f"p_{i}_x_newton"]);

    f_x = f(df_curr['x']);
    df_curr['f_x'] = f_x;

    dfs[str(func)] = df_curr;
    max_diff[str(func)] = int(np.floor(np.log10(
        df_curr.iloc[:,3::3].max().max())));

max_key = max(max_diff, key=max_diff.get);
```

Vamos observar a diferença absoluta máxima entre os valores calculados pelo interpolador de Lagrangre e Newton, para cada função:

```python {.cb-nb}
for k, v in max_diff.items():
    display.display(display.Math(
        fr"D_{{\text{{MAX}}}}({k}) = 10^{{{v}}}"));
```

Como podemos ver, a diferença máxima é da ordem de `display.display(display.Math(fr"10^{{{max_diff[max_key]}}}"))`{.python .cb-nb} para `display.display(display.Math(fr"f(x) = {max_key}"))`{.python .cb-nb}, portanto, não há uma diferença significativa em usar a interpolação polinomial na forma de Newton ou na forma de Lagrange. Portanto, a partir de agora, somente consideraremos os resultados referentes ao polinômio na forma de Newton.

Vamos comparar cada função com os seus respectivos polinômios interpoladores, para diferentes graus de cada polinômio:

```python {.cb-nb}
sp.init_printing(use_latex="mathjax");
for func in lst:
    fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(9, 15));
    fig.suptitle(fr'$f(x) = {sp.latex(func)}$', size='xx-large');
    df = dfs[str(func)]

    for i in range(2, 11):
        df[f"err_{i}_newton"] = \
        np.absolute(df['f_x'] - df[f"p_{i}_x_newton"]);

    ax1.\
    set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,11)))
    for i in range(2, 11):
        ax1.plot(df['x'], df[f"p_{i}_x_newton"],
        label=fr"$p_{{{i-1}}}(x)$")
    ax1.plot(df['x'], df['f_x'], label=fr"${sp.latex(func)}$", color='black')
    ax1.set_title("Interpolacao polinomial");
    ax1.set_xlabel(fr"$x$");
    ax1.set_ylabel(fr"$f(x)$ ou $p(x)$");
    ax1.legend();

    ax2.set_prop_cycle('color',
    plt.cm.Spectral(np.linspace(0,1,11)))
    for i in range(2, 11):
        ax2.plot(df['x'], df[f"err_{i}_newton"],
        label=fr"$Erro p_{{{i-1}}}(x)$")
    ax2.set_title("Erro na interpolacao polinomial");
    ax2.set_xlabel(fr"$x$");
    ax2.set_ylabel(fr"Erro absoluto$(x)$");
    ax2.legend();

    max_e = df.iloc[:,29:].max();
    x_axis = np.arange(1, 10);
    ax3.plot(x_axis, max_e);
    ax3.set_xlabel("Grau do polinomio interpolante");
    ax3.set_ylabel("Erro absoluto maximo");
    ax3.set_title("Erro absoluto maximo x Grau do polinomio interpolante");
    fig.tight_layout();
```

### Interpolando dados

Agora, vamos usar o polinômio interpolador de newton para interpolar os dados da nossa tabela.

```python {.cb-nb}
data = pd.read_csv("pontosout.csv", names=['x', 'f_x']);
pontosin = pd.read_csv("pontos.csv", names=['x', 'y']);
nfig = plt.figure();
plt.plot(data.x, data.f_x, label=fr"$p(x)$");
plt.plot(pontosin.x, pontosin.y, linestyle="", marker="o", label=fr"$y_i$");
plt.legend();
```

## Integração numérica

Agora, queremos aproximar a integral definida pelos pontos, de algumas maneiras diferentes.  
Primeiramente, vamos supor que a função que queremos integrar é justamente dada pelo polinômio que interpola os pontos dados.  
Vamos então avaliar a função em $n+1$ pontos, e utilizar a regra do trapézio composto e a regra de Simpson composta para aproximar o valor da integral.

Temos que
$$
\begin{aligned}
\int_{p}^{q} f(x) \, dx =
\sum_{i=0}^{n - 1} \int_{x_{i}}^{x_{i + 1}} f(x) \, dx
\end{aligned}
$$
Portanto, para aproximar o valor da integral definida em todo o intervalo, basta calcular o valor da integral para cada sub-intervalo e somar os valores.

### Regra do trapézio composta

Para a regra do trapézio composta, aproximamos o valor da integral em cada sub-intervalo $[x_{i}, x_{i+1}]$ pela área do trapézio definido por $x_{i}, x_{i+1}$ e $f(x_{i}), f(x_{i+1})$.
Então temos que:
$$
\begin{aligned}
\int_{x_{i}}^{x_{i+1}} f(x) \approx (f(x_{i}) + f(x_{x + 1})) \frac{x_{i + 1} - x_{i}}{2}
\end{aligned}
$$

### Regra de Simpson composta

Já para a regra de Simpson composta, ao invés de tomar um sub-intervalo com 2 pontos e calcular a área sobre o trapézio definido ali, cada sub-intervalo é composto de 3 pontos, e calculamos a área sob o polinômio de grau no máximo 2 que passa por esses pontos. Então temos que
$$
\begin{aligned}
\int_{p}^{q} f(x) \, dx =
\sum_{i=0}^{(n-1)/2} \int_{x_{2i}}^{x_{2(i+1)}} f(x) \, dx
\end{aligned}
$$
Seja então $[a,b]$ algum sub-intervalo cuja integral queremos calcular. Temos então que:

$$
\begin{aligned}
\int_{a}^{b} f(x) \, dx &\approx \int_{a}^{b} p_{3}(x) \, dx\\
\int_{a}^{b} p_{3}(x) dx &=
\int_{a}^{b} \sum_{i=0}^{2} y_{i} L_{i}(x) dx\\
\int_{a}^{b} p_{3}(x) dx &=
\sum_{i=0}^{2} y_{i} \int_{a}^{b} L_{i}(x) dx\\
\end{aligned}
$$
Onde $L_{i}(x)$ é o polinômio da base de Lagrange que passa pelos 3 pontos do intervalo.  
Assim, precisamos descobrir $\int_{a}^{b} L_{i}(x) \, dx$ para $i = 0, 1, 2$.

Sejam $a, x_{1}, b$ os três pontos contidos no intervalo $[a,b]$. Então temos que:
$$
\begin{aligned}
L_{0}(x) &= \frac{(x - x_{1})(x - b)}{(a - x_{1})(a - b)}\\
L_{0}(x) &= \frac{x^{2} - (b + x_{1})x + bx_{1}}{(a - x_{1})(a - b)}\\
L_{1}(x) &= \frac{(x - a)(x - b)}{(x_{1} - a)(x_{1} - b)}\\
L_{1}(x) &= \frac{x^{2} - (a + b)x + ab}{(x_{1} - a)(x_{1} - b)}\\
L_{2}(x) &= \frac{(x - a)(x - x_{1})}{(b - a)(b - x_{1})}\\
L_{2}(x) &= \frac{x^{2} - (a + x_{1})x + ax_{1}}{(b - a)(b - x_{1})}\\
\end{aligned}
$$
Assim, temos que:
$$
\begin{aligned}
\int_{a}^{b} L_{0}(x) \, dx &= \frac{1}{(a - x_{1})(a - b)}
\int_{a}^{b} (x^{2} - (b + x_{1})x + bx_{1}) \, dx\\
\int_{a}^{b} L_{0}(x) \, dx &= \frac{1}{(a - x_{1})(a - b)}
\left.\left(
\frac{x^{3}}{3} - \frac{b + x_{1}}{2} x^{2} + bx_{1} x
\right)\right|_{a}^{b}\\
\int_{a}^{b} L_{0}(x) \, dx &= \frac{1}{(a - x_{1})(a - b)}
\left(
\frac{b^{3}}{3} - \frac{b + x_{1}}{2} b^{2} + bx_{1} b -
\frac{a^{3}}{3} + \frac{b + x_{1}}{2} a^{2} - bx_{1} a
\right)\\
\int_{a}^{b} L_{0}(x) \, dx &= \frac{1}{(a - x_{1})(a - b)}
\left(
\frac{b^{3} - a^{3}}{3} - \frac{b + x_{1}}{2} (b^{2} - a^{2}) + bx_{1} (b - a)
\right)\\
\int_{a}^{b} L_{0}(x) \, dx &= \frac{1}{x_{1} - a}
\left(
\frac{(a + b)^{2} - ab}{3} - \frac{b + x_{1}}{2}(a + b) + bx_{1}
\right)\\
\int_{a}^{b} L_{1}(x) \, dx &= \frac{1}{(x_{1} - a)(x_{1} - b)}
\int_{a}^{b} (x^{2} - (a + b)x + ab) \, dx\\
\int_{a}^{b} L_{1}(x) \, dx &= \frac{1}{(x_{1} - a)(x_{1} - b)}
\left(\left.
    \frac{x^{3}}{3} - \frac{a + b}{2}x^{2} + abx
\right)\right|_{a}^{b}\\
\int_{a}^{b} L_{1}(x) \, dx &= \frac{1}{(x_{1} - a)(x_{1} - b)}
\left(
    \frac{b^{3}}{3} - \frac{a + b}{2}b^{2} + abb -
    \frac{a^{3}}{3} + \frac{a + b}{2}a^{2} - aba
\right)\\
\int_{a}^{b} L_{1}(x) \, dx &= \frac{1}{(x_{1} - a)(x_{1} - b)}
\left(
    \frac{b^{3} - a^{3}}{3} - \frac{a + b}{2}(b^{2} - a^{2}) + ab (b - a)
\right)\\
\int_{a}^{b} L_{1}(x) \, dx &= \frac{b - a}{(x_{1} - a)(x_{1} - b)}
\left(
    \frac{(a + b)^{2} - ab}{3} - \frac{(a + b)^{2}}{2} + ab
\right)\\
\int_{a}^{b} L_{2}(x) \, dx &= \frac{1}{(b - a)(b - x_{1})}
\int_{a}^{b} (x^{2} - (a + x_{1})x + ax_{1}) \, dx\\
\int_{a}^{b} L_{2}(x) \, dx &= \frac{1}{(b - a)(b - x_{1})}
\left(\left.
\frac{x^{3}}{3} - \frac{a + x_{1}}{2}x^{2} + ax_{1}x
\right)\right|_{a}^{b}\\
\int_{a}^{b} L_{2}(x) \, dx &= \frac{1}{(b - a)(b - x_{1})}
\left(
\frac{b^{3}}{3} - \frac{a + x_{1}}{2}b^{2} + ax_{1}b -
\frac{a^{3}}{3} + \frac{a + x_{1}}{2}a^{2} - ax_{1}x
\right)\\
\int_{a}^{b} L_{2}(x) \, dx &= \frac{1}{(b - a)(b - x_{1})}
\left(
\frac{b^{3} - a^{3}}{3} - \frac{a + x_{1}}{2}(b^{2} - a^{2}) + ax_{1}(b-a)
\right)\\
\int_{a}^{b} L_{2}(x) \, dx &= \frac{1}{b - x_{1}}
\left(
\frac{(a + b)^{2} - ab}{3} - \frac{a + x_{1}}{2}(a + b) + ax_{1}
\right)\\
\end{aligned}
$$
Assim, temos que:
$$
\begin{split}
\int_{a}^{b} p_{3}(x) =
&\frac{y_{0}}{x_{1} - a}
\left(
\frac{(a + b)^{2} - ab}{3} - \frac{b + x_{1}}{2}(a + b) + bx_{1}
\right) + \\
&\frac{y_{1}(b - a)}{(x_{1} - a)(x_{1} - b)}
\left(
\frac{(a + b)^{2} - ab}{3} - \frac{(a + b)^{2}}{2} + ab
\right) +\\
&\frac{y_{2}}{b - x_{1}}
\left(
\frac{(a + b)^{2} - ab}{3} - \frac{a + x_{1}}{2}(a + b) + ax_{1}
\right)
\end{split}
$$

### Aproximando valor da integral

Primeiramente, vamos aproximar o valor da integral do polinômio interpolante que encontramos para os valores da tabela, variando o número de pontos amostrados e o método de integração (regra do trapézio composto ou regra de Simpson).  
Para isso, vamos utilizar o programa `integra.c`.
O programa lê de um arquivo .csv definido por `<filename>` uma quantidade de pontos amostrados do polinômio interpolador, e aproxima o valor da sua integral, utilizando a regra de integração definida por `<method>` (`"trap"` para a regra do trapézio e `"simpson"` para a regra de Simpson).

```c {.cb-code include_file=./integra.c include_lines=34-}
```

Geramos então vários arquivos diferentes, cada um com um número diferente de pontos amostrados do polinômio, e então executamos o programa lendo cada um desses arquivos, uma vez para cada método de integração (trapézio ou Simpson). O resultado dessas execuções é salvo no arquivo `integra.out.csv`.

### Resultados

A seguir avaliamos os resultados desses testes.

Primeiramente, carregamos um DataFrame com os resultados:

```python {.cb-nb}
data_int = pd.read_csv('integra.out.csv', \
names=['method', 'n_points', 'int']). \
sort_values(by=['method', 'n_points']). \
reset_index(drop=True);
data_int = data_int.groupby('n_points', as_index=False).\
apply(lambda x : pd.Series({
    'trap_int': x[x['method'] == 'trap']\
    .int.reset_index(drop=True)[0], \
    'simp_int': x[x['method'] == 'simpson']\
    .int.reset_index(drop=True)[0], \
}));
```

O DataFrame tem 3 colunas: `n_points`, `trap_int` e `simp_int`.  
A coluna `n_points` define a quantidade de pontos amostrados para um determinado teste.  
A coluna `trap_int` contém o valor calculado da integral, para um determinado número de pontos, usando a regra do trapézio.  
A coluna `simp_int` contém o valor calculado da integral, para um determinado número de pontos, usando a regra de Simpson.

A seguir criamos mais uma coluna, `diff_method`, que contém a diferença absoluta entre o valor calculado usando a regra do trapézio e a regra de Simpson, para um determinado número de pontos amostrados:

```python {.cb-nb}
data_int['diff_method'] = \
np.absolute(data_int.trap_int - data_int.simp_int);
display.display(data_int);
```

A seguir criamos alguns gráficos para verificar a relação entre o valor calculado por cada método e o número de pontos amostrados:

```python {.cb-nb}
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(9,15));
ax1.loglog(data_int.n_points, data_int.trap_int, label='Trapezio');
ax1.loglog(data_int.n_points, data_int.simp_int, label='Simpson');
ax1.set_title(r"Valor aproximado de $\int_{p}^{q} f(x) \, dx$ x"+ \
r" numero de pontos amostrados");
ax1.set_xlabel("Numero de pontos amostrados");
ax1.set_ylabel(r"$\int_{{p}}^{{q}} f(x) \, dx$");
ax1.legend();
ax2.loglog(data_int.n_points, data_int.diff_method);
ax2.set_title("Diferenca absoluta dos metodos x"+ \
" numero de pontos amostrados");
ax2.set_xlabel("Numero de pontos amostrados");
ax2.set_ylabel("Diferenca absoluta");
```

Note que, apesar dos dois métodos estarem convergindo para o mesmo resultado, o método do trepézio parece estar convergindo mais rapidamente, por algum motivo não aparente.  
Esse efeito fica mais aparente quando consideramos somente valores maiores de `n_pontos`:

```python {.cb-nb}
fig = plt.figure();
plt.loglog(data_int.n_points.loc[10:], data_int.trap_int.loc[10:], label='Trap');
plt.loglog(data_int.n_points.loc[10:], data_int.simp_int.loc[10:], label='Simpson');
plt.title(r"Valor aproximado de $\int_{p}^{q} f(x) \, dx$ x"+ \
r" numero de pontos amostrados");
plt.xlabel("Numero de pontos amostrados");
plt.ylabel(r"$\int_{{p}}^{{q}} f(x) \, dx$");
plt.legend();
```

Vamos agora calcular um valor aproximado para a integral, usando apenas os valores da tabela:

```python {.cb-nb}
res = pd.read_csv("integra.csv", names=['method', 'int']);
display.display(res);
```

# Segunda parte: Integração por Monte Carlo

Agora, vamos utilizar o método de Monte Carlo para aproximar a integral definida para algumas funções.  
Note que, como nesse método, os limites de integração são sempre $0$ e $1$, para integrar alguma função sobre um intervalo arbitrário, podemos precisar fazer alguma substituição de variáveis.

Vamos integrar as seguintes funções:

1. $\int_{0}^{1} \sin(x) \, dx$

    Nesse caso, não precisamos fazer nenhuma substituião de variável, pois o intervalo de integração já é $[0, 1]$.  
    Note também que podemos calcular o resultado dessa integral analiticamente:
    $$
    \begin{aligned}
    \int_{0}^{1} \sin(x) \, dx &=
    \left.\left(1-\cos(x)\right)\right|_{x=0}^{x=1}\\
    \int_{0}^{1} \sin(x) \, dx &=
    1 - \cos(1) - (1 - \cos(0))\\
    \int_{0}^{1} \sin(x) \, dx &=
    1 - \cos(1)
    \end{aligned}
    $$


2. $\int_{3}^{7} x^{3} \, dx$

    Primeiramente, vamos resolver analiticamente:
    $$
    \begin{aligned}
    \int_{3}^{7} x^{3} \, dx &=
    \left.\frac{x^{4}}{4}\right|_{x=3}^{x=7}\\
    \int_{3}^{7} x^{3} \, dx &=
    \frac{7^{4}}{4} - \frac{3^{4}}{4}\\
    \int_{3}^{7} x^{3} \, dx &=
    \frac{(7 + 3)(7-3)(7^{2} + 3^{2})}{4}\\
    \int_{3}^{7} x^{3} \, dx &=
    10 \cdot (49 + 9)\\
    \int_{3}^{7} x^{3} \, dx &= 580\\
    \end{aligned}
    $$

    Agora, vamos fazer uma substituição de variável para mudar os limites do intervalo de integração:

    $$
    \begin{aligned}
    u &= \frac{x - 3}{4}\\
    \frac{du}{dx} &= \frac{1}{4}\\
    dx &= 4du\\
    \int_{3}^{7} x^{3} \, dx &=
    \int_{u = \frac{3-3}{4}}^{u = \frac{7-3}{4}}
    4(4u + 3)^{3} \, du\\
    \int_{3}^{7} x^{3} \, dx &=
    \int_{0}^{1}
    4(4u + 3)^{3} \, du
    \end{aligned}
    $$

3. $\int_{0}^{\infty} e^{-x} \, dx$

    Vamos calcular analiticamente o valor dessa integral imprópria:
    $$
    \begin{aligned}
    \int_{0}^{\infty} e^{-x} \, dx &=
    \left.-e^{-x}\right|_{0}^{\infty}\\
    \int_{0}^{\infty} e^{-x} \, dx &=
    \left(\lim_{x \to \infty} -e^{-x}\right) -
    (-e^{0})\\
    \int_{0}^{\infty} e^{-x} \, dx &= 0 + 1\\
    \int_{0}^{\infty} e^{-x} \, dx &= 1
    \end{aligned}
    $$
    Agora, vamos fazer uma substituição de variável para adequar os limites de integração:

    $$
    \begin{aligned}
    u &= e^{-x}\\
    \frac{du}{dx} &= -e^{-x}\\
    dx &= \frac{du}{-e^{-x}}\\
    \int_{0}^{\infty} e^{-x} \, dx &=
    \int_{u = e^{0}}^{u = e^{-\infty}} -1 \, du\\
    \int_{0}^{\infty} e^{-x} \, dx &=
    -\int_{1}^{0} 1 \, du\\
    \int_{0}^{\infty} e^{-x} \, dx &=
    \int_{0}^{1} 1 \, du
    \end{aligned}
    $$

4. $4 \int_{0}^{1} \int_{0}^{1} g(x,y) \, dx \ dy$, onde
    $$
    \begin{aligned}
    g(x,y) =
    \begin{cases}
    1, &\text{ se } x^{2} + y^{2} \leq 1\\
    0, &\text{ caso contrário}
    \end{cases}
    \end{aligned}
    $$

    Já sabemos que o valor dessa integral é $\pi$.  
    Note que não precisamos fazer nenhuma substituição de variável aqui.

## Aproximando o valor das integrais

Agora, vamos aproximar o valor dessas integrais usando o método de Monte Carlo e verificar a qualidade de nossas aproximações.  
Para isso, precisamos gerar valores de variáveis aleatórias uniformemente distribuídas em $[0,1]$, aplicar a função que queremos integrar sobre cada valor, somar os resultados e tirar a sua média.

O programa `montecarlo` apresentado a seguir, escrito em C, recebe dois parâmetros: `<opt>` e `<n>`.  
O primeiro parâmetro é um inteiro de 1 a 4 que define qual das integrais listadas vamos aproximar.  
O segundo parâmetro é um inteiro positivo que define o número de amostras que iremos utilizar para o nosso cálculo.

```c {.cb-code include_file=./montecarlo.c include_lines=27- .numberLines startFrom="27"}
```
Caso `<opt>` seja 1-3, o valor da variável é calculado usando a função `double g(double x)`, que nada mais é do que um ponteiro de função, cujo valor é definido no switch das linhas 50-76. Caso `<opt>` seja 4, o cálculo é feito de uma maneira diferente, definida nas linhas 60-70, por se tratar de uma integral em duas dimensões.

### Resultados

O programa `montecarlo` é usado para aproximar o valor das integrais listadas, variando o número de amostras `<n>`, e os resultados são salvos no arquivo `montecarlo.out.csv`. A seguir analisamos esses resultados.  
O DataFrame `dt_mt` contém os resultados da aproximação de cada integral, para diferentes valores de `<n>`:

```python {.cb-nb}
dt_mt = pd.read_csv("montecarlo.out.csv", \
names=['samples','sin(x)','x ** 3','e ** (-x)','g(x, y)', '_'])\
.drop(columns='_');
display.display(dt_mt)
```
Note que, à medida que o número de amostras cresce, a aproximação de cada integral parece convergir para o valor correto que calculamos. A única exceção acontece para o cálculo de $\int_{0}^{\infty} e^{-x}$, onde o valor calculado sempre é o correto (pois a função $g(U)$ para esse caso é constante e igual a $1$).

Vamos analisar como evolui o erro relativo de cada aproximação, de acordo com o número de amostras:

```python {.cb-nb}
dt_mt['E_sin(x)'] = np.absolute(
    (dt_mt['sin(x)'] - (1 - np.cos(1)))/(1 - np.cos(1))
);
dt_mt['E_x ** 3'] = np.absolute(
    (dt_mt['x ** 3'] - 580)/580
);
dt_mt['E_e ** (-x)'] = np.absolute(
    dt_mt['e ** (-x)'] - 1
);
dt_mt['E_g(x, y)'] = np.absolute(
    (dt_mt['g(x, y)'] - np.pi)/np.pi
);
fig = plt.figure();
plt.title("Erro relativo da aproximacao da integral");
plt.xlabel("Numero de amostras");
plt.ylabel("Erro relativo");
plt.loglog(dt_mt.samples, dt_mt['E_sin(x)'], label=r'$\sin(x)$')
plt.loglog(dt_mt.samples, dt_mt['E_x ** 3'], label=r'$x^3$')
plt.loglog(dt_mt.samples, dt_mt['E_g(x, y)'], label=r'$g(x,y)$')
plt.legend();
```