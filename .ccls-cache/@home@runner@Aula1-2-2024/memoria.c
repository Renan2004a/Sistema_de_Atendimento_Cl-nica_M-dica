#include "memoria.h"
#include <stdio.h>
#include <stdlib.h>

// Função que aloca memória, manipula o ponteiro e exibe as diferenças (*p vs p)
void demonstrarPonteiro() {
  int *p;

  // Alocação de memória para um único inteiro
  p = (int *)malloc(sizeof(int));
  if (p == NULL) {
    printf("Erro de alocação de memória.\n");
    return;
  }

  // Atribuindo valor à memória apontada por p
  *p = 42; // *p é o valor armazenado no local de memória para o qual p aponta

  // Mostrando a diferença entre p e *p
  printf("Endereço armazenado em p: %p\n",
         (void *)p); // Exibe o endereço de memória (valor de p)
  printf("Valor armazenado em *p: %d\n",
         *p); // Exibe o valor no endereço apontado por p (valor de *p)

  // Liberação da memória alocada
  free(p);
  p = NULL; // Boa prática: definir o ponteiro como NULL após liberar a memória
}

// Nova função que demonstra o uso de malloc e os conceitos entre *p, p, &p e
// outros
void demonstrarAlocacao() {
  // Exemplo 1: Alocação dinâmica de memória usando malloc
  Tipo *p;
  p = (Tipo *)malloc(
      sizeof(Tipo)); // malloc aloca espaço para um objeto do tipo 'Tipo'

  if (p == NULL) {
    printf("Erro de alocação de memória.\n");
    return;
  }

  // Atribuindo valor à estrutura Tipo
  p->valor = 42; // *p significa acessar o valor ao qual o ponteiro 'p' aponta

  // Exemplo 2: Diferença entre *p e p
  printf("\n[Exemplo 2] *p vs p:\n");
  printf("Endereço armazenado em p (endereço da memória alocada): %p\n",
         (void *)p);
  printf("Valor armazenado em *p (valor da estrutura): %d\n", p->valor);

  // Exemplo 3: Diferença entre p e &p
  printf("\n[Exemplo 3] p vs &p:\n");
  printf("Endereço armazenado em p: %p\n",
         (void *)p); // Endereço de memória apontado por p
  printf("Endereço de p (&p): %p\n",
         (void *)&p); // Endereço de memória do ponteiro p (onde ele está
                      // armazenado)

  // Exemplo 4: Diferença entre Tipo *p e Tipo p
  Tipo var;        // Uma variável normal do tipo 'Tipo'
  var.valor = 100; // Atribui um valor a 'var', que não usa malloc

  printf("\n[Exemplo 4] Tipo *p vs Tipo p:\n");
  printf("Valor de Tipo p (var): %d\n",
         var.valor); // Acessando a variável diretamente
  printf("Valor de Tipo *p (*p): %d\n",
         p->valor); // Acessando o valor alocado dinamicamente

  // Exemplo 5: Atribuindo novamente memória usando malloc
  free(p); // Boa prática: liberar a memória antes de realocar
  p = (Tipo *)malloc(sizeof(Tipo)); // Re-alocando espaço para 'Tipo'

  if (p == NULL) {
    printf("Erro de alocação de memória.\n");
    return;
  }

  // Atribuindo novo valor à memória apontada por p
  p->valor = 84;
  printf("\n[Exemplo 5] Novo valor após reallocação: %d\n", p->valor);

  // Liberação da memória alocada
  free(p);
  p = NULL; // Boa prática: definir o ponteiro como NULL após liberar a memória
}

void refePonteiro() {
  int a = 42;  // Variável 'a' que contém o valor 42
  int *p = &a; // Ponteiro 'p' recebe o endereço de 'a'

  printf("Endereço de a (&a): %p\n", (void *)&a); // Exibe o endereço de 'a'
  printf("Valor de a (*p): %d\n",
         *p); // Exibe o valor apontado por 'p' (que é o valor de 'a')

}
