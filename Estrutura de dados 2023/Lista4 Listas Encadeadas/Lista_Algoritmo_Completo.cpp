#include <stdio.h>
#include <stdlib.h>

struct lista {
	int valor;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* create(Lista* l)
{
	return NULL;
}

Lista* locale(Lista* l, int valor)
{
	Lista* atual = l;
	Lista* anterior = NULL;
	
	while (atual != NULL && atual->valor < valor){
		anterior = atual;
		atual = atual->prox;
	}
	return anterior;	
}

Lista* insert(Lista* l, int valor)
{
	Lista* noh = (Lista*) malloc(sizeof(Lista));
	noh->valor = valor;
	
	if(l == NULL){
		noh->prox = l;
		return noh;
	} else {
		Lista* nohAnterior = locale(l, valor);
		noh->prox = nohAnterior->prox;
		nohAnterior->prox = noh;
		return l;
	}
}

Lista* remove(Lista* l, int valor)
{
	Lista* atual = l;
	Lista* anterior = NULL;
	
	if( atual != NULL && atual->valor != valor){
		anterior = atual;
		atual = atual->prox;
	}
	
	if(atual == NULL) return l;		// não encontrou o valor
	
	if(anterior == NULL){		//valor esta no primeiro nó
		l = atual->prox;
		free(atual);
	} else {
		anterior->prox = atual->prox;
		free(atual);
	}
	
	return l;
}

void Qtd(Lista* l){
	int i;
	Lista* atual = l;
	for(i = 0; atual != NULL; i++){
		atual = atual->prox;
	}
	printf("A lista possui %d elementos.\n", i);
}


int main(void){
	Lista* l = create(l);
	
	l = insert(l, 10);
	l = insert(l, 20);
	l = insert(l, 30);
	Qtd(l);
	l = remove(l,10);
	Qtd(l);
}
