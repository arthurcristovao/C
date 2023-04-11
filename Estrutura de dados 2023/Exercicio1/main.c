#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


int main(int argc, char *argv[]) {
	system("pause");
	int i;
	for (i = 1; i <= 20; i++)
	{
		if (push(i))
			printf("Empilhou %d\n", i);
		else 
			printf("Falha em empilhar %d\n", i);
	}
	if (full())
		printf("Ficou cheia!\n");
	for (i = 1; i <= 20; i++)
	{
		int v;
		if (pop(&v))
			printf("Desempilhou %d\n", v);
		else 
			printf("Falha em desempilhar \n");
	}
	if (empty())
		printf("Ficou vazia!\n");
	return 0;
}
