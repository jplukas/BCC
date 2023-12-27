# Álgebra Relacional

As operações aqui vistas têm como domínio relações (subconjuntos do produto cartesiano) entre elementos de diferentes conjuntos, e produzem novas relações. Podemos pensar em relações também como tuplas.

## Operações unárias

Operações unárias da álgebra relacional operam sobre uma única relação, e são aplicadas sobre cada tupla individualmente.

### SELECT

Usamos a operação SELECT para escolher um subconjunto de tuplas de uma determinada relação que satisfaçam alguma condição booleana. Podemos considerar a operação SELECT como um filtro.

Em geral, a operação SELECT é denotada por:
$$
\begin{aligned}
\sigma_{\text{<condicao>}}(R)
\end{aligned}
$$
Onde $\sigma$ denota a operação SELECT, e $\text{<condicao>}$ é uma expressão booleana sobre os atributos de $R$.  
A expressão especificada em $\text{<condicao>}$ é formada por um número de cláusulas da forma
$$
\begin{aligned}
\text{<nome do atributo> <operação de comparação> <valor constante>} 
\end{aligned}
$$
ou
$$
\begin{aligned}
\text{<nome do atributo 1> <operação de comparação> <nome do atributo 2>}
\end{aligned}
$$
Onde $\text{<nome do atributo>}$ é algum atributo de $R$, $\text{<operação de comparação>}$ é normalmente algum dos operadores $\{<, >, \leq, \geq, =, \neq\}$, e $\text{<valor constante>}$ é um valor constante que pertença ao domínio do atributo.  
Cláusulas podem ser conectadas por meio de operadores booleanos como $\bf{OU}$, $\bf{E}$ e $\bf{NÃO}$.

Exemplo: Selecionar todos os empregados que trabalham no departamento 4 e ganham mais de 25000 por ano, ou que trabalham no departamento 5 e ganham mais de 30000 por ano:  
$$
\begin{aligned}
\sigma_{
(\text{Dno} = 4 \bf{ E } \text{Salário} > 25000)
\bf{ OU }
(\text{Dno} = 5 \bf{ E } \text{Salário} > 30000)
}(\text{EMPREGADOS})
\end{aligned}
$$

Note que, como SELECT é uma operação unária, a sua condição de seleção não pode envolver mais de uma tupla.  
O grau da relação resultante dessa operação é o mesmo da relação original.  
A cardinalidade da relação resultante é sempre menor ou igual do que a da relação original, isto é:
$$
\begin{aligned}
|\sigma_{c}(R)| \leq |R|
\end{aligned}
$$

### PROJECT

Podemos pensar na operação PROJECT como uma restrição dos atributos de uma relação $R$.  
Se pensarmos em $R$ como uma tabela, onde cada linha é uma tupla, então a operação SELECT seleciona linhas de $R$, enquanto a operação PROJECT "seleciona" colunas dessa tabela.

A operação PROJECT é denotada por
$$
\begin{aligned}
\pi_{\text{<lista de atributos>}}(R)
\end{aligned}
$$
Onde $\text{<lista de atributos>}$ é uma lista de atributos das tuplas de $R$.

Note que, caso sejam selecionados somente atributos que não sejam únicos em $R$, a relação resultante poderia ter tuplas repetidas. A operação PROJECT não permite isso, e remove todas as duplicações de tuplas do resultado.

Exemplo: Selecionar o primeiro nome e o salário dos empregados que ganhem mais do que 50000 por ano:
$$
\begin{aligned}
\pi_{\text{PNome, Salário}}(\sigma_{\text{Salário > 50000}}(\text{EMPREGADOS}))
\end{aligned}
$$

Note que a operação PROJECT não é comutativa, e que o grau da relação resultante é sempre menor ou igual ao de $R$. Mais ainda, o grau da relação resultante será o número de atributos em $\text{<lista de atributos>}$.

### RENAME

## Operações binárias

Temos também operações clássicas da teoria de conjuntos: união, intersecção e diferença de conjuntos, que têm significados análogos.  
Porém, uma observação faz-se necessária: Para essas operações, os seus operandos devem ser compatíveis. Isso significa que uma operação $R \cup S$ só faz sentido se os graus de $R$ e $S$ forem iguais e se os domínios dos conjuntos sobre os quais $R$ e $S$ estão definidos forem iguais (isto é, se os domínios dos atributos de $R$ e $S$ forem iguais).

### Produto cartesiano


## Operações de Agregação

# Cálculo Relacional de Tuplas

# Formas normais e normalização

# Transações

# Escalonamento

# Decomposição

# Seriabilidade

# SQL

# Controle de concorrência

# Recuperação de Falhas

