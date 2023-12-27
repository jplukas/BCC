---
title: |
       | MAC 0219 - Introdução à computação paralela e distribuída
       | Exercício Programa 1

author: |
        | Joao Pedro Lukasavicus Silva
        | <joao.lukasavicus.silva@usp.br>
        | 9276940
codebraid:
    jupyter: true
...

# Introdução

Nesse exercício programa, vamos usar um *Lattice Gas Automata* para simular o comportamento de um fluído.  
O modelo que iremos adotar consiste em um grid hexagonal, onde cada célula pode conter até seis particulas de gás, movendo-se em seis direções diferentes (no máximo uma partícula por direção), ou pode consistir de uma barreira física.

Dado um estado qualquer do sistema, o próximo estado é calculado para cada uma das células (em qualquer ordem), e o próximo estado do sistema como um todo é simplesmente composto pelos estados individuais de cada uma das células.  
O estado seguinte de cada celula é calculado em duas etapas: uma etapa de propagação e uma etapa onde são checadas colisões entre partículas.

- **Propagação:**
Primeiro, para cada direção possível, verificamos se há uma partícula vindo daquela direção em uma célula adjacente. Se houver, atualizamos a célula corrente com a partícula vindo da célula adjacente.  
Também verificamos se há alguma partícula vindo de uma colisão com uma barreira física.

- **Colisão:**
Na etapa de resolução de colisões, para cada situação possível de colisão, populamos a célula alvo com o código que corresponde a situação seguinte após a colisão, isto é, a direção das partículas, de acordo com as regras estabelecidas no enunciado.

Aqui está um exemplo de uma colisão entre duas partículas com direções opostas:  
![1](./000.png){ width=25% }
![2](./001.png){ width=25% }
![3](./002.png){ width=25% }
![4](./003.png){ width=25% }

## Código da atualização

De `lga_seq.c`:
```c {.cb-code include_file="./lga_seq.c" include_lines=9-45 .numberLines startFrom="9"}
```

## Código da checagem de colisões

De `lga_base.c`
```c {.cb-code include_file="./lga_base.c" include_lines=152-179 .numberLines startFrom="152"}
```

# Paralelização

Este é o código responsável por atualizar a grade a cada iteração (na versão sequencial):  
```c {.cb-code include_file="./lga_seq.c" include_lines=62-81 .numberLines startFrom="62"}
```
Note que a cada iteração do laço são feitas duas atualizações da grade:

- Linha 74:  
  ```c {.cb-code include_file="./lga_seq.c" include_lines=74 .numberLines startFrom="74"}
  ```

- Linha 79:  
  ```c {.cb-code include_file="./lga_seq.c" include_lines=79 .numberLines startFrom="79"}
  ```

De modo que, a cada iteração do laço, a variável `grid_1` é atualizada com o valor do grid depois de 2 atualizações.  
Essas duas chamadas de funções variam somente na ordem de seus parâmetros efetivos: na primeira, a variável `grid_1` é usada como valor para o parâmetro `grid_in`, e a variável `grid_2` é usada como valor para o parâmetro `grid_out`, e vice-versa na segunda chamada.  

A seguir está o código da função `update`:  
```c {.cb-code include_file="./lga_seq.c" include_lines=49-58 .numberLines startFrom="49"}
```
Note que somente são feitas operações de leitura sobre a variável apontada por `*grid_in`, e somente operações de escrita na variável apontada por `*grid_out`. Portanto, poderíamos facilmente paralelizar essa função.

## Paralelização com OpenMP

A OpenMP é uma API que contém diretivas de compilação, bibliotecas de tempo de execução e variáveis de ambientes para auxiliar a escrita de programas paralelos utilizando memória compartilhada.  

A OpenMP é desenhada para máquinas multi-core, com memória compartilhada.  
O modelo de execução é baseado em threads. Cada thread é uma sub-unidade do programa principal que compartilha memória e código e pode ser executada de forma autônoma.

As diretivas da OpenMP têm a forma de comentários no código fonte, e são ignoradas pelo compilador, a não ser quando explicitamente especificado, como por exemplo, usando uma *flag* de compilação.

Cada diretiva do OpenMP tem o seguinte formato (em C/C++):  
`#pragma omp <nome da diretiva> [cláusulas]`  
Onde cada diretiva tem a sua lista de cláusulas validas, que definem aspectos do seu comportamento.

Implementar uma versão paralelizada da função utilizando as diretivas do OpenMP é simples. Aqui está a versão paralelizada de `update`:  
```c {.cb-code include_file="./lga_omp.c" include_lines=31-48 .numberLines startFrom="31"}
```

Nessa versão paralelizada da função `update`, a assinatura da função foi mudada para incluir o parâmetro `n_threads`. Esse parâmetro é importante para fazer a divisão do trabalho entre as threads.  
Além disso, o acesso de cada posição das matrizes `grid_in` e `grid_out` é feito com apenas um índice, a saber, `i`, diferentemente da versão sequencial, que usa índices `i` e `j`. Isso foi feito para que se pudesse usar apenas um laço para iterar sobre todos os elementos das matrizes.  
Assim, o laço `for` das linhas 39-48 itera sobre todos os `grid_size * grid_size` elementos do grid, obtendo o estado de cada célula de `grid_in`, calculando o próximo estado e gravando o resultado na posição correspondente em `grid_out`.

A diretiva `parallel for` (linha 35) do OMP combina duas diretivas, `parallel` e `for`. A seguir explicamos com mais detalhes cada uma:

**Diretiva** `parallel`: É a diretiva de construção fundamental da OpenMP. Essa diretiva delimita um bloco de código que será executado por múltiplas threads. No nosso exemplo, essa diretiva especifica que o laço das linhas 39-48 deve ser executado por múltiplas threads.  
No exemplo usamos três cláusulas dessa diretiva.  
A primeira, `shared`, especifica quais são as variáveis que devem ser compartilhadas entre as threads. No código, as variáveis compartilhadas são `grid_in`, `grid_out`, `grid_size` e `n_threads`. A única variável dentre essas cujo valor é modificado é `grid_out`. Como veremos a seguir, por conta da diretiva `for`, não há duas threads que acessem simultaneamente uma mesma posição desse vetor, de modo que não é possivel que haja conflitos de leitura/escrita entre diferentes threads.  
A segunda, `private`, especifica quais variáveis devem ser próprias de cada thread. O que efetivamente acontece é que cada thread tem a sua própria cópia da variável, e faz as suas operacoes em cima dessa cópia. No nosso exemplo, a variável `i` é a única variável não compartilhada.  
A terceira, `num_threads` controla o número de threads a serem criadas para executarem o código na região definida. No nosso caso, usamos um argumento vindo da linha de comando.

**Diretiva** `for`: Especifica que as iterações do loop definido em seguida devem ser executadas em paralelo, assumindo que o código está em uma região paralela (por exemplo, definida pela diretiva `parallel`).  
No exemplo somente utilizamos a cláusula `schedule` dessa diretiva. Essa cláusula define como as iterações do loop são divididas entre as threads.
A opção selecionada `STATIC` (sem o parâmetro `chunk`) define que as iterações são divididas (quase) igualmente de acordo com o número de threads e atribuídas estaticamente para cada thread.  
Assim, suponha que o programa `time_test` seja invocado com os parâmetros `--grid-size 8` e `--n-threads 2`. Então serão criadas duas threads, $t_{1}$ e $t_{2}$, de modo que:

- $t_{1}$:  

  ```c {.numberLines startFrom="39"}
  for (i = 0; i < 32; i++) {
    if (grid_in[i] == WALL)
      grid_out[i] = WALL;
    else
      grid_out[i] = get_next_cell(
          i / grid_size,
          i % grid_size,
          grid_in, grid_size);
  }
  ```

- $t_{2}$:  

  ```c {.numberLines startFrom="39"}
  for (i = 32; i < 64; i++) {
    if (grid_in[i] == WALL)
      grid_out[i] = WALL;
    else
      grid_out[i] = get_next_cell(
          i / grid_size,
          i % grid_size,
          grid_in, grid_size);
  }
  ```

## Paralelizacao com Pthreads

Assim como a OpenMP, a PThreads (POSIX Threads) também é uma API que é usada para facilitar o desenvolvimento de programas paralelos, usando threads. Porém, diferentemente da OpenMP, a PThreads é implementada apenas como uma biblioteca C, sem o uso de diretivas de compilador. Então, para gerenciar as threads, usamos tipos, funções e variáveis de ambiente definidas na biblioteca.

Para criar uma (nova) thread, usamos a função `pthread_create`. Essa função recebe 4 argumentos:

1. `thread`: um ponteiro opaco para um identificador do tipo `pthread_t`, que serve de identificador único para a thread a ser criada;
2. `attr`: um ponteiro opaco para um objeto do tipo `pthread_attr_t`, que contém atributos da thread. Pode ser `NULL`, que faz com que a thread seja criada com os atributos padrão;
3. `start_routine`: uma subrotina C do tipo `void`, que será executada pela thread. Essa subrotina aceita ao máximo um argumento, que deve ser um ponteiro do tipo `void`;
4. `arg`: um ponteiro do tipo `void`, que é passado como argumento para a subrotina a ser executada pela thread.

O retorno dessa função é um inteiro, que sinaliza se a thread foi criada com sucesso.

Assim que uma thread é criada, ela está apta a executar de forma autônoma, até ser bloqueada, ou terminar.  
A função `pthread_join` é uma das funcoes usadas para obter sincronizacao entre threads. Essa funcao recebe 2 argumentos:

1. `thread`: um ponteiro, do tipo `pthread_t` para a thread alvo (que eh setado na chamada da funcao `pthread_create`);
2. `value_ptr`: um ponteiro do tipo `void*`, que aponta para o valor de retorno da thread alvo, se houver algum.

Ao invocar a funcao `pthread_join` para alguma thread alvo, a thread que faz essa chamada eh bloqueada ate que a thread alvo termine, caso a thread alvo esteja em execucao. Caso a thread ja tenha terminado, a funcao nao faz nada (?).

Para paralelizar nosso programa usando PThreads, foram feitas modificações em duas funções: `update` e `simulate_pth` (em relação a `simulate_seq`).

Aqui está o código da função `update`:

```c {.cb-code include_file="./lga_pth.c" include_lines=38-48 .numberLines startFrom="38"}
```

Esta é a função que é passada para ser executada por cada thread, como veremos a seguir. Então, como vimos, essa função só recebe um único argumento, `args`, que é um ponteiro para uma estrutura que serve para abrigar os parâmetros que queremos passar para essa função. Aqui está a definição dessa estrutura:

```c {.cb-code include_file="./lga_pth.c" include_lines=5-11 .numberLines startFrom="5"}
```

Basicamente é outra maneira de se passar os parâmetros `start`, `end`, `grid_in`, `grid_out` e `grid_size`.

A função então percorre a matriz `grid_in`, célula por célula, calcula o próximo estado de cada célula e grava o resultado na posição correspondente em `grid_out`, começando pela posição definida pelo parâmetro `start` e terminando uma posição antes da posição `end`.

Agora, vamos analisar a função `simulate_pth`:

```c {.cb-code include_file="./lga_pth.c" include_lines=50-97 .numberLines startFrom="50"}
```

Para cada iteração do programa, a primeira coisa que fazemos é preparar as estruturas necessárias para disparar as threads.  
Primeiro calculamos a quantidade de trabalho que cada thread deve executar, isto é, a quantidade de células cujo estado cada thread será responsável por atualizar, na linha 58. Desse modo podemos dizer a cada thread sobre qual porção do grid ela deve realizar seu trabalho.  
Depois, caso não haja como dividir igualmente o trabalho entre as threads, calculamos quantas threads terão que realizar um trabalho extra (atualizar o estado de mais uma célula), na linha 59.  
Então, criamos dois vetores para acomodar os ponteiros para as estruturas que guardarão os argumentos da função a ser executada por cada thread, e os ponteiros para os identificadores de cada thread, nas linhas 60 e 61, respectivamente.  
Então, para cada thread, armazenamos os valores corretos para os argumentos da função `update` e disparamos a thread.  
Por fim, precisamos esperar que cada thread faça o seu trabalho, o que acontece na linha 76: a thread principal é bloqueada até que todas as demais threads terminem de executar. Todo esse processo conclui uma atualização de estado do grid, o que basicamente é equivalente à linha 74 da função `simulate_seq` em `lga_seq.c`:  
```c {.cb-code include_file="./lga_seq.c" include_lines=74 .numberLines startFrom="74"}
```

Assim, nas linhas 83-90 da função `simulate_pth` em `lga_pth.c`, fazemos o trabalho referente à segunda atualização da grade:  
```c {.cb-code include_file="./lga_pth.c" include_lines=83-90 .numberLines startFrom="83"}
```  
que é equivalente a  
```c {.cb-code include_file="./lga_seq.c" include_lines=79 .numberLines startFrom="79"}
```
na função `simulate_seq` em `lga_seq.c`.

# Testes

Agora, vamos analisar os tempos de execução do programa `time_test` nas versões sequencial, paralelizada com OpenMP e paralelizada com Pthreads. Para isso, vamos executar o programa várias vezes, variando o conjunto de argumentos, para utilizar as diferentes versões do programa.

Para cada versão, queremos analizar o comportamento do tempo de execução do algoritmo variando o tamanho da entrada e o número de threads (no caso das versões paralelizadas). Fazemos isso invocando o programa usando diferentes argumentos de linha de comando.  
O que especifica a versão a ser usada pelo programa é o primeiro argumento, `impl`. Esse argumento pode receber os valores `seq`, para executar a versão sequencial, `omp`, para a versão usando OpenMP, ou `pth`, para a versão usando PThreads.  
O tamanho da entrada é controlado pelo argumento `grid_size`. Vamos fornecer ao programa entradas que dobrarão de tamanho a cada iteração.  
Por último, o argumento `num_threads` especifica a quantidade de threads a serem usadas pelo programa, no caso de invocação de uma versão paralelizada.  
Além de variar os argumentos, para cada tupla de argumentos usados na invocação do programa, repetimos os mesmos argumentos 30 vezes, para se obter uma boa média dos tempos de execução. Usamos esses valores para calcular uma média, bem como um intervalo de confiança para o tempo de execução do programa, para cada tupla de argumentos.

Os testes foram realizados usando um script bash, que salva os resultados no arquivo `testes.csv`:

```bash {.numberLines}
INFILES=`ls *.in`;
@echo "impl,num_threads,i,grid_size,time" > testes.csv;

for impl in omp pth; do \
  nthreads=1;
  for j in `seq 1 6`; do \
    for i in `seq 1 30`; do \
      for arq in $INFILES; do \
        echo -n $impl,$nthreads,$i,${arq%.in}, >> testes.csv;
        ./time_test --grid_size ${arq%.in} --impl $impl \
        --num_threads $nthreads >> testes.csv; 
      done;
    done;
    nthreads=`expr $nthreads \* 2`;
  done;
done;

for i in `seq 1 30`; do \
  for arq in $INFILES; do \
    echo -n seq,1,$i,${arq%.in}, >> testes.csv;
    ./time_test --grid_size ${arq%.in} --impl seq >> testes.csv; 
  done;
done;
```

## Resultados

Feitos os testes, vamos analisar os resultados usando Python.

Primeiramente, fazemos o carregamento de alguns pacotes, e algumas configurações iniciais:

```python {.cb-nb show=code}
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as st
from IPython import display
import warnings
warnings.filterwarnings('ignore')
import csv
```

Agora, vamos calcular as médias e intervalos de confiança. Aqui estamos usando um índice de confiança de 99%.

```python {.cb-nb}
data = pd.read_csv("testes.csv");
def transf(x):
    lo, up = st.t.interval(
      confidence=0.99,
      df=29,
      loc=x.time.mean(),
      scale=st.sem(x.time)
    )
    t_mean = x.time.mean()
    s = pd.Series({
        'time_lo' : lo,
        'time_up' : up,
        'time_mean' : t_mean
    })

    return s

df = data.groupby(['impl', 'num_threads', 'grid_size'], as_index=False).apply(transf);
display.display(df.head());
```

Vamos analisar a relação entre o tempo de execução do programa e o tamanho da entrada, para as diferentes implementações, com números diferentes de threads.

Primeiramente, a versão sequencial:

```python {.cb-nb}
df_impl = df[df.impl == 'seq'];
plt.figure();
plt.suptitle("Tempo de execucao x tamanho da entrada");
plt.title("Versao sequencial");
plt.xlabel('grid_size');
plt.ylabel('Tempo de execucao (segundos)');
# plt.yscale('log', base=2);
# plt.xscale('log', base=2);
plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,8)));
for n_threads in df_impl.num_threads.unique().tolist():
  df_impl_threads = df_impl[df_impl.num_threads == n_threads];
  plt.plot(df_impl_threads['grid_size'],
  df_impl_threads['time_mean'],
  marker='o');
  plt.fill_between(df_impl_threads['grid_size'],
  df_impl_threads['time_lo'],
  df_impl_threads['time_up']);
```

Agora, as versões OpenMP e Pthreads:  
(Os códigos são muito parecidos com o anterior, por isso foram omitidos)

```python {.cb-nb show=rich_output}
df_impl = df[df.impl == 'omp'];
plt.figure();
plt.suptitle("Tempo de execucao x tamanho da entrada");
plt.title("Versao OpenMP");
plt.xlabel('grid_size');
plt.ylabel('Tempo de execucao (segundos)');
# plt.yscale('log', base=2);
# plt.xscale('log', base=2);
plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,8)));
for n_threads in df_impl.num_threads.unique().tolist():
  df_impl_threads = df_impl[df_impl.num_threads == n_threads];
  plt.plot(df_impl_threads['grid_size'],
  df_impl_threads['time_mean'],
  label=f"{n_threads} threads");
  plt.fill_between(df_impl_threads['grid_size'],
  df_impl_threads['time_lo'],
  df_impl_threads['time_up']);
plt.legend();
```

```python {.cb-nb show=rich_output}
df_impl = df[df.impl == 'pth'];
plt.figure();
plt.suptitle("Tempo de execucao x tamanho da entrada");
plt.title("Versao Pthreads");
plt.xlabel('grid_size');
plt.ylabel('Tempo de execucao (segundos)');
# plt.yscale('log', base=2);
# plt.xscale('log', base=2);
plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,8)));
for n_threads in df_impl.num_threads.unique().tolist():
  df_impl_threads = df_impl[df_impl.num_threads == n_threads];
  plt.plot(df_impl_threads['grid_size'],
  df_impl_threads['time_mean'],
  label=f"{n_threads} threads");
  plt.fill_between(df_impl_threads['grid_size'],
  df_impl_threads['time_lo'],
  df_impl_threads['time_up']);
plt.legend();
```

## Considerações

Note que, como esperado, o tempo de execução do algoritmo na versão sequencial parece ser quadrático no tamanho da entrada, se considerarmos o tamanho da entrada como o argumento `grid_size`. Poderíamos também argumentar que a medida correta do tamanho da entrada seria `grid_size`$^2$, pois o algoritmo lida com matrizes de tamanho `grid_size` x `grid_size`. Para fins de simplicidade, vamos considerar a medida do tamanho da entrada simplesmente como `grid_size`.

Nas versões paralelizadas, o tempo de execução também parece ser quadrático no tamanho da entrada, mas inversamente linear na quantidade de threads, o que faz sentido, uma vez que dividimos a matriz que representa a grade de células igualmente entre todas as threads, que executam ao mesmo tempo.

Agora vamos investigar o comportamento das versões paralelizadas do programa para entradas relativamente "pequenas":

```python {.cb-nb show=rich_output}
df_impl = df[(df.impl == 'omp') & (df.grid_size <= 256)];
plt.figure();
plt.suptitle("Tempo de execucao x tamanho da entrada (valores pequenos)");
plt.title("Versao OpenMP");
plt.xlabel('grid_size');
plt.ylabel('Tempo de execucao (segundos)');
# plt.yscale('log', base=2);
# plt.xscale('log', base=2);
plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,8)));
for n_threads in df_impl.num_threads.unique().tolist():
  df_impl_threads = df_impl[df_impl.num_threads == n_threads];
  plt.plot(df_impl_threads['grid_size'],
  df_impl_threads['time_mean'],
  label=f"{n_threads} threads");
  plt.fill_between(df_impl_threads['grid_size'],
  df_impl_threads['time_lo'],
  df_impl_threads['time_up']);
plt.legend();
```

```python {.cb-nb show=rich_output}
df_impl = df[(df.impl == 'pth') & (df.grid_size <= 256)];
plt.figure();
plt.suptitle("Tempo de execucao x tamanho da entrada (valores pequenos)");
plt.title("Versao Pthreads");
plt.xlabel('grid_size');
plt.ylabel('Tempo de execucao (segundos)');
# plt.yscale('log', base=2);
# plt.xscale('log', base=2);
plt.gca().set_prop_cycle('color',plt.cm.Spectral(np.linspace(0,1,8)));
for n_threads in df_impl.num_threads.unique().tolist():
  df_impl_threads = df_impl[df_impl.num_threads == n_threads];
  plt.plot(df_impl_threads['grid_size'],
  df_impl_threads['time_mean'],
  label=f"{n_threads} threads");
  plt.fill_between(df_impl_threads['grid_size'],
  df_impl_threads['time_lo'],
  df_impl_threads['time_up']);
plt.legend();
```

É possível ver que, nas versões paralelizadas, quando se usa várias threads, há um intervalo (em relação ao tamanho da entrada) no qual o tempo de execução das versões paralelizadas (para alguns valores de `num_threads`) é praticamente constante, e maior do que o tempo de execução da versão sequencial. Além disso, execuções com um número maior de threads utilizadas tendem a demorar mais do que execuções com um número menor de threads nesse intervalo, e o tamanho desse intervalo (isto é, o tamanho máximo da entrada para o qual esse fenômeno é observado) tende a aumentar juntamente com o número de threads utilizadas.  
Uma hipótese plausível para esse fenômeno é que o overhead de se criar e gerenciar múltiplas threads domina o tempo de execução para tamanhos relativamente "pequenos" da entrada.