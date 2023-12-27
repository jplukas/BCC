# Convergência Absoluta e Condicional

[Convergência Absoluta]{#def:convergencia_absoluta}
: Dizemos que uma série $\sum_{n=1}^{\infty}a_{n}$ é ***absolutamente convergente*** se $\sum_{n=1}^{\infty}|a_{n}|$ for convergente.

[Convergência condicional]{#def:convergencia_condicional}
: Uma série que é convergente, mas não é absolutamente convergente é denominada ***condicionalmente convergente***.

[Convergência absoluta]{#thm:conv_abs}
: Se $\sum_{n=1}^{\infty} |a_{n}|$ for convergente, então $\sum_{n=1}^{\infty}a_{n}$ também será.

## Critério da razão para séries de termos quaisquer

[Critério da razão generalizado]{#thm:crit_razao_geral}
: Seja a série $\sum_{n=1}^{\infty}a_{n}$, com $a_{n} \neq 0$ para todo $n \in \mathbb{N}$. Suponha que o limite $\lim_{n \to \infty} \left| \frac{a_{n+1}}{a_{n}} \right| = L$ exista, seja ele finito ou infinito. Então temos:

    1. Se $L < 1$, a série é convergente
    2. Se $L > 1$ ou $L = \infty$, a série é divergente
    3. Se $L = 1$, o critério nada revela
