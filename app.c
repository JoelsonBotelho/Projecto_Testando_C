#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tarefa.h"

int main() {
  ListaDeTarefas lista;
  inicializarLista(&lista, 10); // Inicializa com uma capacidade inicial de 10
  char nome[20];
  int opcao = 0, idT = 0;
  do{
    printf("Escolha uma opção:\n");
    printf("1 - Adicionar tarefa\n");
    printf("2 - Marcar tarefa como concluída\n");
    printf("3 - Listar tarefas\n");
    printf("4 - Liberar lista\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
        printf("Digite a descrição da tarefa: ");
        scanf("%s", nome);
        adicionarTarefa(&lista, nome);
        printf("Tarefa adicionada com sucesso!\n");
      break;
      case 2:
        printf("Digite o id da tarefa que deseja marcar como concluída: ");
        scanf("%d", &idT);
        marcarTarefaConcluida(&lista, idT);
        printf("Tarefa marcada como concluída com sucesso!\n");      
      break;
      case 3:
        printf("\nLista de Tarefas Atualizada:\n");
        listarTarefas(lista);
      break;
      case 4:
        liberarLista(&lista);
      break;
    }
  }while(opcao != 0);
  return 0;
}
