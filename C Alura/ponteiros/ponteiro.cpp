#include <stdio.h>

// quando define um ponteiro, a variavel se torna um endere�o de memoria e o * acessa o valor que esta nesse endere�o

void calcula(int *c){ // o * recebe o endere�o de mem�ria
	
	printf("calcula %d %d\n", (*c), c); //c virou um endere�o de memoria e *c acessa o valor do endere�o
	
	(*c)++; //o parenteses refor�a o acesso ao conteudo do endere�o
	
	printf("calcula %d %d\n", (*c), c);
}

int main(){
	int c = 10;
	
	printf("main %d %d\n", c, &c);
	calcula(&c); //esta passando um endere�o de memoria da variavel c
	printf("main %d %d\n", c, &c);
}
