# Valores e tipos
##  Para cada um dos tipos abaixo (definidos em Pascal), mostre qual conjunto de valores eles representam usando a notação de tipos primitivos, produto cartesiano ($X$), união disjunta ($+$), mapeamentos ($\to$), conjuntos potencia ($\mathcal{P}$).

```{pascal}
type Cores = (azul, vermelho, amarelo);
   Tonalidade = 1..10;
   Textura = 1..5;
   PontoColorido = record c: Cores;
      to: Tonalidade;
      tx: Textura
   end;
   LinhaColorida = array [1..30] of PontoColorido;
   NovaCor = set of Cores;
   Noptr = ˆNoListras;
   NoListras = record c: LinhaColorida;
      next: Noptr
end;
```
 - $Cores = \text{primitivo (enumeracao)}$
 - $Tonalidade, textura = \text{primitivo (subconj. Inteiros)}$
 - $PontoColorido = Cores \times Tonalidade \times Textura$
 - $LinhaColorida = Integer \mapsto PontoColorido$
 - $NovaCor = \mathcal{P}(Cores)$
 - $NoPtr = \text{primitivo (apontador para Cores)}$
 - $NoListras = \{\} \cup LinhaColorida \times NoListras \\ \text{(tipo recursivo)}$

##
### C
a) \
   - $int$\
      Números inteiros de −32,767 a +32,76\
   - $char$\
      Caracteres (geralmente codificados a partir de inteiros na faixa [0, 255]).
   - $float$\
      Números de ponto flutuante
   - Apontadores para os tipos predefinidos e definidos pelo programador

b) \
   - Mapeamentos: *arrays* cujo índice são números inteiros
   - Produto cartesiano: *structs*, tipos estruturados em que cada subelemento de uma variável é acessado pelo seu nome.
   - União disjunta: *union*, união disjunta livre (isto é, sem elemento discriminante)
  
   Os elementos que existem (ou podem ser criados) na linguagem não cobrem o tipo conjunto potencia.

c) Sim. É possível construir ainda: tipos enumerados (*enum*) e tipos recursivos, usando *structs* e apontadores. Além disso, pode-se dar nomes a tipos compostos definidos pelo programador, como *structs* e *unions*.

##
a) Produto cartesiano $T \times S$.
b) Mapeamento $T \mapsto T ^ \prime$
c) Tipo recursivo $list = \{\} \cup \{T \times list\}$
d) Mapeamento $Palavra-chave \mapsto resultados$

# Variáveis
##

##
a) O conjunto de valores é o mesmo. Cada item da lista armazena um número inteiro.
b) A forma de se acessar um determinado elemento da lista é parecido, mas não é igual. Em `ll`, para se acessar o primeiro item da lista, usamos o operador (ou função) `head`, e para se acessar o n-ésimo elemento da lista, precisamos acessar todos os elementos anteriores, de maneira sequencial (isto é, `head(tail(ll))` acessa o segundo elemento da lista, `head(tail(tail(ll)))` acessa o terceiro, e assim por diante). Para se acessar o n-ésimo elemento de `lp`, também devemos acessar todos os elementos anteriores, de maneira sequencial (`lp.elem` acessa o primeiro elemento, `lp.prox.elem` acessa o segundo elemento, `lp.prox.prox.elem` acessa o terceiro elemento, e por assim em diante).
c) O mecanismo de atribuição funciona de maneira idêntica nos dois tipos apresentados.

##
Quanto ao armazenamento e acesso aos valores, a variável `ll` pode ser considerada simples, pois usamos o seu valor como um todo por meio das operações definidas (`head`, `tail`, concatenação, etc), e não podemos acessar seus sub-elementos de maneira explícita. Já a variável `lp` é considerada composta, pois pode se dizer que seu tipo é um produto cartesiano $Integer \times IntList$, e podemos acessar seus sub-elementos explicitamente (`lp.elem` e `lp.prox`).\
Quanto à existência, a variável `ll` pode ser classificada como uma variável local ao bloco de comando em que é declarada, como global para sub-blocos. Já a variável `lp` pode ser considerada uma variável intermitente, ou de *heap*, pois para usá-la precisamos explicitamente reservar um espaço na memória (por meio do comando `New(lp)`).

# Vinculações e verificação de tipos

##
 - C: A vinculação de tipos em C é realizada estaticamente, pois todas as variáveis precisam ser declaradas explicitamente com seu tipo. A vinculação de armazenamento também é feita de maneira estática, uma vez que está definido o tipo da variável.
 - Python: A vinculação de tipos é feita de maneira dinâmica, em tempo de execução, pois uma variável pode ter tipos diferentes durante a execução do programa. Por esse mesmo motivo, a vinculação de armazenamento também é dinâmica.

##
Variáveis intermitentes, ou do tipo *heap* são criadas por meio de comandos explícitos de alocação de memória. Em algumas linguagens, como C, pode-se criar apontadores para espaços de memória que contenham valores de um tipo predefinido, quanto valores de qualquer tipo, caso em que acontece uma vinculação de tipo dinâmica (mais ou menos, já que nesse caso, o tipo associado à variável é o tipo *void*). Vale notar que, para se alocar memória para uma variável, precisamos saber o tipo dela, para saber a quantidade de memória necessária para armazenar os valores que queremos que ela represente.

##

##

##
a) Exemplo: `3 / 2`. Nesse exemplo, os dois operandos são inteiros, mas o resultado pode ser tanto o valor inteiro `1` quanto o valor de ponto flutuante `1.5`. Se a sobrecarga desse operador for independente de contexto, não há como afirmar qual resultado seria o esperado. Já se a sobrecarga for dependente de contexto, o valor calculado depende de qual é o tipo da expressão onde ela é esperada (exemplo: `int x = 3 / 2` - `x = 1` ou `double x = 3 / 2` - `x = 1.5`).
b) Como procedimentos não retornam valores, não podemos considerar uma sobrecarga deles dependente de contexto.

##
a) As sobrecargas podem ser realizadas, mas precisam ser dependentes de contexto. Por exemplo, em uma simples atribuição de valor a uma variável `x = 10`, precisamos saber o tipo de `x` para poder atribuir o valor correto à variável. Além disso, caso tenhamos um comando `y = 3 / 2`, precisamos saber o tipo da variável `y` para podermos realizar a atribuição com o valor correto, então precisamos que a sobrecarga da operação de divisão também seja dependente de contexto.
b) Ver a)

##
A principal diferença entre polimorfismo e sobrecarga (em funções), é que o polimorfismo é aplicado quando usamos a sobrecarga definida sobre uma família de tipos, para aplicar uma abstração de maneira uniforme, e a sobrecarga acontece quando usamos um mesmo identificador para operações diferentes

# Abstrações

## 