# Simulador de Algoritmos de Escalonamento

Bem-vindo ao **Simulador de Algoritmos de Escalonamento**! Este projeto tem como objetivo implementar e demonstrar o funcionamento de dois algoritmos clássicos de escalonamento de processos: **Circular (Preemptivo)** e **SJF (Não Preemptivo)**.

## 📋 Objetivo

O projeto visa criar uma aplicação em **C** ou **JavaScript** que simule os algoritmos de escalonamento com as seguintes características:

-   **Circular (Preemptivo)**:

    -   Utiliza um quantum fixo para alternar entre os processos.
    -   Todos os processos possuem o mesmo tempo de chegada.

-   **SJF (Não Preemptivo)**:
    -   Seleciona o processo com menor tempo de execução.
    -   Todos os processos possuem o mesmo tempo de chegada.

## 🛠️ Funcionalidades

1. **Entrada Dinâmica de Dados**:

    - Permite que o usuário insira o número de processos, tempos de execução e quantum.

2. **Execução dos Algoritmos**:

    - Implementação do algoritmo Circular com quantum fixo.
    - Implementação do algoritmo SJF para seleção do menor tempo de execução.

3. **Cálculo de Métricas**:

    - Tempo médio de espera.
    - Tempo médio de turnaround.
    - Tempo de espera e retorno de cada processo.
    - Tempo total de uso do processador.

4. **Visualização**:
    - Exibição do diagrama de Gantt para ilustrar a evolução dos algoritmos.

## 📂 Estrutura do Projeto

-   [`docs/requisitos-Guia.md`](docs/requisitos-Guia.md): Documento detalhado com os requisitos e guia para implementação.
-   `README.md`: Este arquivo, que serve como introdução ao projeto.

## 🚀 Como Usar

1. Clone este repositório:

    ```bash
    git clone https://github.com/seu-usuario/scheduler-algorithm.git
    cd scheduler-algorithm
    ```

2. Escolha a linguagem de implementação:

    - Para **C**, siga as instruções no arquivo [`requisitos.md`](requisitos.md).
    - Para **JavaScript**, consulte a seção correspondente no mesmo arquivo.

3. Compile e execute o código:

    - **C**:
        ```bash
        gcc -o scheduler scheduler.c
        ./scheduler
        ```
    - **JavaScript**:
        ```bash
        node scheduler.js
        ```

4. Insira os dados solicitados e visualize os resultados, incluindo métricas e o diagrama de Gantt.

## 📖 Documentação

Para detalhes técnicos e exemplos de código, consulte os seguintes arquivos:

-   Requisitos e Guia de Implementação
-   Guia Inicial de Implementação

## 🧑‍💻 Tecnologias Utilizadas

-   Linguagens: **C** e **JavaScript**
-   Estruturas de Dados: Vetores, structs e/ou matrizes
-   Ferramentas: Markdown para documentação compatível com GitHub

## 📊 Exemplo de Saída

### Diagrama de Gantt

```plaintext
P1 P2 P3 P1 P2 P3
```

### Métricas

```plaintext
+----+----------------+----------------+----------------+
| ID | Tempo Espera   | Tempo Retorno  | Tempo Execução |
+----+----------------+----------------+----------------+
|  1 |             10 |             15 |              5 |
|  2 |              5 |             10 |              5 |
|  3 |              0 |              5 |              5 |
+----+----------------+----------------+----------------+

Tempo médio de espera: 5.00
Tempo médio de retorno: 10.00
```

## 📬 Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

---

**Autor:** Gabriel D. N. Silva  
**Licença:** MIT
