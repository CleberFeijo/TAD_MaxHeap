#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "heap.h"

typedef struct item{
	int chave;
	void *obj;
}Item;

struct heap{
	Item *vet;	//vetor
	int tam;	//tamanho
};

//calcula indice do filho do elemento a esquerda
int IndiceFilhoEsq(Heap h, int indice){
	int filho = (2*indice) + 1;
	if(indice >= h->tam || filho >= h->tam) return -1;
	return filho;
}

//calcula indice do filho do elemento a direita
int IndiceFilhoDir(Heap h, int indice){
    int filho = (2*indice)+2;
    if(indice >= h->tam || filho >= h->tam) return -1;
    return filho;
}

//calcula indice do pai do elemento
int IndicePai(Heap h, int indice){
    int pai = (int)floor((indice-1)/2);
    if(indice <= 0 || indice >= h->tam) return -1;
    return pai;
}

void AjustarSubindo (Heap h, int indice){
    if(indice != -1){
        int pai = IndicePai(h,indice);
        if(pai != -1){
            if(h->vet[indice].chave > h->vet[pai].chave){
			
                Item aux = h->vet[indice];
                h->vet[indice] = h->vet[pai];
                h->vet[pai] = aux;
                AjustarSubindo(h,pai);
            }
        }
    }
}

void AjustarDescendo (Heap h, int indice){
    if(indice != -1 && IndiceFilhoEsq(h, indice) != -1){
        int indiceMaiorFilho = IndiceFilhoEsq(h, indice);
        if(IndiceFilhoDir(h,indice)!= -1 && h->vet[IndiceFilhoDir(h,indice)].chave > h->vet[indiceMaiorFilho].chave)
            indiceMaiorFilho = IndiceFilhoDir(h, indice);
        if (h->vet[indiceMaiorFilho].chave > h->vet[indice].chave){
            Item aux = h->vet[indice];
            h->vet[indice] = h->vet[indiceMaiorFilho];
            h->vet[indiceMaiorFilho] = aux;
            AjustarDescendo(h, indiceMaiorFilho);
        }
    }
}

//funcao para inicializar
Heap inicializar(){
	Heap heap = (Heap) malloc(sizeof(struct heap));
	heap->vet = (Item*) malloc(0);
	heap->tam = 0;
	return heap;
}

//funcao para destruir
Heap destruir(Heap heap){
	int i;
	for(i=0; i<heap->tam; i++){
		free(heap->vet[i].obj);
	}
	free(heap->vet);
	free(heap);
	return NULL;
}

//função para inserir
int push(Heap heap, void* elemento, int tamMem, int *chave){
	heap->tam++;
	heap->vet = (Item*) realloc(heap->vet, heap->tam*sizeof(Item));
	heap->vet[heap->tam-1].obj = (void*) malloc(tamMem);
	heap->vet[heap->tam-1].chave = *chave;
	memcpy(heap->vet[heap->tam-1].obj, elemento, tamMem);
	AjustarSubindo(heap, heap->tam-1);
	return 1;
}

//função para remover
int pop(Heap heap, void *retorno, int tamMem, int *chave){
	if(heap->tam == 0){
		retorno = NULL;
		return 0;
	}
	*chave = heap->vet[0].chave;
	memcpy(retorno, heap->vet[0].obj, tamMem);
	heap->vet[0] = heap->vet[heap->tam-1];
	heap->tam--;
	AjustarDescendo(heap, 0);
	heap->vet = (Item*) realloc(heap->vet, heap->tam*sizeof(Item));
	return 1;
}

//funcao para imprimir
void imprimir(Heap heap){
	int i;
  printf("Chaves: ");
	for(i=0; i<heap->tam; i++){
		printf("%d\t", heap->vet[i].chave);
	}
	printf("\n");
}
