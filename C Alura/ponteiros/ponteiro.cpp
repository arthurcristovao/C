#include <stdio.h>

// quando define um ponteiro, a variavel se torna um endereço de memoria e o * acessa o valor que esta nesse endereço

void calcula(int *c){ // o * recebe o endereço de memória
	
	printf("calcula %d %d\n", (*c), c); //c virou um endereço de memoria e *c acessa o valor do endereço
	
	(*c)++; //o parenteses reforça o acesso ao conteudo do endereço
	
	printf("calcula %d %d\n", (*c), c);
}

int main(){
	int c = 10;
	
	printf("main %d %d\n", c, &c);
	calcula(&c); //esta passando um endereço de memoria da variavel c
	printf("main %d %d\n", c, &c);
}
