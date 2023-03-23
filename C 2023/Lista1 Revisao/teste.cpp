#include <stdio.h>

void leitura(int* p){
	printf("Na funcao: %d", p);
}

int main() {
   int a = 10; //declara uma variável inteira "a" com o valor 10
   int *ponteiro; //declara um ponteiro para um inteiro
   ponteiro = &a; //atribui o endereço de "a" ao ponteiro

   printf("O valor de a é: %d\n", a); //imprime o valor de "a"
   printf("O valor de *ponteiro é: %d\n", *ponteiro); //imprime o valor armazenado no endereço apontado por "ponteiro"
   printf("O endereço de a é: %d\n", &a); //imprime o endereço de "a"
   printf("O valor armazenado em ponteiro é: %p\n", ponteiro); //imprime o endereço armazenado em "ponteiro"

	leitura(ponteiro);

   return 0;
}
