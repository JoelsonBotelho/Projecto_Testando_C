#ifndef TAREFA_H
#define TAREFA_H
#define MAX_DESCRICAO 100

typedef struct {
    char descricao[MAX_DESCRICAO];
    int concluida;
} Tarefa;

typedef struct {
    Tarefa *tarefas;
    int tamanho;
    int capacidade;
} ListaDeTarefas;

void inicializarLista(ListaDeTarefas *lista, int capacidadeInicial);
void adicionarTarefa(ListaDeTarefas *lista, char *descricao);
void marcarTarefaConcluida(ListaDeTarefas *lista, int indice);
void listarTarefas(ListaDeTarefas lista);
void liberarLista(ListaDeTarefas *lista);
#endif