#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int valor;
	struct lista* prox;
} Lista;

Lista* criaLista(void)
{
	return NULL;
}

Lista* insereLista(Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->valor = i;
	novo->prox = l;
	
	return novo;
}

void imprimeLista(Lista* l)
{
	Lista* p;
	for(p = l; p != NULL; p = p->prox){	
		printf("info = %d\n", p->valor);
	}	
}

int main(void){
	Lista* l;
	
	l = criaLista();
	l = insereLista(l, 23);
	l = insereLista(l, 45);
	l = insereLista(l, 29);
	
	imprimeLista(l);
}
