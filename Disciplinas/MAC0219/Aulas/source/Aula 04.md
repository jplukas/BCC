# Pthreads e OPENMP

## Motivação

## IEEE POSIX Threads

- Define um modelo de execução
- Independente de linguagens
- Define uma API para criação e controle de threads
- Não define uma implementação

## API Pthreads

Implementação de POSIX threads

## OpenMP

Open multi-processing

- API para parelelismo multithreading e memória compartilhada
- Diretivas de compilador
- Biblioteca de tempo de execução
- Variáveis de ambiente

Objetivos:

- Padronizar
- Simplificar
- Promover portabilidade

### Modelo de programação

- Threads dinâmicas
- Paralelismo explícito e aninhável
- Diretivas de compilador
- Modelo Fork-Join

#### Diretivas

- Criar regiões paralelas
- Distribuir blocos de código
- Distribuir iterações de laços
- Sincronizar threads

#### Biblioteca runtime

- Obter e definir o número de threads
- Obter IDs de threads
- Obter região paralela e nível de aninhamento
- Obter, criar e destruir locks

#### Variáveis de ambiente

- Definir número de threads
- Distribuir iterações de laços
- Associar threads a processadores
- Configurar paralelismo aninhado
- Configurar threads dinâmicas
