#include <stdio.h>

void copia(int* array1, int* array2){
	
	
	
	for(int i = 0; i < 10; i++ ){
		array2[i] = array1[i];
		//if(array2[i] == 0) printf("\n");
		printf("Copia do array: %d\n", array2[i]);
	}
	
}

void armazena(int* array1){
	
	for(int i = 0; i < 10; i++ ){
		scanf("%d", &array1[i]);
	}
	
}


int main(void){
	
	int array1[10], array2[10];
	
	
	
	armazena(array1);
	printf("\n");
	copia(array1, array2);
	
	return 0;
}
