#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int valor;
	struct lista* prox;
} Lista;

Lista* create(){
	return NULL;
}

Lista* locale(Lista* L, int valor){
	Lista* atual = L;
	Lista* anterior = NULL;
	while( atual != NULL && atual->valor < valor){
		anterior = atual;
		atual = atual->prox;
	}
	return anterior;
}

void insert(Lista* L, int valor){
	Lista* novoNo = (Lista*) malloc(sizeof(Lista));
	novoNo->valor = valor;
	
	if( L == NULL){
		L->prox = novoNo;
		return novoNo; 
	} else {
		Lista* noAnterior = locale(L, valor);
		novoNo->prox = noAnterior->prox;
		noAnterior->prox = novoNo; 
		return L;
	}
	
}

int main(void){
	Lista* L = create();
}
