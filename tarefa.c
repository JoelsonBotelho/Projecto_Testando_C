#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tarefa.h"

void inicializarLista(ListaDeTarefas *lista, int capacidadeInicial) {
    lista->tamanho = 0;
    lista->capacidade = capacidadeInicial;
    lista->tarefas = (Tarefa *)malloc(sizeof(Tarefa) * capacidadeInicial);
}

void adicionarTarefa(ListaDeTarefas *lista, char *descricao) {
    if (lista->tamanho >= lista->capacidade) {
        // Aumentar a capacidade da lista dinamicamente, se necessário
        lista->capacidade *= 2;
        lista->tarefas = (Tarefa *)realloc(lista->tarefas, sizeof(Tarefa) * lista->capacidade);
    }

    if (lista->tamanho < lista->capacidade) {
        strcpy(lista->tarefas[lista->tamanho].descricao, descricao);
        lista->tarefas[lista->tamanho].concluida = 0;
        lista->tamanho++;
    } else {
        printf("A lista de tarefas está cheia!\n");
    }
}

void marcarTarefaConcluida(ListaDeTarefas *lista, int indice) {
    if (indice >= 0 && indice < lista->tamanho) {
        lista->tarefas[indice].concluida = 1;
    } else {
        printf("Índice inválido!\n");
    }
}

void listarTarefas(ListaDeTarefas lista) {
    for (int i = 0; i < lista.tamanho; i++) {
        printf("%d. %s [%s]\n", i, lista.tarefas[i].descricao, lista.tarefas[i].concluida ? "Concluída" : "Pendente");
    }
}

void liberarLista(ListaDeTarefas *lista) {
    free(lista->tarefas);
    lista->tarefas = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
}