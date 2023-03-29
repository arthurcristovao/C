typedef struct lista{
	int dado;
	struct lista* prox;
} Lista;

Lista* criaLista(void)
{
	return NULL;
}

Lista* insereLista(Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->dado = i;
	novo->prox = l;
	//printf("%d\n", novo->dado);
	return novo;
}

Lista* Localiza (Lista* L, int valor) {
	Lista* atual = L;
	Lista * anterior = NULL;
	
	while (atual != NULL && atual->dado < valor) {
		anterior = atual;
		atual = atual->prox;
	}
	
	return anterior;
}

Lista* Remover(Lista* L, int valor) //REMOÇÃO
{
	Lista* atual = L; // atual deve conter No com o valor;
	Lista* anterior = NULL; // anterior deve conter No anterior ao No com o valor;
	
		while ( atual != NULL && atual->dado != valor)
		{
			anterior = atual;
			atual = atual->prox;
		}
	
		if (atual == NULL) return L; // não encontrou
		if (anterior == NULL) // valor no primeiro No
		{
			L = atual->prox;
			free(atual);
		}
		else // valor no meio da lista
		{
			anterior->prox = atual->prox;
			free(atual);
		}
	return L;
}

void imprimeLista(Lista* l)
{
	Lista* p;
	for(p = l; p != NULL; p = p->prox){	
		printf("info = %d\n", p->dado);
	}	
}
