# Requisitos e Guia para Desenvolvimento de uma Aplicação de Escalonamento

## Objetivo

Desenvolver uma aplicação em C (ou JavaScript) que simule os algoritmos de escalonamento **Circular (Preemptivo)** e **SJF (Não Preemptivo)**, com as seguintes características:

1. **Circular (Preemptivo)**:

    - Utilizar um quantum fixo para alternar entre os processos.
    - Todos os processos possuem o mesmo tempo de chegada.

2. **SJF (Não Preemptivo)**:
    - Selecionar o processo com menor tempo de execução.
    - Todos os processos possuem o mesmo tempo de chegada.

## Requisitos

1. **Conceitos Utilizados**:

    - Vetores, registros (structs) e/ou matrizes.
    - Funções para modularizar o código.

2. **Variáveis**:

    - Não utilizar valores fixos ou constantes para os processos, tempos ou quantum.
    - Permitir entrada dinâmica de dados pelo usuário.

3. **Saída**:

    - Mostrar a evolução do algoritmo (diagrama de Gantt).
    - Calcular e exibir:
        - Tempo médio de espera.
        - Tempo médio de turnaround.
        - Tempo de espera de cada processo.
        - Tempo de retorno de cada processo.
        - Tempo total de uso do processador.

4. **Compatibilidade**:
    - Código e documentação compatíveis com Markdown para renderização no GitHub.

---

## Passo a Passo para Implementação

### 1. Estrutura de Dados

Definir uma estrutura para representar os processos:

```c
typedef struct {

}
```

### 2. Entrada de Dados

Permitir que o usuário insira o número de processos, tempos de execução e quantum (para Circular):

```c

```

### 3. Algoritmo Circular (Preemptivo)

Implementar o algoritmo Circular com quantum fixo:

```c

```

### 4. Algoritmo SJF (Não Preemptivo)

Implementar o algoritmo SJF:

```c

```

### 5. Cálculo de Métricas

Calcular e exibir as métricas:

```c

```

### 6. Exibição do Diagrama de Gantt

Mostrar a evolução do algoritmo:

```c

```

## Guia para Implementação em JavaScript

### Estrutura de Dados

### Algoritmo Circular

### Algoritmo SJF

---
