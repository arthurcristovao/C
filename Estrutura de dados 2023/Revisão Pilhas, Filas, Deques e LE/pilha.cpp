#include <stdio.h>
#include <stdlib.h>

#define tam 5

typedef struct pilha {
	int topo;
	int* dados;
} Pilha;

Pilha* create(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = 0;
	p->dados = (int*) malloc (tam * sizeof(int));
	
	return p;
}

int full(Pilha* p){
	return (p->topo == tam);
}

void push(Pilha* p, int valor){
	if( full(p) ){
		printf("A pilha esta cheia.\n");
	} else {
		p->dados[++p->topo] = valor;
	}
}

int empty(Pilha* p){
	return (p->topo == 0);
}

int pop(Pilha* p){
	int v;
	
	if( empty(p) ){
		printf("A pilha esta vazia.\n");
	} else {
		v = p->dados[p->topo--];
	}
	
	return v;
}


int main(void){
	Pilha* p = create();
	int v;
	
	v = pop(p);
	printf("%d\n", v);
	push(p, 10);
	push(p, 20);
	push(p, 30);
	push(p, 40);
	push(p, 50);
	push(p, 60);
	
	
}
