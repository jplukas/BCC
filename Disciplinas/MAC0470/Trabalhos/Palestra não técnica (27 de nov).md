---
title: Palestra não técnica (27 de nov)
created: 2023-11-25T17:55:08
modified: 2023-11-26T15:38:48
---

## Uma visão crítica sobre o software livre: suas limitações e seus pontos negativos

### SEGURANÇA

#### Código disponível publicamente

Qualquer um pode ler o código de um software livre e encontrar uma falha, é verdade. Mas qual é a garantia de que, ao abrir o seu código, a pessoa que encontrar um erro necessariamente corrigirá ou relatará a falha que encontrou?

O código aberto promove um maior conhecimento sobre o seu software ao usuário, mas esse conhecimento pode ser usado maliciosamente CONTRA o seu software. 

Há o argumento de que se o código é aberto, há mais pessoas olhando o código e portanto os erros poderiam ser encontrados mais rapidamente. Mais cérebros analisando em paralelo. Porém, existe o ponto também de que a falta de acesso ao código-fonte é por si só uma camada extra de segurança, pois dificulta o encontro direto das vulnerabilidades do código.

Ninguém vai encontrar um erro no código se ele não encontrar o código.

#### Contraponto

Ora, mas e se o dententor do código fechado for mal intencionado e desejar inserir um backdoor no software dele?

(explicar o que é backdoor)

(exemplo de casos reais que aconteceram)

(mas isso não é impossível no linux)

#### Quem vai contribuir?

Além disso, a partir do momento em que você abre o código para a comunidade, pessoas desconhecidas vão começar a participar do processo de desenvolvimento.

Por mais que você tenha permissões privilegiadas, conforme a comunidade aumenta se torna impossível manter um controle rigoroso do que é ou não aprovado.

Você não conhece todas as pessoas que estão contribuindo. Não conhece o nível técnico de quem contribui e de quem revisa. Como você sabe que todo aquele mar de contribuições não vai introduzir uma falha grave no seu software?

E como garantir que não são mal intencionados?

Afinal, software livre não costuma passar por rigorosas análises de segurança como é feito com software proprietário.

#### Exemplo de traquinagem

Um exemplo de inserção de código malicioso é este que ocorreu em 2021.

Dizem que é possível inserir backdoor em código proprietário, mas isso não significa que é impossível existir backdoor em código aberto.

Pesquisadores da Universidade de Minnesota foram pegos submetendo patches que introduziam deliberadamente vulnerabilidades de segurança na base de código oficial do Linux, como parte de suas atividades de pesquisa. 

Isso levou à proibição da Universidade de Minnesota de contribuir para o projeto de kernel do Linux de código aberto.

Em nome da "pesquisa" o sujeito introduziu uma falha proposital no software livre mais importante do mundo e ninguém percebeu. Depois eles tiveram que reverter todos os commits da universidade em massa, até mesmo os que não eram maliciosos e corrigiam de fato problemas de segurança.

Uma falha de segurança para a qual todo software livre está disponível pela própria natureza de abertura para que qualquer um leia e escreva no código.

#### Uso militar

Todo software tem problemas de segurança, seja aberto ou fechado. Porém, esta natureza aberta do software livre levanta alguns questionamentos quando ele é usado em ambiente militar.

"Os exércitos utilizam FOSS, e este tipo de software tem um papel crítico em vários aspectos da operação militar.

Mas existem preocupações sobre manipulação hostil no código aberto, pois, devido à sua natureza aberta, qualquer um pode escrever, ler e utilizar o código.

“Está exposto a manipulação hostil de maneiras que nós ainda mal compreendemos”."

Um exemplo concreto disto é o caso anterior do kernel do Linux. Ora, imagine se a segurança nacional e a soberania do seu país fossem comprometidos porque um zé mané de uma universidade de outro país foi brincar de hacker no kernel e inseriu uma vulnerabilidade em milhões ou bilhões de máquinas.

### DEPENDÊNCIA

#### Dependência

Imaginem o caso de alguém que possui uma verdadeira paixão por programação. O sujeito quando sai do trabalho dele, que é programar para alguma grande empresa, para se distrair, ele continua programando, mas dessa vez em projetos pessoais, sem receber nada por isso.

Eis que ele desenvolve uma biblioteca muito útil para uma linguagem muito popular, ou um plugin muito importante para uma ferramenta.

E então o projeto se populariza e muita gente começa a usar, porque de fato é muito bom. Os anos vão passando, os desenvolvedores vão percebendo como aquilo ali torna o trabalho deles mais eficiente até que passam a existir novos projetos que dependam inteiramente dessa ferramenta mantida por um cara só.

Eis que chega um momento na vida deste sujeito em que ele não quer mais continuar com o projeto. Talvez a linguagem já está ultrapassada e ele quer trabalhar com coisas novas, ou ele teve filhos e prefere ficar mais tempo com a família, ou ele sofreu um acidente grave (bus factor).

Logo, dezenas, ou centenas, ou milhares de projetos, grandes infraestruturas de enormes empresas agora passam a ter um problema gravíssimo com uma dependência que foi abandonada.

Ou pior, ele nem precisa abandonar a biblioteca. Se ele faz um trabalho ruim, ou os seus colaboradores, uma vulnerabilidade na biblioteca dele pode implicar numa vulnerabilidade no seu sistema.

#### Exemplos

Bun, esbuild, elysia, hono.

Bun é um runtime de javascript.
Esbuild é um bundler.
Elysia e Hono são frameworks HTTP, concorrentes.
Null-ls é um plugin do neovim.

No caso do null-ls, o projeto era mantido por este sujeito. Ele disse que não estava mais com tempo e energia, nem usava mais o Neovim como editor principal dele. Então ele só desistiu.

O problema é que existia uma infinidade de plugins do Neovim que foram para o ralo porque todos eles dependiam do null-ls, que servia de interface para integrar objetos externos ao LSP (Language Server Protocol) do Neovim.

Era uma ferramenta fundamental, para centenas ou milhares de plugins do Neovim, e que até hoje não possui um substituto. 

A decisão de um sujeito defasou centenas de programas.

#### Suporte

Então você identifica o problema, expõe e pede por uma correção urgente.

E por que eles estariam interessados em resolver esse problema com tanta urgência quanto você? Eles não recebem nada para trabalhar nesse projeto, não recebem alguma porcentagem dos milhões que você lucra. Eles sequer são reconhecidos ou valorizados pelos trabalhos prestados.

Mesmo se você tiver um problema, você vai reclamar para quem? Eles não recebem para te ajudar. O problema é seu, não deles. Então você também fica a mercê da boa vontade de um mantenedor ou da comunidade para receber ajuda.

Existe um alto risco relacionado a projetos open source que podem ser descontinuados. Então se você depende de um projeto desses em vez de manter sua própria versão interna, você precisa estar preparado para o caso de qualquer problema com o projeto de terceiros.

Ah, mas se o mantenedor avacalhar é só fazer um fork? Será que é tão simples assim?

### PODER DE DECISÃO

#### Fork hell

Quando um projeto possui uma comunidade, ele passa também a possuir um drama interno. Há aqueles que são responsáveis por tomar as decisões do rumo do projeto, geralmente os lead mantainers.

Porém, se alguém da comunidade decide não concordar com essas determinadas decisões, eles podem simplesmente fazer o fork sem mais nem menos. Isso pode parecer algo bom a princípio, pois significa que há liberdade que o projeto que tanto amam não será "pervertido" pelos líderes. Como se houvesse espaço para todos.

Mas esse tipo de coisa tem um impacto negativo para a comunidade e enfraquece ainda mais o software. Além de dividir os desenvolvedores, o que diminui a eficiência do desenvolvimento, divide também os usuários, que não sabem mais qual é a melhor versão, qual é a mais provável de continuar sendo mantida...

Isso pode enfraquecer o software.

E se você se considera dono do projeto, e tem uma ideia futura para ele, anunciá-lo como software livre, e colocar uma licença livre no seu software abre portas para a situação em que você não manda mais no seu projeto e precisa ceder à pressão da comunidade, senão a qualquer momento alguém pode "te trair" e, se der certo, ela vira dona do seu projeto, da sua ideia.

Você trabalha para si ou vira escravo da comunidade?

#### Exemplos

Bitcoin Cash é um fork do Bitcoin. Isso confunde a cabeça do usuário. Tem gente até hoje que compra Bitcoin Cash achando que é Bitcoin.

LibreOffice que é um fork do OpenOffice. De fato, os motivos para o fork eram razoáveis. Hoje o OpenOffice é do Apache. Mas, de novo, isso promove uma divisão. O desenvolvedor quer contribuir para uma suíte de office, para qual ele vai contribuir?
Ele quer inserir uma funcionalidade nova, ele vai ter que implementar nas duas? E o usuário? Ainda mais o usuário leigo, que está começando no Linux, ele fica sobrecarregado com o número de opções que ele possui.

É importante realçar que obviamente existem pontos muito positivos. Não somos cegos a ponto de achar que isso é algo ruim.
Mas queremos promover a reflexão sobre os pontos negativos que também existem.

#### Para quem você trabalha?

Há de se notar também que nem todos os programas open source são dirigidos por um sujeito sozinho ou por uma comunidade. O código pode estar disponível publicamente, mas quem toma as decisões por trás é uma companhia, baseada nos seus interesses, especialmente se o software for comercializado.

Portanto, será que você não estaria trabalhando de graça? Pode ser que companhia fature muito dinheiro com a ajuda do software e você não receba um tostão furado.

Ou pior, trabalhando para algo que pode ser usado contra você? Para fins que você repudia e/ou te farão mal?

(exemplo Android?)

### MAS É LIVRE MESMO?

Mas se você quiser mesmo abrir o seu software, você tem que estar ciente de que todo mundo vai poder usar. Você está abrindo, talvez, a oportunidade para uma pessoa fazer algo que não poderia antes sem a sua ajuda. Inclusive coisas ruins.

E impedir esse tipo de coisa é muito mal visto na comunidade de software livre.

(exemplo do cara que tentou proibir grandes empresas na licença)

Você perde o controle total, não só legal, sobre quem vai ou não vai usar o seu software. Então você pode desenvolver uma biblioteca de bitcoin que vai ser usada para lavar dinheiro, uma biblioteca de VPN que pode ser usada para esconder pedófilos ou um driver de criptografia que vai ser usado por terroristas para detonar explosivos.