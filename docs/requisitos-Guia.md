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
} Process;
```

### 2. Entrada de Dados

Permitir que o usuário insira o número de processos, tempos de execução e quantum (para Circular):

```c
int n, quantum;
Process processes[MAX_PROCESSES];
printf("Digite o número de processos: ");
scanf("%d", &n);

printf("Digite o quantum para o algoritmo Circular: ");
scanf("%d", &n);

for (int i = 0; i < n; i++){
    processes[i].id = i + 1;
    printf("Digite o tempo de execução do processo P%d: ", i + 1);
    scanf("%d", &processes[i].burst_time);
    processes[i].remaining_time = processes[i].burst_time;
    processes[i].waiting_time = 0;
    processes[i].turnaround = 0;
}
```

### 3. Algoritmo Circular (Preemptivo)

Implementar o algoritmo Circular com quantum fixo:

```c
void round_robin(Process processes[], int n, int quantum) {
    int current_time = 0;
    int completed = 0;

    while(completed < n) {
        for (int i = 0; i < n; i++>) {
            if (processes[i].remaining_time > 0){
                if (processes[i].remaining_time > quantum) {
                    current_time  += quatum;
                    processes[i].remaining_time -= quantum;
                } else {
                    current_time += processes[i];
                    remaining_time;
                    processes[i].waiting_time = current_time - processes[i].burst_time = current_time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }
}
```

### 4. Algoritmo SJF (Não Preemptivo)

Implementar o algoritmo SJF:

```c

```

### 5. Cálculo de Métricas

Calcular e exibir as métricas:

```c
void display_metrics(Process processes[], int n) {
    float total_waiting_time = 0; total_turnaround = 0;

    printf("\nMétricas dos Processos:\n");
    printf("+----+----------------+----------------+----------------+\n");
    printf("| ID | Tempo Espera   | Tempo Retorno  | Tempo Execução |\n");
    printf("+----+----------------+----------------+----------------+\n");

    for ( int i = 0; i < n; i++>) {
        printf("| %2d | %14d | %14d | %14d |\n",
                processes[i].id,
                processes[i].waiting_time,
                processes[i].turnaround,
                processes[i]burst_time);

        total_waiting_time += processes[i].waiting_time;
        total_turnaround =+ processes[i].turnaround;
    }

    printf("+----+----------------+----------------+----------------+\n");
    printf("\nTempo médio de espera: %.2f\n", total_waiting_time / n);
    printf("Tempo médio de retorno: %.2f\n", total_turnaround_time / n);
}
```

### 6. Exibição do Diagrama de Gantt

Mostrar a evolução do algoritmo:

```c
void draw_gantt_chart(Process processes[], int n) {
    printf("\nDiagrama de Gantt:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].id);
    }
    printf("\n");
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
