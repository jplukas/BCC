# Introdução

[Dados]{#def:dados}
: Dados são fatos relacionados, que podem ser gravados, e com significado implícito. Por exemplo: nomes, telefones e endereços de pessoas.

[Banco de dados]{#def:banco_de_dados}
: Um ***banco de dados*** é uma coleção de dados relacionados.

    - Um banco de dados representa algum aspecto do mundo real, ou ***minimundo***. Mudanças no *minimundo* devem refletir mudanças no banco de dados.
    - Um banco de dados é uma coleção coerente de dados com algum significado inerente. Uma coleção aleatória de dados não pode ser considerada um banco de dados.
    - Um banco de dados é projetado, construído e populado com dados para um propósito específico. Tem um grupo de usuários pretendidos definido, e algumas aplicações pré concebidas nas quais esses usuários têm algum interesse.

[Sistema Gerenciador de Banco de Dados]{#def:sistema_gerenciador_de_banco_de_dados}
: Um ***Sistema Gerenciador de Bancos de dados***, ou ***SGBD***, é um sistema computadorizado que permite a usuários ***definir***, ***construir***, ***manipular*** e ***compartilhar*** bancos de dados entre vários usuários e aplicações diferentes.
*Definir* bancos de dados involve especificar os tipos de dados, estruturas, e restrições para os dados a serem armazenados no banco de dados. A definição do banco de dados também é armazenada no próprio banco de dados, e é chamada de ***meta-dados***.
*Construir* um banco de dados é o processo de armazenar dados em alguma mídia de armazenamento controlada pelo SGBD.
*Manipular* um banco de dados envolve utilizar funções para recuperar, alterar, atualizar ou destruir dados, entre outras operações que se pode realizar com os dados de um BD.
*Compartilhar* um banco de dados habilita diferentes usuários e programas aplicativo a acessar o banco de dados simultaneamente.

Um ***programa aplicativo*** acessa o banco de dados mandando ***consultas***, ou ***queries***, ou ***transações***. Uma consulta geralmente faz com que dados sejam recuperados do banco de dados. Uma transação geralmente causa alguma mudança no banco de dados.

## Sistemas de bancos de dados

Um banco de dados, aliado a um sistema gerenciador é chamado de ***sistema de banco de dados***.
Em um banco de dados, normalmente dados relacionados estão organizados em um mesmo *arquivo*, que contém ***registros*** de mesmo tipo. Cada registro pode ser visto como uma tupla de ***elementos de dados*** relacionados a uma mesma entidade do mundo a ser representada. Devemos definir ***tipos de dados*** adequados para representar e manipular os dados que queremos armazenar.

### Projeto de banco de dados

O projeto de um sistema de banco de dados em uma organização começa com uma fase chamada ***análise e especificação de requisitos***, onde se levantam as necessidades que o sistema deve atender, e suas funcionalidades essenciais.
Esses requisitos são então documentados e transformados em um ***projeto conceitual***.
O projeto é então traduzido para um ***projeto lógico***, onde utilizamos algum tipo de ***modelo de dados*** para representar os dados e seus relacionamentos. Usamos então esse modelo para definir detalhes de uso e implementação do sistema.
A fase final é o ***projeto físico***, onde definimos especificações mais detalhadas sobre como os dados devem ser acessados, armazenados e manipulados pelo SGBD. O banco de dados é então implementado, populado com dados reais e continuamente atualizado para refletir o estado do minimundo.

## Características de bancos de dados

Diversas características distinguem a abordagem do uso de um banco de dados da abordagem mais simples de ***processamento de arquivos***. Na última, cada programa aplicativo é responsável por implementar as suas sob-rotinas de acesso e manipulação de arquivos, o que traz uma série de complicações, como:

- Falta de consistência entre diferentes aplicações
- Excesso de trabalho em áreas não-vitais do programa aplicativo
- Dificuldade ou incapacidade de compartilhamento de dados
- Redundância

Na abordagem de bancos de dados esses problemas são remediados, pois quem é responsável por definir, manter e realizar o acesso aos dados é um programa só, o SGBD.

As principais vantagens da abordagem de bancos de dados sobre a de processamento de arquivos são:

- Natureza auto-descritiva de um sistema de banco de dados
- Isolamento entre programas e dados, e abstrações de dados
- Suporte a múltiplas visões de dados
- Compartilhamento de dados e processamento de transações

### Auto-descrição de um sistema de banco de dados

Uma característica fundamental de bancos de dados é que os sistemas de bancos de dados não possuem apenas o banco de dados em si próprio, mas também uma definição, ou descrição completa da sua estrutura e restrições, que pode ser acessada por meio do SGBD. Chamamos essa informação de ***meta-dados*** do banco de dados.
É importante notar também que alguns tipos de sistemas de bancos de dados mais novos, os chamados NOSQL, não requerem tais meta-dados. Ao invés disso, os dados são armazenados como ***dados auto-descritivos***, que incluem ambos os nomes dos itens dos dados quanto os seus valores, juntos, em uma única estrutura.

Em comparação, na abordagem de processamento de arquivos, a definição da estrutura dos dados deve estar no programa aplicativo, e é sua responsabilidade saber como acessar e manipulá-los, o que faz com que seja virtualmente impossível dois programas diferentes utilizarem o mesmo arquivo de dados.

### Isolamento entre programas e dados, e abstrações de dados

No processamento tradicional de arquivos, qualquer alteração na estrutura de um arquivo faz com que **todos** os programas que o manipulem tenham que ser alterados. Em contraste, alterar a estrutura interna de um banco de dados *normalmente* não requer tais alterações nos programas que o acessam. Chamamos essa propriedade de ***independência programa-dados***.
Em alguns tipos de sistemas de bancos de dados, como sistemas ***orientados a objeto***, e sistemas ***objeto-relacionais***, além dos dados, podemos definir ***operações*** nos dados, como parte do banco de dados. Tais operações são definidas em duas partes: uma ***interface***, que define o nome da operação, seus argumentos e tipos de dados, e uma ***implementação***, que detalha todas transformações que a operação executa, e como as executa. A implementação de uma operação pode ser definida separadamente da sua interface, mas deve "concordar" com ela, no sentido de que deve ter o mesmo nome, e os mesmos atributos e mesmos tipos. Porém uma mesma interface pode ser implementada de n maneiras diferentes.
Aplicações podem então operar sobre os dados invocando tais operações por meio de seus nomes e argumentos, sem saber detalhes de sua implementação. A isso chamamos de ***independência programa-operação***.

A característica de sistemas de bancos de dados que permite esses tipos de independência é o que chamamos de ***abstração de dados***. Um SGBD provê aos usuários uma ***representação conceitual*** dos dados, que não inclui nenhum detalhe sobre como os dados são armazenados, ou sobre como as operações são implementadas. Um ***modelo de dados*** é um tipo de modelo de dados que é usado para prover essa representação conceitual.

### Suporte a múltiplas visões de dados

Um banco de dados tipicamente possui múltiplos usuários, com múltiplas perspectivas ou ***visões*** dos dados. Uma visão pode ser um subconjunto do banco de dados, e pode conter ***dados virtuais***, que não estão necessariamente, fisicamente no banco de dados, mas são derivados de algum processamento dos dados.

### Compartilhamento de dados e processamento de transações

Como um sistema de banco de dados deve ser utilizado por uma variedade de usuários e programas aplicativo, muitas vezes simulteneamente, ele deve empregar algum tipo de ***controle de concorrência***, para assegurar consistência de suas operações.
O conceito de ***transação*** é um conceito central em aplicações de bancos de dados. Uma transação é um processo que inclui um ou mais acessos ao banco de dados, tal como leitura ou atualização de registros do banco de dados. Cada transação deve assegurar uma variedade de propriedades, para que ela seja considerada "segura". A propriedade de ***isolamento*** assegura que cada transação parece ser executada em isolamento, isto é, nenhuma transação é afetada por nenhuma outra. A propriedade de ***atomicidade*** garante que, ou **todas** as operações de uma transação são executadas, ou nenhuma é.

## Vantagens da abordagem de base de dados

