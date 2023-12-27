# Representação de números no computador

Como o computador representa, armazena e faz cálculos com números? Para analizar isso, vamos dividir esse assunto entre números inteiros e reais.

Para o computador, ao invés do sistema decimal, usamos o sistema binário para representar números, por conveniência. Isso se deve ao fato dos circuitos lógicos do computador trabalharem com dois estados básicos: 0 e 1, ou ligado e desligado, etc. Em um computador, a menor unidade de informação é um bit (abreviação de binary digit), cujo valor é 0 ou 1. Um byte é uma sequência de 8 bits. Uma word é uma sequência de 4 bytes (ou 32 bits).

## Inteiros

Tipicamente, inteiros são representados usando uma word, ou 32 bits. Para inteiros não-negativos, poderíamos simplesmente utilizar a notação usual em base 2 para representar um inteiro $x$ entre $0$ e $2^{32} - 1$, podendo assim representar $2^{32}$ inteiros não-negativos diferentes.\
Por exemplo, o número $71$ poderia ser representado como
$$000000000000000000000000001000111$$
e o número $0$ como
$$000000000000000000000000000000000$$

### Complemento de 2

Para representar números negativos, uma ideia seria usar o bit mais significativo (mais a esquerda) para representar o sinal, e o restante para representar o módulo do número. Assim, o número $-71$ seria representado como
$$100000000000000000000000001000111$$
Poderíamos dizer que desse modo, poderíamos representar $2^{32}$ inteiros diferentes, metade positiva e metade negativa, porém, nesse esquema, o número $0$ seria representado de duas formas distintas:
$$000000000000000000000000000000000$$
e
$$100000000000000000000000000000000$$
então apenas podemos representar números inteiros entre $-2^{32} + 1$ e $2^{32} - 1$.

Outra forma de se representar inteiros, mais conveniente, é por meio do complemento de 2. Nessa forma, um inteiro não-negativo entre $0$ e $2^{32} - 1$ é representado de maneira usual, segundo sua expansão binária. Porém, um inteiro negativo $-y$ é representado segundo a expansão binária $2^{32} - y$.\
Por exemplo, o número $71$ seria representado da maneira usual, enquanto o número $-71$ seria representado como
$$111111111111111111111111110111001$$
Para verificar que essa representação é correta, vamos adicionar as representações de $71$ e $-71$:
$$
000000000000000000000000001000111+ \\
111111111111111111111111110111001 \\
= 1000000000000000000000000000000000$$
Entao, retirando-se o bit de overflow, obtemos a representacao correta do resultado.

Podemos agora entao representar inteiros entre $-2^{32}$ e $2^{32} - 1$.

## Nao inteiros

### Ponto fixo

Na representação de ponto fixo, dividimos a word em três partes. Um bit para o sinal, 15 bits para a parte inteira e 16 bits para a parte não inteira (depois da vírgula, na representação binária). Desse modo, temos como representar números desde 2^-15 até 2^15. O número 11/2 seria representado como:
|0|000000000000101|100000000000000|
|-|---------------|---------------|

### Ponto Flutuante

No sistema de ponto flutuante, representamos um número real de forma similar a notação científica (ou exponencial). Seja um número real $x$, representamos $x$ na notação científica como $x = S \cdot 10^E$, com $1 \leq S < 10$. Isto é, representamos o número $233,526$ em notação científica como $2,33526 \cdot 10^{2}$.
No nosso caso, como queremos representar números reais em um computador, usaremos o sistema binário para isso. Então, dado um número real $x$, o representaremos como $x = S \cdot 2^E$, onde $1 \leq S < 2$. Assim, dividimos a word em três partes: um bit para o sinal, oito bits para o expoente $E$, e 23 bits para a mantissa $S$. Assim, o número $11/2$ seria representado como:
|0|00000011|10110000000000000000000|
|-|--------|-----------------------|
Porém, como $1 \leq S$, então o primeiro bit de $S$ deve sempre ser $1$, e não precisamos armazenar esse bit. De fato, não o fazemos na prática, e então nossa representação para o número $11/2$ fica como
|0|00000010|01100000000000000000000|
|-|--------|-----------------------|

Assim, podemos armazenar números de $2^{-256}$ a $2^{256}$ (embora não todos os números entre eles), o que não é possível utilizando inteiros de 32 bits!
(Por quê? Como a máquina faz operações aritméticas de ponto flutuante?)

### Precisao, epsilon de maquina e ulp

A precisão de um sistema de ponto flutuante é determinado pelo número de bits da mantissa mais o bit escondido. Nós denotamos esse número por $p$. No caso anterior, $p = 24$.
O menor número de ponto flutuante que é maior do que $1$ é:
$$
    (1.000\dots 1)_{2} = 1 + 2^{-(p-1)}
$$
Ao intervalo entre $1$ e esse número, damos o nome de épsilon da máquina:
$$
    \epsilon = 1 + 2^{-(p-1)} - 1 = 2^{1-p}
$$
Mais geralmente, para qualquer número de ponto flutuante $x = S \cdot 2^E$, denominamos $ulp(x) = \epsilon \cdot 2^{E}$. Ou seja, $ulp(x)$ é o intervalo entre $x$ e o próximo número de ponto flutuante.

### O Numero especial Zero

Para representar o número $0$, temos um problema, pois com o bit $1$ escondido na mantissa, se todos os bits da nossa mantissa forem $0$, o número representado será somente uma potência de $2$. Uma possibilidade de se tratar esse problema é esquecer a ideia do bit escondido, e perder um bit de precisão, ou utilizar uma bitstring de zeros no expoente para sinalizar quando o número é zero. Veremos mais adiante como o sistema IEEE resolve esse problema.

### Diferenças de densidade

Considere a distância entre os números de ponto flutuante com expoente igual a $0$ (isto é, $E = 0$). Já vimos que $ulp(x) = 2^E \cdot \epsilon$. Então, nesse caso, $ulp(x) = \epsilon$ para todos esses números. Já para o caso em que $E$ é um número grande, digamos, $20$, temos que $ulp(x) = 2^{20} \cdot \epsilon$. Então as distâncias entre os números de ponto flutuante aumentam conforme aumentam os expoentes.  

# A representação de ponto flutuante do IEEE

## Ponto flutuante do IEEE, requisitos

Todos os formatos de representação de números de ponto flutuante do IEEE tem 3 requisitos básicos:

- Representação consistente de números de ponto flutuante
- Operações aritméticas com arredondamento correto com modos de arredondamento diferentes
- Tratamento consistente de situações excepcionais como divisão por $0$.

## O formato Single

## Subnormais

## O formato Double

## Single vs Double

## O formato Extended

## Precisão e epsilon de máquina dos formatos IEEE

## Dígitos significativos

## Big e Little Endian
