#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Função para imprimir a lista
void printList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("Elementos da lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    struct Node* head = NULL;
    int option, value;

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Imprimir a lista\n");
        printf("2. Adicionar um novo elemento\n");
        printf("0. Sair\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printList(head);
                break;
            case 2:
                printf("Digite o valor do novo elemento: ");
                scanf("%d", &value);
                // Adiciona o novo elemento no início da lista
                {
                    struct Node* newNode = createNode(value);
                    newNode->next = head;
                    head = newNode;
                }
                break;
            case 0:
                // Libera a memória antes de sair
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
}
