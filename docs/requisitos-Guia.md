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
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround;
    int completion_time;
} Process;
```

```c
typedef struct {
    int process_id;
    int start_time;
    int end_time;
} ExecutionHistory;
```

### 2. Entrada de Dados

Permitir que o usuário insira o número de processos, tempos de execução e quantum (para Circular):

```c
void input_processes(Process processes[], int *n, int *quantum)
{
    printf("Digite o número de processos: ");
    scanf("%d", n);

    if (*n > MAX_PROCESSES)
    {
        printf("Número máximo de processos excedido. Limitando a %d processos. \n", MAX_PROCESSES);
        *n = MAX_PROCESSES;
    }

    printf("Digite o quantum para o algoritmo Circular: ");
    scanf("%d", quantum);

    for (int i = 0; i < *n; i++)
    {
        processes[i].id = i + 1;
        printf("Digite o tempo de execução do processo P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        if (processes[i].burst_time <= 0)
        {
            printf("Tempo de execução não pode ser <= 0. Definindo como 1.\n");
            processes[i].burst_time = 1;
        }

        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround = 0;
    }
}
```

### 3. Algoritmo Circular (Preemptivo)

Implementar o algoritmo Circular com quantum fixo:

```c
void round_robin(Process processes[], int n, int quantum, ExecutionHistory history[], int *history_size)
{
    int current_time = 0;
    int completed = 0;
    *history_size = 0;

    // Inicializa todos os processos
    initialize_processes(processes, n);

    while (completed < n)
    {
        int idle = 1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0)
            {
                idle = 0; // O processador não está ocioso

                int execution_time;
                if (processes[i].remaining_time > quantum)
                {
                    execution_time = quantum;
                    processes[i].remaining_time -= quantum;
                }
                else
                {
                    execution_time = processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed++;
                    processes[i].completion_time = current_time + execution_time;
                    processes[i].turnaround = processes[i].completion_time;
                    processes[i].waiting_time = processes[i].turnaround - processes[i].burst_time;
                }

                // Registra a execução para o diagrama de Gantt
                history[*history_size].process_id = processes[i].id;
                history[*history_size].start_time = current_time;
                history[*history_size].end_time = current_time + execution_time;
                (*history_size)++;

                current_time += execution_time;
            }
        }

        // Se todos os processos estiverem esperando por I/O, avança o tempo
        if (idle)
        {
            current_time++;
        }
    }
}
```

### 4. Algoritmo SJF (Não Preemptivo)

Implementar o algoritmo SJF:

```c
void sjf_non_preemptive(Process processes[], int n, ExecutionHistory history[], int *history_size)
{
    int current_time = 0;
    int completed = 0;
    *history_size = 0;

    // Inicializa todos os processos
    initialize_processes(processes, n);

    while (completed < n)
    {
        int shortest_job = -1;
        int min_burst = INT_MAX;

        // Encontra o próximo processo com o menor tempo de execução
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0 && processes[i].burst_time < min_burst)
            {
                min_burst = processes[i].burst_time;
                shortest_job = i;
            }
        }

        if (shortest_job != -1)
        {
            // Registra a execução para o diagrama de Gantt
            history[*history_size].process_id = processes[shortest_job].id;
            history[*history_size].start_time = current_time;
            history[*history_size].end_time = current_time + processes[shortest_job].burst_time;
            (*history_size)++;

            current_time += processes[shortest_job].burst_time;
            processes[shortest_job].completion_time = current_time;
            processes[shortest_job].turnaround = processes[shortest_job].completion_time;
            processes[shortest_job].waiting_time = processes[shortest_job].turnaround - processes[shortest_job].burst_time;
            processes[shortest_job].remaining_time = 0;
            completed++;
        }
        else
        {
            // Se não houver processos prontos, avança o tempo
            current_time++;
        }
    }
}
```

### 5. Cálculo de Métricas

Calcular e exibir as métricas:

```c
void display_metrics(Process processes[], int n)
{
    float total_waiting_time = 0, total_turnaround = 0, total_burst_time = 0;

    printf("\nMétricas dos Processos:\n");
    printf("+----+----------------+----------------+----------------+\n");
    printf("| ID | Tempo Espera   | Tempo Retorno  | Tempo Execução |\n");
    printf("+----+----------------+----------------+----------------+\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %2d | %14d | %14d | %14d |\n",
               processes[i].id,
               processes[i].waiting_time,
               processes[i].turnaround,
               processes[i].burst_time);

        total_waiting_time += processes[i].waiting_time;
        total_turnaround += processes[i].turnaround;
        total_burst_time += processes[i].burst_time;
    }

    printf("+----+----------------+----------------+----------------+\n");
    printf("\nTempo médio de espera: %.2f\n", total_waiting_time / n);
    printf("Tempo médio de retorno: %.2f\n", total_turnaround / n);
    printf("Tempo total de uso do processador: %.2f\n", total_burst_time);
}
```

### 6. Exibição do Diagrama de Gantt

Mostrar a evolução do algoritmo:

```c
void draw_gantt_chart(ExecutionHistory history[], int history_size)
{
    printf("\nDiagrama de Gantt:\n");

    // Imprime linha superior
    printf("+");
    for (int i = 0; i < history_size; i++)
    {
        for (int j = 0; j < 6; j++)
            printf("-");
        printf("+");
    }
    printf("\n");

    // Imprime IDs dos processos
    printf("|");
    for (int i = 0; i < history_size; i++)
    {
        printf(" P%-2d |", history[i].process_id);
    }
    printf("\n");

    // Imprime linha inferior
    printf("+");
    for (int i = 0; i < history_size; i++)
    {
        for (int j = 0; j < 6; j++)
            printf("-");
        printf("+");
    }
    printf("\n");

    // Imprime tempos
    printf("%d", history[0].start_time);
    for (int i = 0; i < history_size; i++)
    {
        for (int j = 0; j < 6; j++)
            printf(" ");
        printf("%d", history[i].end_time);
    }
    printf("\n");
}
```

### 7. Funções Auxiliares

```c
void initialize_processes(Process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround = 0;
        processes[i].completion_time = 0;
    }
}

void reset_process_stats(Process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround = 0;
        processes[i].completion_time = 0;
    }
}
```

## Guia para Implementação em JavaScript

### Estrutura de Dados

```javascript
class Process {
	constructor(id, burstTime) {
		this.id = id;
		this.burstTime = burstTime;
		this.remainingTime = burstTime;
		this.waitingTime = 0;
		this.turnaround = 0;
	}
}
```

### Algoritmo Circular

### Algoritmo SJF

---
