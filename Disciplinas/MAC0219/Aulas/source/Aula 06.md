# Modelos para a computação paralela

Não existe um modelo universal para a computação paralela, como os modelos de Von Neumann e da Máquina de Turing são para a computação sequencial.
Um motivo que explica essa ausência é o trade-off entre realismo e simplicidade dos modelos.

- Modelos de aplicação: Representam o paralelismo de um algoritmo
- Modelos de máquina: Descrevem as características das máquinas.
- Modelos de execução: Detalham a forma de programação

Criando uma aplicação paralela:

1. Escolha um modelo para a máquina;
2. Escolha uma representação para o algoritmo;
3. Escolha um modelo de execução;

## Escalonamento

Atribui a cada tarefa uma máquina e um tempo de início.
Exemplos:

- Processador e processos;

## Modelos de aplicação

- Grafos de fluxo de dados
- Grafo de precedência
- Grafo de dependência

### Grafo de precedência

O algoritmo é dividido em tarefas, nas quais:

- Um vértice representa uma tarefa
- Uma aresta representa relações de dependência;

Termos importantes:

- Sucessores;
- Sucessores diretos;
- Predecessores;
- Predecessores Diretos;
- Largura;
- Caminho crítico;
- Granularidade.

## Modelos para máquinas

Taxonomia de Flynn - Classificação quanto aos fluxos:

- De instruções
- De dados

|Instruções\
Dados|Simples|Múltiplo|
|----------------|-------|--------|
|Simples|SISD sequencial|SIMD|
|Múltiplo|MISD|MIMD|

### Máquinas sistólicas

## Modelos de execução

Usado no desenvolvimento

- Predição de custos
- Planejamento da comunicação

Ligado ao modelo da máquina

Principais modelos:

- PRAM
- Modelos com atraso de comunicação
- Modelo Sistólico
- Topologias específicas
- LogP
- BSP / CGM
- Tarefas maleáveis

### PRAM

- Parallel Random Access Machine
- Surgiu em 1978 e é uma referência
- Usado para análise de algoritmos paralelos

- Número ilimitado de processadores
- Síncrono
- Acesso a memória uniforme
- Memória ilimitada

### Modelos com atraso de comunicação

- Fornece um suporte para a comunicação
- Processadores com memória local
- Vários resultados teóricos
- Considera o essencial das máquinas reais

### Modelo sistólico

### Topologias específicas

- Anel
- Toro
- Caminho
- Grade
- Hipercubo
- Mais sofisticadas
  - CCC (cube connected cycles)
  - De Bruijn
