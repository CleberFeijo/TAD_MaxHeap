#ifndef Heap_h
#define Heap_h

typedef struct heap *Heap;										//Ponteiro para struct Heap
Heap inicializar();												//Definicao da funcao para inicializar a heap
Heap destruir(Heap heap);										//Definicao da funcao para destruir a heap
int push(Heap heap, void *elemento, int tamMem, int *chave);	//Definicao da funcao para inserir na heap
int pop(Heap heap, void *retorno, int tamMem, int *chave);		//Definicao da funcao para remover da heap
void imprimir(Heap heap);										//Definicao da funcao para imprimir os elementos da heap

#endif



