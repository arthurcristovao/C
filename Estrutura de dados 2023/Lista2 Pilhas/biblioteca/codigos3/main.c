#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int array[10];

int main(int argc, char *argv[]) {
	
	int i;
	for(i = 1; i <= 15; i++)
		push(array, i);
		
	for(i = 1; i <= 15; i++)
	{
		int valor = pop(array);
		printf("%d\n", valor);
	}
	
	system("pause");
	return 0;
}
