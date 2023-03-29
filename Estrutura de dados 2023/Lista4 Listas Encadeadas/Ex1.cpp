#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ex1.h"

int main(void){
	Lista* lista1, * lista2;
	int i;
	float timeA, timeB, timeC, timeD, timeE, timeF;
	clock_t start, end;
	
	lista1 = criaLista();
	lista2 = criaLista();
	
	printf("a\n\n");
	//a. Insira 100.000 números (comece 0 insira até 99.999). Calcule o tempo
	start = clock();
	for( i = 0; i < 1000000; i++){
		lista1 = insereLista(lista1, i);
	}
	end = clock();
	timeA = (float) ( end - start ) / CLOCKS_PER_SEC;
	
	printf("b\n\n");
	//b. Remova os números 10000 a 10999. Calcule o tempo da remoção
	start = clock();
	for(i = 10000 ; i < 11000; i++){
		lista1 = Remover(lista1, i);
	}
	end = clock();
	timeB = (float) ( end - start ) / CLOCKS_PER_SEC;
	
	printf("c\n\n");
	//c. Consulte os valores armazenados entre as posições 15000 e 20000. Calcule o tempo da consulta.
	start = clock();
	for( i = 15000; i <= 20000; i++){
		lista1 = Localiza(lista1, i);
		
	}
	end = clock();
	timeC = (float) ( end - start ) / CLOCKS_PER_SEC;
	
	printf("d\n\n");
	//d. Insira 100.000 números (comece 99.999 insira até 0). Calcule o tempo
	start = clock();
	for(i = 9999990; i >= 0; i--){
		lista2 = insereLista(lista2, i);
	}
	end = clock();
	timeD = (float) (end - start) / CLOCKS_PER_SEC;
	
	printf("e\n\n");
	//e. Remova os números 10000 a 10999. Calcule o tempo da remoção.
	start = clock();
	for(i = 10000 ; i < 11000; i++){
		lista2 = Remover(lista2, i);
	}
	end = clock();
	timeE = (float) ( end - start ) / CLOCKS_PER_SEC;
	
	printf("f\n\n");
	//f. Consulte os valores armazenados entre as posições 15000 e 20000. Calcule o tempo da consulta.
	start = clock();
	for( i = 15000; i <= 20000; i++){
		lista2 = Localiza(lista2, i);
	}
	end = clock();
	timeF = (float) ( end - start ) / CLOCKS_PER_SEC;
	
	printf("A %.2f\n", timeA);
	printf("B %.2f\n", timeB);
	printf("C %.2f\n", timeC);
	printf("D %.2f\n", timeD);
	printf("E %.2f\n", timeE);
	printf("F %.2f\n", timeF);
}
