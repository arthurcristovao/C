#include <stdio.h>
#include <stdlib.h>

#define tam 5

typedef struct fila{
	int n;		//head
	int ini; 	//tail
	int* dados;
} Fila;

Fila* create(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	f->dados = (int*) malloc ( tam * sizeof(int)); 
	
	return f;
}

int full(Fila* f){
	return ( f->n == tam );
}

void insert(Fila* f, int v)
{
	if( full(f) ){
		printf("A fila esta cheia\n");
	} else {
		f->dados[f->n++] = v;
		printf("Entrou %d\n", v);
	}
}

int empty(Fila* f){
	return ( f->n == 0 || f->ini == tam);
}

int remove(Fila* f)
{
	int v;
	if( empty(f) ){
		printf("A fila esta vazia\n\n");
	} else {
		v = f->dados[f->ini];
		f->ini++;
		
		printf("Saiu %d\nini: %d\n\n", v, f->ini-1);
		return v;
	}
}

void show(Fila* f){
	for(int i = f->ini; i< f->n; i++){
		printf("%d, %d\n", i, f->dados[i]);
	}
}

void f_free(Fila* f){
	free(f->dados);
	free(f);
}

int main(void){
	Fila* f;
	int v;
	
	f = create();
	
	remove(f);

	insert(f, 10);
	insert(f, 20);

	
	show(f);
	
	f_free(f);
}
