#include <stdio.h>
#include <stdlib.h>
#include "exemplo.h"

#define N 4

typedef struct fila{
	int n;
	int ini;
	int* vet;
} Fila;

Fila* fila_cria(void)
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->n = 0;	//inicializa a fila vazia
	f->ini = 0; //escolhe uma posição inicial
	f->vet = (int*) malloc(N * sizeof(Fila));
	return f;
}

int fila_cheia (Fila* f)
{
	return (f->n == N);
}

void fila_insere(Fila* f, float v)
{
	int fim;
	if(fila_cheia(f)) {
		printf("Capacidade da fila estourou\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->vet[fim] = v;
	f->n++;
	printf("Insere: %.f\n", v);
}



int fila_vazia (Fila* f)
{
	return (f->n == 0);
}

float fila_retira (Fila* f)
{
	float v;
	if(fila_vazia(f)) {
		printf("Fila vazia.\n");
		exit(1);
	}	
	v = f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;
	return v;
}

int main(void){
	float x;
	
	Fila* fila1 = fila_cria();
	
	fila_insere(fila1, 23);
	fila_insere(fila1, 81);
	
	x = fila_retira(fila1);
	printf("Remove: %.f\n", x);
	
	fila_insere(fila1, 100);
	
	x = fila_retira(fila1);
	printf("Remove: %.f\n", x);
	
	fila_insere(fila1, 50);
	fila_insere(fila1, 30);
	fila_insere(fila1, 40);
	fila_insere(fila1, 10);

	
	
	
}

