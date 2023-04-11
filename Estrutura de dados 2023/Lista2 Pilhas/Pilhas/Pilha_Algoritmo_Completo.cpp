#include <stdio.h>
#include <stdlib.h>
#include "Pilha_Algoritmo_Completo.h"

#define tam 5

//criar uma pilha vazia			create()
//inserir no topo				push()
//remover do topo				pop()
//verificar se está cheia		full()
//verificar se está vazia		empty()
//liberar a memória				free()

typedef struct pilha {
	int n; //topo
	int* array;
}Pilha;

Pilha* create(){
	Pilha* p = (Pilha*) malloc (sizeof(Pilha));
	p->n = 0;
	p->array = (int*) malloc (tam * sizeof(int)); //provavel erro
	
	return p;
}

int full(Pilha* p){
	return (p->n == tam);
}

void push(Pilha* p, int v)
{
	if( full(p) ){
		printf("A pilha esta cheia!\n");
	} else {
		p->array[++p->n] = v;
		printf("Push %d\n", p->array[p->n]);
	}	 
}

int empty(Pilha* p){
	return (p->n == 0);
}

int pop(Pilha* p)
{
	int v;
	if( empty(p) ){
		printf("A pilha esta vazia\n");
	} else {
		v = p->array[p->n--];
	}
	
	return v;
}

void free_p(Pilha* p){
	free(p);
}

int main(void){
	Pilha* p = create();
	int value;
	
	
	value = pop(p);
	if(value != 0) printf("Pop %d\n", value);
	push(p, 10);
	push(p, 20);
	push(p, 30);
	push(p, 40);
	push(p, 50);
	push(p, 60);
	value = pop(p);
	if(value != 0) printf("Pop %d\n", value);
	value = pop(p);
	if(value != 0) printf("Pop %d\n", value);
	value = pop(p);
	if(value != 0) printf("Pop %d\n", value);
	value = pop(p);
	if(value != 0) printf("Pop %d\n", value);
	value = pop(p);
	if(value != 0) printf("Pop %d\n", value);
	value = pop(p);
	if(value != 0) printf("Pop %d\n", value);
	value = pop(p);
	if(value != 0) printf("Pop %d\n", value);
	
	free_p(p);
	
}
