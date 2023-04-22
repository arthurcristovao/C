#include <stdio.h>
#include <stdlib.h>

#define tam 5

typedef struct fila {
	int head;
	int tail;
	int* dados;	
} Fila;

Fila* create(){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->head = 0;
	f->tail = 0;
	f->dados = (int*) malloc(tam * sizeof(int));
	
	return f;
}

int full(Fila* f){
	return ( f->head == tam );
}

void enqueue(Fila* f, int valor){
	if( full(f) ){
		printf("A fila esta cheia.\n");
	} else {
		f->dados[++f->head] = valor;
		printf("Enfileirou o valor %d na posicao %d\n", valor, f->head-1);
	}
}

int empty(Fila* f){
	return ( f->head == 0 || f->tail == tam);
}

int dequeue(Fila* f){
	int v;
	if( empty(f) ){ 
		printf("A fila esta vazia.\n");
	} else {
		v = f->dados[f->tail+1];
		f->tail++;
		f->head--;
		if(f->head <= 0) f->head = 0;
		return v;
	}
	
}

int main(void){
	Fila* f = create();
	int v;
	
	enqueue(f, 10);
	enqueue(f, 20);
	enqueue(f, 30);

	printf("\n\n");
	
	v = dequeue(f);
	printf("%d\n", v);
	v = dequeue(f);
	printf("%d\n", v);
	v = dequeue(f);
	printf("%d\n", v);
	v = dequeue(f);
	printf("%d\n", v);

	
}


