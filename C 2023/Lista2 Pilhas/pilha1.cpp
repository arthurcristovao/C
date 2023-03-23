#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int topo;
	int tam;
	int* array;
} Pilha;

Pilha* criar_pilha(int tam)
{
	Pilha* pilha = (Pilha*) malloc(sizeof(Pilha)); //cria um endereço de memoria do tamanho da struct
	pilha->tam = tam;
	pilha->topo = -1;
	pilha->array = (int*) malloc(pilha->tam * sizeof(Pilha));
	
	return pilha;
}

void empilhar(Pilha* pilha, int valor)
{
	printf("\n");
	
	if(pilha->topo == pilha->tam - 1){ //verifica se a pilha esta cheia
		printf("A pilha esta cheia.");
		return;
	}	
	pilha->array[++pilha->topo] = valor; //adiciona o valor ao topo da pilha antes de incrementar o contador topo
	printf("Empilha o valor %d", valor);
}

int desempilhar(Pilha* pilha)
{
	if(pilha->topo == -1){ 		//verifica se esta vazia
		printf("\nA pilha esta vazia");
		return -1;
	}
	return pilha->array[pilha->topo--];	
}

int main(void)
{	
	Pilha* pilha1 = criar_pilha(5);
	Pilha* pilha2 = criar_pilha(10);
	int x;

//-------------------
	desempilhar(pilha1);
	
	int j = 3; //tamanho da impressão
	for(int i = 0; i < j; i++){		
		empilhar(pilha1, (i+1)*10);
	}

	for(int i = 0; i < j; i++){		
		x = desempilhar(pilha1);
		printf("\nDesempilha o valor %d", x);
	}
	
	desempilhar(pilha1);	
//--------------------
	
	
	for(int i = 0; i < 11; i++){		
		empilhar(pilha2, (i+1)*10);
	}


	
	return 0;
}
