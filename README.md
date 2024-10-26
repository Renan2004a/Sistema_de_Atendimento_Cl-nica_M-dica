# Sistema de Atendimento em uma Clínica Médica

# Descrição
Este programa simula um sistema de atendimento para uma clínica médica utilizando uma fila circular. A fila é usada para gerenciar pacientes que aguardam por atendimento médico. Pacientes são adicionados à fila quando chegam à clínica e removidos da fila quando chamados para atendimento, garantindo que o paciente que está esperando há mais tempo seja atendido primeiro (modelo FIFO - First In, First Out). Este programa é a entrega da Tarefa "FILA" na disciplina Estrutura de Dados

# Estrutura de Dados
A fila circular é representada por uma estrutura que contém os seguintes campos:

- itens[MAX]: Armazena os nomes dos pacientes (O tamanho máximo da fila é definido por MAX).
- inicio: Um índice que aponta para o início da fila (paciente a ser atendido).
- fim: Um índice que aponta para o fim da fila (último paciente a chegar).
- quantidade: Um contador que rastreia quantos pacientes estão atualmente na fila.

# Funcionalidades
O programa oferece as seguintes funcionalidades:

## 1. Adicionar paciente à fila (enfileirar):
Adiciona um novo paciente ao final da fila circular, desde que a fila não esteja cheia.
A função verifica se é a primeira inserção e ajusta os índices da fila conforme necessário.

## 2. Remover paciente da fila para atendimento (desenfileirar):
Remove o paciente que está na posição inicio da fila, ou seja, o paciente que chegou primeiro.
Atualiza os índices de forma circular e reinicializa a fila quando ela estiver vazia.

## 3. Exibir fila de pacientes (exibirFila):
Exibe os pacientes presentes na fila na ordem correta, do paciente mais antigo ao mais recente.

## 4. Verificar se a fila está cheia (estaCheia):
Retorna verdadeiro se o número de pacientes na fila atingir o valor máximo (MAX).

## 5. Verificar se a fila está vazia (estaVazia):
Retorna verdadeiro se não houver pacientes na fila.

# Aluno
Renan Alves Tavares

# Docente
Johnatan Alves De Oliveira - Estrutura de Dados

