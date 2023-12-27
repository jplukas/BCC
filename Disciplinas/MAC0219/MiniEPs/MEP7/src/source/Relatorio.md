---
title: |
       | MAC 0219/5742 - Introdução à Computação Paralela e Distribuída
       | Mini EP 7 - contenção

author: |
        | Joao Pedro Lukasavicus Silva
        | <joao.lukasavicus.silva@usp.br>
        | 9276940

codebraid:
        jupyter: true
...

# Introducao

Em computação paralela, contenção (ou thread contention) é o nome dado para a
situação em que uma ou mais threads se encontram impossibilitadas de continuar pois
aguardam um recurso compartilhado que atualmente está sendo utilizado por outra
thread. O tempo que uma thread passa em contenção é essencialmente perdido, em vez
de ser usado para alguma tarefa útil.
Um exemplo de contenção é o caso em que muitas threads chegam em uma seção
crítica ao mesmo tempo. Como apenas uma pode executar a região, simultaneamente,
todas as demais ficarão aguardando até que a região seja liberada. Este caso também é
chamado de lock contention.
Neste mini EP, tentaremos empregar uma técnica para redução de contenção em um
programa contendo uma seção crítica.

## O programa

O programa preenche um vetor com numeros pseudo-aleatórios, depois cria um número de threads e usa essas threads para  transformar o conteúdo do vetor e depois calcular o seu valor máximo. Cada thread deve iterar sobre sua parte do vetor, e a cada iteração realizar as suas transformações, e depois consultar uma variável global para decidir se o iterando atual é maior do que o máximo global. Se for, o valor do máximo global é atualizado.
Então, no nosso programa, a comunicação entre as threads é feita com variáveis compartilhadas.

Note que, como temos várias threads tentando ler e escrever em um mesmo espaço de memória (a variável `max`), precisamos de algum tipo de sincronização para garantir consistência. Por exemplo, pode ser que a thread 1 consulte o valor da variável `max`, decida que o iterando atual é maior do que `max` e decida atualizar seu valor. Porém, entre a instrução de verificação do valor de `max` e a sua atualização, a thread 2 faz essas duas operações, e o valor do iterando atual da segunda thread é maior do que o da primeira. Então, logo após a thread 2 terminar essas operações, a thread 1 atualiza o valor de `max`, gerando um resultado incorreto. Para previnir isso, definimos uma *seção crítica*, onde apenas uma thread pode executar os seus comandos de uma vez. Podemos dizer então que definir uma seção crítica é como definir uma operação atômica, uma vez que as suas operações devem ser executadas todas de uma vez, sem se misturar com operações de outras threads.

Isso é implementado no nosso programa por meio de um *mutex*. Um *mutex* é uma espécie de 'trava', que pode ser bloqueada e desbloqueada:

```c {.numberLines startFrom="70"}
{
   pthread_mutex_lock(&lock);
   if (t->arr[i] > max)
      max = t->arr[i];
   pthread_mutex_unlock(&lock);
}
```

Para entrar na seção crítica, uma thread deve tentar obter o mutex, por meio da instrução `pthread_mutex_lock(&lock)`. Se o mutex estiver desbloqueado, o que significa que nenhuma outra thread esta na seção crítica, a thread então bloqueia o mutex e executa as instruções subsequentes.
Se o mutex estiver bloqueado, significa então que alguma outra thread esta na seção crítica. então a thread que nao conseguiu obter o mutex é bloqueada, e deve aguardar ate que o sistema operacional a 'acorde' de novo.

Para sair da seção crítica e desbloquear o mutex, uma thread invoca a função `pthread_mutex_unlock(&lock)`, o que sinaliza para o sistema operacional acordar alguma outra thread que esteja dormindo esperando para entrar na seção crítica, se houver.

## Thread contention

A seguir está o código completo que é executado por cada thread do programa:

```c {.numberLines startFrom="54"}
void *thread_work(void *arg) {
   struct task *t = (struct task *)arg;
   
      for (int i = 0; i < t->size; ++i) {
      t->arr[i] = a_laborious_function(t->arr[i]);
      t->arr[i] = a_laborious_function(t->arr[i]);
      
      // protecao para possiveis NaNs ou overflows
      if(isnan(t->arr[i]) || isinf(t->arr[i]))
         t->arr[i] = rand() / RAND_MAX;
      
      // Nao modifique o comentario a seguir (linha 69). 
      // Ele sera substituido em tempo de compilacao de acordo 
      // com o valor do parametro IF do Makefile:
      
      //@#@IF
      {
         pthread_mutex_lock(&lock);
         if (t->arr[i] > max)
            max = t->arr[i];
         pthread_mutex_unlock(&lock);
      }
   
   }
   
   return NULL;
}
```

Note que, a cada iteração do laço das linhas 57-77, é feita uma chamada da função `pthread_mutex_lock(&lock)`, que potencialmente bloqueia a thread. Muitas dessas chamadas sao desnecessárias, pois somente precisamos entrar na regiao crítica quando vamos escrever na variável `max`, isto é, quando o iterando atual for maior que `max`. Assim, muitas threads ficam bloqueadas desnecessariamente enquanto poderiam estar realizando trabalho, como por exemplo, executando os comandos das linhas 58-59, `t->arr[i] = a_laborious_function(t->arr[i])`.

## Redução de contenção

Um possível modo de mitigar esse problema seria fazer a verificação da linha 72 antes da seção crítica. Se o iterando atual nao for maior do que o valor de `max`, nao precisamos bloquear a thread, e podemos continuar realizando trabalho:

```c {.numberLines startFrom="69"}
if (t->arr[i] > max)
{
   pthread_mutex_lock(&lock);
   if (t->arr[i] > max)
      max = t->arr[i];
   pthread_mutex_unlock(&lock);
}
```

No nosso projeto, isso é feito por meio de diretivas de compilacao, utilizando o comando `make IF=k`, onde `k` é um numero natural que representa a quantidade de *if*s encadeados na linha 70. Por exemplo, compilando o projeto utilizando o comando `make IF=3` transformaria o código das linhas 69-75 em:

```c {.numberLines startFrom="69"}
if (t->arr[i] > max) if (t->arr[i] > max) if (t->arr[i] > max)
{
   pthread_mutex_lock(&lock);
   if (t->arr[i] > max)
      max = t->arr[i];
   pthread_mutex_unlock(&lock);
}
```

Note que, mesmo realizando `k` vezes o teste `t->arr[i] > max` na linha 69, ainda precisamos realizar esse mesmo teste na linha 72, uma vez que os testes da linha 69 nao estao na seção crítica, então nada garante que outra thread entre na seção crítica entre a execucao da linha 69 e 70, que é onde efetivamente a nossa thread entraria na seção crítica.

# Testes

Queremos analisar a influencia dos diferentes parametros sobre o tempo de execucao do algoritmo. Para isso, vamos variar cada parametro dentro de um conjunto estabelecido e executar o programa para cada variacao dos parametros. Além disso, vamos rodar um teste com os mesmos parâmetros por 30 vezes, e obter a média dos tempos de execução.

Sejam $I, S, T$ os conjuntos de valores para os parametros "quantidade de ifs", "tamanho do array" e "numero de threads", respectivamente. então, efetivamente teremos uma execucao do programa para cada elemento de $I \times S \times T$.

Usamos então o seguinte script para fazer esses testes:

```sh {.numberLines}
#!/bin/bash

n_tests=30
ifs=2
threads=12
v_size_start=10000
v_size_end=20000000
iterations=10
v_step=$((($v_size_end - $v_size_start)/$iterations))
fname=out.csv

if test -f "$fname"; then
    rm -f "$fname"
fi
echo ifs,threads,v_size,iter,time >> $fname
for i in `seq 0 $ifs`;
do
    make IF=$i &> /dev/null
    for j in `seq 1 $threads`;
    do
        for k in `seq $v_size_start $v_step $v_size_end`;
        do
            for n in `seq 1 $n_tests`;
            do
                echo -n "$i,$j,$k,$n," >> $fname
                ./contention $j $k >> $fname
            done
        done
    done
done
```

O código acima primeiro compila o programa usando o comando `MAKE IF=i`, para $i \in I$, depois executa o programa compilado `./contention $j $k`, com parametros $j \in T$, $k \in S$, por 30 vezes, e salva o resultado de cada execucao no arquivo `out.csv`.

Note que
$$
\begin{aligned}
I &= \{0, 1, 2\}\\
S &= \{x \in \mathbb{N} : 10000 \leq x \leq 20000000 \wedge x \equiv 10000 \pmod{20000000 / 10}\}\\
T &= \{x \in \mathbb{N} : 1 \leq x \leq 12\}
\end{aligned}
$$
E
$$
\begin{aligned}
|I| &= 3\\
|S| &= 11\\
|T| &= 12
\end{aligned}
$$
então $|I \times S \times T| = 396$, isto é, temos $396$ variacoes de parametros para analisar.

# Resultados

Para analisar os dados gerados pelos testes da seção anterior, vamos usar o python com alguns pacotes, como pandas, numpy, scipy e scikit-learn. Para gerar graficos, usaremos o matplotlib.

## Configuracoes preeliminares

### Importando bibliotecas

```python {.cb-nb}
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
import numpy as np
import scipy.stats as st
```

### Lendo e formatando dados

```python {.cb-nb}
df = pd.read_csv('out.csv')
df['time'] = pd.to_numeric(df['time'].str.replace('s', ''))
print(f"Tempo total: {df.time.sum()} segundos")
```

### Calculando as médias e intervalos de confiança

```python {.cb-nb}
def transf(x):
    lo, up = st.t.interval(confidence=0.99, df=29, loc=x.time.mean(), scale=st.sem(x.time))
    t_mean = x.time.mean()
    s = pd.Series({
        'time_lo' : lo,
        'time_up' : up,
        'time_mean' : t_mean
    })

    return s

data = df.groupby(['ifs', 'threads', 'v_size'], as_index=False).apply(transf)
```

## Tamanho do vetor x tempo de execucao

Agora, vamos analisar a relacao entre o parametro "tamanho do vetor" e o tempo de execucao do algoritmo, para cada valor possível dos parametros "quantidade de ifs" e "threads":

```python {.cb-nb}
ifs = data['ifs'].unique().tolist()
for ifn in range(len(ifs)):
   fig = plt.figure(figsize=(9, 5))
   plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,15)))
   df_0 = data[data['ifs'] == ifs[ifn]]
   for val in df_0['threads'].unique().tolist():
      t = df_0[df_0['threads'] == val]
      plt.plot(t['v_size'], t['time_mean'], label=f"{val} threads")
      plt.fill_between(t['v_size'], t['time_lo'], t['time_up'])
   plt.suptitle("Tamanho do vetor x Tempo de execucao")
   plt.title(f"IF={ifs[ifn]}")
   plt.ylabel('Tempo de execucao (segundos)')
   plt.xlabel('Numero de posicoes do vetor')
   fig.legend()
```

Podemos ver que, quando fixamos os parametros "quantidade de ifs" e "threads", ha uma clara relacao de dependencia linear entre o parametro "tamanho do vetor" e o tempo de execucao do programa. Isto é praticamente equivalente a dizer que a complexidade de tempo do nosso algoritmo é linear no tamanho do vetor, ou $O(n)$ (onde $n$ é o tamanho do vetor).

## Coeficiente linear

Como existe essa relacao, podemos então reduzir a dimensao do nosso dataset. Vamos trocar as variáveis "tempo de execucao" e "tamanho do vetor" por uma unica variável: "coeficiente linear", que é o coeficiente linear entre essas duas variáveis:

```python {.cb-nb}
def insp(x):
   return pd.Series({'lin':LinearRegression().fit(x[['v_size']], x.time_mean).coef_[0]})

grouped = data.groupby(['ifs', 'threads'], as_index=False).apply(insp)
```

Agora, vamos tentar analisar a relacao entre as variáveis "numero de ifs", "threads" e "coeficiente linear":

```python {.cb-nb}
fig = plt.figure()
plt.title('Numero de threads x coeficiente linear')
plt.xlabel('Numero de threads')
plt.ylabel('Coeficiente linear (tamanho do vetor x tempo)')
plt.xticks([i for i in range(1, len(grouped['threads'].unique()) + 1)])
for val in grouped['ifs'].unique().tolist():
   t = grouped[grouped['ifs'] == val]
   plt.plot(t['threads'], t['lin'], '--o', label=f"IF={val}")
fig.legend()
```

Podemos ver claramente duas situações distintas. Na primeira, onde `IF=0`, não estamos empregando nenhuma estratégia de redução de contenção. Então, ao aumentar a quantidade de threads, é esperado que consigamos reduzir o tempo de execução do algoritmo. Entretanto, como podemos ver acima, essa aceleração para em "threads"=3, e não conseguimos nenhum benefício adicional ao continuar aumentando o número de threads do programa. Na verdade, após esse ponto, o coeficiente linear entre o tamanho do vetor e o tempo de execução do programa volta a crescer, chegando inclusive ao mesmo patamar da situacao em que o programa é executado com uma unica thread.
Parece que estamos observando, na pratica, o efeito da contenção de threads, mais especificamente, de lock contention.

## Thread contention na pratica

### Numero de threads x tempo de execucao

Vamos analisar melhor a relacao entre o numero de threads e o tempo de execucao do programa, para diferentes tamanhos de array:

```python {.cb-nb}
fig = plt.figure(figsize=(9, 5))
plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,15)))
df_0 = data[data['ifs'] == ifs[0]]
lst = df_0['v_size'].unique().tolist()
plt.xlabel('Numero de threads')
plt.ylabel('Tempo de execucao (segundos)')
plt.xticks([i for i in range(1, len(df_0['threads'].unique()) + 1)])
for val in range(len(lst)):
    t = df_0[df_0['v_size'] == lst[val]]
    plt.plot(t['threads'], t['time_mean'], '-o', label=f"v_size={lst[val]}")
    plt.fill_between(t['threads'], t['time_lo'], t['time_up'])

plt.title("Threads x tempo de execucao, para IF=0")
fig.legend()
```

Note que o gráfico confirma nossa suposição: o tempo de execução praticamente cai pela metade quando o numero de threads passa de 1 para 2, mas a partir de 3 threads, esse tempo para de diminuir e passa a aumentar, chegando ate o patamar do tempo de execucao com apenas uma thread novamente.

## redução de thread contention

Vamos observar agora os efeitos da estrategia de redução de contenção adotada:

### Numero de threads x tempo de execucao

```python {.cb-nb}
for i in range(1, 3):
    fig = plt.figure(figsize=(9, 5))
    plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,15)))
    df_0 = data[data['ifs'] == ifs[i]]
    plt.xlabel('Numero de threads')
    plt.ylabel('Tempo de execucao (segundos)')
    plt.xticks([i for i in range(1, len(df_0['threads'].unique()) + 1)])
    for val in df_0['v_size'].unique().tolist():
        t = df_0[df_0['v_size'] == val]
        plt.plot(t['threads'], t['time_mean'], '-o', label=f"v_size={val}")
        plt.fill_between(t['threads'], t['time_lo'], t['time_up'])
    plt.suptitle("Numero de threads x tempo de execucao")
    plt.title(f"IF={ifs[i]}")
    fig.legend()
```

A estrategia de contenção adotada parece ser efetiva, pois parece manter o efeito do aumento de threads sobre o tempo de execucao do algoritmo para alem de 3 threads, continuando a diminuir o tempo de execucao do programa, a medida que o numero de threads aumenta.

### Performance prevista

Temos, em `contention.c`, o seguinte código:

```c {.numberLines startFrom="127"}
int threads_with_one_more_work = N % num_threads;
for (int i = 0; i < num_threads; ++i) {
   int work_size = N / num_threads;
   if (i < threads_with_one_more_work)
      work_size += 1;
   tasks[i].arr = V + i * work_size;
   tasks[i].size = work_size;
   if(pthread_create(&threads[i], NULL, thread_work, (void *)&tasks[i]))
   DIE("Failed to create thread %d\n", i)
}
```

Onde dividimos o vetor `V` em `num_threads` partes, e cada thread fica responsavel por iterar sobre um subvetor de tamanho $\lceil \frac{N}{t} \rceil$, onde $N$ é o tamanho do vetor, e $t$ é a quantidade de threads.

Esperamos então que, sem estar sob a influencia de contenção de threads, e enquanto cada thread puder ser executada em um processador diferente, que a complexidade de tempo do nosso programa seja algo proximo de $O(\frac{N}{t})$. Para simplificar as coisas, vamos então admitir que o tempo seja linear em $\frac{N}{t}$

Seja $T \left(\frac{N}{t}\right)$ o tempo que o programa leva para executar para um vetor de tamanho $N$, com $t$ threads. Assumindo todas as condicoes acima, temos:
$$
\begin{aligned}
T\left(\frac{N}{t}\right) &= \alpha + \beta \left(\frac{N}{t}\right) \\
T\left(\frac{N}{1}\right) &= \alpha + \beta \left(\frac{N}{1}\right) \\
\alpha &= T\left(\frac{N}{1}\right) - \beta \left(\frac{N}{1}\right)\\
T\left(\frac{N}{t}\right) &=
T\left(\frac{N}{1}\right) - \beta \left(\frac{N}{1}\right) + \beta \left(\frac{N}{t}\right) \\
T\left(\frac{N}{t}\right) &=
T\left(\frac{N}{1}\right) + \beta \left(\frac{N}{t} - \frac{N}{1}\right)\\
T\left(\frac{N}{t}\right) &=
T\left(\frac{N}{1}\right) + \beta N \left(\frac{1 - t}{t}\right)\\
\beta N &=
\left(T\left(\frac{N}{t}\right) - T\left(\frac{N}{1}\right)\right) \left(\frac{t}{1 - t}\right)\\
\end{aligned}
$$
Para $t \geq 2$.

então, para um determinado valor de $N$, esperamos que o valor de $\beta N \approx \beta_{t N} N = \left(T\left(\frac{N}{t}\right) - T\left(\frac{N}{1}\right)\right) \left(\frac{t}{1 - t}\right)$ seja aproximadamente constante. Vamos verificar isso:

```python {.cb-nb}
for i in range(1, 3):
    fig = plt.figure(figsize=(9, 5))
    plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,15)))
    plt.xlabel("Threads")
    plt.ylabel(r"$\beta_{t N} N \approx \beta N$")
    df_0 = data[data['ifs'] == ifs[i]]
    plt.xticks([i for i in range(2, len(df_0['threads'].unique()) + 1)])
    for val in df_0['v_size'].unique().tolist():
        t = df_0[df_0['v_size'] == val]
        plt.plot(t['threads'].iloc[1:], (t['time_mean'].iloc[1:] - t['time_mean'].iloc[0]) *
        (t['threads'].iloc[1:] / (1-t['threads'].iloc[1:])), '-o', label=f"v_size={val}")
    plt.title(f"IF={ifs[i]}")
    plt.suptitle(r"Threads x $\beta_{t N} N$")
    fig.legend()
```

Parece ser o caso. Vamos melhorar nossa analise, diminuindo o efeito de $N$ (isto é, calculando o valor de $\beta_{t N} = \frac{1}{N}\left(T\left(\frac{N}{t}\right) - T\left(\frac{N}{1}\right)\right) \left(\frac{t}{1 - t}\right)$):

```python {.cb-nb}
for i in range(1, 3):
    fig = plt.figure(figsize=(9, 5))
    plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,15)))
    plt.xlabel("Threads")
    plt.ylabel(r"$\beta_{t N} \approx \beta$")
    df_0 = data[data['ifs'] == ifs[i]]
    plt.xticks([i for i in range(2, len(df_0['threads'].unique()) + 1)])
    for val in df_0['v_size'].unique().tolist():
        t = df_0[df_0['v_size'] == val]
        plt.plot(t['threads'].iloc[1:], ((t['time_mean'].iloc[1:] - t['time_mean'].iloc[0]) *
        (t['threads'].iloc[1:] / (1-t['threads'].iloc[1:])))/
        val, '-o', label=f"v_size={val}")
    plt.title(f"IF={ifs[i]}")
    plt.suptitle(r"Threads x $\beta_{t N}$")
    fig.legend()
```

Vamos agora excluir o caso onde $N = 10000$:

```python {.cb-nb}
for i in range(1, 3):
    fig = plt.figure(figsize=(9, 5))
    plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,15)))
    plt.xlabel("Threads")
    plt.ylabel(r"$\beta_{t N} \approx \beta$")
    df_0 = data[data['ifs'] == ifs[i]]
    plt.xticks([i for i in range(2, len(df_0['threads'].unique()) + 1)])
    lst = df_0['v_size'].unique().tolist()
    for val in lst[1:]:
        t = df_0[df_0['v_size'] == val]
        plt.plot(t['threads'].iloc[1:], ((t['time_mean'].iloc[1:] - t['time_mean'].iloc[0]) *
        (t['threads'].iloc[1:] / (1-t['threads'].iloc[1:])))/
        val, '-o', label=f"v_size={val}")
    plt.title(f"IF={ifs[i]}")
    plt.suptitle(fr"Threads x $\beta_{{t N}}$, com $N > {lst[0]}$")
    fig.legend()
```

Note que, apesar da mudança brusca entre 6 e 7 threads, no resto do gráfico, a nossa aproximação para $\beta_{tN}$ é praticamente constante, o que parece confirmar nossa hipótese de que o tempo de execução do programa é linear em $\frac{N}{t}$.
