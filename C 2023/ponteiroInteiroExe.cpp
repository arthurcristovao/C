#include <stdio.h>

void leitura(int* p){
	printf("Na funcao: %d", p);
}

int main() {
   int a = 10; //declara uma vari�vel inteira "a" com o valor 10
   int *ponteiro; //declara um ponteiro para um inteiro
   ponteiro = &a; //atribui o endere�o de "a" ao ponteiro

   printf("O valor de a �: %d\n", a); //imprime o valor de "a"
   printf("O valor de *ponteiro �: %d\n", *ponteiro); //imprime o valor armazenado no endere�o apontado por "ponteiro"
   printf("O endere�o de a �: %d\n", &a); //imprime o endere�o de "a"
   printf("O valor armazenado em ponteiro �: %p\n", ponteiro); //imprime o endere�o armazenado em "ponteiro"

	leitura(ponteiro);

   return 0;
}
