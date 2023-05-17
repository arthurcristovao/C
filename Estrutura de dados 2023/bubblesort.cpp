#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20

void bolha(int n, int* v){
	int i,j;
	for( i = n - 1 ; i >= 1 ;  i--)
		for( j = 0; j < i; j++)
			if(v[j] > v[j+1]){
				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
}

int main(void){
	int i, v[TAM];
	
	srand(time(NULL));
	
	for( int i = 0; i < TAM; i++) 
		v[i] = (rand()%1000) + 1;
	
	bolha(TAM, v);
	printf("Vetor ordenado: \n");
	
	for( i = 0 ; i < TAM ; i++) printf("%d\n", v[i]);
	
	
	return 0;
	
}
