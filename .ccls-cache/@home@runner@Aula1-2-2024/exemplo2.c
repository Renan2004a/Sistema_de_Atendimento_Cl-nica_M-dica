#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;

    // Alocação de memória para um único inteiro
    p = (int*) malloc(sizeof(int));
    if (p == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Atribuindo valor à memória apontada por p
    *p = 42; // *p é o valor armazenado no local de memória para o qual p aponta

    // Mostrando a diferença entre p e *p
    printf("Endereço armazenado em p: %p\n", (void*)p);    // Exibe o endereço de memória (valor de p)
    printf("Valor armazenado em *p: %d\n", *p);            // Exibe o valor no endereço apontado por p (valor de *p)

    // Liberação da memória alocada
    free(p);
    p = NULL;  // Boa prática: definir o ponteiro como NULL após liberar a memória

    return 0;
}
