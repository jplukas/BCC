---
title: |
       | MAC 0210 - Laboratorio de Metodos Numericos
       | EP 2 - Comprimir e conquistar

author: |
        | Joao Pedro Lukasavicus Silva
        | <joao.lukasavicus.silva@usp.br>
        | 9276940
...

# Introdução

Este exercício-programa tem como objetivo generalizar dois métodos de interpolação por polinômios para o caso bivariado: a interpolação bilinear e a interpolação bicúbica. O experimento consiste em começar com uma imagem grande, fazer uma amostra pequena de seus pixels e depois reconstruıí-la.

Vamos testar esses métodos para imagens geradas por funções e imagens reais. Além disso, vamos obter uma medida do erro da interpolação para cada imagem reconstruída.  
Observação: somente vamos considerar imagens quadradas.

Vamos utilizar o Octave como plataforma de programação para escrever nossos programas.  
Vamos usar duas funções nativas do Octave: `imread` e `imwrite`.  
Para os nossos fins, essas duas funções leem imagens tratam imagens como "matrizes" de inteiros $m \times n$, onde $m$ denota o número de linhas da matriz e $n$ o número de colunas. Cada elemento da matriz, por sua vez, é um vetor $(r, g, b) \in \mathbb{N}^{3}$, onde $0 \leq r,g,b \leq 255$, que representa um pixel da imagem, em que cada componente determina o valor da intensidade de uma cor para um determinado pixel ($r$ para **vermelho**, $g$ para **verde** e $b$ para **azul**).

# Compressão de imagens

Para "comprimir" uma imagem, vamos prosseguir do seguinte modo: Seja `originalImg.png` a imagem original, e $A$ a sua representação matricial, como indicamos anteriormente.  
Suponha que $A$ seja uma matriz quadrada $p \times p$, e que existam $n,k \in \mathbb{N}$ tais que $p = n(k + 1) + 1$. Sejam $(a_{i, j})_{1 \leq i,j \leq p}$ os elementos de $A$. Então vamos manter em $A$ somente os elementos $a_{i,j}$ tais que
$$
\begin{aligned}
i &\equiv 1 \pmod{k+1}\\
j &\equiv 1 \pmod{k+1}
\end{aligned}
$$
Assim, denote por $A^{\prime}$ a matriz que representa a imagem depois da compressão. Temos que $A^{\prime}$ será uma matriz quadrada $n (k + 1) \times n (k + 1)$.

A seguir está o código que faz a compressão das imagens:
```octave {.cb-code include_file="./source/ep2/compress.m" .numberLines}
```  

# Reconstrução das imagens

Para reconstruir cada imagem, basicamente inserimos espaços entre os pixels que conhecemos e preenchemos esses espaços utilizando o método de interpolação escolhido: bilinear ou bicúbico.

# Experimentos

## Experimento 1 - Imagens geradas por computador

Primeiramente, vamos testar os nossos metodos de interpolacao com funcoes geradas por computador.

Primeiramente, vamos usar imagens em preto e branco.

: $f(x,y) = \sin x$

+--------+--------------------------------+----------------------------------------+
|Tipo    |Imagem                          |Erro                                    |
+:======:+:==============================:+:======================================:+
|Original|![Original-1]{height=175px}     |N/A                                     |
+--------+--------------------------------+----------------------------------------+
|Bilinear|![Reconstruida-11]{height=175px}|`_`{.bash .cb-paste copy=e_41 show=expr}|
+--------+--------------------------------+----------------------------------------+
|Bicubica|![Reconstruida-12]{height=175px}|`_`{.bash .cb-paste copy=e_42 show=expr}|
+--------+--------------------------------+----------------------------------------+

: $f(x,y) = \sin x$

+--------+--------------------------------+----------------------------------------+
|Tipo    |Imagem                          |Erro                                    |
+:======:+:==============================:+:======================================:+
|Original|![Original-2]{height=175px}     |N/A                                     |
+--------+--------------------------------+----------------------------------------+
|Bilinear|![Reconstruida-21]{height=175px}|`_`{.bash .cb-paste copy=e_51 show=expr}|
+--------+--------------------------------+----------------------------------------+
|Bicubica|![Reconstruida-22]{height=175px}|`_`{.bash .cb-paste copy=e_52 show=expr}|
+--------+--------------------------------+----------------------------------------+

: $f(x,y) = \sin x$

+--------+--------------------------------+----------------------------------------+
|Tipo    |Imagem                          |Erro                                    |
+:======:+:==============================:+:======================================:+
|Original|![Original-3]{height=175px}     |N/A                                     |
+--------+--------------------------------+----------------------------------------+
|Bilinear|![Reconstruida-31]{height=175px}|`_`{.bash .cb-paste copy=e_61 show=expr}|
+--------+--------------------------------+----------------------------------------+
|Bicubica|![Reconstruida-32]{height=175px}|`_`{.bash .cb-paste copy=e_62 show=expr}|
+--------+--------------------------------+----------------------------------------+

## Resultados

```python {.cb-nb jupyter_kernel=python3}
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sympy as sp
from IPython import display
import warnings
warnings.filterwarnings('ignore')
import csv
plt.rcParams['ytick.right'] = plt.rcParams['ytick.labelright'] = True
plt.rcParams['ytick.left'] = plt.rcParams['ytick.labelleft'] = False
```

```python {.cb-nb}
data = pd.read_csv('source/testes/data.csv');
```

```python {.cb-nb}
for (img_name,), group_img in data.groupby(['img']):
    fig, axs = plt.subplots(1, 2, sharey=True);
    fig.add_subplot(111, frameon=False);
    plt.tick_params(labelcolor='none', top=False,
    bottom=False, left=False, right=False);
    plt.grid(False);
    plt.xlabel("k");
    plt.ylabel("Erro");
    i = 0;
    for (direto,), group_direto in group_img.groupby(['direto']):
        axs[i].set_title(f"Reconstrucao: {direto}");
        for (metodo,), group_metodo in group_direto.groupby(['metodo']):
            axs[i].loglog(group_metodo.k, group_metodo.erro, label=metodo, base=2);
        axs[i].legend();
        i += 1;

    plt.suptitle(f"Erro versus 'k', imagem: {img_name}");
```

`octave --eval "calculateError('source/testes/in_4.png','source/testes/4_decompressed_15_1.png')" -p source/ep2`{.bash .cb-expr show=none name=e_41}

`octave --eval "calculateError('source/testes/in_4.png','source/testes/4_decompressed_15_2.png')" -p source/ep2`{.bash .cb-expr show=none name=e_42}

`octave --eval "calculateError('source/testes/in_5.png','source/testes/5_decompressed_15_1.png')" -p source/ep2`{.bash .cb-expr show=none name=e_51}

`octave --eval "calculateError('source/testes/in_5.png','source/testes/5_decompressed_15_2.png')" -p source/ep2`{.bash .cb-expr show=none name=e_52}

`octave --eval "calculateError('source/testes/in_6.png','source/testes/6_decompressed_15_1.png')" -p source/ep2`{.bash .cb-expr show=none name=e_61}

`octave --eval "calculateError('source/testes/in_6.png','source/testes/6_decompressed_15_2.png')" -p source/ep2`{.bash .cb-expr show=none name=e_62}

[Original-1]: ./source/testes/in_4.png
[Reconstruida-11]: ./source/testes/4_decompressed_15_1.png
[Reconstruida-12]: ./source/testes/4_decompressed_15_2.png

[Original-2]: ./source/testes/in_5.png
[Reconstruida-21]: ./source/testes/5_decompressed_15_1.png
[Reconstruida-22]: ./source/testes/5_decompressed_15_2.png

[Original-3]: ./source/testes/in_6.png
[Reconstruida-31]: ./source/testes/6_decompressed_15_1.png
[Reconstruida-32]: ./source/testes/6_decompressed_15_2.png