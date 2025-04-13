#include "scheduler.h"

int main()
{
    Process processes[MAX_PROCESSES];
    ExecutionHistory history[MAX_PROCESSES * 10]; // Para armazenar o histórico de execução
    int n, quantum, history_size = 0;
    int choice;

    printf("=== Simulador de Algoritmos de Escalonamento ===\n\n");

    // Entrada de dados
    input_processes(processes, &n, &quantum);

    do
    {
        printf("\nEscolha o algoritmo de escalonamento:\n");
        printf("1. Circular (Round Robin)\n");
        printf("2. SJF (Shortest Job First) Não-Preemptivo\n");
        printf("3. Executar ambos e comparar\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n=== Executando Algoritmo Circular (Round Robin) ===\n");
            round_robin(processes, n, quantum, history, &history_size);
            draw_gantt_chart(history, history_size);
            display_metrics(processes, n);
            break;

        case 2:
            printf("\n=== Executando Algoritmo SJF Não-Preemptivo ===\n");
            sjf_non_preemptive(processes, n, history, &history_size);
            draw_gantt_chart(history, history_size);
            display_metrics(processes, n);
            break;

        case 3:
            printf("\n=== Executando Algoritmo Circular (Round Robin) ===\n");
            round_robin(processes, n, quantum, history, &history_size);
            draw_gantt_chart(history, history_size);
            display_metrics(processes, n);

            // Resetar estatísticas dos processos para o próximo algoritmo
            reset_process_stats(processes, n);

            printf("\n=== Executando Algoritmo SJF Não-Preemptivo ===\n");
            sjf_non_preemptive(processes, n, history, &history_size);
            draw_gantt_chart(history, history_size);
            display_metrics(processes, n);
            break;

        case 0:
            printf("Saindo do programa. Obrigado!\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 0);

    return 0;
}