# Princípios e conceitos básicos

## Noções básicas de arquitetura de computadores

### Arquitetura sequencial

#### Arquitetura de Von Neumann

#### Hierarquia de memória

### Arquiteturas paralelas

#### Taxonomia de Flynn

#### Tipos de acesso a memória

#### Granularidade de paralelismo

#### Topologias

#### Teoria

## A importância do paralelismo

## Dois tipos de paralelismo

### Memória compartilhada

### Passagem de mensagens

## Paradigmas de computação paralela e distribuída

### Paralelismo iterativo

Caso de estudo: multiplicação de matrizes

Considere o seguinte problema: Dadas matrizes $A$ e $B$, ambas matrizes $n \times n$, calcule o resultado da sua multiplicação, e seja $C = A \cdot B$ o resultado dessa multiplicação.
Em um programa sequencial, podemos fazer isso usando o seguinte código (suponha que $A$ = `double a[n, n]`, $B$ = `double b[n, n]`, e $C$ = `double c[n, n]`).

~~~c
for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        c[i, j] = .0;
        for(int k = 0; k < n; k++){
            c[i, j] += a[i, k] * b[k, j];
        }
    }
}
~~~

Esse algoritmo tem uma complexidade de tempo $O(n^{3})$.

Note que, para calcular a $i$-ésima linha de $C$, precisamos apenas da $i$-ésima linha de $A$, e, ao calcular duas linhas diferentes de $C$, estamos realizando operações de escrita independentes.
Então podemos calcular essas linhas de forma concorrente:

~~~c
co[i = 0 to n-1]{
    for(int j = 0; j < n; j++){
        c[i, j] = .0;
        for(int k = 0; k < n; k++){
            c[i, j] += a[i, k] * b[k, j];
        }
    }
}
~~~

O código acima gera $n$ processos independentes, que executam em paralelo, cada um com um valor de $i$ diferente, de $0$ até $n-1$, e espera que todos terminem.

Note que, para calcular os produtos internos entre linhas e colunas das matrizes, também podemos fazer essas operações em paralelo:

~~~c
co[i = 0 to n-1]{
    co[j = 0 to n]{
        c[i, j] = .0;
        for(int k = 0; k < n; k++){
            c[i, j] += a[i, k] * b[k, j];
        }
    }
}
~~~

Assim, o código acima gera $n^{2}$ processos independentes (um para cada combinação possível de $i$ e $j$), onde cada um é responsável por calcular uma posição da matriz resultante. Cada um deles tem complexidade de tempo $O(n)$. Se cada um desses processos puder rodar em um processador diferente, então poderemos computar a multiplicação de duas matrizes $n \times n$ em $O(n)$, porém, para isso, precisaríamos de no mínimo $n^{2}$ processadores diferentes.

### Paralelismo recursivo

Um programa recursivo pode ser implementado usando concorrência quando tem chamadas recursivas independentes. Isso será o caso quando:

1. As chamadas recursivas não escrevem em variáveis globais
2. Diferentes chamadas não escrevem em variáveis compartilhadas (ou referências a variáveis).

Um exemplo no qual podemos implementar paralelismo recursivo é o *problema da quadratura*.
Nesse problema, queremos aproximar a integral de uma função contínua, digamos, $f(x)$, entre $a$ e $b$.
Podemos então calcular um valor aproximado para essa integral com o seguinte código:

~~~c
double fesq = f(a), fdir, area = .0;
double largura = (b-a) / n;
for(double i = a + largura; i <= b; i += largura){
    fdir = f(i);
    area += (fesq + fdir) * largura / 2;
    fesq = fdir;
}
~~~

Nessa abordagem, dividimos o intervalo $[a, b]$ em $n$ sub-intervalos, usamos a regra do trapezóide para calcular a área de cada sub-intervalo, e somamos os valores das áreas para aproximar a área total.
A complexidade desse algoritmo depende de dois fatores: o número de sub-intervalos e a complexidade da função $f(x)$. Podemos então dizer que a complexidade do nosso algoritmo será $O(nf(x))$.

Uma abordagem alternativa seria utilizar divisão e conquista, e um número variável (dinâmico) de sub-intervalos:
Primeiro, calculamos o valor $m$ que corresponde ao meio do intervalo $[a, b]$. Depois, aproximamos o valor da área sob a curva $f(x)$ em três regiões: de $a$ a $m$, de $m$ a $b$, e de $a$ a $b$. Se a diferença entre a soma das duas sub-regiões e a região total for menor do que um certo valor `EPSILON`, então a nossa aproximação é considerada boa o suficiente. Senão, dividimos o problema maior (de $a$ a $b$) em dois subproblemas menores (de $a$ a $m$ e de $m$ a $b$), e repetimos o processo.
Essa abordagem é chamada de *quadratura adaptativa*, e pode ser implementada da seguinte maneira:

~~~c {#quad_adapt .numberLines}
double quad(double esq, dir, fesq, fdir, area, epsilon){
    double meio = (esq + dir) / 2;
    double fmeio = f(meio);
    double esqarea = (fesq + fmeio) * (meio - esq) / 2;
    double dirarea = (fdir + fmeio) * (dir - meio) / 2;
    if(abs(esqarea + dirarea - area) > epsilon){
        esqarea = quad(esq, meio, fesq, fmeio, esqarea, epsilon);
        dirarea = quad(meio, dir, fmeio, fdir, dirarea, epsilon);
    }
    return esqarea + dirarea;
}

double adap_quad(double a, b, epsilon, double (*f)(double)){
    double f_a = f(a);
    double f_b = f(b);
    return quad(a, b, f_a, f_b, (f_a + f_b) * (b - a) / 2, epsilon);
}
~~~

Note que, supondo que a função $f(x)$ não tenha efeitos colaterais, cada chamada de `quad` só escreve em variáveis locais, e, em um mesmo nível na árvore de recursão, nenhuma chamada da função depende de qualquer outra. Então podemos reescrever o código das linhas [$7$](#quad_adapt-7) e [$8$](#quad_adapt-8) da seguinte forma:

~~~c {#quad_adapt .numberLines startFrom="7"}
        co esqarea = quad(esq, meio, fesq, fmeio, esqarea, epsilon);
        \\ dirarea = quad(meio, dir, fmeio, fdir, dirarea, epsilon);
        oc
~~~

No código acima, as duas chamadas de `quad` são executadas de forma paralela, e a função que faz as chamadas aguarda o retorno das duas, por meio da diretiva `co`.

### Sistemas produtor/consumidor

Um processo produz, e outro consome. Podem estar organizados em um pipeline
Produtor -> buffer -> consumidor
Exemplo:

- Pipes do Unix
- Transmissão de mensagens em um caminho

### Clientes e servidores

Padrão dominante em sistemas distribuídos
Cliente: solicita serviços, espera por resposta
Servidor: aguarda e processa pedidos
Exemplo:

- Sistema de arquivos
- Servidores WEB

### Interação entre pares

Descentralização de responsabilidade
