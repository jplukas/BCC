# Introducao

Qual eh o melhor algoritmo de ordenacao?  
O que eh melhor?  
A pergunta trata-se de classificar algoritmos  
Analise de algoritmos

Quais problemas podem ser resolvidos por um computador?
O que eh problema?  
O que queremos dizer por resolver?  
O que eh um computador?  
Essas perguntas tratam-se de classificar problemas.  
Essas sao perguntas que tentaremos responder ao longo de todo o semestre.  

# Problema em MAC0414

Exemplo:
Dado um numero inteiro $n$, decidir se $n$ eh primo.  
Problemas de decisao - resposta SIM ou NAO.

Dado uma string $w$ sobre $\{0,1\}$, decidir se $w$ esta em $L$ (primos).

***Alfabeto:*** Conjunto nao-vazio de simbolos.  
$$
\begin{aligned}
\Sigma &= \{0,1\}\\
\Gamma &= \{a, b, c\}
\end{aligned}
$$

***String:*** sequencias *finitas* $w$ de simbolos de um alfabeto $\Sigma$
$$
\begin{aligned}
w &= w_{1}, \ldots, w_{n}\\
w &= 01101
\end{aligned}
$$
$n$ eh o comprimento da string

Uma ***linguagem*** (sobre um alfabeto $\Sigma$) eh um conjunto de strings (sobre $\Sigma$).  
A definicao/especificacao de uma linguagem tem a cara
$$
\begin{aligned}
\{w : w \text{ satisfaz alguma condicao}\} \\
\{w : w \text{ tem o mesmo numero de 0s e 1s}\}\\
\{w : w \text{ eh um inteiro binario que eh primo}\}
\end{aligned}
$$

# Computacao

## Maquina de estados

Modelo de maquina (finita) de estados.

String fornecida em uma fita dividida em posicoes, e cada posicao tem um simbolo.

(@) Cabeca le um simbolo, fornece ao controle e move a fita uma posicao.

(@) Controle vai para um estado que depende do estado atual e do simbolo lido

A maquina aceita ou rejeita uma string.

## Automatos

Tem estados, transicoes

Um ***automato finito deterministico*** eh composto por 5 coisas $(Q, \Sigma, \delta, s, F)$

- $Q$: conjunto de estados;
- $\Sigma$: alfabeto da fita;
- $\delta : Q \times \Sigma \to Q$;
- $s$: estado inicial;
- $F$: conjunto de estados de aceitacao;

O conjunto de todas as linguagens reconhecidas por um automato $M$ eh denominada ***linguagem de $M$***.