#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void media(int* array, int tam) {
	int media = 0;
	
	for(int i = 0; i < tam; i++){
		media += array[i] ;
	}
	
	media /= tam;
	printf("\n\nA media e %d", media);	
}

void sorteio(int* array, int tam) {
	srand(time(0));
	
	for(int i = 0; i < tam; i++){
		array[i] = rand() % 100;
		printf("\n%d", array[i]);
	}	
}

int digita(){
	int tam;	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);	
	return tam;
}


int main(void){
	int tam = digita();
	int array[tam];
	
	sorteio(array, tam);
	media(array, tam);	
}
