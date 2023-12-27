# Programação com variáveis compartilhadas

Programas sequenciais frequentemente empregam o uso de variáveis compartilhadas como um meio de conveniência, mas podem ser escritos sem elas. De fato, muitos argumentam que *deveriam* ser escritos sem elas.
Programas concorrentes, por outro lado, dependem do uso de componentes compartilhadas. Isso porque a única maneira na qual diferentes processos podem trabalhar em conjunto para resolver um problema ou realizar uma tarefa é comunicando, e a única forma na qual processos podem se comunicar é se um processo escrever em *algo* que outro processo leia. Este algo pode ser uma variável compartilhada ou um canal de comunicação. Então, comunicação entre processos é feita por meio de variáveis compartilhadas ou por troca de mensagens.

## Processos e sincronização

### Estados, Ações, Históricos e Propriedades

[Estado de um programa]{#def:estado_de_um_programa}
: O ***estado*** de um programa concorrente consiste no conjunto de valores de suas variáveis em algum ponto no tempo. Essas variáveis incluem tanto aquelas que foram explicitamente declaradas quanto variáveis implícitas, como o *program counter* para cada processo. Cada processo no programa executa de maneira independente, alterando o estado do programa.

Um processo executa uma sequência de declarações. Uma declaração, por sua vez, é implementada por uma sequência de uma ou mais ***ações atômicas***, que são ações que indivisivelmente examinam ou alteram o estado do programa.

[Histórico de um programa]{#def:historico_de_um_programa}
: Uma execução particular de um programa pode ser vista como uma sequência de estados, a qual damos o nome de ***histórico***: $s_{0} \to s_{1} \to \ldots \to s_{n}$. Em um histórico, $s_{0}$ é o estado inicial do programa, e os outros estados $s_{i}$ são estados subsequentes. Qualquer transição de um estado para outro do programa é causada por um ação atômica.

O papel da sincronização é restringir o número de possíveis históricos de um programa concorrente para aqueles que são desejáveis. ***Exclusão mútua*** está relacionada com combinar ações atômicas implementadas diretamente por hardware em sequências de ações chamadas ***seções críticas*** que aparentam ser atômicas, isto é, não podem ser entrelaçadas com ações em outros processos que referenciam as mesmas variáveis.
Sincronização de condições está relacionada com atrasar uma ação até que o estado satisfaça uma condição booleana.
Ambas as formas de sincronização podem causar atraso em processos, e então elas restringem o conjunto de ações atômicas que podem ser executadas em seguida.
