#ifndef MEMORIA_H
#define MEMORIA_H

// Declaração de uma estrutura 'Tipo' para ser usada na função
// demonstrarAlocacao
typedef struct {
  int valor;
} Tipo;

// Função que aloca memória, manipula o ponteiro e exibe as diferenças
void demonstrarPonteiro();

// Nova função que demonstra o uso de malloc e os conceitos entre *p, p, &p e
// outros
void demonstrarAlocacao();

void refePonteiro();

#endif
