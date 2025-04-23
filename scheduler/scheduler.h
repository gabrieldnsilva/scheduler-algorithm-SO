#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_PROCESSES 100

// Estrutura para armazenar informações do processo
typedef struct
{
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround;
    int completion_time;
} Process;

// Estrutura para armazenar o histórico de execução
typedef struct
{
    int process_id;
    int start_time;
    int end_time;
} ExecutionHistory;

// Funções para os algoritmos de escalonamento
void round_robin(Process processes[], int n, int quantum, ExecutionHistory history[], int *history_size);
void sjf_non_preemptive(Process processes[], int n, ExecutionHistory history[], int *history_size);

// Funções para métricas e visualização
void display_metrics(Process processes[], int n);
void draw_gantt_chart(ExecutionHistory history[], int history_size);
void reset_process_stats(Process processes[], int n);

// Funções auxiliares
void initialize_processes(Process processes[], int n);
void input_processes(Process processes[], int *n, int *quantum);

#endif // SCHEDULER_H