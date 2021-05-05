#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

typedef struct carro{
	char nome[20], cor[10];
	int ano, id;
}Carro;

int main(void) {
  	int op, chave;
	Heap h = inicializar();
	Carro carro;
	do{
		system("cls");
		printf("1\tInserir Carro\n2\tRemover Carro\n3\tImprimir a Heap de Carros\n4\tSair\n>");
		scanf("%d", &op);
		system("cls");
		switch(op){
			case 1:
				printf("Digite o nome do carro:\n>");
				scanf("%s", carro.nome);
				system("cls");
				printf("Digite a cor do carro:\n>");
				scanf("%s", carro.cor);
				system("cls");
				printf("Digite o ano do carro:\n>");
				scanf("%d", &carro.ano);
				system("cls");
				printf("Digite o ID do carro:\n>");
				scanf("%d", &carro.id);
				push(h, &carro, sizeof(Carro), &carro.id);
				break;
			case 2:
				pop(h, &carro, sizeof(Carro), &chave);
				printf("O CARRO:\nNome: %s\nCor: %s\nAno: %d\nId %d\nFOI REMOVIDO", carro.nome, carro.cor, carro.ano, carro.id);
				system("pause");
				break;
			case 3:
				imprimir(h);
				system("pause");
				break;
			case 4:
				h = destruir(h);
				printf("Programa finalizado . . .\n");
				return 0;
		}
	}while(1);
}
