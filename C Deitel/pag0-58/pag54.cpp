#include <stdio.h>

int main(){
	int contador = 1, nota, total = 0, media;
	
	while( contador <= 10 ){
		printf("Digite a nota: ");
		scanf( "%d", &nota);
		
		total += nota;
		contador += 1;
	}
	
	media = total/10;
	
	printf("Media da turma eh %d\n", media);
	printf("\n%d", contador);
	
}
