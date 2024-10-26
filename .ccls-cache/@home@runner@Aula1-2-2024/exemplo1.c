#include <stdio.h>
#include <stdlib.h> // Para usar malloc e free

int main() {
  int *p;

  // Alocação de memória dinâmica para o ponteiro 'p'
  p = (int *)malloc(sizeof(int));
  if (p == NULL) {
    printf("Erro de alocação de memória.\n");
    return 1;
  }

  // Atribuição de valor e exibição
  *p = 42;
  printf("Valor de p antes do free: %d\n", *p);

  // Liberação da memória alocada
  free(p);

  // Caso 1: Acesso ao ponteiro p após a memória ser liberada
  // Isso causa comportamento indefinido (use apenas para fins didáticos)
  // Não recomendado acessar a memória após free
  // printf("Valor de p após free (acesso ilegal): %d\n", *p); // Isso pode
  // causar crash ou valor indefinido

  // Caso 2: O valor do ponteiro em si não muda após free
  printf("Endereço de p após free: %p\n", (void *)p);

  // Caso 3: Definindo o ponteiro para NULL após o free
  p = NULL;
  printf("Endereço de p após ser definido como NULL: %p\n", (void *)p);

  return 0;
}
