#include <stdio.h>
#include <stdlib.h>
#include "deque_Algoritmo_Completo.h"

#define tam 3

//criar uma fila vazia					create();
//inserir no fim da fila				insert();
//remover no inicio da fila
//verificar se a fila esta vazia
//verificar se a fila esta cheia		full()
//liberar a fila						f_free()

struct fila{
	int n; //quantidade atual de itens na fila
	int ini; // indice
	float* array;
};

Fila* create(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	f->array = (float*) malloc(tam * sizeof(float));
	
	return f;
}

int full(Fila* f){
	return ( f->n == tam );
}

void insert(Fila* f, float v)
{
	int fim;
	if ( full(f) ){
		printf("A fila esta cheia!\n");
	} else {
		fim = (f->ini + f->n) % tam; //forma o deque
		f->array[fim] = v;
		f->n++;
		printf("Entrou: %.2f -> qtd: %d -> posicao: %d\n\n", f->array[fim], f->n, fim);
	}
}

int empty(Fila* f){
	return ( f->n == 0);
}

float remove(Fila* f)
{
	float v;
	if( empty(f) ){
		printf("A fila esta vazia!\n");
	} else {
		v = f->array[f->ini];
		f->ini = (f->ini + 1) % tam;
		f->n--;
		return v;
	}
}

void f_free(Fila* f){
	free(f->array);
	free(f);
}

int main(void){
	Fila* f;
	float v;
	
	f = create();
	
	insert(f, 10);
	insert(f, 20);
	insert(f, 30);
	v = remove(f);
	printf("Saiu %.2f -> qtd: %d -> Inicio: %d\n\n", v, f->n, f->ini);
	v = remove(f);
	printf("Saiu %.2f -> qtd: %d -> Inicio: %d\n\n", v, f->n, f->ini);
	insert(f, 40);
	insert(f, 50.5);
	insert(f, 60);
	
	
	f_free(f);
}


