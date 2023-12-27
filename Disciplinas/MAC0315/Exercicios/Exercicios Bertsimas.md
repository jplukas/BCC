# Introdução
- 1\.1 Suponha que uma função $f:\mathfrak{R}^n \mapsto \mathfrak{R}$ é ao mesmo tempo côncava e convexa. Prove que $f$ é uma função afim.
  
  Sejam $x, y \in \mathfrak{R}^n$, e $\lambda \in [0, 1]$. Como $f$ é ao mesmo tempo côncava e convexa, vale o seguinte
  $$
  \lambda f(x) + (1 - \lambda) f(y) \leq 
  f(\lambda x + (1 - \lambda) y) \leq
  \lambda f(x) + (1 - \lambda) f(y)
  $$
  O que resulta em
  $$
  f(\lambda x + (1 - \lambda) y) =
  \lambda f(x) + (1 - \lambda) f(y)
  $${#eq:primeira}
  Em particular, para $x = y$, temos
  $$
  \begin{align}
  f(\lambda x + (1 - \lambda) x) &=
  \lambda f(x) + (1 - \lambda) f(x) \\
  f(-\lambda x) &= - \lambda f(x)
  \end{align}
  $$
  Podemos dizer então, sem perda de generalidade, que 
  $$
  f(\lambda x) = \lambda f(x)
  $${#eq:segunda}
  Para todo $x \in \mathfrak{R}^n$ e $\lambda \in \mathfrak{R}$\
  Sejam $x, y \in \mathfrak{R}^n$. Por @eq:primeira temos que
  $$
  f(x/2 + y/2) = f(x)/2 + f(y)/2
  $$
  Porém, por @eq:segunda e escolhendo $\lambda = 2$, temos que
  $$
  \begin{align}
  f(2(x/2 + y/2)) &= 2(f(x)/2 + f(y)/2)\\
  f(x + y) &= f(x) + f(y)
  \end{align}
  $${#eq:terceira}
  Como $x \in \mathfrak{R}^n$, então podemos dizer que $x = (x_1, x_2, \dots, x_n)$, com $x_i \in \mathfrak{R}$ para todo $1 \leq i \leq n$. Além disso, seja $e^i \in \mathfrak{R}^n$ tal que $e^1 = (1, 0, \dots, 0)$, $e^2 = (0, 1, \dots, 0)$, e $e^n = (0, 0, \dots, 1)$, isto é: 
  $$
  e^i_k = \begin{cases}
     1, &\text{caso } i = k\\
     0, &\text{caso contrário}
  \end{cases}
  $$
  Então, podemos escrever $x = \sum_{i = 1}^n x_i e^i$, e temos, por @eq:terceira:
  $$
  \begin{align}
  f (x) &= f \left(\sum_{i = 1}^n x_i e^i \right)\\
  f(x) &= 
  \sum_{i = 1}^n f(x_i e^i)\\
  f(x) &= 
  \sum_{i = 1}^n x_i f(e^i)
  \end{align}
  $$
  Considerando $a_0 = 0$, e $a_i = f(e^i)$, para $1 \leq i \leq n$, temos que 
  $$
  f(x) = a_0 + \sum_{i = 1}^n a_i x_i
  $$
  E portanto, $f$ é uma função afim.

- 1.2 Suponha que $f_1, \dots, f_n$ sejam funções tais que $f_i:\mathfrak{R}^n \mapsto \mathfrak{R}$, e seja $f(x) = \sum_{i = 1}^m f_i(x)$. Mostre que:
   a) **Se cada $f_i$ é convexa, então $f$ também é.**

      Sejam $x, y \in \mathfrak{R}^n$, e $\lambda \in [0, 1]$. Temos que:
      $$
      \begin{align}
      f(\lambda x + (1 - \lambda) y) &= 
      \sum_{i = 1}^m f_i(\lambda x + (1 - \lambda) y)\\
      f(\lambda x + (1 - \lambda) y) &= 
      \sum_{i = 1}^m \lambda f_i(x) + (1 - \lambda) f_i(y)\\
      f(\lambda x + (1 - \lambda) y) &= 
      \lambda \left(\sum_{i = 1}^m f_i(x) \right) + 
      (1 - \lambda) \left(\sum_{i = 1}^m f_i(x) f_i(y)\right)\\
      f(\lambda x + (1 - \lambda) y) &= 
      \lambda f(x) + (1 - \lambda) f(y)
      \end{align}
      $$
      Portanto $f$ é convexa.

   b) **Se cada $f_i$ é linear por partes e convexa, então $f$ também é.**

      Já mostramos que se cada $f_i$ for convexa, então $f$ também será. Precisamos apenas mostrar que $f$ é linear por partes, se as $f_i$ forem linear por partes e convexas então.\
      Como cada $f_i$ é uma função linear por partes convexa, podemos escrever
      $$
      f_i(x) = \max_{k = 1, \dots, m} \left({c_k^i}^T x + d_k^i\right)
      $$
      E portanto, temos:
      $$
      f(x) = \sum_{i = 1}^n \max_{k = 1, \dots, m} \left({c_k^i}^T x + d_k^i\right)
      $$

- 1.3
- 1.4 Considere o problema:
   $$
   \begin{align}
   \text{minimize} \quad &2x_1 + 3|x_2 - 10|\\
   \text{sujeito a} \quad &|x_1 + 2| + |x_2| \leq 5
   \end{align}
   $${#eq:prob1}
   E o reformule como um problema de otimização linear.

   Seja $z = |x|$. Então tempos que $z$ é o menor número tal que $z \geq x$ e  $z \geq -x$. Assim, sendo $z_1, z_2, z_3$ variáveis novas, podemos escrever
   $$
   \begin{align}
      2x_1 + 3|x_2 - 10| &= 2x_1 + 3z_1 \quad \text{com}\\
      z_1 &\geq x_2 - 10\\
      z_1 &\geq 10 - x_2
   \end{align}
   $$
   $$
   \begin{align}
      |x_1 + 2| + |x_2| &= z_2 + z_3 \quad \text{com}\\
      z_2 &\geq x_1 + 2\\
      z_2 &\geq -x_1 - 2\\
      z_3 &\geq x_2\\
      z_3 &\geq -x_2\\
   \end{align}
   $$
   Então, podemos reescrever @eq:prob1 como:
   $$
   \begin{align}
      &\text{minimize} & 2x_1 + 3z_1\\
      &\text{sujeito a} & z_1 \geq x_2 - 10\\
      &&z_1 \geq 10 - x_2\\
      &&z_2 \geq x_1 + 2\\
      &&z_2 \geq -x_1 - 2\\
      &&z_3 \geq x_2\\
      &&z_3 \geq -x_2\\
   \end{align}
   $$
   Ou ainda:
   $$
   \begin{align}
      &\text{minimize} & 2x_1 + 3z_1\\
      &\text{sujeito a} & z_1 - x_2 \geq - 10\\
      &&z_1 + x_2 \geq 10\\
      &&z_2 - x_1 \geq 2\\
      &&z_2 + x_1 \geq - 2\\
      &&z_3 - x_2 \geq 0\\
      &&z_3 + x_2\geq 0\\
   \end{align}
   $$
   E finalmente, 
   $$
   \begin{align}
      &\text{minimize} & [2, 0, 0, 3, 0, 0]
      \begin{bmatrix}
      x_1\\x_2\\x_3\\z_1\\z_2\\z_3
      \end{bmatrix}
      \\
      &\text{sujeito a} & 
      \begin{bmatrix}
      0 & -1 & 0 & 1 & 0 & 0\\
      0 & 1 & 0 & 1 & 0 & 0\\
      -1 & 0 & 0 & 0 & 1 & 0\\
      1 & 0 & 0 & 1 & 1 & 0\\
      0 & -1 & 0 & 1 & 0 & 1\\
      0 & 1 & 0 & 1 & 0 & 1\\
      \end{bmatrix}
      \begin{bmatrix}
      x_1\\x_2\\x_3\\z_1\\z_2\\z_3
      \end{bmatrix} \leq
      \begin{bmatrix}
      -10\\10\\2\\-2\\0\\0
      \end{bmatrix}
   \end{align}
   $$