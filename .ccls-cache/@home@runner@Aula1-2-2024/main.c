// Estrutura de Dados - Renan A. Tavares - 202225014
// Sistema de Atendimento em uma Clínica Médica - Tarefa FILA

#include <stdio.h>
#include <string.h>
#define MAX 5

// definição da estrutura - Fila
typedef struct {
    char pacientes[MAX][30]; // armazena os nomes
    int inicio;
    int fim;
    int quantidade; // n° de pacientes
} FilaCircular;

// iniciar a fila
void inicializarFila(FilaCircular* fila) {
    fila->inicio = -1;
    fila->fim = -1;
    fila->quantidade = 0;
}

// verificar se a fila está cheia
int estaCheia(FilaCircular* fila) {
    return fila->quantidade == MAX;
}

// verificar se a fila está vazia
int estaVazia(FilaCircular* fila) {
    return fila->quantidade == 0;
}

// enfileirar
void enfileirar(FilaCircular* fila, char nome[]) {
    if (estaCheia(fila)) {
        printf("Fila cheia! Não é possível adicionar mais pacientes.\n");
        return;
    }

    // verifica se é a primeira inserção
    if (fila->inicio == -1) {
        fila->inicio = 0;  // Define o início
    }

    // Atualiza o índice do fim de forma circular
    fila->fim = (fila->fim + 1) % MAX;

    // Insere o nome do paciente na posição 'fim'
    strcpy(fila->pacientes[fila->fim], nome);

    // Incrementa a quantidade de elementos na fila
    fila->quantidade++;
    printf("Paciente %s adicionado à fila.\n", nome);
}

// desenfileirar
void desenfileirar(FilaCircular* fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia! Nenhum paciente para atendimento.\n");
        return;
    }

    printf("Paciente %s foi chamado para atendimento.\n", fila->pacientes[fila->inicio]);
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->quantidade--;

    if (estaVazia(fila)) {
        fila->inicio = -1;
        fila->fim = -1;
    }
}

// exibir os pacientes na fila
void exibirFila(FilaCircular* fila) {
    if (estaVazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }

    printf("Pacientes na fila:\n");
    int i, posicao = 1;
    for (i = fila->inicio; posicao <= fila->quantidade; i = (i + 1) % MAX, posicao++) {
        printf("%d. %s\n", posicao, fila->pacientes[i]);
    }
}

// menu do sistema de atendimento
int main() {
    FilaCircular fila;
    inicializarFila(&fila);

    int opcao;
    char nomePaciente[50];

    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar paciente\n");
        printf("2. Chamar paciente para atendimento\n");
        printf("3. Exibir fila de pacientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Digite o nome do paciente: ");
                fgets(nomePaciente, sizeof(nomePaciente), stdin);
                nomePaciente[strcspn(nomePaciente, "\n")] = '\0';
                enfileirar(&fila, nomePaciente);
                break;
            case 2:
                desenfileirar(&fila);
                break;
            case 3:
                exibirFila(&fila);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

