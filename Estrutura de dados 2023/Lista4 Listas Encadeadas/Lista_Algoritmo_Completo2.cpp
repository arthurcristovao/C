#include <stdio.h>
#include <stdlib.h>

struct lista {
	int valor;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* create(){
	return NULL;
}

Lista* locale(Lista* l, int valor){
	Lista* atual = l;
	Lista* anterior = NULL;
	
	while ( atual != NULL && atual->valor < valor){
		anterior = atual;
		atual = atual->prox;
	}
	
	return anterior;
}

Lista* insert(Lista* l, int valor){
	Lista* novoNo = (Lista*) malloc(sizeof(Lista));
	novoNo->valor = valor;
	if( l == NULL ){ // se está no inicio
		novoNo->prox = l;
		return novoNo;
	} else {
		Lista* noAnterior = locale(l, valor);
		novoNo->prox = noAnterior->prox;
		noAnterior->prox = novoNo;
		return l;
	}
}

Lista* remove(Lista* l, int valor){
	Lista* atual = l;
	Lista* anterior = NULL;
	
	while( atual != NULL && atual->valor < valor){
		anterior = atual;
		atual = atual->prox;
	}
	
	if(atual == NULL) return L;
	
	if(anterior == NULL){		//primeiro nó
		l = atual->prox;
		free(atual);
	} else {					//meio da lista
		anterior->prox = atual->prox;
		free(atual);
	}
	return l;	
}

int main(void){
	Lista* l = create();
	
	
}
